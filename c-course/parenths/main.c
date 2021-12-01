/*
 *  Igor Krzywda
 *  lista 3, zadanie 2
 *
 *  Argument 'c' pozwala na ewaluowanie kodu C pod względem
 *  zamknięcia nawiasów (pomijanie komentarzy i definicji 
 *  znaków oraz stringów
 */

#include "parenths.h"

int main(int argc, char **argv) {
    if (argc > 1 && argv[1][0] == 'c') {
        process_parens_in_c_source();
    } else {
        process_parens();
    }
    return 0;
}
