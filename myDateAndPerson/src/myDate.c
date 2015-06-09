#include <stdlib.h>
#include "myDate.h"

struct MyDate {
    int day;
    int month;
    int year;
};

MyDate* MyDate_new(int day, int month, int year){
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

int MyDate_getDay(MyDate* date){
    return date->day;
}

int MyDate_getMonth(MyDate* date){
    return date->month;
}

int MyDate_getYear(MyDate* date){
    return date->year;
}

int MyDate_earlier(MyDate* first, MyDate* second){
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

int MyDate_differenceInYears(MyDate* first, MyDate* second){
    MyDate* temp = MyDate_new(first->day, first->month, first->year);
    if (MyDate_earlier(first, second) == 0){
        return 0;
    } else if (MyDate_earlier(first, second) == -1){
        first = second;
        second = temp;
    }
    int difference = second->year - first->year;
    if (first->month > second->month || (first->month == second->month && first->day > second->day)){
        difference -= 1;
    }
    MyDate_free(temp);
    return difference;
}

void MyDate_free(MyDate* date){
    free(date);
    return;
}
