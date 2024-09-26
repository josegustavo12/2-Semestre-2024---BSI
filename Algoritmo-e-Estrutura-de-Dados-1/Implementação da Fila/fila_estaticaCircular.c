#include <stdio.h>
#include <stdlib.h>
#include "fila_estaticaCircular.h"

void criarFila(Fila* fila, int capacity) {
    fila->capacity = capacity;
    fila->data = (int *)malloc(capacity * sizeof(int));
    if (fila->data == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    fila->front = 0;
    fila->rear = -1;
    fila->size = 0;
}

void enqueue(Fila* fila, int valor) {   

    if (fila->size >= fila->capacity){ // caso o tamanho seja maior que a capacidade da fila

        printf("\nOverflow");
        return;
    }

    if (fila->front == -1){

        fila->front = 0;
        fila->rear = 0;
    }

    else if (fila->rear == fila->capacity -1){

        fila->rear = 0;
    }

    else{

        fila->rear = fila->rear +1;
    }

    // acima ele faz as verificações para ver se ele cabe dentro da fila

    fila->data[fila->rear] = valor; // coloca o valor dentro da fila de fato
    fila->size += 1; // aumenta o tamanho da fila
}

int dequeue(Fila* fila) {

    if (fila->size == 0){

        printf("\nErro.\nUnderflow!");
        return -1;
    }

    int temp = fila->data[fila->front];

    if (fila->size == 1){

        fila->front = -1;
        fila->rear = -1;
    }

    else if(fila->front == fila->capacity - 1){

        fila->front = 0;
    }

    else{

        fila->front = fila->front + 1;
    }

    fila->size -= 1; // retira um valor do tamanho
    return temp; // retorna o valor que foi retirado 

}

void imprimir(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia\n");
        return;
    }
    int i;
    for (i = 0; i < fila->size; i++) {
        printf("%d ", fila->data[(fila->front + i) % fila->capacity]);
    }
    printf("\n");
}

int getFront(Fila* fila) {
    if (isEmpty(fila)) {
        fprintf(stderr, "Fila vazia\n");
        return -1; // ou outro valor de erro apropriado
    }
    return fila->data[fila->front];
}

int getSize(Fila* fila) {
    return fila->size;

/*

    tem outras formas de fazer o getSize:
    return fila->size == fila->capacity;
    utilizando o if para caso a afirmação acima seja verdadeira, aí ele retorna 0 ou 1

*/

}

int isEmpty(Fila* fila) {
    return fila->size == 0;
}

int isFull(Fila* fila) {
    return fila->size == fila->capacity;
}

void clear(Fila* fila) {
    free(fila->data);
    fila->data = NULL;
    fila->capacity = 0;
    fila->front = 0;
    fila->rear = -1;
    fila->size = 0;
}

