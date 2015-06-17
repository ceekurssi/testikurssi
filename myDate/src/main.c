#include <stdio.h>
#include "myDate.h"

//tän vois tehdä vähän järkevämmin

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 5.
 * Define a structure called myDate in myDate.c. myDate contains three members, integers for day, month and year. 
 * Implement all functions in myDate.c. */

int main(void) {
    MyDate* date = MyDate_new(22, 3, 2017);
    MyDate* newDate = MyDate_afterNumberOfDays(date, 7);
    printf("Date after a week is %d.%d.%d\n", MyDate_getDay(newDate), MyDate_getMonth(newDate), MyDate_getYear(newDate));
    printf("Today's date is %d.%d.%d\n", MyDate_getDay(date), MyDate_getMonth(date), MyDate_getYear(date));
    MyDate* secondDate = MyDate_afterNumberOfDays(date, 693);
    printf("The date after 690 days is %d.%d.%d\n", MyDate_getDay(secondDate), MyDate_getMonth(secondDate), MyDate_getYear(secondDate));
    printf("Difference between date and second date in years: %d\n", MyDate_differenceInYears(secondDate, date));
    
    MyDate_free(date);
    MyDate_free(newDate);
    MyDate_free(secondDate);
    return 0;
}
