#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} dyn_array_t;

/* Initialize array with given initial capacity.
 * Returns 0 on success, -1 on allocation failure.
 */
int dyn_array_init(dyn_array_t* arr, size_t initial_capacity);

/* Free all resources. Safe to call multiple times. */
void dyn_array_free(dyn_array_t* arr);

/* Append value to the end.
 * Returns 0 on success, -1 on allocation failure.
 */
int dyn_array_push_back(dyn_array_t* arr, int value);

/* Remove last element.
 * Returns 0 on success, -1 if array is empty.
 */
int dyn_array_pop_back(dyn_array_t* arr);

/* Get element at index.
 * Returns 0 on success, -1 if index is out of bounds.
 */
int dyn_array_get(const dyn_array_t* arr, size_t index, int* out_value);

/* Resize logical size.
 * If new_size > capacity, grow capacity.
 * New elements must be initialized to 0.
 * Returns 0 on success, -1 on allocation failure.
 */
int dyn_array_resize(dyn_array_t* arr, size_t new_size);

#endif
