#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_largest) {
FILE *mock_input = freopen("mockinput", "w+", stdin);
     fputs("6 8 10 0", mock_input);
     fseek(mock_input, 0, SEEK_SET);
     int userInt = maximum_integer();
     char user[20];
     sprintf(user, "%d\n", userInt);
     char *ref = "10\n";
     char infostr[100] = "";
     int ret = mycompare(user, ref, infostr);
     fail_unless(!ret, "When giving input \"6 8 10 0\", your output:\n%s\nReference output:\n%s\nReason: %s\n",
            user, ref, infostr);
     
     mock_input = freopen("mockinput", "w+", stdin);
     fputs("-6 5 2 a", mock_input);
     fseek(mock_input, 0, SEEK_SET);
     userInt = maximum_integer();
     sprintf(user, "%d\n", userInt);
     ref = "5\n";
     ret = mycompare(user, ref, infostr);
     fail_unless(!ret, "When giving input \"-6 5 2 a\", your output:\n%s\nReference output:\n%s\nReason: %s\n",
            user, ref, infostr);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_largest, "1");
	return tmc_run_tests(argc, argv, s);
}
