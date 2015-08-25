#ifndef HARDWARE_H
#define	HARDWARE_H

#include <stdio.h>
typedef struct HardwareData HardwareData;

void textFile(FILE* file);
void updateRecord(FILE* file);
void newRecord(FILE* file);
void deleteRecord(FILE* file);

#endif	/* HARDWARE_H */

