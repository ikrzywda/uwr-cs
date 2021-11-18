#include <stdio.h>

#define MAX_SQUARE_SIDE_LEN 11

typedef char SquareBuffer[MAX_SQUARE_SIDE_LEN][MAX_SQUARE_SIDE_LEN];

int read_side_len() {
    int n;
    scanf("%d", &n);
    return (n % 2) ? n : -1;
}

void generate_template(SquareBuffer s, int n, int m) {
    if (n < 1) return;
    char c = (((n / 2) - 1) % 2) ? '#' : 'o';
    for (int i = m - n; i < n; ++i) {
        s[i][m-n] = c;
        s[m-n][i] = c;
        s[n-i-1][n-1] = c;
        s[n-1][n-i-1] = c;
    }
    generate_template(s, n-2, m);
}

void print_template(SquareBuffer s, int n) {
    for (int j = 0; j < MAX_SQUARE_SIDE_LEN; ++j) {
        for (int i = 0; i < MAX_SQUARE_SIDE_LEN; ++i) {
            if (s[j][i] != '#') {
                putchar(' ');
            } else {
                putchar('#');
            }
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
