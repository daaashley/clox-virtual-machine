#include <stdio.h>

#include "memory.h"
#include "value.h"

void initValueArray(ValueArray* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

void writeValueArray(ValueArray* array, Value value) {
    if (array->capacity < array->count + 1) { // Check if we need to grow the array
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values,oldCapacity,array->capacity);
    }

    array->values[array->count] = value; // Place new value at current count, then inc
    array->count++;
}

void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value,array->values,array->count);
    initValueArray(array);
}