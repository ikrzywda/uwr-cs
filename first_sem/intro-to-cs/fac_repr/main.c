#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fac_repr(int n) {
    int out[100] = {0};
    int i = 0;
    int j = 1;
    while (n > 0) {
        out[i] = n % j;
        n /= j;
        ++j; ++i;
    }
    for (--i; i > 0; --i) {
        printf("%d ", out[i]);
    }
}

int g(int n) {
    if (n <= 3) return 1;
    int g_buf[4] = {1,1,1,1};
    for (int i = 3; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            g_buf[j] = g_buf[j+1];
        }
        g_buf[3] = g_buf[0] + g_buf[1] + g_buf[2];
    }
    return g_buf[3];
}

// zad 4 result 486
int t_rec(int n, int m) {
    if (n >= 0 && !m) return n;
    if (!n && m >= 0) return m;
    else return t_rec(n - 1, m) + 2 * t_rec(n, m - 1);
}


// zad 7 result 486
int z2(int n, int m) {
    if (n == 1 && m > 1) return -1;
    int i = 0;
    while (m > 0) {
        m /= n;
        ++i;
    }
    return i;
}

int main() {
    int m,n,k,check;
    for (int i = 0; i < 20; ++i) {
        n = rand() % 10 + 2;
        m = rand();
        k = z2(n,m);
        printf("n = %d, m = %d, k = %d, n^k = %d n^(k-1) = %d\t n^(k-1) > n: %s\n", n, m, k, (int)pow(n,k), (int)pow(n,k-1),
                ((int)(pow(n,k-1)) > n) ? "False" : "True");
    }
    printf("\n\n%d", t_rec(3,4));
}
