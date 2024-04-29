#include <stddef.h>
#include <string.h>
//#define SIMPLE_FACTORY
#ifdef SIMPLE_FACTORY

#define CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))


// this is our public header
enum shape_type {
	SHAPE_CIRCLE,
	SHAPE_RECTANGLE
};

struct shape_api {
	void (*draw)(shape_t shape);
};

// define a generic shape handle
typedef struct shape_api** shape_t;

struct shape {
	const struct shape_api* const api;
};

shape_t shape_create(enum shape_type type);
void shape_draw(shape_t shape);

#endif // SHAPE_FACTORY