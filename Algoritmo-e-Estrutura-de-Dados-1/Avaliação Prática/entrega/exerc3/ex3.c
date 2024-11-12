#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>

//Cria uma fila com todos os indices
void criarFilaEstat(FilaEstat *fila, int capacity) {
    //inicializa cada elemento da fila
    fila->front = 0;
    fila->rear = 0;
    fila->capacity = capacity;
    fila->size = 0;

    // adiciona todos os índices possíveis (de 0 até capacity-1)
    for (int i = 0; i < capacity; i++) {
        enqueue(fila, i);  // adiona o indice
    }
}

// Verifica se a fila está vazia
int isEmpty(FilaEstat *fila) {
    return fila->size == 0;
}

// Verifica se a fila está cheia
int isFull(FilaEstat *fila) {
    return fila->size == fila->capacity;
}

// Adiciona um item na fila
int enqueue(FilaEstat *fila, int item) {
    if (isFull(fila)) { // verifica se a fila está cheia antes de adicionar o item
        printf("Fila está cheia. Não é possível enfileirar o item %d.\n", item);
        return 0; // quando falha
    }
    fila->data[fila->rear] = item;  // coloca o item no final da fila
    fila->rear = (fila->rear + 1) % fila->capacity;  // atualiza o o ultimo elemento do final da fila
    fila->size++;  // aumenta o tamanho da fila
    return 1;  // quando da certo
}

// Remove e retorna o primeiro item da fila
int dequeue(FilaEstat *fila, int *item) {
    if (isEmpty(fila)) { // Verifica se a fila está vazia antes de tentar remover um item.
        printf("Fila está vazia. Não é possível desenfileirar.\n");
        return 0; //quando da errado
    }
    *item = fila->data[fila->front];  // Retira o item da frente da fila
    fila->front = (fila->front + 1) % fila->capacity;  // Atualiza o índice do primeiro elemento da fila
    fila->size--;  // diminui o tamanho da fila
    return 1;  //quando da certo
}

// Função para copiar os elementos da fila para um array temporário
// Essa função copia todos os itens da fila para um array e atualiza o tamanho do array copiado
int copiarFila(FilaEstat *fila, int *tempArray, int *tempSize) {
    if (isEmpty(fila)) {
        *tempSize = 0;  // Se a fila estiver vazia, define o tamanho do array temporário como 0
        return 0; // Fila vazia
    }
    int size = 0;
    int i = fila->front;
    // Percorre a fila e copia os itens para o array temporário
    while (size < fila->size) {
        tempArray[size++] = fila->data[i];
        i = (i + 1) % fila->capacity;  // Atualiza o índice com wrap-around
    }
    *tempSize = size;  // Atualiza o tamanho do array temporário
    return 1;  // Sucesso
}

// Funções da LNSE (Lista de Nós Simplesmente Encadeados)

// Inicializa a LNSE
void criarLNSE(LNSE *list, int capacity) {
    criarFilaEstat(&list->filalivre, capacity);  //cria a fila de índices livres
    for (int i = 0; i < capacity; i++) {
        list->vetor[i].next = INDEX_NULL;  //inicializa o "next" de cada nó como nulo
        list->vetor[i].data = 0;  //inicializa o valor da data de cada nó como 0
    }
    list->head = INDEX_NULL;  //inicializa o head como nulo
    list->tail = INDEX_NULL;  //inicializa o tail como nulo
    list->size = 0;  // inicializa o tamanho da lista como 0
}

// Insere o valor x na posição i da lista real
void inserir(LNSE *list, int x, int i) {
    if (isEmpty(&list->filalivre)) {
        printf("Não há espaço para inserir o elemento %d.\n", x);
        return;  // Se a fila estiver vazia, não há índice disponível para a inserção
    }
    if (i < 0 || i > list->size) {
        printf("Posição inválida para inserção: %d.\n", i);
        return;  // Verifica se a posição de inserção é válida
    }

    int indc; //indc abreviação de indice
    if (!dequeue(&list->filalivre, &indc)) {
        printf("Erro ao desenfileirar Índice para inserção.\n");
        return;  //se não tiver índices livres disponíveis, a inserção falha
    }

    list->vetor[indc].data = x;  // o valor do nó na posição do índice
    list->vetor[indc].next = INDEX_NULL;  //próximo índice é nulo

    if (i == 0) {  // inserir no início da lista
        list->vetor[indc].next = list->head;  //róximo elemento do novo nó será o head atual
        list->head = indc;  // o novo nó se torna o head da lista
        if (list->size == 0) {  //quando a lista ficar vazia, o tail deve apontar para o novo nó
            list->tail = indc;
        }
    } else {
        int no_anterior = list->head;
        // passa a lista até o elemento anterior à posição de inserção
        for (int j = 0; j < i - 1; j++) {
            no_anterior = list->vetor[no_anterior].next;
        }
        list->vetor[indc].next = list->vetor[no_anterior].next;  // O próximo do novo nó vai ser o próximo do no_anterior
        list->vetor[no_anterior].next = indc;  // O next do nó anterior passa a ser o novo nó

        if (no_anterior == list->tail) {  // Se o nó anterior era o tail, o novo nó passa a ser o tail
            list->tail = indc;
        }
    }
    list->size++;  // Aumenta o tamanho da lista
}

