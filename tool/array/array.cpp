#include "array.h"

#include <cstdlib>

#define INT sizeof(short int)

short int* create_int_arr(short int size){
    auto* arr = (short int*)malloc(size*INT);
    return arr;
}

void free_int_arr (short int* arr){
    free(arr);
}
