#include <stdlib.h>
/*BEGIN SOLUTION*/
/*END SOLUTION*/
#include "person.h"

struct Person {
    char* name;
    int age;
    Person* prev;
};

Person* Person_new(char* name, int age){
    Person* person = malloc(sizeof(Person));
    if (person == NULL){
        return NULL;
    }
    person->name = name;
    person->age = age;
    person->prev = NULL;
    return person;
}

char* Person_getName(Person* person){
    return person->name;
}

int Person_getAge(Person* person){
    return person->age;
}

void Person_free(Person* person){
    free(person);
    return;
}

Person* Person_getPrevious(Person* person){
    return person->prev;
}

void Person_setPrevious(Person* person, Person* prevPerson){
    person->prev = prevPerson;
}
