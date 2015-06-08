#include <stdio.h>
#include "person.h"

int main()
{
    Person* kalle = newPerson("Kalle", 20);
    becomeOlder(kalle);
    printf("My name is %s and I'm %d years old\n", getName(kalle), getAge(kalle));
    
    if (isAdult(kalle)){
        printf("%s is an adult\n", getName(kalle));
    } else {
        printf("%s is a minor\n", getName(kalle));
    }
    personFree(kalle);
    return 0;
}
