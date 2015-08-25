#include <stdio.h>
#include "source.h"

/*Tehtävä suoraan kirjasta x. Pitää miettiä, mitä tästä annetaan valmiina ja mitä tietoja halutaan testata ja muokata tehtävänantoa sen mukaan. 
 * The Bottleneck Bridge has only a single westbound tollbooth. Every weekday morning rush hour traffic starts 
 * to arrive at 6:00 AM. Between 6:00 and 6:15, cars arrive at the rate of 5 per minute. 
 * Between 6:15 and 6:30, cars arrive at the rate of 8 per minute. 
 * Between 6:30 and 7:00, cars arrive at the rate of 12 per minute.
 * Between 7:00 and 8:00, cars arrive at the rate of 15 per minute.
 * Between 8:00 and 9:00, cars arrive at the rate of 6 per minute 
 * and from 9:00 to 10:00, cars arrive at the rate of 1 per minute.
 * No traffic travels west after 10:00. 
 * The toll collector can collect tolls from 7 cars each minute.
 * Write a program that simulates the flow of traffic past the tollbooth.
 * Your program should build a queue with a record for each car.
 * Store the time of the car's arrival (to the nearest minute) in the record for that car.
 * Have your program print out the maximum length of the queue, 
 * the maximum time any car waited in the queue,
 * and the average wait time for all cars that traveled across the bridge that day.
 * Modify the program so that the user car input the number of tolls per minute that can be collected.
 * Then experiment with different values to see how maximum size of the queue changes as you vary the value. a*/

int main(int argc, char* argv[]) {
    int throughput = 7;
/*
    if (argc > 1) {
        if (sscanf(argv[1], "%i", &throughput) != 1) {
            printf("error - not an integer");
        }
    }
*/

    beginSimulation(throughput);
    return 0;
}
