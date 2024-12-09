#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* left;
    struct Node* right;
    int height;

} Node;

typedef struct{
    Node* root;
}Tree;

Node* createNode(int data);

Tree* createTree();

Node* insert( Node* node, int data );

int search( Node* node, int data );

Node* getMaxNode( Node* node );

Node* getMinNode( Node* node );

Node* deleteNode( Node* node, int data, char filhoSubstituto);

void strPreorder(Node *node);
void strInorder(Node *node);
void strPostorder(Node *node);

int getHeight(Node* node);
int getBalance(Node* node);
int max(int a, int b);

Node* leftRotation(Node* node);
Node* rightRotation(Node* node);
Node* leftRightRotation(Node* node);
Node* rightLeftRotation(Node* node);



#endif // TREE_H_INCLUDED
