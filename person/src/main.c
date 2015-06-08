#include <stdio.h>
#include "person.h"

int main()
{
    Person* kalle = newPerson("Kalle", 20);
    printf("My name is %s and I'm %d years old.\n", getName(kalle), getAge(kalle));
    personFree(kalle);
    return 0;
}
