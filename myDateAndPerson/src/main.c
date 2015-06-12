#include <stdio.h>
#include "myDate.h"
#include "person.h"

//myDate vois miettiä uudestaan ja muokata sitten tätäkin

int main() {
    Person* ville = Person_new("Ville", 2, 6, 1999);
    Person* kalle = Person_new("Kalle", 8, 5, 2005);
    
    printf("%s is %d years old\n", Person_getName(ville), Person_age(ville));
    printf("%s is %d years old\n", Person_getName(kalle), Person_age(kalle));
    
    if (Person_olderThan(ville, kalle) == 1){
        printf("%s is older than %s\n", Person_getName(ville), Person_getName(kalle));
    } else if (Person_olderThan(ville, kalle) == -1){
        printf("%s is older than %s\n", Person_getName(kalle), Person_getName(ville));
    }
    
    Person_free(ville);
    Person_free(kalle);

    return 0;
}
