#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t n) {
	uint32_t mask = ~0;
	for (int i = 0; i < 32; ++i) {
		putchar((n << i) & ~(mask >> 1)  
			? '1' : '0');
	}
	putchar('\n');
}

// copy bit from ith position to kth position in variable x
uint32_t copy_bit(int i, int k, int x) {
    int offset = k - i; 
    if (!offset) return x;

    uint32_t mask_k = (1 << (32 - k)) ^ x;
    uint32_t mask_i = (1 << (32 - i)) & x;
    
    if (offset < 0) mask_i <<= -offset;
    else mask_i >>= offset;
    return mask_i ^ x;
}

uint32_t copy_bit_no_if(int i, int k, uint32_t x) {
    uint32_t tf_mask = ((1 << (32 - i)) & x) >> (32 - i);
    x &= (uint32_t)(~(1 << (32 - k)));
    return x | (tf_mask << (32 - k));
}

// Kernighan's algorithm 
// (https://www.techiedelight.com/brian-kernighans-algorithm-count-set-bits-integer/)
int count_set_bits_kgh(uint32_t x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

struct A {              // offsets:
    int8_t a;           // 0
    char padding_1[7];  // 
    void *b;            // 8
    int8_t c;           // 16
    char padding_2;     
    int16_t d;          // 18
    char padding[4];
};

struct B {              // offsets:
    uint16_t a;         // 0
    char padding[6];
    double b;           // 8
    void *c;            // 16
};

struct C {              // optimised struct A
    int8_t a;
    int8_t c; 
    int16_t d;
    void *b;
};

int main() {
    print_binary(0xFFFFFFFE);
    print_binary(copy_bit_no_if(32, 1, 0xFFFFFFFE));
    print_binary(copy_bit_no_if(32, 2, 0xFFFFFFFE));
}