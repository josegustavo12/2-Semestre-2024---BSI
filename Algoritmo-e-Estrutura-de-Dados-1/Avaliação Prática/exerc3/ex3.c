#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>

// Funções da Fila Estática

// Inicializa a fila com todos os índices disponíveis
void criarFilaEstat(FilaEstat *fila, int capacity) {
    fila->front = 0;
    fila->rear = 0;
    fila->capacity = capacity;
    fila->count = 0;
    // Não enfileira nada aqui; a função que usa initializeQueue deve enfileirar as posições
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
        return 0; // Falha
    }
    fila->data[fila->rear] = item;
    fila->rear = (fila->rear + 1) % fila->capacity;
    fila->count++;
    return 1; // Sucesso
}

// Remove e retorna o primeiro item da fila
int dequeue(FilaEstat *fila, int *item) {
    if(isEmpty(fila)) {
        printf("Fila está vazia. Não é possível desenfileirar.\n");
        return 0; // Falha
    }
    *item = fila->data[fila->front];
    fila->front = (fila->front + 1) % fila->capacity;
    fila->count--;
    return 1; // Sucesso
}

// Função para copiar os elementos da fila para um array temporário
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize) {
    if(isEmpty(fila)) {
        *tempSize = 0;
        return 0; // Fila vazia
    }
    int count = 0;
    int i = fila->front;
    while(count < fila->count) {
        tempArray[count++] = fila->data[i];
        i = (i + 1) % fila->capacity;
        if(count >= fila->capacity) break; // Prevenir loop infinito
    }
    *tempSize = count;
    return 1; // Sucesso
}

// Funções da LNSE

// Inicializa a LNSE
void criarLNSE(LNSE *list, int capacity) {
     criarFilaEstat(&list->filalivre, capacity);
    for(int i = 0; i < capacity; i++) {
        list->vector[i].next = NULL_INDEX;
        list->vector[i].data = 0; // Valor padrão
        // Enfileirar todos os índices na fila de free indices
        enqueue(&list->filalivre, i);
    }
    list->head = NULL_INDEX;
    list->tail = NULL_INDEX;
    list->size = 0;
}

// Insere o valor x na posição i da lista real
void inserir(LNSE *list, int x, int i) {
    if(isEmpty(&list->filalivre)) { // Fila está vazia
        printf("Não há espaço para inserir o elemento %d.\n", x);
        return;
    }
    if(i < 0 || i > list->size) {
        printf("Posição inválida para inserção: %d.\n", i);
        return;
    }

    int idx;
    if(!dequeue(&list->filalivre, &idx)) {
        printf("Erro ao desenfileirar índice para inserção.\n");
        return;
    }

    list->vector[idx].data = x;
    list->vector[idx].next = NULL_INDEX;

    if(i == 0) {
        // Inserção no início da lista
        list->vector[idx].next = list->head;
        list->head = idx;
        if(list->size == 0) {
            list->tail = idx;
        }
    } else {
        // Inserção em posição intermediária ou final
        int prev = list->head;
        for(int j = 0; j < i - 1; j++) {
            prev = list->vector[prev].next;
        }
        list->vector[idx].next = list->vector[prev].next;
        list->vector[prev].next = idx;
        if(prev == list->tail) {
            list->tail = idx;
        }
    }
    list->size++;
}

// Remove o elemento na posição i da lista real e retorna seu valor
int remover(LNSE *list, int i, int *removed_value) {
    if(i < 0 || i >= list->size) {
        printf("Posição inválida para remoção: %d.\n", i);
        return 0; // Falha
    }
    if(list->size == 0) {
        printf("Lista vazia. Não há elementos para remover.\n");
        return 0; // Falha
    }

    int removed_idx;
    if(i == 0) {
        // Remoção do primeiro elemento
        removed_idx = list->head;
        list->head = list->vector[removed_idx].next;
        if(list->size == 1) {
            list->tail = NULL_INDEX;
        }
    } else {
        // Remoção de elemento intermediário ou final
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
    return 1; // Sucesso
}

// Busca o elemento x na lista e retorna sua posição real
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
    return -1; // Elemento não encontrado
}

// Retorna o número de elementos na lista real
int size_list(LNSE *list) {
    return list->size;
}

// Remove todos os elementos da lista
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

// Imprime a lista real, índices de head e tail, e o conteúdo do vetor
void imprimir(LNSE *list, int capacity) {
    printf("\n--- Estado Atual da LNSE ---\n");

    // Imprimir a lista real
    printf("Lista real: ");
    int current = list->head;
    while(current != NULL_INDEX) {
        printf("%d -> ", list->vector[current].data);
        current = list->vector[current].next;
    }
    printf("NULL\n");

    // Imprimir índices de head e tail
    printf("Head index: %d\n", list->head);
    printf("Tail index: %d\n", list->tail);

    // Copiar os índices livres da fila para um array temporário
    int freeIndices[MAX_CAPACITY];
    int freeSize = 0;
    copiarFila(&list->filalivre, freeIndices, &freeSize);

    // Criar um array para marcar quais índices estão livres
    int isFree[MAX_CAPACITY];
    for(int i = 0; i < capacity; i++) {
        isFree[i] = 0; // Inicialmente, todos estão ocupados
    }
    for(int i = 0; i < freeSize; i++) {
        if(freeIndices[i] >= 0 && freeIndices[i] < capacity) {
            isFree[freeIndices[i]] = 1; // Marcar como livre
        }
    }

    // Imprimir o vetor com os índices dos próximos elementos
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
