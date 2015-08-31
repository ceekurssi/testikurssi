#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

/** 
 * Objective: Practise the use of an object-oriented design pattern. 
 * Implement ArrayList, a dynamically expanding array-based data structure. 
 * First, familiarize yourself with the header file arraylist.h. 
 * Then implement the missing functionality in arraylist.c.
 */

int main(void) {
    ArrayList* list = ArrayList_new();

    char* elem1 = "cat";
    ArrayList_add(list, &elem1);
    char* elem2 = "rat";
    ArrayList_add(list, &elem2);
    char* elem3 = "dog";
    ArrayList_add(list, &elem3);
    char* elem4 = "sheep";
    ArrayList_add(list, &elem4);
    char* elem5 = "goat";
    ArrayList_add(list, &elem5);
    char* elem6 = "elephant";
    ArrayList_add(list, &elem6);
    char* elem7 = "pig";
    ArrayList_add(list, &elem7);
    char* elem8 = "cow";
    ArrayList_add(list, &elem8);
    char* elem9 = "chicken";
    ArrayList_add(list, &elem9);
    char* elem10 = "duck";
    ArrayList_add(list, &elem10);
    char* elem11 = "theeta";
    ArrayList_add(list, &elem11);
    char* elem12 = "rabbit";
    ArrayList_add(list, &elem12);
    char* elem13 = "mouse";
    ArrayList_add(list, &elem13);
    char* elem14 = "hedgehog";
    ArrayList_add(list, &elem14);

    printf("list before: \n");
    for (int i = 0; i < ArrayList_size(list); i++) {
        if (ArrayList_get(list, i) != NULL) {
            printf("%d: %s \n", i, *(char**)ArrayList_get(list, i));
        }
    }
    
    printf("\nremoving element 5, %s\n", *(char**)ArrayList_get(list, 5));
    ArrayList_remove(list, 5);

    printf("\nlist after: \n");
    
    for (int i = 0; i < ArrayList_size(list); i++) {
        if (ArrayList_get(list, i) != NULL) {
            printf("%d: %s \n", i, *(char**)ArrayList_get(list, i));
        }
    }

        
        ArrayList_destroy(list);
        free(list);

}
