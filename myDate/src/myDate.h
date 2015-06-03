#ifndef MYDATE_H
#define	MYDATE_H

typedef struct MyDate MyDate;

MyDate* newMyDate(int day, int month, int year);
int getDay(MyDate* date);
int getMonth(MyDate* date);
int getYear(MyDate* date);
int earlier(MyDate* first, MyDate* second);
void advance(MyDate* date);
void advanceDays(MyDate* date, int days);
MyDate* afterNumberOfDays(MyDate* date, int days);
int differenceInYears(MyDate* first, MyDate* second);
void myDateFree(MyDate* date);

#endif	/* MYDATE_H */

