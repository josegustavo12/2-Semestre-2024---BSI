#ifndef EX3_H
#define EX3_H

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY_MAX 10
#define INDEX_NULL -1

// Estrutura para representar um nó na LNSE
typedef struct {
    int data;
    int next;
} Node;

// Estrutura para implementar uma fila estática
typedef struct {
    int data[CAPACITY_MAX];
    int front;
    int rear;
    int capacity;
    int size; // Número de elementos na fila
} FilaEstat;

// Estrutura para implementar a Lista Não Sequencial e Estática (LNSE)
typedef struct {
    Node vetor[CAPACITY_MAX];   // Vetor de nós
    FilaEstat filalivre;       // Fila de índices livres
    int head;                    // Índice do primeiro elemento
    int tail;                    // Índice do último elemento
    int size;                    // Número de elementos na lista
} LNSE;

// Funções da Fila Estática
void criarFilaEstat(FilaEstat *fila, int capacity);

// Função para verificar se a fila está vazia
int isEmpty(FilaEstat *fila);

// Função para verificar se a fila está cheia
int isFull(FilaEstat *fila);

// Função para adicionar um item à fila
int enqueue(FilaEstat *fila, int item);

// Função para remover um item da fila
int dequeue(FilaEstat *fila, int *item);

// Função para copiar os elementos da fila para um array temporário
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize);

// Funções da LNSE

// Função que cria e inicializa a Lista Não Sequencial Estática
void criarLNSE(LNSE *list, int capacity);

// Função para inserir um elemento na LNSE
void inserir(LNSE *list, int x, int i);

// Função para remover um elemento da LNSE
int remover(LNSE *list, int i);

// Função para buscar um elemento na LNSE
int buscar(LNSE *list, int x);

// Função para retornar o tamanho da LNSE
int size_listaLNSE(LNSE *list);

// Função para limpar a LNSE
void clearListaLNSE(LNSE *list);

// Função para imprimir os elementos da LNSE
void imprimir(LNSE *list);

#endif // EX3_H
