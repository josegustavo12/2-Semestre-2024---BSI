#ifndef TREE_H
#define TREE_H

typedef struct Node{

    int data;
    struct Node* esquerda; // estrutura do elemento a esquerda
    struct Node* direita; // estrutura do elemento a direita

}Node;

typedef struct Tree{

    Node* root; // raiz da árvore, ou seja, o primeiro elemento
    int size; // tamanho da árvore

} Tree;

Tree* createTree();
Node* createNode(int data); // função para criar o nó (estrutura do elemento da árvore)
Node* insert(Node* node, int data); // função para inserir o elemento dentro de uma árvore; Parametros: Node* node -> estrutura do nó que irá inserir, data -> valor do elemento

int search (Node* node, int data);

Node* deleteNode(Node* node, int data, char filhoSubstituto);

Node* getMaxNode(Node* node);

#endif // TREE_H