#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include <assert.h>
#include <string.h>

/**
 * INTERNAL DATA STRUCTURE:
 */
struct ArrayList {
    void** array;
    int end;
    int max;
};

/**
 * DECLARING PRIVATE METHODS:
 */
void expand(ArrayList*);

/**
 * CONSTRUCTORS:
 */
ArrayList* ArrayList_new() {
    return ArrayList_new_withInitialCapacity(10);
}

/**
 * Allocate a new ArrayList structure and initialize its contents. 
 * The size of the list (= end index) should initially be zero, 
 * and the size of the array (= max index) should be set to initialMax.
 * Also allocate the array for the elements. It should be large enough 
 * to fit 'initialMax' amount of void* pointers.
 * Finally return a pointer to the newly created ArrayList.
 */
ArrayList* ArrayList_new_withInitialCapacity(size_t initialMax) {
    /*BEGIN SOLUTION*/
    ArrayList* self = malloc(sizeof (ArrayList));
    self->array = malloc(initialMax * sizeof (void*));
    self->end = 0;
    self->max = initialMax;
    return self;
    /*END SOLUTION*/
}

/**
 * PUBLIC METHODS:
 * 
 * Notice that all public methods take a *self pointer as their first parameter. 
 * This is analogous to the 'this' or 'self' keyword found in many 
 * object-oriented programming languages.
 */

/**
 * Add an element to the end of the list and increase the size by one.
 */
void ArrayList_add(ArrayList* self, void* element) {
    /*BEGIN SOLUTION*/
    self->array[self->end] = element;
    self->end++;
    if (self->end == self->max) {
        expand(self);
    }
    /*END SOLUTION*/
}

/**
 * Retrieve an element specified by the index i. If the index points outside 
 * of the list, return NULL.
 */
void* ArrayList_get(ArrayList* self, int i) {
    /*BEGIN SOLUTION*/
    if (i < 0 || i >= self->end) {
        return NULL;
    }
    return self->array[i];
    /*END SOLUTION*/
}

/**
 * Remove an element specified by the index i. Move all subsequent elements 
 * to the left (so that their indices are subtracted by one). If the index point outside 
 * of the list, don't do anything.
 */
void ArrayList_remove(ArrayList* self, int i) {

    /*BEGIN SOLUTION*/
        
    if (i < 0 || i >= self->end) {
        return;
    }

    //    while (i + 1 < self->end) {
    //        self->array[i] = self->array[i + 1];
    //        i++;
    //    }

    int numMoved = self->end - i - 1;
    if (numMoved > 0) {
        memmove(self->array + i, self->array + i + 1, numMoved * sizeof (void*));
    }
    
    self->end--;
    /*END SOLUTION*/
}

/**
 * Returns the number of elements stored in this list.
 */
int ArrayList_size(ArrayList* self) {
    return self->end;
}

void ArrayList_destroy(ArrayList* self) {
    free(self->array);
}

/**
 * PRIVATE METHODS:
 */

/**
 * Expand the array to fit more elements. 
 * All existing elements should be preserved.
 */

void expand(ArrayList* self) {
    /*BEGIN SOLUTION*/
    self->max *= 2;
    self->array = realloc(self->array, self->max * sizeof (void *));;
    /*END SOLUTION*/
}
