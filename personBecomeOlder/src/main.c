#include <stdio.h>
#include "person.h"

int main()
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
