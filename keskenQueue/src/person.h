#ifndef PERSON_H
#define	PERSON_H

typedef struct Person Person;

Person* Person_new(char* name, int age);
char* Person_getName(Person* person);
int Person_getAge(Person* person);
void Person_free(Person* person);
Person* Person_getPrevious(Person* person);
void Person_setPrevious(Person* person, Person* prevPerson);

#endif	/* PERSON_H */

