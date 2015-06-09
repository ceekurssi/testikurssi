#include <stdio.h>
#include "person.h"

int main()
{
    Person* kalle = Person_new("Kalle", 20);
    printf("My name is %s and I'm %d years old.\n", Person_getName(kalle), Person_getAge(kalle));
    Person_free(kalle);
    return 0;
}
