#include "opaque.h"

// std includes
#include <stdlib.h>
#include <string.h>


// actual define of the struct in private space of the c file
struct opaque
{
	uint32_t data;
};

#define OPAQUE_INIT(index) \
static struct opaque opaque_##index = { }; \

int opaque_init(struct opaque* self) {
	memset(self, 0, sizeof(*self));

	return 0;
}
int opaque_deinit(struct opaque* self) {
	// free any internal resources and return to known state
	self->data = 0;
	return 0;
}
struct opaque* opaque_new() {
	// dynamically allocate an instance
	return malloc(sizeof(struct opaque));
}
void opaque_free(struct opaque** self) {
	// free dyamicall allocated instance
	free(*self);
	// set the passed pointer to NULL!
	*self = NULL;
}
void opaque_set_data(struct opaque* self, uint32_t data) {
	self->data = data;
}
uint32_t opaque_get_data(struct opaque* self) {
	return self->data;
}
size_t opaque_size(void) {
	return sizeof(struct opaque);
}