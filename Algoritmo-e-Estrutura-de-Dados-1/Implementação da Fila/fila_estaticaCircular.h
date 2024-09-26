#ifndef FILA_ESTATICACIRCULAR_H_INCLUDED
#define FILA_ESTATICACIRCULAR_H_INCLUDED

typedef struct {
    int capacity;
    int *data; // ponteiro para um vetor que guarda os dados
    int front;
    int rear;
    int size;
} Fila;

void criarFila(Fila* fila, int capacity);
void enqueue(Fila* fila, int valor);
int dequeue(Fila* fila);
void imprimir(Fila* fila);
int getFront(Fila* fila);
int getSize(Fila* fila);
int isEmpty(Fila* fila);
int isFull(Fila* fila);
void clear(Fila* fila);

#endif // FILA_ESTATICACIRCULAR_H_INCLUDED
