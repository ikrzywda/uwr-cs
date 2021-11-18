/*
 *  Igor Krzywda
 *  lista 3, zadanie 2
 *
 *  Argument 'c' pozwala na ewaluowanie kodu C pod względem
 *  zamknięcia nawiasów (pomijanie komentarzy i definicji 
 *  znaków oraz stringów
 */

#include "parenths.h"

/*
 *  TextData = {
 *      [0] = <kolumna>,
 *      [1] = <wiersz>,
 *      [2] = <liczba zagnieżdżonych '('>
 *      [3] = <liczba zagnieżdżonych '['>
 *      [4] = <liczba zagnieżdżonych '{'>
 *  }
 */

void throw_error(char paren, TextData pos) {
    printf("'%c' unmatched at (%d,%d)\n", 
            paren, pos[0], pos[1]);
}

int get_next_paren(TextData t) {
    int c;
    while ((c = getchar()) != EOF) {
        ++t[0];
        if (c == '\n') {
            t[0] = 0; ++t[1];
        } else if (c == '(' || c == ')' || c == '['
                    || c == ']' || c == '{' || c == '}') {
            return c;
        } 
    }
    return EOF;
}

void skip_multiline_comment(TextData t) {
    int c, prev;
    while ((c = getchar()) != EOF) {
        if (c == '*') {
            prev = 1;
        } else if (prev && c == '/') {
            return;
        } else if (c == '\n') {
            ++t[1];
        } else {
            prev = 0;
        }
    }
}

void skip_comment(TextData t) {
    int c = getchar();
    if (c == '*') {
        skip_multiline_comment(t);
    } else if (c == '/') {
        while ((c = getchar() != EOF) && c != '\n') continue;
        ++t[1];
    }
}

void skip_char_def() {
    int c;
    while ((c = getchar()) != EOF && c != '\'') {
        if (c == '\\') getchar();
    }
}

void skip_str_def() {
    int c;
    while ((c = getchar()) != '\"' && c != EOF) 
        if (c == '\\') getchar();
}

int get_next_paren_c(TextData t) {
    int c;
    while ((c = getchar()) != EOF) {
        ++t[0];
        if (c == '\n') {
            t[0] = 0; ++t[1];
        } else if (c == '(' || c == ')' || c == '['
                    || c == ']' || c == '{' || c == '}') {
            return c;
        } else if (c == '/') {
            skip_comment(t);
        } else if (c == '\'') {
            skip_char_def();
        } else if (c == '\"') {
            skip_str_def();
        }
    }
    return EOF;
}

int compare_parens(char p1, char p2) {
    if (p1 - p2 > 2) return 1;
    return 0;
}

char opposite_paren(char paren) {
    switch(paren) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default: 
            return '\0';
    }
    return '\0';
}

int index_for_paren(char c) {
    if (c == '(' || c == ')') {
        return 2;
    } else if (c == '[' || c == ']') {
        return 3;
    } else if (c == '{' || c == '}') {
        return 3;
    }
    return -1;
}

int nesting(char c, TextData t) {
    return t[index_for_paren(c)];
}

void change_nesting(int i, char c, TextData t) {
    t[index_for_paren(c)] += i;
}

void find_pair(char p, TextData t) {
    int c, target = opposite_paren(p);
    unsigned row = t[0], col = t[1];
    while ((c = get_next_paren(t)) != EOF) {
        if (c == target) {
            return; 
        } else if (c == '(' || c == '[' || c == '{') {
            change_nesting(1, p, t);
            find_pair(c, t);
        } else if (!nesting(c, t)) {
            throw_error(c, t);
        } else {
            change_nesting(-1, c, t);
        }
    }
    TextData error_data = {[0] = row, [1] = col};
    throw_error(p, error_data);
}

void find_pair_c(char p, TextData t) {
    int c, target = opposite_paren(p);
    unsigned row = t[0], col = t[1];
    while ((c = get_next_paren_c(t)) != EOF) {
        if (c == target) {
            return; 
        } else if (c == '(' || c == '[' || c == '{') {
            change_nesting(1, p, t);
            find_pair_c(c, t);
        } else if (!nesting(c, t)) {
            throw_error(c, t);
        } else {
            change_nesting(-1, c, t);
        }
    }
    TextData error_data = {[0] = row, [1] = col};
    throw_error(p, error_data);
}

void process_parens() {
    int c;
    TextData t = {[1] = 1};
    while ((c = get_next_paren(t)) != EOF) {
        if (c == ')' || c == ']' || c == '}') {
            throw_error(c, t);
        } else {
            find_pair(c, t);
        }
    }
}

void process_parens_in_c_source() {
    int c;
    TextData t = {[1] = 1};
    while ((c = get_next_paren_c(t)) != EOF) {
        if (c == ')' || c == ']' || c == '}') {
            throw_error(c, t);
        } else {
            find_pair_c(c, t);
        }
    }
}

