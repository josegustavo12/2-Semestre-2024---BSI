#ifndef EX3_H
#define EX3_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Lista {
    Node* head;
    Node* tail;
    int size;
} Lista;

typedef struct Fila {
    int capacity;
    int* data;      // Alterado para int*
    int front;
    int rear;
    int size;
} Fila;

typedef struct LNSE {
    Lista* lista;
    Fila fila;
} LNSE;

// Funções da Lista
Node* criarNode(int data);
Lista* criarLista();
int getSize(Lista* lista);
int isEmpty(Lista* lista);
void insertHead(Lista* lista, int data);
void insertTail(Lista* lista, int data);
void insert(Lista* lista, int data, int position);
void removeHead(Lista* lista);
void removeTail(Lista* lista);
void removeNode(Lista* lista, int position);
int busca(Lista* lista, int data);
void clearlista(Lista* lista);
void printLista(Lista* lista);

// Funções da Fila
void criarFila(Fila *fila, int capacity);
int isEmptyf(Fila *fila);
int isFull(Fila *fila);
void enqueue(Fila *fila, int data);
int dequeue(Fila *fila);
int getFront(Fila *fila);
void clearf(Fila *fila);
void imprimirF(Fila *fila); // Renomeado para evitar conflito

// Funções da LNSE
LNSE* crialistaLNSE(int capacity);
void inserir(LNSE* lista_lnse, int data, int position);
void remover(LNSE* lista_lnse, int position);
int buscar(LNSE* lista_lnse, int data);
int sizeLNSE(LNSE* lista_lnse);
void clearLNSE(LNSE* lista_lnse);
void imprimirLNSE(LNSE* lista_lnse);

#endif // EX3_H
