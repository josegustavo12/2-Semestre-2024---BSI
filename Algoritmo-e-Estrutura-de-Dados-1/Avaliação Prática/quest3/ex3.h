// quest3.h
#ifndef QUEST3_H
#define QUEST3_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
#define NULL_INDEX -1

// Estrutura para representar um nó na LNSE
typedef struct {
    int value;
    int next;
} Node;

// Estrutura para implementar uma fila estática
typedef struct {
    int data[MAX_CAPACITY];
    int front;
    int rear;
    int capacity;
    int count; // Número de elementos na fila
} StaticQueue;

// Estrutura para implementar a Lista Não Sequencial e Estática (LNSE)
typedef struct {
    Node vector[MAX_CAPACITY];   // Vetor de nós
    StaticQueue freeQueue;       // Fila de índices livres
    int head;                    // Índice do primeiro elemento
    int tail;                    // Índice do último elemento
    int size;                    // Número de elementos na lista
} LNSE;

// Funções da Fila Estática
void initializeQueue(StaticQueue *q, int capacity);
int isEmpty(StaticQueue *q);
int isFull(StaticQueue *q);
int enqueue(StaticQueue *q, int item);
int dequeue(StaticQueue *q, int *item);
int copyQueue(StaticQueue *q, int *tempArray, int *tempSize);

// Funções da LNSE
void initializeLNSE(LNSE *list, int capacity);
void inserir(LNSE *list, int x, int i);
int remover(LNSE *list, int i, int *removed_value);
int buscar(LNSE *list, int x);
int size_list(LNSE *list);
void clearList(LNSE *list, int capacity);
void imprimir(LNSE *list, int capacity);

#endif // QUEST3_H
