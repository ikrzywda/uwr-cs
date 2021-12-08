#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    struct node *prev;
    struct node *next;
    double info;
} Node;

Node *init(double val);
bool append(Node **head, double val);
bool prepend(Node **head, double val);
bool is_empty(Node **head);
void print_node(Node *n);
void print_front(Node *head);
void print_back(Node *head);
bool pop_front(Node **head, double *result);
bool pop_back(Node **head, double *result);
unsigned length(Node *head);
bool insert(Node **head, double val, unsigned index);

#endif
