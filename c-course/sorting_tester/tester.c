#include "tester.h"

const unsigned kTestCount = 100;
const unsigned kSetCount = 3;
const unsigned kArrLengths[3] = {5000, 10000, 50000};

struct test {
    clock_t *results;
    double *inarr;
    double *outarr;
    void (*sortfun)(void *arr, size_t len, size_t el_size, 
            int (*cmp)(const void*, const void*));
};

double min_time(double *r, int test_set) {
    int k = kTestCount * test_set;
    double min = r[k];
    for (int i = k + 1; i < k + kTestCount; ++i) {
        if (r[i] < min) {
            min = r[i];
        }
    }
    return min;
}

double max_time(double *r, int test_set) {
    int k = kTestCount * test_set;
    double max = 0;
    for (int i = k; i < k + kTestCount; ++i) {
        if (r[i] > max) {
            max = r[i];
        }
    }
    return max;
}

double mean_time(double *r, int test_set) {
    int k = kTestCount * test_set;
    double mean = 0;
    for (int i = k; i < k + kTestCount; ++i) {
        mean += r[i];
    }
    return mean / kTestCount;
}

void print_arr(int len, double *arr) {
    for (int i = 0; i < len; ++i) {
        printf("%2.f ", arr[i]);
    }
    putchar('\n');
}

void print_results(double *r) {
    double out_data[kSetCount][3];
    printf("size\tmin\t\tmax\t\tmean\n");
    for (int i = 0; i < kSetCount; ++i) {
        printf("%d\t", kArrLengths[i]);
        out_data[i][0] = min_time(r, i);
        out_data[i][1] = max_time(r, i);
        out_data[i][2] = mean_time(r, i);
        printf("%f\t%f\t%f\n", out_data[i][0], out_data[i][1], out_data[i][2]);
    }
}

int cmp(const void *a, const void *b) {
    double ca = *(double*)a;
    double cb = *(double*)b;
    if (ca < cb) {
        return -1;
    } else if (ca > cb) {
        return 1;
    } 
    return 0;
}

void throw_error(int err_code) {
    if (err_code == NOT_PERM) {
        printf("Error. Algorithm does not preserve elements\n");
    } else if (err_code == NOT_SORTED) {
        printf("Error. Algorithm does not sort in non-increasing order\n");
    }
    exit(1);
}

void fill_randvals(int len, double *arr) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand();
    }
}

int is_perm(int len, double *a, double *b) {
    int *el;
    qsort(a, len, sizeof(double), cmp);
    for (int i = 0; i < len; ++i) {
        el = (int*)bsearch(&b[i], a, len, sizeof(double), cmp);
        if (el == NULL) {
            return 0;
        }
    }
    return 1;
}

int is_sorted(int len, double *a) {
    for (int i = 1; i < len; ++i) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }
    return 1;
}

double time_sort(int len, double *inarr, double *outarr, sortfun sort) {
    clock_t end, start = clock();
    sort(outarr, len, sizeof(double), cmp);
    end = clock();
    if (!is_perm(len, inarr, outarr)) {
        return NOT_PERM;
    }
    if (!is_sorted(len, outarr)) {
        return NOT_SORTED;
    }
    return (double)(end - start) / CLOCKS_PER_SEC;
}


void test_sorting(sortfun sort) {
    int offset = 0;
    double results[kTestCount * kSetCount];
    double *inarr, *outarr;
    for (int i = 0; i < kSetCount; ++i) {
        inarr = malloc(sizeof(double) * kArrLengths[i]);
        outarr = malloc(sizeof(double) * kArrLengths[i]);
        for (int j = 0; j <= kTestCount; ++j) {
            fill_randvals(kArrLengths[i], inarr);
            memcpy(outarr, inarr, sizeof(double) * kArrLengths[i]);
            if ((results[offset + j] = time_sort(kArrLengths[i], inarr, 
                                                outarr, sort)) < 0) {
                throw_error((int)results[offset + j]);
                return;
            }
        }
        free(inarr); free(outarr);
        offset += kTestCount;
    }
    print_results(results);
}
