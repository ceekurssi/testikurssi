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
    MyDate* first = newMyDate(3, 5, 1990);
    MyDate* second = newMyDate(5, 5, 1990);
    MyDate* third = newMyDate(2, 3, 1989);
    MyDate* fourth = newMyDate(3, 5, 1990);
    
    ck_assert_msg(getDay(first) == 3, "getDay doesn't work. Day should be 3, but it was %d", getDay(first));
    ck_assert_msg(getMonth(first) == 5, "getMonth doesn't work. Month should be 5, but it was %d", getMonth(first));
    ck_assert_msg(getYear(first) == 1990, "getYear doesn't work. Year shold be 1990, but it was %d", getYear(first));
    ck_assert_msg(earlier(first, second) == 1, "earlier doesn't work. 3.5.1990 is earlier than 5.5.1990");
    ck_assert_msg(earlier(second, third) == -1, "earlier doesn't work. 5.5.1990 isn't earlier than 2.3.1989");
    ck_assert_msg(earlier(first, fourth) == 0, "earlier doesn't work. 3.5.1990 is the same date than 3.5.1990");
    advance(first);
    ck_assert_msg(getDay(first) == 4, "advance doesn't work. Day should be 4, but it was %d", getDay(first));
    advanceDays(first, 5);
    ck_assert_msg(getDay(first) == 9, "advance doesn't work. Day should be 9, but it was %d", getDay(first));
    advanceDays(first, 666);
    ck_assert_msg(differenceInYears(first, third) == 3, "diffrenceInYears doesn't work. Difference should be 3, but it was %d", differenceInYears(first, third));
    ck_assert_msg(differenceInYears(third, first) == 3, "diffrenceInYears doesn't work. Difference should be 3, but it was %d", differenceInYears(first, third));
    ck_assert_msg(differenceInYears(second, fourth) == 0, "diffrenceInYears doesn't work. Difference should be 0, but it was %d", differenceInYears(second, fourth));

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_myDate, "1");
	return tmc_run_tests(argc, argv, s);
}
