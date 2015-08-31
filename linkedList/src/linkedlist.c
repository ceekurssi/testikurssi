#include <stdlib.h>
#include "linkedlist.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

/**
 * Allocate a new LinkedList structure and initialize its contents. 
 * The size of the list should initially be zero and the head and tail 
 * pointers should be set to NULL.
 * Finally return a pointer to the newly created LinkedList.
 */
LinkedList* LinkedList_new() {
    /*BEGIN SOLUTION*/
    LinkedList* self = malloc(sizeof(LinkedList));
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
    return self;
    /*END SOLUTION*/
}

/**
 * Add an element to the end of the list and increase the size by one. Allocate 
 * a new Node and set its "previous" attribute to the list's current tail. 
 * Then update the List's 'tail' attribute to point to the new tail node.
 */
void LinkedList_add(LinkedList* self, void* element) {
    /*BEGIN SOLUTION*/
    Node* node = malloc(sizeof (Node));
    node->elem = element;
    node->next = NULL;
    node->previous = self->tail;
    if (self->size > 0) {
        self->tail->next = node;
        self->tail = node;
    } else {
        self->head = node;
        self->tail = node;
    }
    self->size++;
    /*END SOLUTION*/
}

/**
 * Helper method: Return the Node object pointed by the index. 
 * If the index points outside of the list, return NULL.
 */
Node* LinkedList_getNode(LinkedList* self, int index) {
    /*BEGIN SOLUTION*/
    Node* node = self->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
    /*END SOLUTION*/
}

/**
 * Helper method: Return the head node of the list.
 */
Node* LinkedList_getHead(LinkedList* self) {
    /*BEGIN SOLUTION*/
    return self->head;
    /*END SOLUTION*/
}

/**
 * Helper method: Return the tail node of the list.
 */
Node* LinkedList_getTail(LinkedList* self) {
    /*BEGIN SOLUTION*/
    return self->tail;
    /*END SOLUTION*/
}

/**
 * Return the number of elements stored in the list.
 */
int LinkedList_size(LinkedList* self) {
    /*BEGIN SOLUTION*/
    return self->size;
    /*END SOLUTION*/
}

/**
 * Get the stored element by index. If the index points outside of 
 * the list, return NULL. You can use the getNode method to get the node.
 */
void* LinkedList_get(LinkedList* self, int index) {
    /*BEGIN SOLUTION*/
    if (index < 0 || index >= self->size) {
        return NULL;
    }
    Node* node = LinkedList_getNode(self, index);
    return node->elem;
    /*END SOLUTION*/
}

/**
 * Remove the element (and the Node) pointed to by the index and 
 * decrease the size by one. 
 */
void LinkedList_remove(LinkedList* self, int index) {
    /*BEGIN SOLUTION*/
    if (self->size == 0) {
        return;
    }
    self->size--;
    
    Node* node = LinkedList_getNode(self, index);
    if (node->previous != NULL) {
        node->previous->next = node->next;
    }
    if (node->next != NULL) {
        node->next->previous = node->previous;
    } else {
        self->tail = node->previous;
    }
    free(node);
    /*END SOLUTION*/
}

/**
 * Destructor. Free all nodes allocated by this data structure (but not the 
 * actual stored pointers).
 */
void LinkedList_destroy(LinkedList* self) {
    /*BEGIN SOLUTION*/
    Node* node = self->head;
    Node* tmp;
    while (node != NULL) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
    /*END SOLUTION*/
}
