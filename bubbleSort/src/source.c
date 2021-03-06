#include "source.h"

int* bubble_sort(int* numbers, int count, compare comp){
    /*BEGIN SOLUTION*/
    int changed = 1;
    while(changed){
        changed = 0;
        for (int i = 0; i < count-1; i++){
            if (comp(numbers[i], numbers[i+1]) > 0){
                int temp = numbers[i+1];
                numbers[i+1] = numbers[i];
                numbers[i] = temp;
                changed = 1;
            }
        }
    }
    return numbers;
    /*END SOLUTION*/
}

int sorted_compare(int first, int second){
    return first - second;
}

int reverse_compare(int first, int second){
    return second - first;
}
