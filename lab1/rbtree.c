#include "rbtree.h"


struct Node* TNULL;
struct Node* root;

// Preorder
void preOrderHelper(struct Node* node) {
    if (node != TNULL) {
        printf("%ld ", node->data);
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

// Inorder
void inOrderHelper(struct Node* node) {
    if (node != TNULL) {
        inOrderHelper(node->left);
        printf("%ld ", node->data);
        inOrderHelper(node->right);
    }
}

// Post order
void postOrderHelper(struct Node* node) {
    if (node != TNULL) {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        printf("%ld ", node->data);
    }
}

struct Node* searchTreeHelper(struct Node* node, uint64_t key) {
    if (node == TNULL || key == node->data) { return node; }

    if (key < node->data) { return searchTreeHelper(node->left, key); }
    return searchTreeHelper(node->right, key);
}

// For balancing the tree after deletion
void deleteFix(struct Node* x) {
    struct Node* s;
    while (x != NULL && x != root && x->color == 'B') {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s != NULL && s->color == 'R') {
                s->color = 'B';
                x->parent->color = 'R';
                left_rotate(x->parent);
                s = x->parent->right;
            }

            if ((s->right != NULL && s->left != NULL) && s->left->color == 'B' && s->right->color == 'B') {
                s->color = 'R';
                x = x->parent;
            } else {
                if ((s->right != NULL) && s->right->color == 'B') {
                    s->left->color = 'B';
                    s->color = 'R';
                    right_rotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 'B';
                s->right->color = 'B';
                left_rotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s != NULL && s->color == 'R') {
                s->color = 'B';
                x->parent->color = 'R';
                right_rotate(x->parent);
                s = x->parent->left;
            }

            if (s->right != NULL && s->right->color == 'B') {
                s->color = 'R';
                x = x->parent;
            } else {
                if (s->left != NULL && s->left->color == 'B') {
                    s->right->color = 'B';
                    s->color = 'R';
                    left_rotate(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 'B';
                s->left->color = 'B';
                right_rotate(x->parent);
                x = root;
            }
        }
    }
    if (x != NULL) x->color = 'B';
}

void rbTransplant(struct Node* u, struct Node* v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL)
        v->parent = u->parent;
}

void deleteNodeHelper(struct Node* node, uint64_t key) {
    struct Node* z = TNULL;
    struct Node *x, *y;
    while (node != TNULL) {
        if (node->data == key) { z = node; }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == TNULL) {
        printf("Key not found in the tree\n");
        return;
    }

    y = z;
    uint64_t y_original_color = y->color;
    if (z->left == TNULL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);
    if (y_original_color == 0) { deleteFix(x); }
}

// For balancing the tree after insertion
void insertFix(struct Node* z) {
    while (z != root && z != root->left && z != root->right && z->parent->color == 'R') {
        struct Node* y;
        if (z->parent && z->parent->parent && z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;
        if (!y)
            z = z->parent->parent;
        else if (y->color == 'R') {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        } else {
            if (z->parent == z->parent->parent->left && z == z->parent->left) {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                right_rotate(z->parent->parent);
            }
            if (z->parent && z->parent->parent && z->parent == z->parent->parent->left && z == z->parent->right) {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                left_rotate(z->parent);
                right_rotate(z->parent->parent);
            }
            if (z->parent && z->parent->parent && z->parent == z->parent->parent->right && z == z->parent->right) {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                left_rotate(z->parent->parent);
            }
            if (z->parent && z->parent->parent && z->parent == z->parent->parent->right && z == z->parent->left) {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                right_rotate(z->parent);
                left_rotate(z->parent->parent);
            }
        }
    }
    root->color = 'B';
}

void printHelper(struct Node* root, bool last, char* indent) {
    if (root != TNULL) {
        printf("%s", indent);
        if (last) {
            printf("\033[1mR\033[0m\033[33m----\033[0m");
            char* temp = "   ";
            strcat(indent, temp);
        } else {
            printf("\033[1mL\033[0m\033[33m----\033[0m");
            char* temp = "\033[33m|  \033[0m";
            strcat(indent, temp);
        }

        printf((root->color == 'R') ? "\033[1;31m" : "\033[1;34m");
        printf("%ld\033[0m\n", root->data);
        printHelper(root->left, false, indent);
        printHelper(root->right, true, indent);
    }
}

void preorder() {
    preOrderHelper(root);
    printf("\n");
}

void inorder() {
    inOrderHelper(root);
    printf("\n");
}

void postorder() {
    postOrderHelper(root);
    printf("\n");
}

struct Node* search(uint64_t k) {
    return searchTreeHelper(root, k);
}

struct Node* minimum(struct Node* node) {
    while (node->left != TNULL) { node = node->left; }
    return node;
}

struct Node* maximum(struct Node* node) {
    while (node->right != TNULL) { node = node->right; }
    return node;
}

struct Node* successor(struct Node* x) {
    if (x->right != TNULL) { return minimum(x->right); }

    struct Node* y = x->parent;
    while (y != TNULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

struct Node* predecessor(struct Node* x) {
    if (x->left != TNULL) { return maximum(x->left); }

    struct Node* y = x->parent;
    while (y != TNULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

void left_rotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != TNULL) { y->left->parent = x; }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL) { y->right->parent = x; }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Inserting a node
void insert(uint64_t key) {
    struct Node* z = (struct Node*)malloc(sizeof(struct Node));
    z->data = key;
    z->left = z->right = z->parent = NULL;

    if (root == NULL) {
        z->color = 'B';
        root = z;
    } else {
        struct Node* y = NULL;
        struct Node* x = root;

        while (x != NULL) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';
        insertFix(z);
    }
}

struct Node* get_root() {
    return root;
}

void delete_node(uint64_t data) {
    deleteNodeHelper(root, data);
}

void print() {
    char* indent = (char*)malloc(0b11111111);
    if (root) { printHelper(root, true, indent); }
}
