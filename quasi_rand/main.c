#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_num(int *num_str) {
    for (int j = 0; num_str[j] != EOF; ++j) {
        printf("%d ", num_str[j]);
    }
    putchar('\n');
}

void convert_bases(int base, int n, int *num_str) {
    int i = 0;
    while (n > 0) {
        num_str[i++] = n % base;
        n /= base;
    }
}

void offset(int *num_str, int len) {
    int num_str_cpy[1000];
    int l = 0, offset;
    while (num_str[l++] != EOF);
    offset = len - l;
    for (int i = 0; i < 1000; ++i) {
       num_str_cpy[i] = num_str[i];
    }
    for (int i = 0; num_str_cpy[i] != EOF; ++i) {
        num_str[i+offset] = num_str_cpy[i];
        num_str[i] = 0;
    }
    print_num(num_str);
}

void reverse(int *num_str, int len) {
    int temp;
    for (int i = 0; i < len/2; ++i) {
        temp = num_str[i];
        num_str[i] = num_str[len-i-1];
        num_str[len-i-1] = temp;
    }
    for (int i = 0; i < len; ++i) {
        if (num_str[i] == EOF) {
            num_str[i] = 0;
        }
    }
}

int rnd(int *num_str, int base) {
    int i = 0, out = 0, n;
    while ((n = num_str[i]) != EOF) {
        out += n * pow(base, i);
        ++i;
    }
    return out;
}

int qrand(int base, int len, int seed) {
    int num_str[1000] = {[0 ... 999] = EOF};
    convert_bases(base, seed, num_str);
    reverse(num_str, len);
    return rnd(num_str, base);
}

void print_row(int len, int x) {
    for (int i = 0; i < len; ++i) {
        printf("%c", (i == x) ? 'X' : '.');
    }
    putchar('\n');
}

void print_squares(int base, int len, int n) {
    int r;
    for (int i = 0; i < n; ++i) {
        r = qrand(base, len, i % (int)pow(base, len)) % n; 
        print_row(n, r);
    }
    putchar('\n');
    for (int i = 0; i < n; ++i) {
        print_row(n, rand() % n);
    }
}

int main() {
    int base, len, n;
    srand(0);
    scanf("%d %d", &base, &len);
    if (scanf("%d", &n) == EOF) {
        n = pow(base, len);
    }
    print_squares(base, len, n);
    return 0;
}
