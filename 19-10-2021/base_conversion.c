#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned long long int ull;

const unsigned kIoLen = 100; // input length

/*  input: n,p,q
 *  n - number in base of p
 *  p - base of n
 *  q - target base of n
 *  
 *  2 <= p,q <= 36
 *
 *  output: n in base of q
 */

ull digits_to_num(unsigned base, char *n_str) {
    char c;
    unsigned power = strlen(n_str) - 1;
    unsigned sv, msv = (base > 10) ? 'A' + (base - 11) : '0' + base - 1;
    ull out = 0;
    while ((c = *(n_str++)) != '\0') {
        sv = (c - '0') > 10 ? c - 'A' + 10 : (c - '0');
        if (sv > msv) {
            return 0;
        }
        out += sv * pow(base, power);
        --power;
    }
    return out;
}

int digits_to_new_base(unsigned base, ull num, char *out) {
    if (base > 36) {
        return -1;
    }
    char temp[kIoLen];
    unsigned i = 0, r;
    while (num > 0) {
        temp[i++] = (r = num % base) > 10 ? 'A' + (r - 10) : '0' + r;
        num /= base;
    }
    for (unsigned j = 0; j < i; ++j) {
        out[i - 1 - j] = temp[j];
    }
    return 1;
}

int main() {
    char n_str[kIoLen], out[kIoLen];
    unsigned p, q;
    printf("Enter a number (n) in source base (p) to convert it to target base (q). \
            \n\rEach argument is seperated by one space\n\n");
    scanf("%u %u %s", &p, &q, n_str);
    ull num_repr = digits_to_num(p, n_str);
    digits_to_new_base(q, num_repr, out);
    printf("\n\n\tn in the base of %d: %s (%Lu in decimal)\n \
            \r\tn in the base of %d: %s\n", 
            p, n_str, num_repr, q, out);
}
