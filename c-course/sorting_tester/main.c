#include "tester.h"

void isort(int len, double *arr) {
    int j, k;
    for (int i = 1; i < len; ++i) {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = k;
    }
}

void isort_wrapper(void *arr, size_t len, size_t size, 
        int(*cmp)(const void*, const void*)) {
    isort(len, arr);
}

int main() {
    test_sorting(qsort);
    test_sorting(isort_wrapper);
}
