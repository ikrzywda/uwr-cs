#include <stdio.h>
#include <math.h>

const int kPrimeArrLen = 10000;

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}

void find_pairs(int *primes, int len, int n) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i; j < len; ++j) {
            if ((primes[i] + primes[j]) == n) {
                printf("%d %d ", primes[i], primes[j]);
            }
        }
    }
}

int main() {
    int n, primes[kPrimeArrLen];
    scanf("%d", &n);
    if (n < 4 || n > 100000 || n % 2) {
        printf("NIEPOPRAWNA LICZBA");
    } else {
        int j = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime(i)) {
                primes[j++] = i;
            }
        }
        find_pairs(primes, j, n);
    }
}
