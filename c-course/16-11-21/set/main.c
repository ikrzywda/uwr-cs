/*
 *  Igor Krzywda
 *  Lista 4, zadanie 1
 */

#include "set.h"

int main() {
    Set s,t,u;
    read_set(s);
    read_set(t);
    print_set(s);
    print_set(t);
    set_sym_diff(s, t, u);
    print_set(u);
    add_to_set(4, u);
    print_set(u);
    remove_from_set(10, u);
    print_set(u);
    clear_set(u);
    print_set(u);
}
