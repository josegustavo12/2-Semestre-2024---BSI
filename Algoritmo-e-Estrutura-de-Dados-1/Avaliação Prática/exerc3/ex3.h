// quest3.h
#ifndef QUEST3_H
#define QUEST3_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
#define NULL_INDEX -1

// Estrutura para representar um n� na LNSE
typedef struct {
    int data;
    int next;
} Node;

// Estrutura para implementar uma fila est�tica
typedef struct {
    int data[MAX_CAPACITY];
    int front;
    int rear;
    int capacity;
    int count; // N�mero de elementos na fila
} FilaEstat;

// Estrutura para implementar a Lista N�o Sequencial e Est�tica (LNSE)
typedef struct {
    Node vector[MAX_CAPACITY];   // Vetor de n�s
    FilaEstat filalivre;       // Fila de �ndices livres
    int head;                    // �ndice do primeiro elemento
    int tail;                    // �ndice do �ltimo elemento
    int size;                    // N�mero de elementos na lista
} LNSE;

// Fun��es da Fila Est�tica
void criarFilaEstat(FilaEstat *fila, int capacity);
int isEmpty(FilaEstat *fila);
int isFull(FilaEstat *fila);
int enqueue(FilaEstat *fila, int item);
int dequeue(FilaEstat *fila, int *item);
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize);

// Fun��es da LNSE
void criarLNSE(LNSE *list, int capacity);
void inserir(LNSE *list, int x, int i);
int remover(LNSE *list, int i, int *removed_value);
int buscar(LNSE *list, int x);
int size_list(LNSE *list);
void clearList(LNSE *list, int capacity);
void imprimir(LNSE *list, int capacity);

#endif // QUEST3_H
