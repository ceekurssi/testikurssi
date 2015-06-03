#include <stdlib.h>
#include <time.h>
#include "person.h"

struct Person {
    char* name;
    MyDate* birthday;
};

Person* newPerson(char* name, int day, int month, int year){
    Person* person;
    
    person = malloc(sizeof(Person));
    if (person == NULL){
        return NULL;
    }
    person->name = name;
    person->birthday = newMyDate(day, month, year);
    return person;
}

char* getName(Person* person){
    return person->name;
}

int age(Person* person){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    MyDate* today = newMyDate(tm.tm_mday, tm.tm_mon +1, tm.tm_year + 1900);
    return differenceInYears(person->birthday, today);
}

int olderThan(Person* first, Person* second){
    return earlier(first->birthday, second->birthday);
}

void personFree(Person* person){
    free(person);
    return;
}

int isAdult(Person* person){
    if (age(person) < 18){
        return 0;
    } else {
        return 1;
    }
}

