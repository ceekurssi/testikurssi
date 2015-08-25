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
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    print(a, b);
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[100];
    char message[100] = "";
    char* rightString = "./test\ncommand\nline\narguments\n";
    fread(userString, 99, 1, fp);
    int ret = mycompare(userString, rightString, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST

int main(int argc, const char *argv[])
{
    a = argc;
    b = argv;
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_print, "1");
	return tmc_run_tests(argc, argv, s);
}
