// ex1.h
#ifndef EX1_H
#define EX1_H

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do Nó para a Pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Definição da estrutura da Pilha
typedef struct Pilha {
    Node* top;
    int tamanho;
} Pilha;

// Definição da estrutura da Fila
typedef struct Fila {
    char* data;
    int front;
    int rear;
    int size;
    int capacity;
} Fila;

// Protótipos das Funções da Pilha
Pilha* criarPilha();
Node* criarNode(char data);
int isEmpty(Pilha* pilha);
void push(Pilha* pilha, char data);
char pop(Pilha* pilha);
void imprimirPilha(Pilha* pilha);

// Protótipos das Funções da Fila
void criarFila(Fila *fila, int capacity);
int isEmptyf(Fila *fila);
int isFull(Fila *fila);
void enqueue(Fila *fila, char data);
char dequeue(Fila *fila);
char getFront(Fila *fila);
void clearf(Fila *fila);
void imprimir(Fila *fila);

// Protótipo da Função de Verificação de Balanceamento
int verificarBalanceamento(Fila* fila);

#endif // EX1_H
