#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

START_TEST(test_multiply_matrix) {

    freopen("mockoutput", "w", stdout);
    multiply_matrix(5);
    fclose(stdout);
    FILE* fp = fopen("mockoutput", "r");
    char userString[100] = "";
    char message[100] = "";
    char* rightString = "1\t2\t3\t4\t5\t\n2\t4\t6\t8\t10\t\n3\t6\t9\t12\t15\t\n4\t8\t12\t16\t20\t\n5\t10\t15\t20\t25\t\n";
    fread(userString, 99, 1, fp);
    int ret = mycompare(userString, rightString, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-5");

	tmc_register_test(s, test_multiply_matrix, "5");
        
	return tmc_run_tests(argc, argv, s);
}
