// quest3.h
#ifndef QUEST3_H
#define QUEST3_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
#define NULL_INDEX -1

// Estrutura para representar um nó na LNSE
typedef struct {
    int data;
    int next;
} Node;

// Estrutura para implementar uma fila estática
typedef struct {
    int data[MAX_CAPACITY];
    int front;
    int rear;
    int capacity;
    int count; // Número de elementos na fila
} FilaEstat;

// Estrutura para implementar a Lista Não Sequencial e Estática (LNSE)
typedef struct {
    Node vector[MAX_CAPACITY];   // Vetor de nós
    FilaEstat filalivre;       // Fila de índices livres
    int head;                    // Índice do primeiro elemento
    int tail;                    // Índice do último elemento
    int size;                    // Número de elementos na lista
} LNSE;

// Funções da Fila Estática
void criarFilaEstat(FilaEstat *fila, int capacity);
int isEmpty(FilaEstat *fila);
int isFull(FilaEstat *fila);
int enqueue(FilaEstat *fila, int item);
int dequeue(FilaEstat *fila, int *item);
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize);

// Funções da LNSE
void criarLNSE(LNSE *list, int capacity);
void inserir(LNSE *list, int x, int i);
int remover(LNSE *list, int i, int *removed_value);
int buscar(LNSE *list, int x);
int size_list(LNSE *list);
void clearList(LNSE *list, int capacity);
void imprimir(LNSE *list, int capacity);

#endif // QUEST3_H
