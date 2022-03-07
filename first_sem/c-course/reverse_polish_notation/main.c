// Igor Krzywda
// Lista 8 zadanie 1

#include "rpn.h"

int main() {
    Stack *s = init_stack();
    Node *n;
    while ((n = read_node()) != NULL) {
        push(s, n); 
    }
    Node *AST_root = term(s);
    printf("AST:\n");
    print_tree(AST_root, 0);
    printf("infix notation:\n");
    print_infix(AST_root, false);
}
