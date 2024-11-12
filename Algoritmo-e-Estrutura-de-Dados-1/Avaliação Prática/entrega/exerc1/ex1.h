#ifndef EX1_H
#define EX1_H

#include <stdio.h>
#include <stdlib.h>

// Definição do noh  da pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Definição da pilha din mica
typedef struct {
    Node* top;
    int tamanho;
} Pilha;

// Função para criar uma nova pilha
Pilha* criarPilha();

// Função para criar um novo noh
Node* criarNode(char data);

// Função para verificar se a pilha está  vazia
int isEmpty(Pilha* pilha);

// Função para adicionar um elemento no topo da pilha
void push(Pilha* pilha, char data);

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha);

//// Função para retornar a quantidade de elementos da pilha
//int size(Pilha* pilha);
//
//// Função para retornar o topo da pilha sem remover
//char getTop(Pilha* pilha);

// Função para imprimir a pilha
void imprimirPilha(Pilha* pilha);

typedef struct {
    int capacity;
    char*data;
    int front;
    int rear;
    int size;
} Fila;

// Função para inicializar a fila
void criarFila(Fila *fila, int capacity);

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, char data);

// Função para remover um elemento da fila
char dequeue(Fila *fila);

// Função para obter o tamanho da fila
int getSize(Fila *fila);

// Função para verificar se a fila está  vazia
int isEmptyf(Fila *fila);

// Função para verificar se a fila está  cheia
int isFull(Fila *fila);

// Função para obter o primeiro elemento da fila
char getFront(Fila *fila);

// Função para limpar a fila
void clearf(Fila *fila);

// Função para imprimir a fila
void imprimir(Fila *fila);

// Função para verificar se a expressão está balanceada usando a fila como argumento
int verificarBalanceamento(Fila* fila);


#endif // EX1_H


