#include "list.h"

int main() {
    Node *n, *m, *k, *l;
    n = m = NULL;
    for (int i = 0; i < 5; ++i) {
        append(&n, i);
        append(&m, i + 5);
    }
    l = cpy(n);
    print_front(l);
    print_back(l);
    print_front(n);
    print_front(m);
    k = merge(n, m);
    print_front(k);
}

