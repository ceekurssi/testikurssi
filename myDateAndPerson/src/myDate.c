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

int differenceInYears(MyDate* first, MyDate* second){
    MyDate* temp = newMyDate(first->day, first->month, first->year);
    if (earlier(first, second) == 0){
        return 0;
    } else if (earlier(first, second) == -1){
        first = second;
        second = temp;
    }
    int difference = second->year - first->year;
    if (first->month > second->month || (first->month == second->month && first->day > second->day)){
        difference -= 1;
    }
    myDateFree(temp);
    return difference;
}

void myDateFree(MyDate* date){
    free(date);
    return;
}
