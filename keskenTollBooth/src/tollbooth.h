#ifndef TOLLBOOTH_H
#define	TOLLBOOTH_H

typedef struct Tollbooth Tollbooth;

Tollbooth* Tollbooth_new(int throughput);
void Tollbooth_addCars(Tollbooth* tollbooth, int numCars);
void Tollbooth_stopAddingCars(Tollbooth* tollbooth);
int Tollbooth_maxQueueLength(Tollbooth* tollbooth);
int Tollbooth_maxWaitTime(Tollbooth* tollbooth);
int Tollbooth_averageWaitTime(Tollbooth* tollbooth);

#endif	/* TOLLBOOTH_H */

