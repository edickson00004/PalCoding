#include <malloc.h>
#include "stack.h"

struct stack {
    // Points to dynamically allocated array of size 'capacity', or is NULL.
    char *data;
    // The capacity of the array.
    size_t capacity;
    // The number of entries currently in the stack.
    size_t length;
};

stack_ptr stack_new() {
    stack_ptr s = malloc(sizeof(struct stack));
    s->data = NULL;
    s->capacity = 0;
    s->length = 0;
    return s;
}

void stack_free(stack_ptr s) {
    if (s->data != NULL)
        free(s->data);
    free(s);
}

void stack_push(stack_ptr s, char c) {
    // TODO (task 2): how do we push an entry onto the stack?
    if(s->length == s->capacity){
        size_t newCapacity = (s->capacity == 0) ? 1 : s->capacity * 2;
        char *newData = realloc(s->data, newCapacity * sizeof(char));
        s->data = newData;
        s->capacity = newCapacity;
    }
    s->data[s->length] = c;
    s->length++;
}

bool stack_pop(stack_ptr s, char *out) {
    // TODO (task 2): how do we pop an entry from the stack?
    if(s->length == 0) {
        return false;
    }
    *out = s->data[s->length-1];
    s->length--;
    return true;
}

