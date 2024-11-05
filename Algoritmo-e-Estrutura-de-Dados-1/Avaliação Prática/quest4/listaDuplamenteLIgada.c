#include "listaDuplamenteLigada.h"

#include <stdio.h>
#include <stdlib.h>

// Definições de estruturas (assumindo que estão no cabeçalho)
typedef struct Node {
    int valor;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Lista {
    Node* head;
    Node* tail;
    int size;
    int ordenado; // 0: não ordenado, 1: ordenado
} Lista;

// Função para criar um novo nó
Node* criarNode(int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novoNode->valor = valor;
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
    lista->ordenado = 0;
    return lista;
}

int getSize(Lista* lista){
    return lista->size;
}

int isEmpty(Lista* lista){
    return getSize(lista) == 0;
}

// INSERE NA HEAD
void insertHead(Lista* lista, int valor){
    Node* novoNode = criarNode(valor);
    lista->ordenado = 0;

    if (isEmpty(lista)){
        lista->head = novoNode;
        lista->tail = novoNode;
    }
    else{
        novoNode->next = lista->head;
        lista->head->prev = novoNode;
        lista->head = novoNode;
    }

    lista->size++;
}

// INSERE NO TAIL
void insertTail(Lista* lista, int valor){
    lista->ordenado = 0;

    if(isEmpty(lista)){
        insertHead(lista, valor);
    }
    else{
        Node* novoNode = criarNode(valor);
        novoNode->prev = lista->tail;
        lista->tail->next = novoNode;
        lista->tail = novoNode;
        lista->size++;
    }
}

void insert(Lista* lista, int valor, int position){
    if(position < 0 || position > getSize(lista)){
        printf("Posição inválida para inserção!\n");
        return;
    }

    lista->ordenado = 0;

    if(position == 0){
        insertHead(lista, valor);
    }
    else if(position == getSize(lista)){
        insertTail(lista, valor);
    }
    else{
        Node* novoNode = criarNode(valor);
        Node* auxNode = lista->head;
        for(int i = 0; i < position - 1; i++){
            auxNode = auxNode->next;
        }

        novoNode->next = auxNode->next;
        novoNode->prev = auxNode;
        auxNode->next->prev = novoNode;
        auxNode->next = novoNode;

        lista->size++;
    }
}

// Função para remover um elemento da lista
void removeHead(Lista* lista){
    if(isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    Node* nodeRemover = lista->head;

    if(getSize(lista) == 1){
        lista->head = NULL;
        lista->tail = NULL;
    }
    else{
        lista->head = nodeRemover->next;
        lista->head->prev = NULL;
    }

    lista->size--;
    free(nodeRemover);
}

void removeTail(Lista* lista){
    if(isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    Node* nodeRemover = lista->tail;

    if(getSize(lista) == 1){
        lista->head = NULL;
        lista->tail = NULL;
    }
    else{
        lista->tail = nodeRemover->prev;
        lista->tail->next = NULL;
    }

    lista->size--;
    free(nodeRemover);
}

void removeNode(Lista* lista, int position){
    if(isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    if(position < 0 || position >= getSize(lista)){
        printf("Posição inválida!\n");
        return;
    }

    if(position == 0){
        removeHead(lista);
        return;
    }

    if(position == getSize(lista) - 1){
        removeTail(lista);
        return;
    }

    Node* tempNode = lista->head;
    for(int i = 0; i < position; i++){
        tempNode = tempNode->next;
    }

    tempNode->prev->next = tempNode->next;
    tempNode->next->prev = tempNode->prev;

    lista->size--;
    free(tempNode);
}

// Função para limpar a lista
void clear(Lista* lista){
    while(!isEmpty(lista)){
        removeHead(lista);
    }
}

// Função para imprimir a lista
void printLista(Lista* lista){
    Node* nohAtual = lista->head;

    if(isEmpty(lista)){
        printf("\n[]\n");
        return;
    }

    printf("\n[");
    while(nohAtual != NULL){
        printf(" %d ", nohAtual->valor);
        nohAtual = nohAtual->next;
    }
    printf("]\n");
}

// Função para ordenar a lista em ordem decrescente usando Bubble Sort
void ordenar(Lista* lista) {
    if(isEmpty(lista) || lista->size == 1){
        lista->ordenado = 1;
        return;
    }

    int trocou;
    Node* nohAtual;

    do {
        trocou = 0;
        nohAtual = lista->head;

        while(nohAtual->next != NULL){
            if(nohAtual->valor < nohAtual->next->valor){
                // Trocar os valores
                int temp = nohAtual->valor;
                nohAtual->valor = nohAtual->next->valor;
                nohAtual->next->valor = temp;
                trocou = 1;
            }
            nohAtual = nohAtual->next;
        }
    } while(trocou);

    lista->ordenado = 1;
}

// Função para encontrar o nó do meio entre inicio e fim
Node* middle(Node* inicio, Node* fim) {
    if (inicio == NULL){
        return NULL;
    }
    Node* slow = inicio;
    Node* fast = inicio->next;

    while (fast != fim){
        fast = fast->next;
        if(fast != fim){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// Função auxiliar para buscar o índice de um nó
int getIndex(Lista* lista, Node* node){
    Node* temp = lista->head;
    int index = 0;
    while(temp != NULL){
        if(temp == node){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

// Função de busca binária recursiva que retorna o índice
int buscaBinariaRecursiva(Lista* lista, Node* inicio, Node* fim, int valor) {
    if (inicio == NULL || fim == NULL || inicio->prev == fim){
        return -1;
    }

    Node* meio = middle(inicio, fim);

    if (meio->valor == valor) {
        return getIndex(lista, meio);
    }
    // Como a lista está ordenada de forma decrescente
    else if (meio->valor < valor) {
        // Valor está na parte esquerda
        return buscaBinariaRecursiva(lista, inicio, meio->prev, valor);
    }
    else {
        // Valor está na parte direita
        return buscaBinariaRecursiva(lista, meio->next, fim, valor);
    }
}

int buscaBinaria(Lista* lista, int valor) {
    if (isEmpty(lista)) {
        return -1;
    }

    return buscaBinariaRecursiva(lista, lista->head, lista->tail, valor);
}

// Função para buscar um valor na lista
int buscar(Lista* lista, int valor){
    if (lista->ordenado == 0){
        printf("Busca sem ser ordenada (Busca Linear)\n");
        Node* tempNode = lista->head;
        for(int i = 0; i < getSize(lista); i++){
            if(tempNode->valor == valor){
                return i;
            }
            tempNode = tempNode->next;
        }
    }
    else{
        printf("Busca ordenada (Busca Binária)\n");
        return buscaBinaria(lista, valor);
    }

    return -1;
}
