#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
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
    Node *node = malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}

void insert(Node **list, int val) {
    Node *l = *list;
    Node *new_node = init_node(val);
    if (l == NULL) return;

    if (l->value >= val) {
        new_node->next = l; 
        *list = new_node;
        return;
    }

    while (l->next != NULL && l->next->value < val) {
        l = l->next;
    }

    new_node->next = l->next;
    l->next = new_node;

}

// ex. 10
Node *merge_in_order(Node *l1, Node **l2) {

    if (l1 == NULL) return *l2;

    Node *ins_node = *l2, *ins_node_t, *temp = l1;

    while (ins_node->next != NULL) {
        ins_node_t = ins_node;
        ins_node = ins_node->next;

        if (temp->value >= ins_node->value) {
            ins_node_t->next = temp;
            l1 = ins_node_t;
        } else {
            while (temp->next != NULL && temp->next->value < ins_node_t->value) {
                temp = temp->next;
            }
            ins_node_t->next = temp->next;
            temp->next = ins_node_t; 
        }
        temp = l1;
    }

    *l2 = NULL;

    return l1;
}

int main() {
    Node *n = init_node(10), *n2 = init_node(21);
    int x, y;

    for (int i = 0; i < 10; ++i) {
        x = rand() % 100; 
        y = rand() % 100; 
        insert(&n, x);
        insert(&n2, y);
    }
    putchar('\n');
    print_list(n);
    print_list(n2);
    n = merge_in_order(n, &n2);
    print_list(n);
}
