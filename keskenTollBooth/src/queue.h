//SOLUTION FILE

#ifndef QUEUE_H
#define	QUEUE_H

typedef struct Queue Queue;

Queue* Queue_new();
void Queue_add(Queue* queue, int value);
int Queue_remove(Queue* queue);
int Queue_getSize(Queue* queue);

#endif	/* QUEUE_H */

