#ifndef BOUNDEDCOUNTER_H
#define	BOUNDEDCOUNTER_H

/*BEGIN SOLUTION*/

struct boundedCounter {
    int value;
    int upperLimit;
};

/*END SOLUTION*/

struct boundedCounter next_boundedCounter(struct boundedCounter counter);

#endif	/* BOUNDEDCOUNTER_H */
