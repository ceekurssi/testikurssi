#include <stdlib.h>
#include "tollbooth.h"
#include "queue.h"

/**
 * Implement the tollbooth functionality here. You can use the Queue you made 
 * earlier to store the cars' arrival times.
 */

/**
 * Place your internal "private" variables inside this struct. You should have 
 * a variable for the current time and a pointer to the queue of cars waiting 
 * on the tollbooth. You're also going to need some variables to keep track of 
 * the number of cars served and the max queue length etc.
 * 
 * Note: Only place variables inside the struct. Don't use any static variables!
 */
struct Tollbooth {
    /*BEGIN SOLUTION*/
    int time;
    int throughput;
    int carsServed;
    int totalWaitTime;
    int maxWaitTime;
    int maxQueueLength;
    Queue* queue;
    /*END SOLUTION*/
};

/**
 * Constructor. Allocate memory for the tollbooth and 
 * initialize all private variables. Finally return a pointer to the 
 * newly allocated Tollbooth.
 */
Tollbooth* Tollbooth_new(int throughput){
    /*BEGIN SOLUTION*/
    Tollbooth* self = malloc(sizeof(Tollbooth));
    if (self == NULL) {
        return NULL;
    }
    self->queue = Queue_new();
    self->time = 0;
    self->throughput = throughput;
    self->carsServed = 0;
    self->maxQueueLength = 0;
    self->maxWaitTime = 0;
    self->totalWaitTime = 0;
    return self;
    /*END SOLUTION*/
    /*STUB: return NULL;*/
}

/**
 * This method is called every "minute" in the simulation with the information
 * of how many new cars have arrived to the booth.
 */
void Tollbooth_addCars(Tollbooth* self, int numCars){
    /*BEGIN SOLUTION*/
    for (int i = 0; i<numCars; i++) {
        Queue_add(self->queue, self->time);
    }
    
    if (Queue_getSize(self->queue) > self->maxQueueLength) {
        self->maxQueueLength = Queue_getSize(self->queue);
    }
    
    for (int i = 0; i<self->throughput; i++) {
        int arrivalTime = Queue_remove(self->queue);
        if (arrivalTime == -1) {
            break;
        }
        self->carsServed++;
        int waitTime = self->time-arrivalTime;
        self->totalWaitTime += waitTime;
        if (waitTime > self->maxWaitTime) {
            self->maxWaitTime = waitTime;
        }
    }
    self->time++;
    /*END SOLUTION*/
}

/**
 * Return the number of cars currently waiting on the queue of the tollbooth.
 */
int Tollbooth_numberOfCarsWaiting(Tollbooth* self) {
    /*BEGIN SOLUTION*/
    return Queue_getSize(self->queue);
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Return the maximum length of the queue.
 */
int Tollbooth_maxQueueLength(Tollbooth* self) {
    /*BEGIN SOLUTION*/
    return self->maxQueueLength;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Return the maximum wait time of the cars that have passed the tollbooth.
 */
int Tollbooth_maxWaitTime(Tollbooth* self) {
    /*BEGIN SOLUTION*/
    return self->maxWaitTime;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Return the average wait time of the cars that have passed the tollbooth.
 */
int Tollbooth_averageWaitTime(Tollbooth* self) {
    /*BEGIN SOLUTION*/
    if (self->carsServed == 0) {
        return 0;
    }
    return self->totalWaitTime/self->carsServed;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}

/**
 * Destructor. Free all memory. If you used a Queue object, call its destructor 
 * method. Finally free your internal struct (the 'self' pointer).
 */
void Tollbooth_destroy(Tollbooth* self){
    /*BEGIN SOLUTION*/
    Queue_destroy(self->queue);
    free(self);
    /*END SOLUTION*/
}

/**
 * This method will be called at the end of the simulation. It lets all 
 * remaining cars to pass the bridge without adding any new cars (ie. it calls 
 * the addCars method with zero until the remaining cars have passed 
 * the tollbooth).
 */
void Tollbooth_stopAddingCars(Tollbooth* self) {
    while (Tollbooth_numberOfCarsWaiting(self) > 0) {
        Tollbooth_addCars(self, 0);
    }
}
