#include <stdio.h>
#include "source.h"

void calculate_average(){
    
    /*BEGIN SOLUTION*/
    int count = 0;
    int grade;
    int sum = 0;
    float average = 0.0;
    
    scanf("%d", &grade);
    
    while (grade != -1){
        sum += grade;
        count++;
        scanf("%d", &grade);
    }
    
    if (count != 0){
        average = (float) sum / count;
    }
    
    printf("%.2f\n", average);
    
    /*END SOLUTION*/
}
