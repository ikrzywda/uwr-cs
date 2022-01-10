#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int **square;
int backtrack = ~(1u)>>1;

void print_square() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", square[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void init_square() {
    square = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        square[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j) {
            square[i][j] = (rand() - (RAND_MAX / 2)) % 100;
        }
    }
}

int start_val() {
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += square[i][0];
    }
    printf("%d ", sum);
    for (int j = 0; j < n; ++j) {
        sum += square[n-1][j];
    }
    printf("%d ", sum);
    return sum;
}

int compute_cost(int x, int y, int net_cost, int min_cost) {  
    int d_cost, l_cost;
    
    if (x == y && x == n - 1) {
        return net_cost + square[x][y];
    }

    if (x < n && y < n) {
        net_cost += square[x][y];
    } else {
        return backtrack;
    }

    if (net_cost > min_cost) {
        return backtrack;
    }
    
    d_cost = compute_cost(x + 1, y, net_cost, min_cost);
    l_cost = compute_cost(x, y + 1, net_cost, min_cost);
    
    return d_cost < l_cost ? d_cost : l_cost;
}

int main(int argc, char **argv) {
    printf("%d\n", ~1u>>1);
    sscanf(argv[1], "%d", &n);
    init_square();
    square[0][0] = 10;
    square[0][1] = 9;
    square[0][2] = -21;
    square[1][0] = 21;
    square[1][1] = 7;
    square[1][2] = 8;
    square[2][0] = 13;
    square[2][1] = 14;
    square[2][2] = 10;
    print_square();
    printf("%d", start_val());
    printf("\n\n%d", compute_cost(0, 0, 0, start_val()));
}
