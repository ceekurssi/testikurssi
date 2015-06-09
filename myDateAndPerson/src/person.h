#ifndef PERSON_H
#define	PERSON_H
#include "myDate.h"

typedef struct Person Person;

Person* Person_new(char* name, int day, int month, int year);
char* Person_getName(Person* person);
int Person_age(Person* person);
int Person_olderThan(Person* first, Person* second);
void Person_free(Person* person);
int Person_isAdult(Person* person);


#endif	/* PERSON_H */

