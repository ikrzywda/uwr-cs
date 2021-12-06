#include "tester.h"
#include <string.h>

void merge(double *arr, double *left, double *right, int n) {
    int i = 0, li = 0, ri = 0;
    for (; i < n; ++i) {
        if (ri == (n/2 + n%2) || (li < n/2 && left[li] < right[ri])) {
            arr[i] = left[li++];
        } else {
            arr[i] = right[ri++];
        }
    }
}

void msort(int n, double *arr) {
    double *left, *right;
    if (n == 1) return;
    left = malloc((n/2) * sizeof(double)); 
    right = malloc((n/2 + n%2) * sizeof(double));
    memcpy(left, arr, n/2 * sizeof(double));
    memcpy(right, arr + n/2, (n/2 + n%2) * sizeof(double));
    msort(n/2, left);
    msort((n/2 + n%2), right);
    merge(arr, left, right, n);
    free(left); free(right);
}

void msort_wrapper(void *arr, size_t len, size_t el_size, int(*cmp)(const void*, const void*)) {
    msort((int)len, (double*)arr);
}

int main() {
    test_sorting(qsort);
    test_sorting(msort_wrapper);
}
