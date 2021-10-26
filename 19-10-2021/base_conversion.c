#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* input p,q,n
 *
 * n - number expressed in in base of p
 * q - base n is to be converted to
 *
 */


typedef long long unsigned int llu;

int convert_symbols(unsigned base, char *num_str, int *output) {
    char c, mnc = base > 10 ? 'A' + (base - 11) : '0' + base - 1;    // maximum ASCII value for expressing a number
    printf("\n%c\n", mnc);
    while ((c = *(num_str++)) != '\0') {
        if (c > mnc) {
            return 0;
        }
        *(output++) = ((c - '0') > 10) ? c - 'A' + 10 : (c - '0');
    }
    *(output++) = -1;
    return 1;
}

void print_converted_symbols(int *syms) {
    int n;
    while ((n = *(syms++)) >= 0) {
        printf("%d ", n);
    }
    putchar('\n');
}

llu convert_to_dec(int base, int *syms) {
    int n, pow;
    llu output = 0;
    while ((n = *(syms++)) >= 0) {
        output += pow(
    }
}

int main() {
    unsigned base;
    char num_str[30];
    int nums[30];
    scanf("%u %s", &base, num_str);
    printf("%d, %s\n", base, num_str);
    printf("%s", convert_symbols(base, num_str, nums) ? "true" : "false");
    print_converted_symbols(nums);
    return 0;
}
