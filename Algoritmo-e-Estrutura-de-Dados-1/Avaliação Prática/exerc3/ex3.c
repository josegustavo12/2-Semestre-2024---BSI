#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializa a fila com todos os índices disponíveis
void criarFilaEstat(FilaEstat *fila, int capacity) {
    fila->front = 0;
    fila->rear = 0;
    fila->capacity = capacity;
    fila->count = 0;
}

// Verifica se a fila está vazia
int isEmpty(FilaEstat *fila) {
    return fila->count == 0;
}

// Verifica se a fila está cheia
int isFull(FilaEstat *fila) {
    return fila->count == fila->capacity;
}

// Adiciona um item na fila
int enqueue(FilaEstat *fila, int item) {
    if(isFull(fila)) {
        printf("Fila está cheia. Não é possível enfileirar o item %d.\n", item);
        return 0;
    }
    fila->data[fila->rear] = item;
    fila->rear = (fila->rear + 1) % fila->capacity;
    fila->count++;
    return 1;
}

// Remove e retorna o primeiro item da fila
int dequeue(FilaEstat *fila, int *item) {
    if(isEmpty(fila)) {
        printf("Fila está vazia. Não é possível desenfileirar.\n");
        return 0;
    }
    *item = fila->data[fila->front];
    fila->front = (fila->front + 1) % fila->capacity;
    fila->count--;
    return 1;
}

// Função para copiar os elementos da fila para um array temporário
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize) {
    if(isEmpty(fila)) {
        *tempSize = 0;
        return 0;
    }
    int count = 0;
    int i = fila->front;
    while(count < fila->count) {
        tempArray[count++] = fila->data[i];
        i = (i + 1) % fila->capacity;
    }
    *tempSize = count;
    return 1;
}

// Inicializa a LNSE
void criarLNSE(LNSE *list, int capacity) {
    criarFilaEstat(&list->filalivre, capacity);
    for(int i = 0; i < capacity; i++) {
        list->vector[i].next = NULL_INDEX;
        list->vector[i].data = 0;
        enqueue(&list->filalivre, i);
    }
    list->head = NULL_INDEX;
    list->tail = NULL_INDEX;
    list->size = 0;
}

// Insere o valor x na posição i da lista real
void inserir(LNSE *list, int x, int i) {
    if(isEmpty(&list->filalivre)) {
        printf("Não há espaço para inserir o elemento %d.\n", x);
        return;
    }
    if(i < 0 || i > list->size) {
        printf("Posição inválida para inserção: %d.\n", i);
        return;
    }

    int idx;
    dequeue(&list->filalivre, &idx);

    list->vector[idx].data = x;
    list->vector[idx].next = NULL_INDEX;

    if(i == 0) {
        list->vector[idx].next = list->head;
        list->head = idx;
        if(list->size == 0) {
            list->tail = idx;
        }
    } else {
        int prev = list->head;
        for(int j = 0; j < i - 1; j++) {
            prev = list->vector[prev].next;
        }
        list->vector[idx].next = list->vector[prev].next;
        list->vector[prev].next = idx;
        if(list->vector[idx].next == NULL_INDEX) {
            list->tail = idx;
        }
    }
    list->size++;
}

// Remove o elemento na posição i da lista real e retorna seu valor
int remover(LNSE *list, int i, int *removed_value) {
    if(i < 0 || i >= list->size) {
        printf("Posição inválida para remoção: %d.\n", i);
        return 0;
    }
    if(list->size == 0) {
        printf("Lista vazia. Não há elementos para remover.\n");
        return 0;
    }

    int removed_idx;
    if(i == 0) {
        removed_idx = list->head;
        list->head = list->vector[removed_idx].next;
        if(list->size == 1) {
            list->tail = NULL_INDEX;
        }
    } else {
        int prev = list->head;
        for(int j = 0; j < i - 1; j++) {
            prev = list->vector[prev].next;
        }
        removed_idx = list->vector[prev].next;
        list->vector[prev].next = list->vector[removed_idx].next;
        if(removed_idx == list->tail) {
            list->tail = prev;
        }
    }

    *removed_value = list->vector[removed_idx].data;
    enqueue(&list->filalivre, removed_idx);
    list->size--;
    return 1;
}

// Função de busca
int buscar(LNSE *list, int x) {
    int current = list->head;
    int pos = 0;
    while(current != NULL_INDEX) {
        if(list->vector[current].data == x) {
            return pos;
        }
        current = list->vector[current].next;
        pos++;
    }
    return -1;
}

// Função para limpar a lista
void clearList(LNSE *list, int capacity) {
    int current = list->head;
    while(current != NULL_INDEX) {
        int next_idx = list->vector[current].next;
        enqueue(&list->filalivre, current);
        list->vector[current].data = 0;
        list->vector[current].next = NULL_INDEX;
        current = next_idx;
    }
    list->head = NULL_INDEX;
    list->tail = NULL_INDEX;
    list->size = 0;
}

// Função para imprimir o estado da lista
void imprimir(LNSE *list, int capacity) {
    printf("\n--- Estado Atual da LNSE ---\n");

    printf("Lista real: ");
    int current = list->head;
    while(current != NULL_INDEX) {
        printf("%d -> ", list->vector[current].data);
        current = list->vector[current].next;
    }
    printf("NULL\n");

    printf("Head index: %d\n", list->head);
    printf("Tail index: %d\n", list->tail);

    int freeIndices[MAX_CAPACITY];
    int freeSize = 0;
    copiarFila(&list->filalivre, freeIndices, &freeSize);

    int isFree[MAX_CAPACITY];
    for(int i = 0; i < capacity; i++) {
        isFree[i] = 0;
    }
    for(int i = 0; i < freeSize; i++) {
        if(freeIndices[i] >= 0 && freeIndices[i] < capacity) {
            isFree[freeIndices[i]] = 1;
        }
    }

    printf("Vetor:\n");
    for(int i = 0; i < capacity; i++) {
        if(isFree[i]) {
            printf("[%d]: (-)\n", i);
        } else {
            printf("[%d]: %d -> ", i, list->vector[i].data);
            if(list->vector[i].next != NULL_INDEX) {
                printf("%d\n", list->vector[i].next);
            } else {
                printf("NULL\n");
            }
        }
    }
}