
#ifndef QUEUE_H
#define	QUEUE_H

typedef struct Queue Queue;

Queue* Queue_new();
void Queue_add(Queue*, int value);
int Queue_remove(Queue*);
int Queue_getSize(Queue*);
void Queue_destroy(Queue*);

#endif	/* QUEUE_H */

