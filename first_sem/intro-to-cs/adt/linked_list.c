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
Node *append(Node *list, int val) {
    Node *new_node = init_node(val);
    Node *l = list;
    if (list == NULL) {
        return new_node;
    }
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = new_node;
    return list;
}

// ex.2
Node *pop(Node *list) {
    Node *prev_node, *l = list;

    if (list == NULL) return NULL;
    if (list->next == NULL) {
        free(list);
        return NULL;
    }

    while (l->next != NULL) {
        prev_node = l;
        l = l->next;
    }

    prev_node->next = NULL; 
    free(l);
    return list;
}


// ex.3
Node *merge_lists(Node *l1, Node **l2) {

    Node *temp = l1;

    if (l1 == NULL) {
        return *l2;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = *l2;
    *l2 = NULL;
    return l1;
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
Node *pop_key(Node *list, int val) {
    Node *prev = NULL, *temp, *l = list;
    while (l != NULL) {
        temp = l;
        l = l->next;
        if (temp->value == val) {
            if (prev != NULL) {
                prev->next = l; 
            } else {
                list = l;
            }
            free(temp);
        } else {
            prev = temp;
        }
    }
    return list;
}


// ex. 6
void print_in_reverse(Node *list) {
    if (list == NULL) return;
    if (list->next != NULL) {
        print_in_reverse(list->next);
    }
    printf("%4d", list->value);
}


// ex. 7
void reverse_list(Node **head, Node *node) {
    if (node == NULL || *head == NULL) return;
    Node *temp;
    if (node->next == NULL) {
        (*head)->next = NULL;
        *head = node;
        return;
    } else {
        temp = node->next;
        reverse_list(head, temp);
    }
    temp->next = node;
}

Node *reverse_list_v2(Node **head, Node *node) {
    if (*head == NULL) return *head;
    Node *temp = NULL;

    temp = node;
    if (node->next != NULL) {
        node = reverse_list_v2(head, node);
    } else {
        (*head)->next = NULL;
        *head = node;
    }
    node->next = temp;
    return temp;
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
        n = append(n, (i%2) ? -i : i);
        n2 = append(n2, i);
    }
    print_list(n);
    print_list(n2);
    for (int i = 0; i < 5; ++i) {
        n = pop(n);
    }
    print_list(n);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    print_in_reverse(n);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    //putchar('\n');
    print_list(n);
    reverse_list(&n, n);
    print_list(n);

    /*if (split_wr_sign(&n, &pos, &neg)) {
        print_list(pos);
        print_list(neg);
    }*/

    n = merge_lists(n, &n2);
    print_list(n);
    n = pop_key(n, 2);
    print_list(n);
    n = pop_key(n, 10);
    print_list(n);
    n = pop_key(n, 9);
    print_list(n);
    free_list(&n);
    print_list(n);
    print_list(n2);
    return 0;
}
