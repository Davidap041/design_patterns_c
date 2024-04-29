#include <stdint.h>

struct opaque; // just a declaration

// init and deinit
int opaque_init(struct opaque* self);
int opaque_deinit(struct opaque* self);

// for heap allocation
struct opaque* opaque_new();
void opaque_free(struct opaque **self);

// methods that operate on an opaque
void opaque_set_data(struct opaque* self, uint32_t data);
uint32_t opaque_get_data(struct opaque* self);
size_t opaque_size(void);

