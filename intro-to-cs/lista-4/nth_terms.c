#include <stdio.h>


/*
 *  Specification:
 *   * INPUT: natural number n
 *   * OUTPUT: (-1)^n * n
 *  Time Complexity: O(1)
 *  Memory Complexity: O(1)
 */

int foo_a(unsigned n) {
    if (n % 2) {
        return -n;
    } else {
        return n;
    }
}

int foo_c(unsigned n, unsigned x) {
    int sum = 0, a;
    for (int i = 1; i <= n; ++i) {
        a = x;
        for (int j = 0; j <= i; ++j) {
            a *= a;
        }
        a *= i;
        sum += a;
    }
    return sum;
}

int main() {
    printf("%d %d\n", foo_a(100), foo_a(3005));
    printf("%d", foo_c(2, 2));
}
