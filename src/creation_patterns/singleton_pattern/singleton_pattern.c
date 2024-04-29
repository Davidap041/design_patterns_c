#include "singleton_pattern.h"
#include <stdio.h>
void application_print_data_singleton(void) {
	// METHOD 1
	printf("singleton data (not safe mode)= %d\n\n", object_get_data()); // ! not safe mode
	
	// METHOD 2
	struct object* self = object_acquire_singleton();
	if (self) {	
		printf("singleton data (mutex mode) first time = %d\n", object_pointer_get_data(self)); 
		object_release_singleton(&self);
	}
	else {
		printf("Fail in acquire object singleton\n");
	}

	self = object_acquire_singleton();
	if (self) {
		printf("singleton value (mutex mode) second time = %d\n\n", object_pointer_get_value(self));
		object_release_singleton(&self);
	}
	else {
		printf("Fail in acquire object singleton\n");
	}

	// METHOD 3
	int state = 0;
	if (object_with_lock_get_state(&state)) printf("Error in get state\n");
	printf("singleton state (lock_inside) first time = %d\n", state); 

	if (object_with_lock_get_state(&state)) printf("Error in get state\n");
	printf("singleton state (lock_inside)  second time = %d\n\n", state);

}