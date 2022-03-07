/*
 *  Igor Krzywda
 *  Lista 4, zadanie 1
 */

#ifndef SET_H
#define SET_H

#include <stdio.h>

#define MAX_SET_SIZE 8000

typedef int Set[MAX_SET_SIZE];

void read_set(Set s);
void print_set(Set s);
void set_union(const Set s, const Set t, Set out);
void set_sym_diff(const Set s, const Set t, Set out);
void clear_set(Set s);
int search_set(Set s, int min, int max, int el);
void add_to_set(int el, Set s);
void remove_from_set(int el, Set s);

#endif
