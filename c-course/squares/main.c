#include <stdio.h>
#include <string.h>

#define MAX_SQUARE_SIDE_LEN 1000

typedef char SquareBuf[MAX_SQUARE_SIDE_LEN][MAX_SQUARE_SIDE_LEN];

void make_basic_square(int n, SquareBuf s) {
    int offset = 0;
    char filler = ((n/2)%2) ? 'o' : '#';
    for (; n > 0; --n) {
        for (int i = offset; i < n; ++i) {
            for (int j = offset; j < n; ++j) {
                s[i][j] = filler;
            }
        }
        ++offset;
        filler = (filler == '#') ? 'o' : '#';
    }
}

void make_diagonals(int n, SquareBuf s) {
    for (int i = 0; i < n; ++i) {
        s[i][i] = '#';
        s[i][n-i-1] = '#';
    }
}

void print_square(SquareBuf s) {
    int i = 0, j = 0;
    while (i < MAX_SQUARE_SIDE_LEN) {
        if (s[i][0] != '#' && s[i][0] != 'o') break;
        while (s[i][j] == '#' || s[i][j] == 'o') {
            putchar(s[i][j++]);
        }
        ++i;
        j = 0;
        putchar('\n');
    }
}

void make_square(int n) {
    SquareBuf s;
    memset(s, 0, sizeof(s));
    make_basic_square(n, s);
    make_diagonals(n, s);
    print_square(s);
}

int main() {
    unsigned n;
    scanf("%d", &n);
    if (!(n % 2)) {
        printf("ERROR");
        return 0;
    }
    make_square(n);
    return 0;
}
