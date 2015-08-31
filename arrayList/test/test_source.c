#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/arraylist.h"

START_TEST(test_SizeOfArrayListIsInitiallyZero) {
    ArrayList* list = ArrayList_new();
    ck_assert_int_eq(ArrayList_size(list), 0);
}

END_TEST

START_TEST(test_SizeOfArrayListIsOneAfterAddingAnElement) {
    ArrayList* list = ArrayList_new();
    int elem = 1337;
    ArrayList_add(list, &elem);
    ck_assert_int_eq(ArrayList_size(list), 1);
}

END_TEST

START_TEST(test_GettingAStoredElementFromListWorks) {
    ArrayList* list = ArrayList_new();
    int elem = 1337;
    ArrayList_add(list, &elem);
    ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 1337);
}

END_TEST

START_TEST(test_GettingANonExistentElementFromListReturnsNULL) {
    ArrayList* list = ArrayList_new();
    int elem = 24;
    ArrayList_add(list, &elem);
    int elem1 = 25;
    ArrayList_add(list, &elem1);
    ck_assert_int_eq(*(int*) ArrayList_get(list, 1), 25);
    ck_assert_ptr_eq(ArrayList_get(list, 4), NULL);
    ck_assert_ptr_eq(ArrayList_get(list, -1), NULL);

}

END_TEST

START_TEST(test_StoringMultipleElementsToListWorks) {
    ArrayList* list = ArrayList_new();

    int elem1 = 1337;
    ArrayList_add(list, &elem1);
    char* elem2 = "theeta";
    ArrayList_add(list, &elem2);
    int elem3 = 74;
    ArrayList_add(list, &elem3);
    char elem4 = 'a';
    ArrayList_add(list, &elem4);

    ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 1337);
    ck_assert_str_eq(*(char**) ArrayList_get(list, 1), "theeta");
    ck_assert_int_eq(*(int*) ArrayList_get(list, 2), 74);
    ck_assert_int_eq(*(char*) ArrayList_get(list, 3), 'a');
    ck_assert_int_eq(ArrayList_size(list), 4);
}

END_TEST

START_TEST(test_StoringEvenMoreElementsToListWorks) {

    int i;

    for (i = 0; i < 10; i++) {
        ArrayList* list = ArrayList_new();

        int elem1 = 1337;
        ArrayList_add(list, &elem1);
        char* elem2 = "theeta";
        ArrayList_add(list, &elem2);
        int elem3 = 74;
        ArrayList_add(list, &elem3);
        char elem4 = 'a';
        ArrayList_add(list, &elem4);
        int elem5 = 55;
        ArrayList_add(list, &elem5);
        int elem6 = 66;
        ArrayList_add(list, &elem6);
        int elem7 = 77;
        ArrayList_add(list, &elem7);
        int elem8 = 88;
        ArrayList_add(list, &elem8);
        int elem9 = 99;
        ArrayList_add(list, &elem9);
        int elem10 = 110;
        ArrayList_add(list, &elem10);
        int elem11 = 111;
        ArrayList_add(list, &elem11);
        int elem12 = 1212;
        ArrayList_add(list, &elem12);
        int elem13 = 1313;
        ArrayList_add(list, &elem13);
        int elem14 = 1414;
        ArrayList_add(list, &elem14);

        ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 1337);
        ck_assert_str_eq(*(char**) ArrayList_get(list, 1), "theeta");
        ck_assert_int_eq(*(int*) ArrayList_get(list, 2), 74);
        ck_assert_int_eq(*(char*) ArrayList_get(list, 3), 'a');
        ck_assert_int_eq(*(int*) ArrayList_get(list, 9), 110);
        ck_assert_int_eq(*(int*) ArrayList_get(list, 10), 111);
        ck_assert_int_eq(*(int*) ArrayList_get(list, 11), 1212);
        ck_assert_int_eq(*(int*) ArrayList_get(list, 12), 1313);
        ck_assert_int_eq(*(int*) ArrayList_get(list, 13), 1414);
        ck_assert_int_eq(ArrayList_size(list), 14);
    }
}

END_TEST

START_TEST(test_RemovingElementFromListWorks) {
    ArrayList* list = ArrayList_new();

    int elem1 = 1337;
    ArrayList_add(list, &elem1);
    char* elem2 = "theeta";
    ArrayList_add(list, &elem2);
    int elem3 = 74;
    ArrayList_add(list, &elem3);

    ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 1337);
    ck_assert_str_eq(*(char**) ArrayList_get(list, 1), "theeta");
    ck_assert_int_eq(*(int*) ArrayList_get(list, 2), 74);

    ArrayList_remove(list, 1);

    ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 1337);
    ck_assert_int_eq(*(int*) ArrayList_get(list, 1), 74);
    ck_assert_int_eq(ArrayList_size(list), 2);
}

END_TEST

START_TEST(test_RemovingElementFromListDoesNotFreeItFromMemory) {
    ArrayList* list = ArrayList_new();

    int* elem = malloc(sizeof (int));
    *elem = 35;
    ArrayList_add(list, elem);
    ck_assert_int_eq(*(int*) ArrayList_get(list, 0), 35);
    ArrayList_remove(list, 0);
    ck_assert_int_eq(*elem, 35);
}

END_TEST

int main(int argc, const char *argv[]) {
    srand((unsigned) time(NULL));
    Suite *s = suite_create("Test-arrayList");
    tmc_register_test(s, test_SizeOfArrayListIsInitiallyZero, "arrayList");
    tmc_register_test(s, test_SizeOfArrayListIsOneAfterAddingAnElement, "arrayList");
    tmc_register_test(s, test_GettingAStoredElementFromListWorks, "arrayList");
    tmc_register_test(s, test_GettingANonExistentElementFromListReturnsNULL, "arrayList");
    tmc_register_test(s, test_StoringMultipleElementsToListWorks, "arrayList");
    tmc_register_test(s, test_StoringEvenMoreElementsToListWorks, "arrayList");
    tmc_register_test(s, test_RemovingElementFromListWorks, "arrayList");
    tmc_register_test(s, test_RemovingElementFromListDoesNotFreeItFromMemory, "arrayList");
    return tmc_run_tests(argc, argv, s);
}
