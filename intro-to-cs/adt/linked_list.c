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

// ex. 1
void append(Node *list, int val) {
    if (list == NULL) {
        return;
    }
    Node *new_node = init_node(val);
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = new_node;
}

// ex.2
int pop(Node *list) {
    int val;
    Node *prev_node;

    while (list->next != NULL) {
        prev_node = list;
        list = list->next;
    }

    val = list->value;
    prev_node->next = NULL; 
    free(list);
    return val;
}


// ex.3
void merge_lists(Node *l1, Node **l2) {
    if (l1 == NULL) return;

    while (l1->next != NULL) {
        l1 = l1->next;
    }
    
    l1->next = *l2;
    *l2 = NULL;
}

void free_list(Node **list) {
    Node *temp;
    Node *l = *list;

    while (l != NULL) {
        temp = l;
        l = l->next;
        free(temp);
    }
    *list = NULL;
}

// ex. 4
void pop_key(Node **list, int val) {
    Node *prev = NULL, *temp, *l = *list;
    // Node *ret = list;
    while (l != NULL) {
        temp = l;
        l = l->next;
        if (temp->value == val) {
            if (prev != NULL) {
                prev->next = l; 
            } else {
                *list = l;
                // ret = l
            }
            free(temp);
        } else {
            prev = temp;
        }
    }
    // return ret;
}


// ex. 6
void print_in_reverse(Node *list) {
    if (list == NULL) return;
    if (list->next == NULL) {
        printf("%4d", list->value);
        return;
    } else {
        print_in_reverse(list->next);
    }
    printf("%4d", list->value);
}


// ex. 7
void reverse_list(Node **head, Node *node) {
    if (node == NULL || *head == NULL) return;
    Node *temp = NULL;
    if (node->next == NULL) {
        (*head)->next = NULL;
        *head = node;
        return;
    } else {
        temp = node->next;
        reverse_list(head, node->next);
    }
    temp->next = node;
}

// ex. 8
int split_wr_sign(Node **list, Node **pos, Node **neg) {
    Node *p, *n, *temp, *l = *list;
    if (l == NULL) return 0;

    p = *pos = malloc(sizeof(Node));
    n = *neg = malloc(sizeof(Node));

    while (l != NULL) {
        temp = l;
        l = l->next;
        if (temp->value < 0) {
            n->next = temp;
            n = n->next;
        } else if (temp->value > 0) {
            p->next = temp;
            p = p->next;
        } else {
            free(temp);
        }
    }

    n->next = p->next = NULL;
    p = *pos; n = *neg;
    *pos = (*pos)->next; *neg = (*neg)->next;

    free(p);
    free(n);
    *list = NULL;

    return 1;
}

int main() {
    Node *n = init_node(10);
    Node *n2 = init_node(20);
    Node *neg, *pos;
    for (int i = 0; i < 10; ++i) {
        append(n, (i%2) ? -i : i);
        append(n2, i);
    }
    print_list(n);
    print_list(n2);
    for (int i = 0; i < 5; ++i) {
        printf("POPPED: %d\n", pop(n));
    }
    print_list(n);
    //print_in_reverse(n);
    //putchar('\n');
    print_list(n);
    reverse_list(&n, n);
    print_list(n);

    if (split_wr_sign(&n, &pos, &neg)) {
        print_list(pos);
        print_list(neg);
    }

    /*merge_lists(n, &n2);
    print_list(n);
    pop_key(&n, 2);
    print_list(n);
    pop_key(&n, 10);
    print_list(n);
    pop_key(&n, 9);
    print_list(n);
    free_list(&n);
    print_list(n);
    print_list(n2);*/
    return 0;
}
