#ifndef CLOCK_H
#define	CLOCK_H
#include "boundedCounter.h"



typedef struct clock clock;

struct clock* clock_new(int hours, int minutes, int seconds);
struct clock* clock_tick(struct clock thisClock);


#endif	/* CLOCK_H */

