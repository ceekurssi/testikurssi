#include <stdlib.h>
#include <time.h>
#include "person.h"

struct Person {
    char* name;
    MyDate* birthday;
};

Person* Person_new(char* name, int day, int month, int year){
    Person* person;
    
    person = malloc(sizeof(Person));
    if (person == NULL){
        return NULL;
    }
    person->name = name;
    person->birthday = MyDate_new(day, month, year);
    return person;
}

char* Person_getName(Person* person){
    return person->name;
}

int Person_age(Person* person){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    MyDate* today = MyDate_new(tm.tm_mday, tm.tm_mon +1, tm.tm_year + 1900);
    int difference = MyDate_differenceInYears(person->birthday, today);
    MyDate_free(today);
    return difference;
}

int Person_olderThan(Person* first, Person* second){
    return MyDate_earlier(first->birthday, second->birthday);
}

void Person_free(Person* person){
    MyDate_free(person->birthday);
    free(person);
    return;
}

int Person_isAdult(Person* person){
    if (Person_age(person) < 18){
        return 0;
    } else {
        return 1;
    }
}

