#include "stdlib.h"
#include "clock.h"

struct boundedCounter;

struct clock {
    struct boundedCounter hours;
    struct boundedCounter minutes;
    struct boundedCounter seconds;
};

struct clock* clock_new(int hours, int minutes, int seconds){
    clock newClock = malloc(sizeof (clock));
    if (newClock == NULL){
        return NULL;
    }
    
    newClock->hours = (struct boundedCounter) {hours, 23};
    newClock->minutes = (struct boundedCounter) {minutes, 59};
    newClock->seconds = (struct boundedCounter) {seconds, 59};
    
    return newClock;
}

struct clock* clock_tick(struct clock thisClock){
    
}
