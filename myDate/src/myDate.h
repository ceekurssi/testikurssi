#ifndef MYDATE_H
#define	MYDATE_H

typedef struct MyDate MyDate;

MyDate* MyDate_new(int day, int month, int year);
int MyDate_getDay(MyDate* date);
int MyDate_getMonth(MyDate* date);
int MyDate_getYear(MyDate* date);
int MyDate_earlier(MyDate* first, MyDate* second);
void MyDate_advance(MyDate* date);
void MyDate_advanceDays(MyDate* date, int days);
MyDate* MyDate_afterNumberOfDays(MyDate* date, int days);
int MyDate_differenceInYears(MyDate* first, MyDate* second);
void MyDate_free(MyDate* date);

#endif	/* MYDATE_H */

