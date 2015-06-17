#include "boundedCounter.h"

struct boundedCounter next_boundedCounter(struct boundedCounter counter){
    if (counter.value < counter.upperLimit){
        counter.value++;
    } else {
        counter.value = 0;
    }
    return counter;
}
