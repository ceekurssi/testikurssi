#include <stdlib.h>
#include "queue.h"

int Queue_enqueue(Person* lastPerson, Person* person) {
    /*BEGIN SOLUTION*/
    Person* p = lastPerson;
    while (p) {
        if (p == person) {
            return 0;
        }
        if (Person_getPrevious(p) != NULL) {
            p = Person_getPrevious(p);
        } else {
            break;
        }
    }
    Person_setPrevious(person, lastPerson);
    return 1;
    /*END SOLUTION*/
}

int Queue_dequeue(Person* lastPerson) {
    /*BEGIN SOLUTION*/

    if (Person_getPrevious(lastPerson) == NULL) {
        Person_free(lastPerson);
        return 0;
    }

    Person* p = lastPerson;
    Person* next;

    while (p) {
        if (Person_getPrevious(p) != NULL) {
            next = p;
            p = Person_getPrevious(p);
        } else {
            Person_setPrevious(next, NULL);
            Person_free(p);
            return 1;

        }
    }
    /*END SOLUTION*/
}

Person* Queue_drop(Person* lastPerson, Person* person) {
    /*BEGIN SOLUTION*/
    
    Person* p = lastPerson;
    if (lastPerson == person){
        p = Person_getPrevious(person);
        Person_free(person);
        return p;
    }
    
    Person* next = p;
    p = Person_getPrevious(p);
    
    while (p){
        if (p == person){
            Person_setPrevious(next, Person_getPrevious(p));
            Person_free(p);
            break;
        }
        if (Person_getPrevious(p) != NULL){
            next = p;
            p = Person_getPrevious(p);
        } 
    }

    return lastPerson;
    /*END SOLUTION*/
}
