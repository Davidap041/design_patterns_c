#include "shape.h"
#ifdef SIMPLE_FACTORY

struct shape_circle
{
	struct shape shape;
	float radius;
};

struct shape_rectangle {
	struct shape shape;
	float width, height;
};

// circle api

static void _shape_circle_draw(shape_t shape) {
	struct shape_circle* self = CONTAINER_OF(shape, struct shape_circle, shape.api);
	// now we can accesss private methods
	_do_draw_circle(self->radius);
}
const struct shape_api _circle_api = {
	.draw = _shape_circle_draw
};

static void shape_circle_init(struct shape_circle* self) {
	memset(self, 0, sizeof(*self));
	self->api = &_circle_api;
}

// rectangle api


static void _shape_rectangle_draw(shape_t shape) {
	struct shape_rectangle* self = CONTAINER_OF(shape, struct shape_rectangle, shape.api);
	// now we can access private methods
	_do_draw_rectangle(self->width, self->height);
}
const struct shape_api _rectangle_api = {
	.draw = _shape_rectangle_draw
};
static void shape_rectangle_init(struct shape_rectangle* self) {
	memset(self, 0, sizeof(*self));
	self->api = &_rectangle_api;
}

// factory methods

void shape_draw(shape_t shape) {
	// call the virtual method
	(*shape)->draw(shape);
}
shape_t shape_create(enum shape_type type) {
	switch (type)
	{
	case SHAPE_CIRCLE: {
		struct shape_circle* shape = (struct shape_circle*)malloc(sizeof(struct shape_circle));
		shape_circle_init(shape);
		return &shape->api;
	}break;
	case SHAPE_RECTANGLE: {
		struct shape_rectangle* shape = (struct shape_rectangle*)malloc(sizeof(struct shape_rectangle));
		shape_rectangle_init(shape);
		return &shape->api;
	}
		
			break;
	default:
		break;
	}
}

#endif // SHAPE_FACTORY