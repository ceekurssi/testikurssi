#include "node.h"

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

typedef struct LinkedList LinkedList;

LinkedList* LinkedList_new();
void LinkedList_add(LinkedList* self, void* element);
void* LinkedList_get(LinkedList* self, int imdex);
void LinkedList_remove(LinkedList* self, int index);
int LinkedList_size(LinkedList* self);
Node* LinkedList_getHead(LinkedList* self);
Node* LinkedList_getTail(LinkedList* self);
Node* LinkedList_getNode(LinkedList* self, int index);
void LinkedList_freeAll(LinkedList*);
void LinkedList_destroy(LinkedList*);

#endif	/* LINKEDLIST_H */
