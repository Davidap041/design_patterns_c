#ifndef _UTILS_MACROS_H_
#define _UTILS_MACROS_H_

#include <stddef.h>
#define LOCK_INIT 0
#define LOCK_TYPE_T int
#define LOCK_METHOD(addr_pointer) (*(addr_pointer) = 1)
#define UNLOCK_METHOD(addr_pointer) (*(addr_pointer) = 0)

#define DEFINE_SINGLETON_ACQUIRE_RELEASE_PROTOTYPE(type) \
struct type *type##_acquire_singleton(void); \
void type##_release_singleton(struct type **self); \


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
}



#endif