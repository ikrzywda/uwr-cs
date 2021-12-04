#ifndef TESTER_H
#define TESTER_H
    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define NOT_PERM -1
#define NOT_SORTED -2

typedef struct test Test;
typedef void(*sortfun)(void *arr, size_t len, size_t el_size,
                  int(*cmp)(const void*, const void*));

double min_time(double *r, int test_set);
double max_time(double *r, int test_set);
double mean_time(double *r, int test_set);
void print_arr(int len, double *arr);
void print_results(double *r);
int cmp(const void *a, const void *b);
void throw_error(int err_code);
double time_sort(int len, double *inarr, double *outarr, sortfun sort);
void test_sorting(sortfun sort);

void fill_randvals(int len, double *arr);
int is_perm(int len, double *a, double *b);
int is_sorted(int len, double *a);


#endif
