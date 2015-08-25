#ifndef QUEUE_H
#define	QUEUE_H

#include "person.h"

int Queue_enqueue(Person* lastPerson, Person* person);
int Queue_dequeue(Person* lastPerson);
Person* Queue_drop(Person* lastPerson, Person* person);

#endif	/* QUEUE_H */

