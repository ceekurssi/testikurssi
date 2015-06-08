#include <stdlib.h>
#include "myDate.h"

struct MyDate {
    int day;
    int month;
    int year;
};

MyDate* newMyDate(int day, int month, int year){
    MyDate* date;
    
    date = malloc(sizeof(MyDate));
    if (date == NULL){
        return NULL;
    }
    
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

int getDay(MyDate* date){
    return date->day;
}

int getMonth(MyDate* date){
    return date->month;
}

int getYear(MyDate* date){
    return date->year;
}

int earlier(MyDate* first, MyDate* second){
    if (first->year < second->year){
        return 1;
    }
    if (first->year == second->year && first->month < second->month){
        return 1;
    }
    if (first->year == second->year && first->month == second->month && first->day < second->day){
        return 1;
    }
    if (first->year == second->year && first->month == second->month && first->day == second->day){
        return 0;
    }
    return -1;
}

void advance(MyDate* date){
    if (date->day < 30){
        date->day += 1;
    } else if (date->month < 12){
        date->day = 1;
        date->month += 1;
    } else {
        date->day = 1;
        date->month = 1;
        date->year += 1;
    }
}

void advanceDays(MyDate* date, int days){
    for (int i = 0; i < days; i++){
        advance(date);
    }
}

MyDate* afterNumberOfDays(MyDate* date, int days){
    MyDate* newDate;
    
    newDate = malloc(sizeof(MyDate));
    if (newDate == NULL){
        return NULL;
    }
    newDate->day = date->day;
    newDate->month = date->month;
    newDate->year = date->year;
    
    advanceDays(newDate, days);
    return newDate;
}

int differenceInYears(MyDate* first, MyDate* second){
    if (earlier(first, second) == 0){
        return 0;
    } else if (earlier(first, second) == -1){
        MyDate* temp = newMyDate(first->day, first->month, first->year);
        first = second;
        second = temp;
        myDateFree(temp);
    }
    int difference = second->year - first->year;
    if (first->month > second->month || (first->month == second->month && first->day > second->day)){
        difference -= 1;
    }
    return difference;
}

void myDateFree(MyDate* date){
    free(date);
    return;
}
