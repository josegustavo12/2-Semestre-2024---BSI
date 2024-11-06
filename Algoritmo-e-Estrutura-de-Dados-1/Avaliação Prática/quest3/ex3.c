#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

// Função para criar um novo nó
Node* criarNode(int data) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNode->data = data;
    novoNode->next = NULL;
    novoNode->prev = NULL;
    return novoNode;
}

// Função para inicializar uma lista duplamente ligada
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int getSize(Lista* lista){
    return lista->size;
}

int isEmpty(Lista* lista){
    return getSize(lista) == 0;
}

// Função para inserir no início da lista
void insertHead(Lista* lista, int data){
    Node* newNode = criarNode(data);

    if (isEmpty(lista)){
        lista->head = newNode;
        lista->tail = newNode;
    }
    else{
        newNode->next = lista->head;
        lista->head->prev = newNode;
        lista->head = newNode;
    }

    lista->size++;
}

// Função para inserir no final da lista
void insertTail(Lista* lista, int data){
    if(isEmpty(lista)){
        insertHead(lista, data);
    }
    else{
        Node* newNode = criarNode(data);

        newNode->prev = lista->tail;
        lista->tail->next = newNode;

        lista->tail = newNode;

        lista->size++;
    }
}

// Função para inserir em uma posição específica
void insert(Lista* lista, int data, int position){
    if(position <= getSize(lista)){

        if(position == 0){
            insertHead(lista, data);
        }
        else if(position == getSize(lista)){
            insertTail(lista, data);
        }
        else{

            Node* newNode = criarNode(data);

            Node* auxNode = lista->head;
            for(int i = 0; i < position - 1; i++){
                auxNode = auxNode->next;
            }

            newNode->prev = auxNode;
            newNode->next = auxNode->next;

            auxNode->next->prev = newNode;
            auxNode->next = newNode;

            lista->size++;
        }
    }
    else{
        printf("Posição inválida para inserção!\n");
    }
}

