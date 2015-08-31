#include <stdlib.h>
#include "queue.h"
#include "node.h"

/**
 * Implement a Queue that stores integer values.
 */

/**
 * Place your internal "private" variables inside this struct.
 */
struct Queue {
    /*BEGIN SOLUTION*/
    Node* head;
    Node* tail;
    int size;
    /*END SOLUTION*/
};

/**
 * Constructor. Allocate memory for a new queue object and initialize 
 * all variables. Return a pointer to the newly created queue.
 */
Queue* Queue_new() {
    /*BEGIN SOLUTION*/
    Queue* self;

    self = malloc(sizeof (Queue));

    if (self == NULL) {
        return NULL;
    }

    self->head = NULL;
    self->tail = NULL;
    self->size = 0;

    return self;
    /*END SOLUTION*/
    /*STUB: return NULL;*/
}

/**
 * Add a new integer value to the end of the queue.
 */
void Queue_add(Queue* self, int value) {
    /*BEGIN SOLUTION*/
    Node* node = malloc(sizeof (Node));
    node->value = value;
    node->next = NULL;
    if (self->size == 0) {
        self->head = node;
        self->tail = node;
    } else {
        self->tail->next = node;
        self->tail = self->tail->next;
    }
    self->size++;
    /*END SOLUTION*/
}

/**
 * Retrieve and return the next integer from the head of the queue.
 */
int Queue_remove(Queue* self) {
    /*BEGIN SOLUTION*/
    if (self->size == 0) {
        return -1;
    }
    Node* node = self->head;
    int value = node->value;
    self->head = self->head->next;
    free(node);
    self->size--;
    return value;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Return the number of integers stored in this queue.
 */
int Queue_getSize(Queue* self) {
    /*BEGIN SOLUTION*/
    return self->size;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Free all memory used by the queue. Finally free the 'self' pointer.
 */
void Queue_destroy(Queue* self) {
    /*BEGIN SOLUTION*/
    Node* node = self->head;
    Node* tmp = NULL;

    while (node != NULL) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
    free(self);
    /*END SOLUTION*/
}
