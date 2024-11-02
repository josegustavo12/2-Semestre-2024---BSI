#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Tree* createTree(){

    Tree* tree = (Tree*)malloc(sizeof(tree)); // aloca espaço para criar a árvore
    tree->root = NULL;
    tree->size = 0;
    return tree;

}

Node* createNode(int data){

    Node* node = (Node*)malloc(sizeof(Node)); // aloca memória para o nó
    node->data = data;
    node->direita = NULL; //valor a direita e esquerda são nulos
    node->esquerda = NULL;

} // função para criar o nó (estrutura do elemento da árvore)
Node* insert( Node* node, int data ){

    if (node == NULL){
        Node* newNode = createNode(data);
        printf("\n%d", newNode->data);
        return newNode;
    }

    // verifica se vai para o lado esquerdo
    if (data < node->data){
        node->esquerda = insert(node->esquerda, data);
    }
    // vai para o lado direito
    else{
        node->direita = insert(node->direita, data);
    }

    printf("\n%d", node->data);
    return node;
} // função para inserir o elemento dentro de uma árvore; Parametros: Node* node -> estrutura do nó que irá inserir, data -> valor do elemento

int search( Node* node, int data ){

    if (node == NULL){
        return 0;
    }

    if (data == node->data){
        return 1;
    }

    int achou;
    // verifica se vai para o lado esquerdo
    if (data < node->data){
        achou = search(node->esquerda, data);
    }
    // vai para o lado direito
    else{
        achou = search(node->direita, data);
    }

    return achou;

}

Node* getMaxNode(Node* node){

    if (node == NULL){
        return NULL;
    }

    if (node->direita == NULL){
        return node;
    }

    return getMaxNode(node->direita);

}
Node* getMinNode(Node* node){

    if (node == NULL){
        return NULL;
    }

    if (node->esquerda == NULL){
        return node;
    }

    return getMinNode(node->esquerda);

}

Node* deleteNode(Node* node, int data, char filhoSubstituto){

    if (node == NULL){
        return node;
    }

    if (data < node->data){
        node->esquerda = deleteNode(node->esquerda, data, filhoSubstituto); // procura o valor recursivamente 
    }
    else if (data > node->data){
        node->direita = deleteNode(node->direita, data, filhoSubstituto); // Corrigido para direita
    }
    else{ // encontrou o nó que será excluído
        if (node->esquerda == NULL){ 
            Node* tempNode = node->direita;
            free(node);
            return tempNode;
        }
        else if (node->direita == NULL){ 
            Node* tempNode = node->esquerda;
            free(node);
            return tempNode;
        }
        else { // o nó possui dois filhos
            Node* tempNode; 
            if (filhoSubstituto == 'D'){ // Correção: comparação de char
                // pegar o menor de todos do lado direito
                tempNode = getMinNode(node->direita);
                node->data = tempNode->data;
                node->direita = deleteNode(node->direita, tempNode->data, filhoSubstituto); // Corrigido para passar o valor de tempNode->data
            }
            else if (filhoSubstituto == 'E'){ // Correção: comparação de char
                // pegar o maior de todos do lado esquerdo
                tempNode = getMaxNode(node->esquerda);
                node->data = tempNode->data;
                node->esquerda = deleteNode(node->esquerda, tempNode->data, filhoSubstituto); // Corrigido para passar o valor de tempNode->data
            }
        }  
    }
    return node; // Retorna o nó atualizado após a remoção
}
