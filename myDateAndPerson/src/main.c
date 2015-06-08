#include <stdio.h>
#include "myDate.h"
#include "person.h"

//tehtävä kesken (valgrind)

int main() {
    Person* ville = newPerson("Ville", 2, 6, 1999);
    Person* kalle = newPerson("Kalle", 8, 5, 2005);
    
    printf("%s is %d years old\n", getName(ville), age(ville));
    printf("%s is %d years old\n", getName(kalle), age(kalle));
    
    if (olderThan(ville, kalle) == 1){
        printf("%s is older than %s\n", getName(ville), getName(kalle));
    } else if (olderThan(ville, kalle) == -1){
        printf("%s is older than %s\n", getName(kalle), getName(ville));
    }

    return 0;
}
