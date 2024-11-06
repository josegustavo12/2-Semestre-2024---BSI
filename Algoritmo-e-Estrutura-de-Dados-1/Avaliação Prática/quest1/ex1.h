#ifndef EX1_H
#define EX1_H

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Pilha {
    Node* top;
    int tamanho;
} Pilha;

typedef struct Fila {
    int capacity;
    char* data;
    int front;
    int rear;
    int size;
} Fila;

// Funções da pilha
Pilha* criarPilha();
Node* criarNode(char data);
int isEmpty(Pilha* pilha);
void push(Pilha* pilha, char data);
char pop(Pilha* pilha);
void imprimirPilha(Pilha* pilha);

// Funções da fila
void criarFila(Fila *fila, int capacity);
int isEmptyf(Fila *fila);
int isFull(Fila *fila);
void enqueue(Fila *fila, char data);
char dequeue(Fila *fila);
char getFront(Fila *fila);
void clearf(Fila *fila);
void imprimir(Fila *fila);

// Função para verificar balanceamento
int verificarBalanceamento(Fila* fila);

#endif // EX1_H
