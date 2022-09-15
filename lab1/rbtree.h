#ifndef RBTREE_H
#define RBTREE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    uint64_t data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    char color;
} ;

void preOrderHelper(struct Node*);
void inOrderHelper(struct Node*);
void postOrderHelper(struct Node*);

struct Node* searchTreeHelper(struct Node*, uint64_t);

void deleteFix(struct Node*);
void rbTransplant(struct Node*, struct Node*);
void deleteNodeHelper(struct Node*, uint64_t);
void insertFix(struct Node*);
void printHelper(struct Node*, bool, char*);

void preorder();
void inorder();
void postorder();

struct Node* search(uint64_t);
struct Node* minimum(struct Node*);
struct Node* maximum(struct Node*);
struct Node* successor(struct Node*);
struct Node* predecessor(struct Node*);

void left_rotate(struct Node*);
void right_rotate(struct Node*);
void insert(uint64_t);

struct Node* get_root();

void delete_node(uint64_t);
void print();
#endif