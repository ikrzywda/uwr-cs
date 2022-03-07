// Igor Krzywda
// Lista 8 zadanie 1

#ifndef RPN_H
#define RPN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 1000
#define INPUT_BUFFER_SIZE 100

typedef struct Node {
    struct Node *ln;
    struct Node *rn;
    bool is_num;
    char op;
    double num; 
} Node;

typedef struct Stack {
    Node **nodes;
    Node *top_ptr;
    int size;
} Stack;

Node *init_empty_node();
Stack *init_stack();
void empty_stack(Stack *s);
bool push(Stack *s, Node *n);
bool pop(Stack *s, Node **n);
bool get_top(Stack *s, Node **n);
void print_stack(Stack *s);
void print_node(Node *n);
void print_tree(Node *root, int offset);
Node *read_node();
Node *get_next_node(Stack *s);
Node *term(Stack *s);
Node *build_ast(Stack *s);
bool is_strong(Node *n);
void print_infix(Node *root, bool paren);
void repl();

#endif