// Função para remover o primeiro elemento da lista
void removeHead(Lista* lista){

    if (isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    Node* nodeRemover = lista->head;

    if (getSize(lista) == 1){
        lista->tail = NULL;
        lista->head = NULL;
    }
    else{
        lista->head = nodeRemover->next;
        lista->head->prev = NULL;
    }

    lista->size--;

    free(nodeRemover);
}

// Função para remover o último elemento da lista
void removeTail(Lista* lista){

    if (isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    Node* nodeRemover = lista->tail;

    if (getSize(lista) == 1){
        lista->tail = NULL;
        lista->head = NULL;
    }
    else{
         lista->tail = nodeRemover->prev;
         lista->tail->next = NULL;
    }

    lista->size--;

    free(nodeRemover);
}

// Função para remover um nó em uma posição específica
void removeNode(Lista* lista, int position){

    if (isEmpty(lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    if ((position < 0) || (position >= getSize(lista))){
        printf("Posição inválida!\n");
        return;
    }

    // se é o primeiro nó
    if (position == 0){
        removeHead(lista);
        return;
    }

    // se é o último nó
    if (position == getSize(lista) - 1){
        removeTail(lista);
        return;
    }

    Node* tempNode = lista->head;
    int i = 0;
    while(tempNode != NULL){

        if (i == position){
            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;
            break;
        }

        tempNode = tempNode->next;
        i++;
    }

    lista->size--;
    free(tempNode);
}

// Função para buscar um elemento na lista
int busca(Lista* lista, int data){

    Node* tempNode = lista->head;
    for(int i = 0; i < getSize(lista); i++){

        if(tempNode->data == data){
            return i;
        }

        tempNode = tempNode->next;
    }

    return -1;
}

// Função para limpar a lista
void clearlista(Lista* lista){
    while(getSize(lista) > 0){
        removeHead(lista);
    }
}

// Função para imprimir a lista
void printLista(Lista* lista){
    Node* nohAtual = lista->head;

    if(getSize(lista) == 0){
        printf("\n[]\n");
        return;
    }

    printf("\n[");
    while(nohAtual != NULL){
        printf(" %d ", nohAtual->data);
        nohAtual = nohAtual->next;
    }
    printf("]\n");
}

// Função para inicializar a fila
void criarFila(Fila *fila, int capacity) {
    fila->capacity = capacity;
    fila->data = (int *)malloc(capacity * sizeof(int)); // Alterado para int*
    if (fila->data == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        fila->capacity = 0;
        fila->front = -1;
        fila->rear = -1;
        fila->size = 0;
        return;
    }
    fila->front = -1;
    fila->rear = -1;
    fila->size = 0;
}

// Função para verificar se a fila está vazia
int isEmptyf(Fila *fila) {
    return fila->size == 0;
}

// Função para verificar se a fila está cheia
int isFull(Fila *fila) {
    return fila->size == fila->capacity;
}

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, int data) {
    if (isFull(fila)) {
        printf("Erro. Overflow!\n");
        return;
    }

    if (fila->front == -1) { // Se a fila está vazia
        fila->front = 0;
        fila->rear = 0;
    } else if (fila->rear == fila->capacity - 1) { // Fila circular
        fila->rear = 0;
    } else { // Incrementa o rear
        fila->rear += 1;
    }

    fila->data[fila->rear] = data; // Armazena o inteiro
    fila->size += 1;
}

// Função para remover um elemento da fila
int dequeue(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("Erro. Underflow!\n");
        return -1;
    }

    int temp = fila->data[fila->front];

    if (fila->size == 1) { // Se havia apenas um elemento
        fila->front = -1;
        fila->rear = -1;
    } else if (fila->front == fila->capacity - 1) { // Fila circular
        fila->front = 0;
    } else { // Incrementa o front
        fila->front += 1;
    }

    fila->size -= 1;
    return temp;
}

// Função para obter o primeiro elemento da fila
int getFront(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return fila->data[fila->front];
}

// Função para limpar a fila
void clearf(Fila *fila) {
    fila->front = -1;
    fila->rear = -1;
    fila->size = 0;
}

// Função para imprimir a fila
void imprimirF(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("\n[ ]\n");
        return;
    }

    Fila auxFila;
    criarFila(&auxFila, fila->capacity);
    if (auxFila.data == NULL) {
        return;
    }

    printf("\n[");
    while(!isEmptyf(fila)){
        int front = dequeue(fila);
        printf(" %d ", front);
        enqueue(&auxFila, front);
    }
    printf("]\n");

    while(!isEmptyf(&auxFila)){
        int auxValor = dequeue(&auxFila);
        enqueue(fila, auxValor);
    }

    free(auxFila.data);
}

// Função para criar uma nova LNSE
LNSE* crialistaLNSE(int capacity){
    LNSE* lista_lnse = (LNSE*)malloc(sizeof(LNSE));
    if (lista_lnse == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    lista_lnse->lista = criarLista();
    criarFila(&lista_lnse->fila, capacity);

    // Adiciona os índices na fila
    for (int i = 0 ; i < capacity; i++){
        enqueue(&lista_lnse->fila, i);
    }

    return lista_lnse;
}

// Função para inserir na LNSE
void inserir(LNSE* lista_lnse, int data, int position){
    if(position <= getSize(lista_lnse->lista)){
        int available_position = dequeue(&lista_lnse->fila);
        if(available_position == -1){
            printf("Nenhuma posição disponível na fila.\n");
            return;
        }

        if(position == 0){
            insertHead(lista_lnse->lista, data);
        }
        else if(position == getSize(lista_lnse->lista)){
            insertTail(lista_lnse->lista, data);
        }
        else{
            insert(lista_lnse->lista, data, position);
        }
    }
    else{
        printf("Posição inválida para inserção.\n");
    }
}

// Função para remover na LNSE
void remover(LNSE* lista_lnse, int position){
    if (isEmpty(lista_lnse->lista)){
        printf("Erro. Underflow!\n");
        return;
    }

    if ((position < 0) || (position >= getSize(lista_lnse->lista))){
        printf("Posição inválida!\n");
        return;
    }

    enqueue(&lista_lnse->fila, position);

    if (position == 0){
        removeHead(lista_lnse->lista);
        return;
    }

    if (position == getSize(lista_lnse->lista) - 1){
        removeTail(lista_lnse->lista);
        return;
    }

    removeNode(lista_lnse->lista, position);
}

// Função para buscar na LNSE
int buscar(LNSE* lista_lnse, int data){
    return busca(lista_lnse->lista, data);
}

// Função para obter o tamanho da LNSE
int sizeLNSE(LNSE* lista_lnse){
    return getSize(lista_lnse->lista);
}

// Função para limpar a LNSE
void clearLNSE(LNSE* lista_lnse){
    clearlista(lista_lnse->lista);
    clearf(&lista_lnse->fila);
}

// Função para imprimir a LNSE
void imprimirLNSE(LNSE* lista_lnse){
    printLista(lista_lnse->lista);
    imprimirF(&lista_lnse->fila);
}
