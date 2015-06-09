#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/myDate.h"


START_TEST(test_myDate)
{
    MyDate* first = MyDate_new(3, 5, 1990);
    MyDate* second = MyDate_new(5, 5, 1990);
    MyDate* third = MyDate_new(2, 3, 1989);
    MyDate* fourth = MyDate_new(3, 5, 1990);
    
    ck_assert_msg(MyDate_getDay(first) == 3, "getDay doesn't work. Day should be 3, but it was %d", MyDate_getDay(first));
    ck_assert_msg(MyDate_getMonth(first) == 5, "getMonth doesn't work. Month should be 5, but it was %d", MyDate_getMonth(first));
    ck_assert_msg(MyDate_getYear(first) == 1990, "getYear doesn't work. Year shold be 1990, but it was %d", MyDate_getYear(first));
    ck_assert_msg(MyDate_earlier(first, second) == 1, "earlier doesn't work. 3.5.1990 is earlier than 5.5.1990");
    ck_assert_msg(MyDate_earlier(second, third) == -1, "earlier doesn't work. 5.5.1990 isn't earlier than 2.3.1989");
    ck_assert_msg(MyDate_earlier(first, fourth) == 0, "earlier doesn't work. 3.5.1990 is the same date than 3.5.1990");
    MyDate_advance(first);
    ck_assert_msg(MyDate_getDay(first) == 4, "advance doesn't work. Day should be 4, but it was %d", MyDate_getDay(first));
    MyDate_advanceDays(first, 5);
    ck_assert_msg(MyDate_getDay(first) == 9, "advance doesn't work. Day should be 9, but it was %d", MyDate_getDay(first));
    MyDate_advanceDays(first, 666);
    ck_assert_msg(MyDate_differenceInYears(first, third) == 3, "diffrenceInYears doesn't work. Difference should be 3, but it was %d", MyDate_differenceInYears(first, third));
    ck_assert_msg(MyDate_differenceInYears(third, first) == 3, "diffrenceInYears doesn't work. Difference should be 3, but it was %d", MyDate_differenceInYears(first, third));
    ck_assert_msg(MyDate_differenceInYears(second, fourth) == 0, "diffrenceInYears doesn't work. Difference should be 0, but it was %d", MyDate_differenceInYears(second, fourth));

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_myDate, "1");
	return tmc_run_tests(argc, argv, s);
}
