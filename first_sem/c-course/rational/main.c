/*
 *  Lista 4, zadanie 2
 *  Igor Krzywda
 */

#include <stdio.h>
#include <math.h>
#include "rational.h"

int main() {
    Rational r = read_rational();
    print_rational(r);
    Rational r1 = read_rational();
    print_rational(r1);
    Rational r2 = add_rational(r, r1);
    print_rational(r2);
    r2 = sub_rational(r, r1);
    print_rational(r2);
    r2 = mult_rational(r, r1);
    print_rational(r2);
    r2 = div_rational(r, r1);
    print_rational(r2);
    printf("r1:\n numerator: %d, denumerator: %d\n", 
            get_numerator(r), get_denominator(r));

}
