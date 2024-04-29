#include "factory_pattern.h"
#ifdef SIMPLE_FACTORY

void usage_shape_factory(void)
{
	shape_t rect = shape_create(SHAPE_RECTANGLE);
	shape_t circle = shape_create(SHAPE_CIRCLE);

	shape_draw(rect);
	shape_draw(circle);
}


#endif // SHAPE_FACTORY