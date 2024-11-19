#include "listaDuplamenteLigada.h"

#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
Node* criarNode(int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novoNode->valor = valor;
    novoNode->next = NULL;
    novoNode->prev = NULL;
    return novoNode;
}

// Função para inicializar uma lista duplamente ligada
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    lista->ordenado=0;
    return lista;
}

int getSize(Lista* lista){
    return lista->size;
}

int isEmpty(Lista* lista){
    return getSize(lista)==0;

    // return lista->head == NULL
}

//INSERE NA HEAD
void insertHead(Lista* lista, int valor){

    Node* novoNode = criarNode(valor);

    lista->ordenado= 0;

    if (getSize(lista)==0){
        lista->head = novoNode;
        lista->tail = novoNode;
    }
    else{
        novoNode->next = lista->head; // o next do novo node vai ser a antiga cabeça
        lista->head->prev = novoNode; // o anterior a cabeça vai virar o novo node, o next do novo node vai ser a cabeça antiga
        lista->head = novoNode; // o novo node vira a nova cabeça
    }

    lista->size++; // aumenta o tamanho da lista
}


//INSERE NO TAIL
void insertTail(Lista* lista, int valor){

    lista->ordenado= 0;

    if( isEmpty(lista) ){
        insertHead(lista, valor);
    }
    else{
        Node* novoNode = criarNode(valor);

        novoNode->prev = lista->tail; // o anterior ao novo node é o atigo nodeTail
        lista->tail->next = novoNode; // o proximo do nodeTail vai ser o novo node
        lista->tail = novoNode; // o node vai virar o tail

        lista->size++;
    }
}

void insert(Lista* lista, int valor, int position){

    if(position <= getSize(lista)){

        if(position==0){
            insertHead(lista, valor);
        }
        else if( position==getSize(lista) ){
            insertTail(lista,valor);
        }
        else{

            //entender dps
            Node* novoNode = criarNode(valor);

            Node* auxNode = lista->head;
            for(int i=0; i<position-1; i++){
                auxNode = auxNode->next;
            }

            novoNode->prev = auxNode;
            novoNode->next = auxNode->next;

            auxNode->next->prev = novoNode;
            auxNode->next = novoNode;

            lista->ordenado= 0;

            lista->size++;

        }

    }

}

// Função para remover um elemento da lista (head)
void removeHead(Lista* lista){

    if ( isEmpty(lista) ){
        printf("Erro. Underflow!");
        return;
    }

    Node* nodeRemover = lista->head;

    if ( getSize(lista)==1 ){
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

// Função para remover um elemento da lista (tail)
void removeTail(Lista* lista){

    if ( isEmpty(lista) ){
        printf("Erro. Underflow!");
        return;
    }

    Node* nodeRemover = lista->tail;

    if ( getSize(lista)==1 ){
        lista->tail = NULL;
        lista->head = NULL;
    }
    else{
         lista->tail = nodeRemover->prev;
         lista->tail->next = NULL;
    }

    lista->size--;

    free(nodeRemover);// limpa o ponteiro da memória
}

void removeNode(Lista* lista, int position){

    if ( isEmpty(lista) ){
        printf("Erro. Underflow!");
        return;
    }

    if ( (position < 0 ) || (position >= getSize(lista)) ){
        printf("Posição inválida!");
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
    int i=0;
    while( tempNode!=NULL ){

        if (i==position){

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

int buscar(Lista* lista, int valor){

    if (lista->ordenado == 0){
        Node* tempNode = lista->head;
        for(int i=0; i<getSize(lista); i++){

            if( tempNode->valor==valor ){
                return i;
            }

            tempNode = tempNode->next;
        }


    }else{
        int indice = buscaBinaria(lista,  valor);
        return indice;
    }

    return -1;
}

void clear(Lista* lista){
    Node* tempNode = lista->head;
    while( getSize(lista)>0 ){
        removeHead(lista);
    }
}

void printLista(Lista* lista){
    Node* nohAtual = lista->head;

    if( getSize(lista)==0 ){
        printf("\n[]");
        return;
    }

    printf("\n[");
    while( nohAtual->next!=NULL ){
        printf(" %d ", nohAtual->valor);
        nohAtual = nohAtual->next;
    }

    // imprime o último noh
    printf(" %d ", nohAtual->valor);

    printf("]");
}


//função para ordenar em ordem decrescente 
void ordenar(Lista* lista) {
    for (int j = getSize(lista); j > 0; j--) {
        Node* nohAtual = lista->head;
        for (int i = 0; i < j-1; i++) {
            if (nohAtual->valor < nohAtual->next->valor) {
                // Trocar os valores
                int temp = nohAtual->valor;
                nohAtual->valor = nohAtual->next->valor;
                nohAtual->next->valor = temp;
            }
            nohAtual = nohAtual->next;
        }
        
    }
    lista->ordenado = 1;
}

// função para achar o valor do meio
Node* acharMeio(Node* inicio, Node* fim) {
  if (inicio == NULL || inicio == fim){
        return inicio;
    }
    Node* slow = inicio;
    Node* fast = inicio;
    while (fast->next != fim && fast->next->next != fim){
        //slow vai se mover um nó por vez e o fast vai se mover dois nós por vez
        slow = slow->next;
        fast = fast->next->next;
    }
    //o fast vai chegar ao final da lista antes de slow permitindo que slow fique no nó do meio
    return slow;


}

//função para pegar o index específico de um elemento
int getIndex(Lista* lista, Node* node){
    Node* temp = lista->head;
    int index = 0;
    while(temp != NULL){
        if(temp == node){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}


//função da busca binária recursiva
int buscaBinariaRecursiva(Lista* lista, Node* inicio, Node* fim, int valor) {
    if (inicio == NULL || fim == NULL || inicio->prev == fim){
        return -1;
    }

    Node* meio = acharMeio(inicio, fim);

    if (meio->valor == valor) {
        return getIndex(lista, meio);
    }
    else if (meio->valor < valor) {

        return buscaBinariaRecursiva(lista, inicio, meio->prev, valor);
    }
    else {
        return buscaBinariaRecursiva(lista, meio->next, fim, valor);
    }
}

//busca binária que recebe a lista e o valor que tá procurando, e chama a lista buscaBinariaRecursiva
//eh chamada quando ordenado=1;
int buscaBinaria(Lista* lista, int valor) {
    if (isEmpty(lista)) {
        return -1;
    }

    return buscaBinariaRecursiva(lista, lista->head, lista->tail, valor);
}
