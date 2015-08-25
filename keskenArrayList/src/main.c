#include <stdio.h>

#include "arraylist.h"

/* Kesken
 * Huom! Testit eivät toimi, joten jotain on väärin. Tähän sitten joku kiva arrayList-tehtävä*/

int main(void) {
    ArrayList* list = ArrayList_new();
    int num_elements = 15;
    int elems[] = {3, 5, 7, 9, 4, 2, 6, 4, 9, 2, 3, 5, 9, 2, 4};
    
    for (int i = 0; i<num_elements; i++) {
        ArrayList_add(list, elems+i);
    }
    
//    int elem1 = 3;
//    int elem2 = 5;
//    int elem3 = 7;
//    ArrayList_add(list, &elem1);
//    ArrayList_add(list, &elem2);
//    ArrayList_add(list, &elem3);
    
    for(int i = 0; i<num_elements; i++) {
        printf("%d: %d \n", i, *(int*)ArrayList_get(list, i));
    }
    
    
}
