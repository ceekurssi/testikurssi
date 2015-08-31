#include <stdio.h>
#include "tollbooth.h"

/**
 * Another object-oriented exercise.
 * 
 * The Bottleneck Bridge has only a single westbound tollbooth. The toll 
 * collector can only collect tolls from N cars each minute. Write a program 
 * that simulates the flow of traffic past the tollbooth.
 * 
 * First, start out by implementing a Queue data structure in queue.c
 * 
 * Then, implement Tollbooth. The tollbooth will receive information about new 
 * cars arriving to the bridge every minute. Store the time of each car's arrival
 * in the queue. Keep track of the maximum length of the queue, maximum waiting
 * time and the average waiting time of cars in the queue.
 * 
 * In the following example in the main function, the tollbooth can 
 * serve 7 cars per minute. Let's say the traffic starts to arrive at 6:00 AM. 
 * Between 6:00 and 6:15, cars arrive at the rate of 5 per minute. 
 * Between 6:15 and 6:30, cars arrive at the rate of 8 per minute. 
 * Between 6:30 and 7:00, cars arrive at the rate of 12 per minute.
 * Between 7:00 and 8:00, cars arrive at the rate of 15 per minute.
 * Between 8:00 and 9:00, cars arrive at the rate of 6 per minute 
 * and from 9:00 to 10:00, cars arrive at the rate of 1 per minute.
 * No traffic travels west after 10:00. 
 * 
 * With the provided main method, your program should have the following output:
 * 
 * Maximum queue length: 652
 * Maximum waiting time: 93
 * Average waiting time: 49
 * 
 */

int main() {
    int throughput = 7;

    Tollbooth* tollbooth = Tollbooth_new(throughput);
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth, 5);
    }
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth, 8);
    }
    for (int i = 0; i < 30; i++) {
        Tollbooth_addCars(tollbooth, 12);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 15);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 6);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 1);
    }
    Tollbooth_stopAddingCars(tollbooth);

    printf("Maximum queue length: %d\n", Tollbooth_maxQueueLength(tollbooth));
    printf("Maximum waiting time: %d\n", Tollbooth_maxWaitTime(tollbooth));
    printf("Average waiting time: %d\n", Tollbooth_averageWaitTime(tollbooth));
    
    Tollbooth_destroy(tollbooth);

    return 0;
}
