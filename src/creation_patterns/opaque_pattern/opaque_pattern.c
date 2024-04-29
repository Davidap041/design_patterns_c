#include "opaque_pattern.h"
#include "opaque/opaque.h"
#include <stdlib.h>
#include <assert.h>
#ifdef STACK_ALLOCATION_EXAMPLE
#include <alloca.h>
#endif

#if 0

void some_caller(..) {
	struct opaque obj;// this is will not work !!
}

#endif // 0

void opaque_pattern_use(void) {
	// #define STACK_ALLOCATION_EXAMPLE
#ifdef STACK_ALLOCATION_EXAMPLE
	/* STACK ALLOCATION
	This scheme uses standard dynamic allocation on the stack using
	alloca method. alloca is like malloc, except that the allocation happens on the stack
	and is automatically released when the function returns. This method doesn’t suffer from
	memory fragmentation like malloc below.
	*/

	// create an opaque type on the stack
	struct opaque* obj = alloca(opaque_size());
	// standard init
	opaque_init(obj);
	// operate on the opaque
	opaque_set_data(obj, 123);
	// done with the object: deinit it
	opaque_deinit(obj);

#endif // STACK_ALLOCATION_EXAMPLE

	// #define DYNAMIC_ALLOCATION_EXAMPLE
#ifdef DYNAMIC_ALLOCATION_EXAMPLE
	/*  DYNAMIC ALLOCATION
	here we have to use malloc or an RTOS alternative. If you use this
	method on resource constrained devices then make sure that you either only allocate
	during initialization or that you do not use this method at all due to the risk of
	fragmenting the memory and reaching the point where no new instances can be
	allocated because of that.
	*/

	// allocate new opaque on the heap
	struct opaque* obj = opaque_new();
	assert(obj != NULL);
	// operate on the opaque
	opaque_set_data(obj, 456);
	// deinit the object
	opaque_deinit(obj);
	// discard memory
	opaque_free(&obj);

#endif // DYNAMIC_ALLOCATION_EXAMPLE

// #define STATIC_ALLOCATION_EXAMPLE
#ifdef STATIC_ALLOCATION_EXAMPLE

	OPAQUE_INIT(1);

#endif // STATIC_ALLOCATION_EXAMPLE
}