// Remove o elemento na posição i da lista real e retorna seu valor
int remover(LNSE *list, int i) {
    if (i < 0 || i >= list->size) {
        printf("Posição inválida para remoção: %d.\n", i);
        return 0;  //posição inválida
    }

    if (list->size == 0) {
        printf("Lista vazia. Não há elementos para remover.\n");
        return 0;  //lista vazia
    }

    int indice_removido;
    if (i == 0) {  // Se for para remover o primeiro elemento
        indice_removido = list->head;
        list->head = list->vetor[indice_removido].next;
        if (list->head == INDEX_NULL) {  // Se a lista ficar vazia, o "tail" também deve ser nulo
            list->tail = INDEX_NULL;
        }
    } else {
        int prev = list->head;
        // Percorre até o elemento anterior à posição de remoção
        for (int j = 0; j < i - 1; j++) {
            prev = list->vetor[prev].next;
        }
        indice_removido = list->vetor[prev].next;  // O índice removido é o próximo do nó anterior
        list->vetor[prev].next = list->vetor[indice_removido].next;  // O próximo do nó anterior passa a ser o próximo do nó removido

        if (indice_removido == list->tail) {  // Se o nó removido era o tail, o tail se torna o nó anterior
            list->tail = prev;
        }
    }

    int valor_removido = list->vetor[indice_removido].data;  // Armazena o valor removido
    enqueue(&list->filalivre, indice_removido);  // adiciona o índice removido novamente
    list->size--;  // Diminui o tamanho da lista

    return valor_removido;  // Retorna o valor do elemento removido
}

// Busca o elemento x na lista e retorna sua posição
int buscar(LNSE *list, int x) {
    int no_atual = list->head;
    int indice = 0;
    while (no_atual != INDEX_NULL) {
        if (list->vetor[no_atual].data == x) {
            return indice;  // retorna a posição do elemento que foi encontrado
        }
        no_atual = list->vetor[no_atual].next;
        indice++;
    }
    return -1;  //o elemento não foi encontrado
}

// Retorna o tamanho da LNSE
int size_listaLNSE(LNSE *list) {
    return list->size;
}

// Remove todos os elementos da lista e retorna à fila de índices livres
void clearListaLNSE(LNSE *list) {
    int no_atual = list->head;
    while (no_atual != INDEX_NULL) {
        int prox_indice = list->vetor[no_atual].next;  // armazena o próximo índice
        enqueue(&list->filalivre, no_atual);  // pega o índice atual para utilizar depois
        list->vetor[no_atual].data = 0;  //valor do nó = 0
        list->vetor[no_atual].next = INDEX_NULL;  //próximo índice = nulo
        no_atual = prox_indice;  //passa para o próximo nó
    }
    list->head = INDEX_NULL;  //head = nulo
    list->tail = INDEX_NULL;  //tail = nulo
    list->size = 0;  //tamanho da lista = 0
}

// Imprime a lista real, índices de head e tail, e o conteúdo do vetor
void imprimir(LNSE *list) {
    printf("\n--- Estado Atual da LNSE ---\n");

    // Imprime a lista real (itens da lista)
    printf("Lista real: ");
    int no_atual = list->head;
    while (no_atual != INDEX_NULL) {
        printf("%d -> ", list->vetor[no_atual].data);  // Imprime o valor do nó
        no_atual = list->vetor[no_atual].next;  // Passa para o próximo nó
    }
    printf("NULL\n");

    // Imprime o índice de head e tail
    printf("Head indice: %d\n", list->head);
    printf("Tail indice: %d\n", list->tail);

    // Copia os índices livres para um array temporário
    int freeIndices[CAPACITY_MAX];
    int freeSize = 0;
    copiarFila(&list->filalivre, freeIndices, &freeSize);

    // Marca os índices livres
    int isFree[CAPACITY_MAX] = {0};
    for (int i = 0; i < freeSize; i++) {
        isFree[freeIndices[i]] = 1;
    }

    // Imprime os índices livres
    printf("Indices livres: ");
    for (int i = 0; i < CAPACITY_MAX; i++) {
        if (isFree[i]) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // Imprime o vetor de nós
    printf("Vetor:\n");
    for (int i = 0; i < CAPACITY_MAX; i++) {
        if (isFree[i]) {
            printf("[%d]: (-)\n", i);  // Indica índice livre
        } else {
            printf("[%d]: %d -> ", i, list->vetor[i].data);  // Imprime o valor e o próximo índice
            if (list->vetor[i].next != INDEX_NULL) {
                printf("%d\n", list->vetor[i].next);
            } else {
                printf("NULL\n");
            }
        }
    }
}
