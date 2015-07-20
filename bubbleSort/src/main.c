#include <stdio.h>
#include "source.h"

//KESKEN, Tehtävänato keksittävä, function pointers?, testiä muokattava keksityn tehtävänannon mukaan

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
