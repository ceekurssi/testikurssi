#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

int a;
const char** b;

START_TEST(test_print) {
    print(a, b);
}
END_TEST

int main(int argc, const char *argv[])
{
    a = argc;
    b = argv;
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_print, "15");
	return tmc_run_tests(argc, argv, s);
}
