#include <stdio.h>
#include "boundedCounter.h"

int main() {
    struct boundedCounter hours = {5, 23};
    struct boundedCounter minutes = {58, 59};
    struct boundedCounter seconds = {50, 59};
    printf("Clock value at start: %02d:%02d:%02d\n", hours.value, minutes.value, seconds.value);
    
    for (int i = 0; i < 100; i++){
        seconds = boundedCounter_next(seconds);
        if (seconds.value == 0){
            minutes = boundedCounter_next(minutes);
            if (minutes.value == 0){
                hours = boundedCounter_next(hours);
            }
        }
        printf("Clock value: %02d:%02d:%02d\n", hours.value, minutes.value, seconds.value);
    }
    return 0;
}
