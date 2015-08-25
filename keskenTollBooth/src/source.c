#include "tollbooth.h"
#include <stdio.h>

void beginSimulation(int carsPerMinute) {
    Tollbooth* tollbooth = Tollbooth_new(carsPerMinute);
    for (int i = 0; i<15; i++) {
        Tollbooth_addCars(tollbooth, 5);
    }
    for (int i = 0; i<15; i++) {
        Tollbooth_addCars(tollbooth, 8);
    }
    for (int i = 0; i<30; i++) {
        Tollbooth_addCars(tollbooth, 12);
    }
    for (int i = 0; i<60; i++) {
        Tollbooth_addCars(tollbooth, 15);
    }
    for (int i = 0; i<60; i++) {
        Tollbooth_addCars(tollbooth, 6);
    }
    for (int i = 0; i<60; i++) {
        Tollbooth_addCars(tollbooth, 1);
    }
    Tollbooth_stopAddingCars(tollbooth);    
    
    printf("Maximum queue length: %d\n", Tollbooth_maxQueueLength(tollbooth));
    printf("Maximum waiting time: %d\n", Tollbooth_maxWaitTime(tollbooth));
    printf("Average waiting time: %d\n", Tollbooth_averageWaitTime(tollbooth));
}
