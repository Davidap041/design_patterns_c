#ifndef _SINGLETON_OBJECT_H_
#define _SINGLETON_OBJECT_H_

#include <stddef.h>
#include "../../utils_macros.h"


int object_get_data(void);
int object_with_lock_get_state(int *state);
int object_get_value(void);
int object_pointer_get_data(struct object* self);
int object_pointer_get_value(struct object* self);


DEFINE_SINGLETON_ACQUIRE_RELEASE_PROTOTYPE(object)

// struct object* object_acquire_singleton(void);
// void object_release_singleton (struct object** self);

#endif // !_SINGLETON_OBJECT_H_