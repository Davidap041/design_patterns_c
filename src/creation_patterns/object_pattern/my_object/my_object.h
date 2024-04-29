#ifndef _MY_OBJECT_H_
#define _MY_OBJECT_H_
#include <stdint.h>
#include <string.h>


struct my_object {
	uint32_t variable;
	uint32_t flags;
};

int my_object_init(struct my_object* self);
int my_object_deinit(struct my_object* self);

#endif //_MY_OBJECT_H_