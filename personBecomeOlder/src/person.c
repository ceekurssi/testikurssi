#include <stdlib.h>
/*BEGIN SOLUTION*/
/*END SOLUTION*/
#include "person.h"

struct Person {
    char* name;
    int age;
};

Person* newPerson(char* name, int age){
    Person* person;
    
    if (age < 0){
        return NULL;
    }
    
    person = malloc(sizeof(Person));
    if (person == NULL){
        return NULL;
    }
    person->name = name;
    person->age = age;
    return person;
}
char* getName(Person* person){
    return person->name;
}
int getAge(Person* person){
    return person->age;
}
void personFree(Person* person){
    free(person);
    return;
}

void becomeOlder(Person* person){
    person->age += 1;
}

int isAdult(Person* person){
    if (person->age < 18){
        return 0;
    } else {
        return 1;
    }
}
