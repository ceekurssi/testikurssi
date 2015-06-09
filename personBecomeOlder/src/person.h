
#ifndef PERSON_H
#define	PERSON_H

typedef struct Person Person;

Person* Person_new(char* name, int age);
char* Person_getName(Person* person);
int Person_getAge(Person* person);
void Person_free(Person* person);
void Person_becomeOlder(Person* person);
int Person_isAdult(Person* person);

#endif	/* PERSON_H */

