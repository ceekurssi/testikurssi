#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/boundedCounter.h"


START_TEST(test_counter) {
    struct boundedCounter counter = {2, 3};
    ck_assert_msg(counter.value == 2, "Counter value should be 2, but it was %d", counter.value);
    ck_assert_msg(counter.upperLimit == 3, "Counter upperLimit should be 3, but it was %d", counter.upperLimit);
    ck_assert_msg(boundedCounter_next(counter).value == 3, "Counter next value should be 3, but it was %d", boundedCounter_next(counter).value);
    counter = boundedCounter_next(counter);
    ck_assert_msg(boundedCounter_next(counter).value == 0, "Counter next value should be 0, but it was %d", boundedCounter_next(counter).value);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_counter, "16");
	return tmc_run_tests(argc, argv, s);
}
