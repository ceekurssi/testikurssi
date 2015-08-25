#include <stdlib.h>
#include "linkedlist.h"
#include <assert.h>
#include <string.h>

Node* find_node(LinkedList*, int);

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

LinkedList* LinkedList_new() {
    LinkedList* self = malloc(sizeof (LinkedList));
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
    return self;
}

void LinkedList_add(LinkedList* self, void* element) {
    Node* node = malloc(sizeof (Node));
    node->elem = element;
    if (self->size > 0) {
        self->tail->next = node;
        self->tail = node;
    } else {
        self->head = node;
        self->tail = node;
    }
    self->size++;
}

void* LinkedList_get(LinkedList* self, int index) {
    Node* node = getNode(self, index);
    return node->elem;
}

void LinkedList_remove(LinkedList* self, int index) {
    if (self->size == 0) {
        return;
    }
    self->size--;
    
    Node* node = getNode(self, index);
    if (node->previous != NULL) {
        node->previous->next = node->next;
    }
    if (node->next != NULL) {
        node->next->previous = node->previous;
    } else {
        self->tail = node->previous;
    }
    free(node);
}

int LinkedList_size(LinkedList* self) {
    return self->size;
}

Node* getNode(LinkedList* self, int index) {
    Node* node = self->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

Node* getHead(LinkedList* self) {
    return self->head;
}

Node* getTail(LinkedList* self) {
    return self->tail;
}
