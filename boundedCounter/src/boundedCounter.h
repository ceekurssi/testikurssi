#ifndef BOUNDEDCOUNTER_H
#define	BOUNDEDCOUNTER_H

struct boundedCounter {
    int value;
    int upperLimit;
};

struct boundedCounter boundedCounter_next(struct boundedCounter counter);

#endif	/* BOUNDEDCOUNTER_H */
