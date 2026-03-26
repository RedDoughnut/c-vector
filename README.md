# c-vector
A vector implementation in C, inspired by C++'s `std::vector` (this one is integer only)

Includes an example in main function

Functions:
- `v_construct()` - Constructs an empty vector
- `v_push_back(vector* self, int val)` - Adds an element to the end of the vector
- `v_pop_back(vector* self)` - Removes the last element from the vector
- `v_at(vector* self, size_t pos)` - Returns an int pointer to the element on index `pos`
- `v_print(vector* self)` - Prints out the vector elements to stdout
- `v_destroy(vector* self)` - Free the memory the vector allocated
- `v_clear(vector* self)` - Clears the vector elements
- `v_reserve(vector* self, size_t n)` - Preallocates memory for at least n elements without changing the size
- `v_sort(vector* self, int (*comp)(const int*, const int*))` - Sorts the vector elements using merge sort with given comparison function
  
Compile and execute with: (Linux)
```
gcc vector.c -o vector && ./vector
```
