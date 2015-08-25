#include <stdio.h>
#include "person.h"
#include "queue.h"

/* People are standing on a queue. Each person has a name, age and they know who is standing in front of them. 
 * You can get that information by using functions Person_getName(Person* person), Person_getAge(Person* person)
 * and Person_getPrevious(Person* person).
 * You can set the previous person by using Person_setPrevious(Person* person, Person* prevPerson).
 * Implement following functions in queue.c.
 * Function int Queue_enqueue(Person* lastPerson, Person* person) adds person to the end of the queue.
 * LastPerson is the lastPerson of the queue before the operation and person is the last one after the operation.
 * You have to check if the person is already on the queue and not add her again. Function should return 1 if the person was added and 0 if not.
 * Function int Queue_dequeue(Person* lastPerson) removes the first person from the queue, which last person is pointed by lastPerson, and releases the memory allocated for it.
 * LastPerson remains the last person if she wasn't the only person on the queue. The function returns 1 if the last person is still on the queue and 0 if not.
 * If the function returns 0, the queue is empty.
 * Function Person* Queue_drop(Person* lastPerson, Person* person) removes person from the queue and releases memory allocated for it. LastPerson is again the lastPerson on the queue before the operation.
 * Person can be anywhere on the queue and after removal, every person on the queue should still know who is in front of them. Function returns a pointer to the last person on the queue after operation. */

int main()
{
    Person* kalle = Person_new("Kalle", 20);
    Person* ville = Person_new("Ville", 5);
    Person* jussi = Person_new("Jussi", 55);
    int ret = Queue_enqueue(kalle, ville);
    printf("Ville added to queue after Kalle: %d\n", ret);
    ret = Queue_enqueue(ville, jussi);
    printf("Jussi added to queue after Ville: %d\n", ret);
    ret = Queue_enqueue(jussi, kalle);
    printf("Kalle added to queue after Jussi: %d\n", ret);
    Person* last = Queue_drop(jussi, ville);
    ret = Queue_dequeue(last);
    printf("Queue exist after dequeue: %d\n", ret);
    ret = Queue_dequeue(last);
    printf("Queue exist after dequeue: %d\n", ret);
    ret = Queue_dequeue(last);
    printf("Queue exist after dequeue: %d\n", ret);
    return 0;
}
