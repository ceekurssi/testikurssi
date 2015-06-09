#include <stdlib.h>
/*BEGIN SOLUTION*/
/*END SOLUTION*/
#include "person.h"

struct Person {
    char* name;
    int age;
};

Person* Person_new(char* name, int age){
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

void Person_becomeOlder(Person* person){
    person->age += 1;
}

int Person_isAdult(Person* person){
    if (person->age < 18){
        return 0;
    } else {
        return 1;
    }
}
