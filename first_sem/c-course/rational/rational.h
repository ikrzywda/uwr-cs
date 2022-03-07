/*
 *  Lista 4, zadanie 2
 *  Igor Krzywda
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdio.h>
#include <stdlib.h>

typedef long long int Rational;

int gcd(int a, int b);
int lcm(int a, int b);

Rational new_rational(int num, int den);
Rational read_rational();

int get_denominator(Rational r);
int get_numerator(Rational r);
void print_rational(Rational r);

void reduce_to_common_denominator(Rational *a, Rational *b);
Rational add_rational(Rational a, Rational b);
Rational sub_rational(Rational a, Rational b);
Rational div_rational(Rational a, Rational b);
Rational mult_rational(Rational a, Rational b);

#endif
