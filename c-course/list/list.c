#include "list.h"

Node *init(double val) {
    Node *new_node = malloc(sizeof(Node));;
    if (new_node == NULL) {
        printf("Cannot allocate memory... Aborting.\n");
        exit(1);
    }
    new_node->next = new_node;
    new_node->prev = new_node;
    new_node->info = val;
    return new_node;
}

bool append(Node **head, double val) {
    if (*head == NULL) {
        *head = init(val);
        return true;
    } 
    Node *last = (*head)->prev;
    Node *first = *head;
    Node *new_node = init(val);
    new_node->next = first;
    new_node->prev = last;
    last->next = new_node;
    first->prev = new_node;
    return true;
}

bool prepend(Node **head, double val) {
    if (*head == NULL) {
        *head = init(val);
        return true;
    } 
    Node *last = (*head)->prev;
    Node *first = *head;
    Node *new_node = init(val);
    new_node->next = first;
    new_node->prev = last;
    last->next = new_node;
    first->prev = new_node;
    *head = new_node;
    return true;
}

void print_node(Node *n) {
    printf("%.2f ", n->info);
}

void print_front(Node *head) {
    if (head == NULL) {
        printf("Empty list\n");
    }
    Node *start = head;
    Node *n = head;
    do {
        print_node(n);
        n = n->next;
    } while (n != start);
    putchar('\n');
}

void print_back(Node *head) {
    if (head == NULL) {
        printf("Empty list\n");
    }
    Node *start = head;
    Node *n = head;
    do {
        print_node(n);
        n = n->prev;
    } while (n != start);
    putchar('\n');
}

bool is_empty(Node **head) {
    if (*head == NULL) {
        return true;
    }
    return false;
}


bool pop_front(Node **head, double *result) {
    if (*head == NULL) {
        return false;
    }
    Node *temp = (*head)->prev;
    *result = temp->info;
    (temp->prev)->next = *head;
    (*head)->prev = temp->prev;
    free(temp);
    return true;
}

bool pop_back(Node **head, double *result) {
    if (*head == NULL) {
        return false;
    }
    Node *temp = (*head)->next;
    *result = (*head)->info;
    temp->prev = (*head)->prev;
    ((*head)->prev)->next = temp;
    free(*head);
    *head = temp;
    return true;
}

unsigned length(Node *head) {
    if (head == NULL) {
        return 0;
    }
    Node *start = head;
    Node *n = head;
    unsigned len =  0;
    do {
        ++len;
        n = n->next;
    } while (n != start);
    return len;
}

bool insert(Node **head, double val, unsigned index) {
    unsigned len = length(*head);
    if (!len || index > len) {
        return false;
    }
    Node *temp = *head;
    Node *new_node = init(val);
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    new_node->prev = temp->prev;
    new_node->next = temp->next;
    (temp->next)->prev = new_node;
    temp->next = new_node;
    return true;
}
