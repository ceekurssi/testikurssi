#ifndef TOLLBOOTH_H
#define	TOLLBOOTH_H

typedef struct Tollbooth Tollbooth;

Tollbooth* Tollbooth_new(int throughput);
void Tollbooth_addCars(Tollbooth*, int numCars);
int Tollbooth_numberOfCarsWaiting(Tollbooth*);
int Tollbooth_maxQueueLength(Tollbooth*);
int Tollbooth_maxWaitTime(Tollbooth*);
int Tollbooth_averageWaitTime(Tollbooth*);
void Tollbooth_destroy(Tollbooth*);
void Tollbooth_stopAddingCars(Tollbooth*);


#endif	/* TOLLBOOTH_H */

