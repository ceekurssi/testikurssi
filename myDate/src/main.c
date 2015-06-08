#include <stdio.h>
#include "myDate.h"

int main() {
    MyDate* date = newMyDate(22, 3, 2017);
    MyDate* newDate = afterNumberOfDays(date, 7);
    printf("Date after a week is %d.%d.%d\n", getDay(newDate), getMonth(newDate), getYear(newDate));
    printf("Today's date is %d.%d.%d\n", getDay(date), getMonth(date), getYear(date));
    MyDate* secondDate = afterNumberOfDays(date, 693);
    printf("The date after 690 days is %d.%d.%d\n", getDay(secondDate), getMonth(secondDate), getYear(secondDate));
    printf("Difference between date and second date in years: %d\n", differenceInYears(secondDate, date));
    
    myDateFree(date);
    myDateFree(newDate);
    myDateFree(secondDate);
    return 0;
}
