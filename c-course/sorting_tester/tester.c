#include "tester.h"

void print_test_data(TestData *td) {
    printf("Input size: %d\n", td->size);
    for (int i = 0; i < td->size; ++i) {
        printf("%2.f ", td->input[i]);
    }
}

void rand_fill(int size, double *arr) {
    for (int i = 0; i  < size; ++i) {
        arr[i] = rand();
    }
}

int is_sorted(int size, double *arr) {
    for (int i = 1; i < size; ++i) {
        if (arr[i-1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

int is_perm(TestData *td) {
    return 0; 
}

TestData *new_test(int size, int test_count) {
    TestData *new_test = malloc(sizeof(TestData));
    new_test->size = size;
    new_test->test_count = test_count;
    new_test->input = malloc(sizeof(double) * size);
    new_test->output = malloc(sizeof(double) * size);
    new_test->times = malloc(sizeof(double) * test_count);
    rand_fill(size, new_test->input);
    return new_test;
}

void free_test(TestData *td) {
    free(td->input);
    free(td->output);
    free(td);
}
