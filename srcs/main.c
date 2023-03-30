#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

// Define a function pointer to the original malloc function
void *(*original_malloc)(size_t);

// Define a replacement malloc function that logs the call to malloc
void *my_malloc(size_t size) {
    printf("Call to malloc(%zu)\n", size);
    // Call the original malloc function
    void *ptr = original_malloc(size);
    return ptr;
}

int main() {
    // Load the original malloc function using dlsym
    original_malloc = dlsym(RTLD_NEXT, "malloc");

    // Call some functions that use malloc
    char *str = my_malloc(10);
    int *arr = malloc(5 * sizeof(int));
	
    // Free the memory to avoid memory leaks
    free(str);
    free(arr);

    return 0;
}
