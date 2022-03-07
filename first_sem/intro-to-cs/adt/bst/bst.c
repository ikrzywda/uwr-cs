#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *init(int val) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return init(val);
    if (val < root->val) 
        root->left = insert(root->left, val);
    if (val > root->val) 
        root->right = insert(root->right, val);
    return root;
}

// ex.1
int el_count(Node *t) {
    if (t == NULL) return 0;
    int count = 1;
    if (t->left != NULL) count += el_count(t->left);
    if (t->right != NULL) count += el_count(t->right);
    if (t->left == NULL && t->right == NULL) return 1;
    return count;
}

// ex.2 
int height(Node *t) {
    if (t == NULL) return 0;
    int hl = 1, hr = 1;
    if (t->left != NULL) hl += height(t->left); 
    if (t->right != NULL) hr += height(t->right); 
    if (t->left == NULL && t->right == NULL) return 1;
    return hl >= hr ? hl : hr;
}

// ex.3 
void print_vals(Node *t) {
    if (t == NULL) return;
    int v = t->val;
    print_vals(t->left);
    if (v > 0) printf("%3d", v);
    print_vals(t->right);
}

// ex.4
bool is_bst(Node *t) {
    if (t == NULL) return true;
    bool l = false, r = false;

    if (t->left != NULL) {
        if (t->left->val < t->val) {
            l = is_bst(t->left);
        } else return false;
    } else l = true;

    if (t->right != NULL) {
        if (t->right->val > t->val) {
            r = is_bst(t->right);
        } else return false;
    } else r = true;

    return l & r;
}

// ex.5
Node *merge_bst(Node *g, Node *l) {
    if (g == NULL) return l;
    if (l == NULL) return g;
    Node *h = g;
    while (h->left != NULL) h = h->left;
    h->left = l;
    return g;
}

void print_tree(Node *root, int offset){
    if(root == NULL) return;
    putchar('|');
    for (int i = 0; i < offset; ++i) {
        putchar('-');
    }
    putchar('[');
    printf("%d", root->val);
    putchar(']');
    putchar('\n');
    print_tree(root->left, offset + 4);
    print_tree(root->right, offset + 4);
}



int main() {
    Node *root = NULL, *root_2 = NULL;
    for (int i = 0; i < 30; ++i) {
        root = insert(root, (rand() % 100) - rand() % 100);
        root_2 = insert(root, (rand() % 100) - rand() % 100);
    }
    print_tree(root, 0);
    printf("\nelement count: %d", el_count(root->left));
    printf("\nheight: %d\n", height(root));
    print_vals(root);
    printf("\nis bst: %s\n", is_bst(root) ? "true" : "false");
    root->val = -100;
    print_tree(root, 0);
    printf("\nis bst: %s\n", is_bst(root) ? "true" : "false");
    root = merge_bst(root, root_2);
    printf("\nis bst: %s\n", is_bst(root) ? "true" : "false");
    print_vals(root);
    return 0;
}
