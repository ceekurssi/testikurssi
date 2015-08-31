#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/linkedlist.h"

START_TEST(test_SizeOfLinkedListIsInitiallyZero) {
    LinkedList* list = LinkedList_new();
    ck_assert_int_eq(LinkedList_size(list), 0);
}

END_TEST

START_TEST(test_HeadAndTailOfLinkedListAreInitiallyNULL) {
    LinkedList* list = LinkedList_new();
    ck_assert_ptr_eq(LinkedList_getHead(list), NULL);
    ck_assert_ptr_eq(LinkedList_getTail(list), NULL);
}

END_TEST

START_TEST(test_SizeOfLinkedListIsOneAfterAddingAnElement) {
    LinkedList* list = LinkedList_new();
    int elem = 1337;
    LinkedList_add(list, &elem);
    ck_assert_int_eq(LinkedList_size(list), 1);
}

END_TEST

START_TEST(test_ListHasSameHeadAndTailNodeAfterAddingAnElement) {
    LinkedList* list = LinkedList_new();
    int elem = 1337;
    LinkedList_add(list, &elem);
    ck_assert_ptr_ne(LinkedList_getHead(list), NULL);
    ck_assert_ptr_eq(LinkedList_getHead(list), LinkedList_getTail(list));
}

END_TEST

START_TEST(test_GettingAStoredElementFromListWorks) {
    LinkedList* list = LinkedList_new();
    int elem = 1337;
    LinkedList_add(list, &elem);
    ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 1337);
}

END_TEST

START_TEST(test_GettingAStoredElementFromListNodeWorks) {
    LinkedList* list = LinkedList_new();
    int elem = 1337;
    LinkedList_add(list, &elem);
    ck_assert_int_eq(*(int*) LinkedList_getNode(list, 0)->elem, 1337);
}

END_TEST

START_TEST(test_GettingANonExistentElementFromListReturnsNULL) {
    LinkedList* list = LinkedList_new();
    int elem = 24;
    LinkedList_add(list, &elem);
    int elem1 = 25;
    LinkedList_add(list, &elem1);
    ck_assert_int_eq(*(int*) LinkedList_get(list, 1), 25);
    ck_assert_ptr_eq(LinkedList_get(list, 4), NULL);
    ck_assert_ptr_eq(LinkedList_get(list, -1), NULL);

}

END_TEST

START_TEST(test_StoringMultipleElementsToListWorks) {
    LinkedList* list = LinkedList_new();

    int elem1 = 1337;
    LinkedList_add(list, &elem1);
    char* elem2 = "theeta";
    LinkedList_add(list, &elem2);
    int elem3 = 74;
    LinkedList_add(list, &elem3);
    char elem4 = 'a';
    LinkedList_add(list, &elem4);

    ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 1337);
    ck_assert_str_eq(*(char**) LinkedList_get(list, 1), "theeta");
    ck_assert_int_eq(*(int*) LinkedList_get(list, 2), 74);
    ck_assert_int_eq(*(char*) LinkedList_get(list, 3), 'a');
    ck_assert_int_eq(LinkedList_size(list), 4);
}

END_TEST

START_TEST(test_NodesHaveCorrectPreviousAndNextPointersAfterAddingMultipleElements) {
    LinkedList* list = LinkedList_new();

    int elem1 = 1337;
    LinkedList_add(list, &elem1);
    char* elem2 = "theeta";
    LinkedList_add(list, &elem2);
    int elem3 = 74;
    LinkedList_add(list, &elem3);
    char elem4 = 'a';
    LinkedList_add(list, &elem4);

    Node* node = NULL;
    Node* prev = NULL;
    int i;
    for (i = 0; i < 4; i++) {
        node = LinkedList_getNode(list, i);
        ck_assert_ptr_eq(node->previous, prev);
        if (prev != NULL) {
            ck_assert_ptr_eq(prev->next, node);
        }
        prev = node;
    }
    ck_assert_ptr_eq(node->next, NULL);
}

END_TEST

