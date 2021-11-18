#include <stdio.h>

#define MAX_SQUARE_SIDE_LEN 1001

typedef char SquareBuffer[MAX_SQUARE_SIDE_LEN][MAX_SQUARE_SIDE_LEN];

int read_side_len() {
    int n;
    scanf("%d", &n);
    return (n % 2) ? n : -1;
}

void generate_template(SquareBuffer s, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = '#';
        }
    }
}

void print_template(SquareBuffer s, int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            putchar(s[j][i]);
        }
        putchar('\n');
    }
}

int main() {
    int n;
    if ((n = read_side_len()) < 0) {
        printf("ERROR");
        return 0;
    }
    SquareBuffer s;
    generate_template(s, n, n);
    print_template(s, n);
}
