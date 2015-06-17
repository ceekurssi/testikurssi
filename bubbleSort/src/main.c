#include <stdio.h>
#include <stdlib.h>
#include "source.h"

//kesken, testit puuttuu. Mikä tässä on se tehtävä, ei ainakaan bubble sort. Tätä pitää muokata/poistaa kokonaan

int main(void){
    int numbers[] = {27, 11, 3, -56, 92, 41, 9};
    int count = sizeof(numbers)/ sizeof(numbers[0]);
    
    printf("Without sorting: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", numbers[i], i == count - 1 ? "\n" : " ");
    }
    
    int* sorted = bubble_sort(numbers, count, sorted_compare);
    printf("Sorted: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", sorted[i], i == count - 1 ? "\n" : " ");
    }
    
    sorted = bubble_sort(numbers, count, reverse_compare);
    printf("Reverse sorted: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", sorted[i], i == count - 1 ? "\n" : " ");
    }
    
    return 0;
}
