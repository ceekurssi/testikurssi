#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/**
 * Another Object-oriented exercise.
 * 
 * Objective: Implement LinkedList, a data structure where elements are chained 
 * to each other. First, familiarize yourself with the Node struct found in 
 * node.h and the header file linkedlist.h. Notice the similarities with the 
 * header file of ArrayList (in previous exercise). 
 * Implement the missing functionality in linkedlist.c.
 */

int main(void) {
    
    LinkedList* list = LinkedList_new();
    
    char* elem1 = "cat";
    LinkedList_add(list, &elem1);
    char* elem2 = "rat";
    LinkedList_add(list, &elem2);
    char* elem3 = "dog";
    LinkedList_add(list, &elem3);
    char* elem4 = "sheep";
    LinkedList_add(list, &elem4);
    char* elem5 = "goat";
    LinkedList_add(list, &elem5);
    char* elem6 = "kebab";
    LinkedList_add(list, &elem6);
    char* elem7 = "pig";
    LinkedList_add(list, &elem7);
    char* elem8 = "cow";
    LinkedList_add(list, &elem8);
    char* elem9 = "chicken";
    LinkedList_add(list, &elem9);
    char* elem10 = "duck";
    LinkedList_add(list, &elem10);
    char* elem11 = "fox";
    LinkedList_add(list, &elem11);
    char* elem12 = "rabbit";
    LinkedList_add(list, &elem12);
    char* elem13 = "mouse";
    LinkedList_add(list, &elem13);
    char* elem14 = "hedgehog";
    LinkedList_add(list, &elem14);
    
    printf("list before: \n");
    for (int i = 0; i < LinkedList_size(list); i++) {
        if (LinkedList_get(list, i) != NULL) {
            printf("%d: %s \n", i, *(char**)LinkedList_get(list, i));
        }
    }
    
    printf("\nremoving element 5, %s\n", *(char**)LinkedList_get(list, 5));
    LinkedList_remove(list, 5);

    printf("\nlist after: \n");
    
    for (int i = 0; i < LinkedList_size(list); i++) {
        if (LinkedList_get(list, i) != NULL) {
            printf("%d: %s \n", i, *(char**)LinkedList_get(list, i));
        }
    }
    
    LinkedList_destroy(list);
    free(list);
    
}
