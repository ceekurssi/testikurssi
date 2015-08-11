#include <stdio.h>
#include "boundedCounter.h"

struct boundedCounter boundedCounter_next(struct boundedCounter counter){
    if (counter.value < counter.upperLimit){
        counter.value++;
    } else {
        counter.value = 0;
    }
    return counter;
}
