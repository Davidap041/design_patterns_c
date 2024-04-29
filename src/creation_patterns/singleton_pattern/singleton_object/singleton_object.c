#include "singleton_object.h"

struct object {
	int data;
	int state;
	int value;
};

#ifdef SYS_INIT

static void _init_singleton(void) {
	_singleton.data = 1;
	_singleton.state = 1;
	_singleton.value = 1;
}

SYS_INIT(_init_singleton, APPLICATION, priority)
#else

static struct object _object_singleton = {
	.data = 1,
	.state = 2,
	.value = 3,
};

#endif // SYS_INIT


#ifndef _UTILS_MACROS_H_
#define LOCK_INIT 0
#define LOCK_TYPE_T int
#define LOCK_METHOD(addr_pointer) (*(addr_pointer) = 1)
#define UNLOCK_METHOD(addr_pointer) (*(addr_pointer) = 0)

#define DEFINE_SINGLETON_ACQUIRE_RELEASE(type) \
static struct type *_##type##_in_use; \
static LOCK_TYPE_T _##type##_lock = LOCK_INIT; \
struct type *type##_acquire_singleton(void) \
{ \
    LOCK_METHOD(&_##type##_lock); \
    if (!_##type##_in_use) { \
        _##type##_in_use = &_##type##_singleton; \
        UNLOCK_METHOD(&_##type##_lock); \
        return _##type##_in_use; \
    } \
    UNLOCK_METHOD(&_##type##_lock); \
    return NULL; \
} \
void type##_release_singleton(struct type **self) \
{ \
    LOCK_METHOD(&_##type##_lock); \
    if ((self != NULL) && (*self == _##type##_in_use)) { \
        _##type##_in_use = NULL; \
        *self = NULL; \
    } \
    UNLOCK_METHOD(&_##type##_lock); \
}\
\

#endif


DEFINE_SINGLETON_ACQUIRE_RELEASE(object)

int object_get_data(void) {
	return _object_singleton.data;
}

int object_with_lock_get_state(int* state) {

	struct object* self = object_acquire_singleton();

	if (self == NULL || state == NULL) return 1;

	*state = self->state;
	object_release_singleton(&self);

	return 0;
}

int object_get_value(void) {
	return _object_singleton.value;
}
int object_pointer_get_data(struct object* self) {
	return self->data;
}
int object_pointer_get_value(struct object* self) {
	return self->value;
}

