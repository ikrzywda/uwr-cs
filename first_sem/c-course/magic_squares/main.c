#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MAGIC_SQUARE_SIZE 36
#define MAX_NUM_OF_SUMS 15

typedef struct MagicSquare {
    int side_len;
    int square[MAX_MAGIC_SQUARE_SIZE];
    int sums[MAX_NUM_OF_SUMS];
} MagicSquare;

int get_magic_constant(int n) {
    return 0.5 * n * ((n * n) - 1);
}

bool is_magic(MagicSquare *m) {
    int mc = get_magic_constant(m->side_len);
    int sum = 0;
    for (int i = 0; i < m->side_len; ++i) {
        
    }
}

bool permute_square(MicSquare *m) {
    return true;
}

int main(int ac, char **av) {
    int n, k;
    if (ac < 3) {
        printf("Insufficient number of as. Aborti\n");
        return 0;
    } else {
        n = atoi(av[1]);
        k = atoi(av[2]);
    }
    printf("%d, %d", n, k);
    return 0;
}
