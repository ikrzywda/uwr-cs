#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void my_twos_complement(int n, int byte_count) {
    char *out = calloc(byte_count, 1);
    int sign = -1, b = byte_count;
    int i = 0;
    if (n > 0) {
        sign = 1;
        b = byte_count - 1;
    }
    if (n < pow(2, b)) {
        printf("Cannot represent the number\n");
        return;
    }
    n *= sign;
    while (n > 0) {
        out[i++] = n % 2;
        n /= 2;
    }
    for (int j = i, k = 0; j < byte_count; ++j, ++k) {
        out[j] = out[byte_count - k];
    }
    if (sign < 0) {
        for (int j = 0; j < byte_count; ++j) {
            out[j] = (!out[j]) ? 1 : 0;
        }
        if (out[byte_count] == 0) {
            out[byte_count] = 1;
        } else {
            i = byte_count;
            while (!out[i]) {
                out[i] = 0;
                --i;
            }   
            out[i] = 1;
        }
    }
    for (int j = 0; j < byte_count; ++j) {
        out[j] += '0';
    }
    printf("%s", out); 
}   

int z(int n) {
    int a = 1, b = n, s;
    while (b - a > 0) {
        s = (a + b) / 2;
        if (s * s == n) return s;
        if (s * s > n) b = s;
        else a = s + 1;
    }
    return b;
}

int main() {
    printf("10: %d\n", z(10));
    printf("8: %d\n", z(8));
    printf("16: %d\n", z(16));
    printf("21: %d\n", z(21));
    printf("64: %d\n", z(64));
    printf("256: %d\n", z(256));
}
