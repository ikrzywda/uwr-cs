#include <stdio.h>
/*
decode: leaq (%rdi,%rsi), %rax
    xorq %rax, %rdi
    xorq %rax, %rsi
    movq %rdi, %rax
    andq %rsi, %rax
    shrq $63, %rax
    ret
*/


long decoded_fun(long x, long y) {
    long z = x + y;
    x ^= z;
    y ^= z;
    x &= y;
    x = (unsigned long)x >> 63;
    return x;
}

int main() {
    long x = decoded_fun(-100, 90);
    printf("7*5 = %ld\n", x);
    fflush(stdout);
}