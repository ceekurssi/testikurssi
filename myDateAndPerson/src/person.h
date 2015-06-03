#ifndef PERSON_H
#define	PERSON_H
#include "myDate.h"

typedef struct Person Person;

Person* newPerson(char* name, int day, int month, int year);
char* getName(Person* person);
int age(Person* person);
int olderThan(Person* first, Person* second);
void personFree(Person* person);
int isAdult(Person* person);


#endif	/* PERSON_H */

