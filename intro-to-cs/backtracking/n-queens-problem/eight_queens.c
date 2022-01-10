#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int *chess_board;

void init() {
    chess_board = malloc(sizeof(int) * n);
    memset(chess_board, -1, sizeof(int) * n);
}

void print_board() {
    for (int i = 0; i < n; ++i) {
        printf("(%d) ", chess_board[i]);
    }
    putchar('\n');
}

void print_chessboard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf(" %c ", (i == chess_board[j]) ? 'Q' : '*');
        }
        putchar('\n');
    }
    printf("\n\n\n");
}

int is_free(int col, int row) {
    for (int i = 0; i < col; ++i) {
        if (chess_board[i] == row || (chess_board[i] + i) == (row + col) ||
                (chess_board[i] - i) == (row - col)) {
            return 0;
        }
    }
    return 1;
}

int queens_count() {
    int k = 1, count = 0;
    chess_board[0] = 0;

    while (k >= 0) {
        if (k == n) {
            count++;
            chess_board[--k]++;
            print_chessboard();
        }
        do {
            chess_board[k]++;
        } while (chess_board[k] < n && !is_free(k, chess_board[k]));
       
        if (chess_board[k] < n) {
            ++k;
        } else {
            chess_board[k] = -1; --k;
        }

    }
    return count;
}

int queens() {
    int k = 1;
    chess_board[0] = 0;

    while (k < n && k >= 0) {
        do {
            chess_board[k]++;
            print_board();
            print_chessboard();
        } while (chess_board[k] < n && !is_free(k, chess_board[k]));
       

        if (chess_board[k] < n) {
            ++k;
        } else {
            chess_board[k] = -1; --k;
        }
    }
    return k;
}

int main(int argc, char **argv) {
    sscanf(argv[1], "%d", &n);
    printf("%d\n", n);
    init();
    //printf("queens() = %d\n", queens());
    //print_chessboard();
    printf("solution_count() = %d", queens_count());
    free(chess_board);
    return 0;
}
