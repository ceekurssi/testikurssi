#include <stdlib.h>
#include "arraylist.h"
#include <assert.h>

void expand(ArrayList*);

struct ArrayList {
    void** array;
    int end;
    int max;
};

ArrayList* ArrayList_new() {
    return ArrayList_new_withInitialCapacity(10);
}

ArrayList* ArrayList_new_withInitialCapacity(size_t initialMax) {
    ArrayList* self = malloc(sizeof(ArrayList));
    self->array = calloc(initialMax, sizeof(void*));
    self->end = 0;
    self->max = 0;
    return self;
}

void ArrayList_add(ArrayList* self, void* element){
    self->array[self->end] = element;
    self->end++;
    if (self->end == self->max) {
        expand(self);
    }
}

void* ArrayList_get(ArrayList* self, int i) {
    return self->array[i];
}

void ArrayList_remove(ArrayList* self, int i) {
    self->array[i] = NULL;
    while (i+1 < self->end) {
        self->array[i] = self->array[i+1];
        i++;
    }
    self->end--;
}
int ArrayList_size(ArrayList* self) {
    return self->end;
}

void expand(ArrayList* self) {
    self->max *= 2;
    self->array = realloc(self->array, self->max * sizeof(void *));
}
