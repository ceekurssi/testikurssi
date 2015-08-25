//SOLUTION FILE

#include <stdlib.h>
#include "queue.h"
#include "node.h"

struct Queue {
    Node* head;
    Node* tail;
    int size;
};

Queue* Queue_new() {
    Queue* queue;

    queue = malloc(sizeof (Queue));

    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void Queue_add(Queue* queue, int value) {
    
    Node* node = malloc(sizeof (Node));
    if (queue->size == 0) {
        queue->head = node;
        queue->tail = node;
    }

    queue->tail->next = node;
    queue->tail->next->value = value;
    queue->tail = queue->tail->next;
    queue->size++;
}

int Queue_remove(Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }
    Node* node = queue->head;
    int value = node->value;
    queue->head = queue->head->next;
    free(node);
    queue->size--;
    return value;
}

int Queue_getSize(Queue* queue) {
    return queue->size;
}
