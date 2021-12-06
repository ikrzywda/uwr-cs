#include <stdio.h>

typedef unsigned DigitRef[11];

/*
 *  Ex. 7
 *  time complexity: O(log(n))
 *  space complexity: O(1)
 */

void check_digits(unsigned n) {
    int used_digits[11] = {0}, udc = 0;
    int d;
    while (n > 0) {
        d = n % 10;
        n /= 10;
        ++used_digits[d];
    }
    for (int j = 0; j < 11; ++j) {
        if (used_digits[j] > 0) {
            ++udc;
        }
    }
    printf("%d\n", udc);
}

/*
 *  Ex. 8
 *  time complexity: log(m) + log(n) = O(log(nm))
 *  space complexity: O(1)
 */

void get_digits_arity(unsigned n, DigitRef r) {
    int d;
    while (n > 0) {
        d = n%10;
        ++r[d];
        n /= 10;
    }
    for (int i = 0; i < 11; ++i) {
        printf("%d ", r[i]);
    }
    putchar('\n');
}

void are_similar(unsigned n, unsigned m) {
    DigitRef r1 = {0}, r2 = {0};
    get_digits_arity(n, r1);
    get_digits_arity(m, r2);
    for (int i = 0; i < 11; ++i) {
        if (r1[i] != r2[i]) {
            printf("False\n");
            return;
        }
    }
    printf("True\n");
}

int main() {
    check_digits(9215);
    check_digits(121);
    check_digits(1234567890);
    are_similar(123412, 11234);
    are_similar(123412, 223411);
    are_similar(110, 101);
    return 0;
}
