#include <stdlib.h>
#include "tollbooth.h"
#include "queue.h"

struct Tollbooth {
    int time;
    int throughput;
    int carsServed;
    int totalWaitTime;
    int maxWaitTime;
    int maxQueueLength;
    Queue* queue;
};

Tollbooth* Tollbooth_new(int throughput){
    Tollbooth* tollbooth = malloc(sizeof(Tollbooth));
    if (tollbooth == NULL) {
        return NULL;
    }
    tollbooth->queue = Queue_new();
    tollbooth->time = 0;
    tollbooth->throughput = throughput;
    tollbooth->carsServed = 0;
    tollbooth->maxQueueLength = 0;
    tollbooth->maxWaitTime = 0;
    tollbooth->totalWaitTime = 0;
    return tollbooth;
}

void Tollbooth_addCars(Tollbooth* tollbooth, int numCars){
    for (int i = 0; i<numCars; i++) {
        Queue_add(tollbooth->queue, tollbooth->time);
    }
    
    if (Queue_getSize(tollbooth->queue) > tollbooth->maxQueueLength) {
        tollbooth->maxQueueLength = Queue_getSize(tollbooth->queue);
    }
    
    for (int i = 0; i<tollbooth->throughput; i++) {
        int car = Queue_remove(tollbooth->queue);
        if (car == -1) {
            break;
        }
        tollbooth->carsServed++;
        int waitTime = tollbooth->time-car;
        tollbooth->totalWaitTime += waitTime;
        if (waitTime > tollbooth->maxWaitTime) {
            tollbooth->maxWaitTime = waitTime;
        }
    }
    tollbooth->time++;
}

void Tollbooth_stopAddingCars(Tollbooth* tollbooth) {
    while (Queue_getSize(tollbooth->queue) > 0) {
        Tollbooth_addCars(tollbooth, 0);
    }
}

int Tollbooth_maxQueueLength(Tollbooth* tollbooth) {
    return tollbooth->maxQueueLength;
}

int Tollbooth_maxWaitTime(Tollbooth* tollbooth) {
    return tollbooth->maxWaitTime;
}

int Tollbooth_averageWaitTime(Tollbooth* tollbooth) {
    return tollbooth->totalWaitTime/tollbooth->carsServed;
}
