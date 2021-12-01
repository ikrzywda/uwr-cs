#ifndef TESTER_H
#define TESTER_H
    
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


typedef struct test_data {
    int size;
    int test_count;
    double *input;
    double *output;
    double *times;
} TestData;

void print_test_data(TestData *td);
void rand_fill(int size, double *arr);
int is_sorted(int size, double *arr);
int is_perm(TestData *td);

TestData *new_test(int size, int test_count);
void free_test(TestData *td);

#endif
