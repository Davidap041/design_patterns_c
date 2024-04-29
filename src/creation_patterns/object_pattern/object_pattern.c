#include "my_object/my_object.h"

struct application {
	struct my_object obj;
};

int application_init(struct applicationn* self) {
	my_object_init(&self->obj);
	return 0;
}