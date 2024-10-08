#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Tree* creatTree(){

    Tree* tree = (Tree*)malloc(sizeof(tree)); // aloca espaço para criar a árvore
    tree->root = NULL;
    tree->size = 0;
    return tree;

}

Node* creatNode(int data){

    Node* node = (Node*)malloc(sizeof(Node)); // aloca memória para o nó
    node->data;
    node->direita = NULL; //valor a direita e esquerda são nulos
    node->esquerda = NULL;

} // função para criar o nó (estrutura do elemento da árvore)
Node* insert(Node* node, int data){

    if (node == NULL){
        Node* newNode = creatNode(data);
        return newNode;
    }

    if (data < node->data){ // verifica se vai p/ o lado esquerdo
        node->esquerda = insert(node->esquerda, data); // insere o nó na esquerda
    }

    else{ // caso n vá para a esquerda, vai p/ a direita
        node->direita = insert(node->direita, data);
    }
    printf("\n%d", node->data);
    return node;

} // função para inserir o elemento dentro de uma árvore; Parametros: Node* node -> estrutura do nó que irá inserir, data -> valor do elemento
