#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
    int* arr;
    size_t size;
    size_t capacity;
} vector;
/*
Constructs an empty vector
*/
vector v_construct(){
    vector self;
    (self).size = 0;
    (self).capacity = 0;
    (self).arr = NULL;
    return self;
}
/*
Adds an element to the end of the vector
*/
void v_push_back(vector* self, int val){
    if((*self).size == (*self).capacity){
        (*self).capacity *= 2;
        if((*self).capacity==0)
            (*self).capacity = 1;
        int* newarr = malloc((*self).capacity * sizeof(int));
        if(!newarr) {
            fprintf(stderr, "vector: allocation failed\n");
            exit(1);
        }
        if((*self).arr != NULL){
            for(size_t i=0;i<(*self).size;i++){
                newarr[i] = (*self).arr[i];
            }
        }
        newarr[(*self).size] = val;
        free((*self).arr);
        (*self).arr = newarr;
    }
    else{
        (*self).arr[(*self).size] = val;
    }
    (*self).size ++;
}
/*
Removes the last element from the vector
*/
void v_pop_back(vector* self){
    
    if((*self).size > 0){
        (*self).size --;
    }
    else{
        fprintf(stderr, "vector: pop_back: can't pop_back, vector has 0 elements\n");
        exit(1);
    }
}
/*
Returns an int pointer to the element on index `pos`
*/
int* v_at(vector* self, size_t pos){
    if(pos >= (*self).size) {
        fprintf(stderr, "vector: at: index out of bounds\n");
        exit(1);
    }
    return (*self).arr + pos;
}
/*
Prints out the vector elements with printf
*/
void v_print(vector* self){
    for(size_t i=0;i<(*self).size;i++){
        printf("%d ", (*self).arr[i]);
    }
    printf("\n");
}
/*
Free the memory the vector allocated
*/
void v_destroy(vector* self){
    free((*self).arr);
}
/*
Clears the vector elements
*/
void v_clear(vector* self){
    (*self).size = 0;
}
/*
Preallocates memory for at least n elements without changing the size
*/
void v_reserve(vector* self, size_t n){
    if(n <= (*self).capacity) return;
    (*self).capacity = 1;
    while((*self).capacity < n) (*self).capacity <<= 1;
    int* newarr = malloc((*self).capacity * sizeof(int));
    if(!newarr) {
        fprintf(stderr, "vector: allocation failed\n");
        exit(1);
    }
    if((*self).arr != NULL){
        for(size_t i=0;i<(*self).size;i++){
            newarr[i] = (*self).arr[i];
        }
    }
    free((*self).arr);
    (*self).arr = newarr;
}
int main(){
    vector v = v_construct();

    v_reserve(&v, 4);
    
    v_push_back(&v, 1);
    v_push_back(&v, 2);
    v_push_back(&v, 3);
    v_push_back(&v, 4);
    *v_at(&v, 0) = 20;
    v_pop_back(&v);
    v_print(&v); // Should print: 20 2 3
    
    v_clear(&v);
    v_push_back(&v, 10);
    v_push_back(&v, 20);
    v_print(&v); // Should print: 10 20

    v_destroy(&v);
}
