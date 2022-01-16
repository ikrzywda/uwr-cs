#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


typedef struct List {
    Node *head;
    Node *tail;
} List;

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
}

List *init_list(int val) {
    List *list = malloc(sizeof(List));
    Node *node = malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    list->tail = node;
    list->head = node;
    return list;
}

// ex. 5
List *append(List *list, int val) {
    if (list == NULL || list->tail == NULL) {
        return NULL;
    }
    Node *new_node = init_node(val);
    list->tail->next = new_node;
    list->tail = new_node;

    return list;
}

// ex. 5
List *merge_lists(List *l1, List **l2) {
    if (l1 == NULL) return NULL;

    l1->tail->next = (*l2)->head;
    (*l2)->head = NULL;
    (*l2)->tail = NULL;
    free(*l2);
    *l2 = NULL;

    return l1;
}

int main() {
    List *n = init_list(10);
    List *n2 = init_list(20);
    for (int i = 0; i < 10; ++i) {
        n = append(n, i);
        n2 = append(n2, i);
    }
    print_list(n->head);
    print_list(n2->head);

    n = merge_lists(n, &n2);
    print_list(n->head);
}
