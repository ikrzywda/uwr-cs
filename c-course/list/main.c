#include "list.h"

int main() {
    Node *n = init(10);
    double x;
    append(&n, 11);
    append(&n, 12);
    append(&n, 13);
    append(&n, 14);
    prepend(&n, 90);
    prepend(&n, 50);
    printf("len: %d\n", length(n));
    print_front(n);
    pop_front(&n, &x);
    printf("Result: %.2f\n", x);
    printf("len: %d\n", length(n));
    print_front(n);
    pop_back(&n, &x);
    printf("Result: %.2f\n", x);
    printf("len: %d\n", length(n));
    insert(&n, 45, 2);
    print_front(n);
    print_back(n);
}
