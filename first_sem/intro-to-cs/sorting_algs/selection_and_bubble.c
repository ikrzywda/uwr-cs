#include <stdio.h>

void print_arr(int n, int *arr) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int n, int *arr) {
    int min_i;
    for (int i = 0; i < n - 1; ++i) {
        min_i = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[min_i] > arr[j]) {
                min_i = j;
            }
        }
        swap(&arr[min_i], &arr[i]);
    }
}
/*
 *  TIME COMPLEXITY: SUM(n-2, 1) = O(n^2)
 *  DOMINATING INSTRUCTION: comparison 
 *  FOR MONOTONICALLY INCREASING:
 *      * 0 substitutions
 *      * SUM(n-1, 1) comparisons
 *  FOR MONOTONICALLY DECREASING:
 *      * SUM(n-1, 1) comparisons
 *      * SUM(n-1, 1) substitutions
 */

void bubble_sort(int n, int *arr) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

/*
 *  TIME COMPLEXITY: n * (n-1) = O(n^2)
 *  DOMINATING INSTRUCTION: comparison
 *  FOR MONOTONICALLY INCREASING:
 *      * 0 subtitutions
 *      * n * (n-1) comparisons
 *  FOR MONOTONICALLY DECREASING:
 *      * n * (n-1) substitutions
 *      * n * (n-1) comparisons
 */

int main() {
    int test[10] = {2,3,32,5,12,1,38,34,436,65};
    int test_2[10] = {2,3,32,5,12,1,38,34,436,65};
    print_arr(10, test);
    selection_sort(10, test);
    print_arr(10, test);
    bubble_sort(10, test_2);
    print_arr(10, test);
}
