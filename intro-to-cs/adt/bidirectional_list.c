#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev, *next;
    int value;
} Node;

void print_list(Node *list) {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }
    while (list != NULL) {
        printf("%4d ", list->value);
        list = list->next;
    }
    putchar('\n');
}

Node *init_node(int val) {
    Node *n = malloc(sizeof(Node));
    n->prev = n->next = NULL;
    n->value = val;
    return n;
}

void append(Node **list, int val) {
    Node *new_node = init_node(val);
    Node *l = *list;

    if (*list == NULL) {
        *list = new_node;
    }
    
    while (l->next != NULL) {
        l = l->next;
    }
    new_node->prev = l;
    l->next = new_node;
}

int pop_front(Node **list) {
    Node *temp = *list;
    int val;
    *list = (*list)->next;
    (*list)->prev = NULL;
    val = temp->value;
    free(temp);
    return val;
}

int main() {

    Node *n = init_node(10);
    
    for (int i = 0; i < 10; ++i) {
        append(&n, (i%2) ? -i : i);
    }

    print_list(n);
    pop_front(&n);
    pop_front(&n);
    print_list(n);
    return 0;
}
