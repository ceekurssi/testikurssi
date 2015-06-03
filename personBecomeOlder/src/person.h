
#ifndef PERSON_H
#define	PERSON_H

typedef struct Person Person;

Person* newPerson(char* name, int age);
char* getName(Person* person);
int getAge(Person* person);
void personFree(Person* person);
void becomeOlder(Person* person);
int isAdult(Person* person);

#endif	/* PERSON_H */

