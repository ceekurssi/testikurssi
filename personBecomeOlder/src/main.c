#include <stdio.h>
#include "person.h"

//tää tulis varmaan person-tehtävän tilalle

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 4. 
 * Header person.h specifies the public interface of a person. 
 * Define a structure called person in person.c. person contains two members, pointer to string name and integer age. 
 * Implement all functions in frankCard.c. 
 * Person_new allocate memory for a new person and set its name to point to a given name and set age to given age.
 * Person_getName should return the name of the person and Person_getAge should return the age of the person.
 * Function Person_becomeOlder should increase the age of a person by one year.
 * Function Person_isAdult should return 1 if person is an adult and 0 if not.
 * Function Person_free should free all allocated memory. */

int main(void)
{
    Person* kalle = Person_new("Kalle", 20);
    Person_becomeOlder(kalle);
    printf("My name is %s and I'm %d years old\n", Person_getName(kalle), Person_getAge(kalle));
    
    if (Person_isAdult(kalle)){
        printf("%s is an adult\n", Person_getName(kalle));
    } else {
        printf("%s is a minor\n", Person_getName(kalle));
    }
    Person_free(kalle);
    return 0;
}
