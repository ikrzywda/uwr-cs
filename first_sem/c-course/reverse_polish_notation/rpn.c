// Igor Krzywda
// Lista 8 zadanie 1

#include "rpn.h"

Node *init_empty_node() {
    Node *n = malloc(sizeof(Node));
    return n;
}

Stack *init_stack() {
    Stack *s = malloc(sizeof(Stack));
    s->nodes = malloc(sizeof(Node*) * STACK_SIZE);
    s->top_ptr = s->nodes[0];
    s->size = 0;
    return s;
}

void empty_stack(Stack *s) {
    s->size = 0;
    s->top_ptr = s->nodes[0];
}

bool push(Stack *s, Node *n) {
    if (s->size < STACK_SIZE) {
        s->nodes[s->size] = n;
        s->top_ptr = s->nodes[s->size++];
        return true;
    } 
    return false;
}

bool pop(Stack *s, Node **n) {
    if (s->size > 0) {
        *n = s->nodes[--s->size]; 
        return true;
    }
    return false;
}

bool get_top(Stack *s, Node **n) {
    if (s->size > 0) {
        *n = s->nodes[s->size - 1]; 
        return true;
    }
    return false;

}

void print_node(Node *n) {
    if (n->is_num) {
        printf(" %.2f ", n->num);
    } else {
        printf(" %c ", n->op);
    }
}

void print_stack(Stack *s) {
    for (int i = 0; i < s->size; ++i) {
        print_node(s->nodes[i]);
    }
}

void print_tree(Node *root, int offset){
    if(root == NULL) return;
    putchar('|');
    for (int i = 0; i < offset; ++i) {
        putchar('-');
    }
    putchar('[');
    print_node(root);
    putchar(']');
    putchar('\n');
    print_tree(root->ln, offset + 4);
    print_tree(root->rn, offset + 4);
}

Node *init_node_with_num(double num) {
    Node *n = malloc(sizeof(Node));
    n->is_num = true;
    n->num = num;
    return n;
}

Node *init_node_with_op(char op) {
    Node *n = malloc(sizeof(Node));
    n->is_num = false;
    n->op = op;
    return n;
}

Node *read_node() {
    char buffer[INPUT_BUFFER_SIZE], c;
    int i = 0;
    double num;
    char op;
    while ((c = getchar()) != ' ' && c != '=' && c != '\n') {
        buffer[i++] = c;
    }
    if (i == 0) return NULL;
    buffer[i] = '\0';
    if ((sscanf(buffer, "%lf", &num)) > 0) {
        return init_node_with_num(num);
    } else if ((sscanf(buffer, "%c", &op)) > 0) {
        return init_node_with_op(op);
    }
    return NULL;
}

Node *get_next_node(Stack *s) {
    Node *n;
    if (!pop(s, &n)) {
        printf("Error:\n* there should be one white space between tokens\n\
                \r* check the correctness of the expression\n");
        exit(1);
    }
    return n;
}

Node *term(Stack *s) {
    Node *new_node, *n;
    new_node = get_next_node(s);
    get_top(s, &n);
    if (!n->is_num) {
        new_node->ln = term(s);
    } else {
        new_node->ln = n;
        pop(s, &n);
    }
    get_top(s, &n);
    if (!n->is_num) {
        new_node->rn = term(s);
    } else {
        new_node->rn = n;
        pop(s, &n);
    }
    return new_node;
}

bool is_strong(Node *n) {
    if (n->op == '*' || n->op == '/') {
        return true;
    }
    return false;
}

void print_infix(Node *root, bool paren) {
    if (root->is_num) {
        print_node(root);
        return;
    }
    bool parenthasize = is_strong(root) ? true : false;
    if (paren == true && !is_strong(root)) {
        putchar('(');
    }
    print_infix(root->rn, parenthasize);
    print_node(root);
    print_infix(root->ln, parenthasize);
    if (paren == true && !is_strong(root)) {
        putchar(')');
    }
}

void repl() {
    Stack *s = init_stack();
    Node *AST_root, *n;
    printf("REPL mode. Use CTRL+C to quit\n");
    while (1) {
        empty_stack(s);
        while ((n = read_node()) != NULL) {
            push(s, n); 
        }
        AST_root = term(s);
        print_tree(AST_root, 0);
        print_infix(AST_root, false);
        putchar('\n');
    }
}
