#include <stdio.h>
#include <inttypes.h>

const int kIntSizeInBits = sizeof(int) * 8;

void int_print_in_binary(int n) {
	unsigned mask = ~0;

	for (int i = 0; i < kIntSizeInBits; ++i) {
		putchar((n << i) & ~(mask >> 1)  
			? '1' : '0');
	}

	putchar('\n');
}

int zero_kth_bit(int n, int k) {
	return n & (~(1 << (kIntSizeInBits - k - 1)));
}

int set_kth_bit_to_high(int n, int k) {
	return n | (1 << (kIntSizeInBits - k - 1));
}

int flip_kth_bit(int n, int k) {
	return n ^ (1 << (kIntSizeInBits - k - 1));
}

int multiply_by_kth_power_of_2(int n, int k) {
	return n << k;
}

int floor_of_division_by_kth_power_of_2(int n, int k) {
	return n >> k;	
}

int mod_of_division_by_kth_power_of_2(int n, int k) {
	return n - floor_of_division_by_kth_power_of_2(n, k);
}

int32_t inverse(int32_t n) {
	int_print_in_binary(1 << 31);
	int_print_in_binary(n ^ (~0u >> 1));
	return (((n << 31) ^ (1 << 31)) | (n >> 1)) & ~n;
}

int main() {
	for (int i = 0; i < kIntSizeInBits; ++i) {
		// int_print_in_binary(zero_kth_bit(~0, i));
		// int_print_in_binary(set_kth_bit_to_high(0, i));
		// int_print_in_binary(flip_kth_bit(0, i));
		//  printf("%d\n", multiply_by_kth_power_of_2(2, i));
		// printf("%d\n", floor_of_division_by_kth_power_of_2(10000, i));
		// printf("%d\n", mod_of_division_by_kth_power_of_2(10000, i));
		printf("%d\n", inverse(-100));
		int_print_in_binary(inverse(-100));
	}
}
