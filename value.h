typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values; // Struct wraps pointer to array, and values that help manage that array
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

#endif