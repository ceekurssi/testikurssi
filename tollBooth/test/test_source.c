#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/queue.h"
#include "../src/tollbooth.h"

START_TEST(test_SizeOfQueueIsInitiallyZero) {
    Queue* q = Queue_new();
    ck_assert_int_eq(Queue_getSize(q), 0);
}

END_TEST

START_TEST(test_SizeOfQueueIsOneAfterAddingAnElement) {
    Queue* q = Queue_new();
    int value = 1337;
    Queue_add(q, value);
    ck_assert_int_eq(Queue_getSize(q), 1);
}

END_TEST

START_TEST(test_GettingAValueFromQueueWorks) {
    Queue* q = Queue_new();
    int value = 1337;
    Queue_add(q, value);
    ck_assert_int_eq(Queue_remove(q), 1337);
}

END_TEST

START_TEST(test_StoringMultipleElementsToQueueWorks) {
    Queue* q = Queue_new();
    int value = 1337;
    Queue_add(q, value);
    value = 111;
    Queue_add(q, value);
    value = 222;
    Queue_add(q, value);
    value = 333;
    Queue_add(q, value);

    ck_assert_int_eq(Queue_getSize(q), 4);
    ck_assert_int_eq(Queue_remove(q), 1337);
    ck_assert_int_eq(Queue_remove(q), 111);
    ck_assert_int_eq(Queue_remove(q), 222);
    ck_assert_int_eq(Queue_remove(q), 333);
    ck_assert_int_eq(Queue_getSize(q), 0);
}

END_TEST

START_TEST(test_TollboothMaxQueueLengthIsInitiallyZero) {
    Tollbooth* tollbooth = Tollbooth_new(7);
    ck_assert_int_eq(Tollbooth_maxQueueLength(tollbooth), 0);
}

END_TEST


START_TEST(test_TollboothMaxWaitTimeIsInitiallyZero) {
    Tollbooth* tollbooth = Tollbooth_new(7);

    ck_assert_int_eq(Tollbooth_maxWaitTime(tollbooth), 0);
}

END_TEST

START_TEST(test_TollboothAverageWaitTimeIsInitiallyZero) {
    Tollbooth* tollbooth = Tollbooth_new(7);

    ck_assert_int_eq(Tollbooth_averageWaitTime(tollbooth), 0);
}

END_TEST

START_TEST(test_Tollbooth1) {
    Tollbooth* tollbooth = Tollbooth_new(7);
    Tollbooth* tollbooth2 = Tollbooth_new(4);
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth, 5);
    }
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth2, 5);
    }
    Tollbooth_stopAddingCars(tollbooth);
    Tollbooth_stopAddingCars(tollbooth2);
    ck_assert_int_eq(Tollbooth_averageWaitTime(tollbooth), 0);
    ck_assert_int_eq(Tollbooth_maxWaitTime(tollbooth), 0);
    ck_assert_int_eq(Tollbooth_maxQueueLength(tollbooth), 5);

    ck_assert_int_eq(Tollbooth_averageWaitTime(tollbooth2), 1);
    ck_assert_int_eq(Tollbooth_maxWaitTime(tollbooth2), 4);
    ck_assert_int_eq(Tollbooth_maxQueueLength(tollbooth2), 19);
}

END_TEST

START_TEST(test_Tollbooth2) {
    Tollbooth* tollbooth = Tollbooth_new(7);
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth, 5);
    }
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth, 8);
    }
    for (int i = 0; i < 30; i++) {
        Tollbooth_addCars(tollbooth, 12);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 15);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 6);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth, 1);
    }
    Tollbooth_stopAddingCars(tollbooth);

    Tollbooth* tollbooth2 = Tollbooth_new(10);
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth2, 5);
    }
    for (int i = 0; i < 15; i++) {
        Tollbooth_addCars(tollbooth2, 8);
    }
    for (int i = 0; i < 30; i++) {
        Tollbooth_addCars(tollbooth2, 12);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth2, 15);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth2, 6);
    }
    for (int i = 0; i < 60; i++) {
        Tollbooth_addCars(tollbooth2, 1);
    }
    Tollbooth_stopAddingCars(tollbooth2);

    ck_assert_int_eq(Tollbooth_averageWaitTime(tollbooth), 49);
    ck_assert_int_eq(Tollbooth_maxWaitTime(tollbooth), 93);
    ck_assert_int_eq(Tollbooth_maxQueueLength(tollbooth), 652);
    
    ck_assert_int_eq(Tollbooth_averageWaitTime(tollbooth2), 15);
    ck_assert_int_eq(Tollbooth_maxWaitTime(tollbooth2), 36);
    ck_assert_int_eq(Tollbooth_maxQueueLength(tollbooth2), 370);
}

END_TEST


int main(int argc, const char *argv[]) {
    srand((unsigned) time(NULL));
    Suite *s = suite_create("Test-tollBooth");
    tmc_register_test(s, test_SizeOfQueueIsInitiallyZero, "tollBoothQueue");
    tmc_register_test(s, test_SizeOfQueueIsOneAfterAddingAnElement, "tollBoothQueue");
    tmc_register_test(s, test_GettingAValueFromQueueWorks, "tollBoothQueue");
    tmc_register_test(s, test_StoringMultipleElementsToQueueWorks, "tollBoothQueue");
    tmc_register_test(s, test_TollboothMaxQueueLengthIsInitiallyZero, "tollBoothTollBooth");
    tmc_register_test(s, test_TollboothMaxWaitTimeIsInitiallyZero, "tollBoothTollBooth");
    tmc_register_test(s, test_TollboothAverageWaitTimeIsInitiallyZero, "tollBoothTollBooth");
    tmc_register_test(s, test_Tollbooth1, "tollBoothTollBooth");
    tmc_register_test(s, test_Tollbooth2, "tollBoothTollBooth");

    return tmc_run_tests(argc, argv, s);
}
