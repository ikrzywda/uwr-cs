
/*
 *  Lista 4, zadanie 2
 *  Igor Krzywda
 */

#include "rational.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    int d = gcd(abs(a), abs(b));
    return (abs(a) * abs(b) / d) * (((a * b) < 0) ? -1 : 1); 
}

Rational new_rational(int num, int den) {
    if (den == 0) {
        printf("\nError: cannot divide by zero. Aborting.\n");
        exit(1);
    }
    int div;
    int sign = ((num * den) < 0) ? -1 : 1;
    num = abs(num);
    den = abs(den);
    div = gcd(num, den);
    num /= div;
    den /= div;
    num *= sign;
    Rational r;
    r = num;
    r <<= 32;
    r |= den;
    return r;
}

Rational new_rational_raw(int num, int den) {
    Rational r;
    r = num;
    r <<= 32;
    r |= den;
    return r;
}

Rational read_rational() {
    int num, den;
    scanf("%d %d", &num, &den);
    return new_rational(num, den);
}


int get_denominator(Rational r) {
    Rational mask = ((~0l) >> 32);
    return r & mask;
}

int get_numerator(Rational r) {
    Rational mask = ((~0l) >> 32);
    r >>= 32;
    return r & mask;
}

void print_rational(Rational r) {
    printf("%d / %d\n", get_numerator(r), get_denominator(r));
}

void reduce_to_common_denominator(Rational *a, Rational *b) {
    int na = get_numerator(*a), 
        nb = get_numerator(*b),
        da = get_denominator(*a),
        db = get_denominator(*b);
    int l = lcm(da, db);
    *a = new_rational_raw(na * (l/da), da * (l/da));
    *b = new_rational_raw(nb * (l/db), db * (l/db));
}

Rational add_rational(Rational a, Rational b) {
    reduce_to_common_denominator(&a, &b);
    return new_rational((get_numerator(a) + get_numerator(b)), 
            get_denominator(a));
}

Rational sub_rational(Rational a, Rational b) {
    reduce_to_common_denominator(&a, &b);
    return new_rational((get_numerator(a) - get_numerator(b)), 
            get_denominator(a));
}

Rational mult_rational(Rational a, Rational b) {
    int na = get_numerator(a), 
        nb = get_numerator(b),
        da = get_denominator(a),
        db = get_denominator(b);
    return new_rational(na * nb, da * db); 
}

Rational div_rational(Rational a, Rational b) {
    int na = get_numerator(a), 
        nb = get_numerator(b),
        da = get_denominator(a),
        db = get_denominator(b);
    if (na == 0) {
        printf("cannot divide by zero. Aborting.\n");
        exit(1);
    }
    return new_rational(na * db, da * nb); 
}