START_TEST(test_StoringEvenMoreElementsToListWorks) {

    int i;

    for (i = 0; i < 10; i++) {
        LinkedList* list = LinkedList_new();

        int elem1 = 1337;
        LinkedList_add(list, &elem1);
        char* elem2 = "theeta";
        LinkedList_add(list, &elem2);
        int elem3 = 74;
        LinkedList_add(list, &elem3);
        char elem4 = 'a';
        LinkedList_add(list, &elem4);
        int elem5 = 55;
        LinkedList_add(list, &elem5);
        int elem6 = 66;
        LinkedList_add(list, &elem6);
        int elem7 = 77;
        LinkedList_add(list, &elem7);
        int elem8 = 88;
        LinkedList_add(list, &elem8);
        int elem9 = 99;
        LinkedList_add(list, &elem9);
        int elem10 = 110;
        LinkedList_add(list, &elem10);
        int elem11 = 111;
        LinkedList_add(list, &elem11);
        int elem12 = 1212;
        LinkedList_add(list, &elem12);
        int elem13 = 1313;
        LinkedList_add(list, &elem13);
        int elem14 = 1414;
        LinkedList_add(list, &elem14);

        ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 1337);
        ck_assert_str_eq(*(char**) LinkedList_get(list, 1), "theeta");
        ck_assert_int_eq(*(int*) LinkedList_get(list, 2), 74);
        ck_assert_int_eq(*(char*) LinkedList_get(list, 3), 'a');
        ck_assert_int_eq(*(int*) LinkedList_get(list, 9), 110);
        ck_assert_int_eq(*(int*) LinkedList_get(list, 10), 111);
        ck_assert_int_eq(*(int*) LinkedList_get(list, 11), 1212);
        ck_assert_int_eq(*(int*) LinkedList_get(list, 12), 1313);
        ck_assert_int_eq(*(int*) LinkedList_get(list, 13), 1414);
        ck_assert_int_eq(LinkedList_size(list), 14);
    }
}

END_TEST

START_TEST(test_RemovingElementFromListWorks) {
    LinkedList* list = LinkedList_new();

    int elem1 = 1337;
    LinkedList_add(list, &elem1);
    char* elem2 = "theeta";
    LinkedList_add(list, &elem2);
    int elem3 = 74;
    LinkedList_add(list, &elem3);

    ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 1337);
    ck_assert_str_eq(*(char**) LinkedList_get(list, 1), "theeta");
    ck_assert_int_eq(*(int*) LinkedList_get(list, 2), 74);

    LinkedList_remove(list, 1);

    ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 1337);
    ck_assert_int_eq(*(int*) LinkedList_get(list, 1), 74);
    ck_assert_int_eq(LinkedList_size(list), 2);
}

END_TEST

START_TEST(test_RemovingElementFromListDoesNotFreeItFromMemory) {
    LinkedList* list = LinkedList_new();

    int* elem = malloc(sizeof (int));
    *elem = 35;
    LinkedList_add(list, elem);
    ck_assert_int_eq(*(int*) LinkedList_get(list, 0), 35);
    LinkedList_remove(list, 0);
    ck_assert_int_eq(*elem, 35);
}

END_TEST

int main(int argc, const char *argv[]) {
    srand((unsigned) time(NULL));
    Suite *s = suite_create("Test-linkedList");
    tmc_register_test(s, test_SizeOfLinkedListIsInitiallyZero, "linkedList");
    tmc_register_test(s, test_HeadAndTailOfLinkedListAreInitiallyNULL, "linkedList");
    tmc_register_test(s, test_SizeOfLinkedListIsOneAfterAddingAnElement, "linkedList");
    tmc_register_test(s, test_ListHasSameHeadAndTailNodeAfterAddingAnElement, "linkedList");
    tmc_register_test(s, test_GettingAStoredElementFromListWorks, "linkedList");
    tmc_register_test(s, test_GettingAStoredElementFromListNodeWorks, "linkedList");
    tmc_register_test(s, test_GettingANonExistentElementFromListReturnsNULL, "linkedList");
    tmc_register_test(s, test_StoringMultipleElementsToListWorks, "linkedList");
    tmc_register_test(s, test_NodesHaveCorrectPreviousAndNextPointersAfterAddingMultipleElements, "linkedList");
    tmc_register_test(s, test_StoringEvenMoreElementsToListWorks, "linkedList");
    tmc_register_test(s, test_RemovingElementFromListWorks, "linkedList");
    tmc_register_test(s, test_RemovingElementFromListDoesNotFreeItFromMemory, "linkedList");
    return tmc_run_tests(argc, argv, s);
}
