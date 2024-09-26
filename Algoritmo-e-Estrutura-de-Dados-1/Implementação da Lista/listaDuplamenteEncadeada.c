#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

// Função para criar um novo nó
Node* criarNode(int data) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novoNode->data = data;
    novoNode->next = NULL;
    novoNode->prev = NULL;
    return novoNode;
}

// Função para inicializar uma lista duplamente ligada
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int getSize(Lista* lista){
    return lista->size;
}

int isEmpty(Lista* lista){
    return getSize(lista) == 0;

    // return  lista->head == NULL
}

void insertHead(Lista* lista, int data){

    Node* newNode = criarNode(data);

    if (getSize(lista) == 0){

        lista->head = newNode;
        lista->tail = newNode;
    }

    else{

        newNode->next = lista->head;
        lista->head->prev = newNode; // ponteiro que está apontando para o primeiro cara "basicamente é um nó"
        lista->head = newNode;

    }

    lista->size++;
}

void printLista(Lista* lista){

    Node* nodeAtual = lista->head;
    printf("\n[");

    if (getSize(lista) == 0){
        printf("[]");
        return;
    }
    while (nodeAtual->next != NULL){
        printf("%d ", nodeAtual->data);
        nodeAtual = nodeAtual->next;
    }
    printf("%d", nodeAtual->data);
    printf("]");
}

void insertTail(Lista* lista, int data){

    if(isEmpty(lista)){
        insertHead(lista, data);
    }

    else{

        Node* newNode = criarNode(data);

        newNode->prev = lista->tail;
        lista->tail->next = newNode;
        lista->tail = newNode;

        lista->size++;

    }
}

void insert(Lista* lista, int data, int position){


    if (position <= getSize(lista)){

        if (position == 0){
            insertHead(lista, data);
        }

        else if (position == getSize(lista)){

            insertTail(lista, data);
        }

        else{
            
            Node* newNode = criarNode(data);
            Node* auxNode = auxNode->next;

            for(int i = 0; i < position-1; i++){
                auxNode = auxNode->next;
            }

            newNode->prev = auxNode;
            newNode->next = auxNode->next;

            auxNode->next->prev = newNode;
            auxNode->next = newNode;

            lista->size++;
        }
    }
}