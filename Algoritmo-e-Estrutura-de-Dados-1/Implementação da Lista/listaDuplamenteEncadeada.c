#include <stdio.h>           // Biblioteca para entrada e saída.
#include <stdlib.h>         // Biblioteca para alocação de memória.
#include "listaDuplamenteEncadeada.h" // Cabeçalho da lista duplamente encadeada.

typedef struct Node {      // Estrutura de um nó da lista.
    int data;              // Dados armazenados no nó.
    struct Node* next;     // Ponteiro para o próximo nó.
    struct Node* prev;     // Ponteiro para o nó anterior.
} Node;

typedef struct Lista {     // Estrutura da lista duplamente encadeada.
    Node* head;           // Primeiro nó da lista.
    Node* tail;           // Último nó da lista.
    int size;             // Número de nós na lista.
} Lista;

Node* criarNode(int data) { // Cria e inicializa um novo nó.
    Node* novoNode = (Node*)malloc(sizeof(Node)); // Alocação de memória.
    if (novoNode == NULL) {                        // Verifica falha na alocação.
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novoNode->data = data;                         // Define os dados do nó.
    novoNode->next = NULL;                         // Inicializa ponteiros como NULL.
    novoNode->prev = NULL;
    return novoNode;
}

Lista* criarLista() { // Inicializa uma nova lista.
    Lista* lista = (Lista*)malloc(sizeof(Lista)); 
    if (lista == NULL) {                           
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->head = NULL;                            // Inicializa lista vazia.
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int getSize(Lista* lista) { 
    return lista->size;
}

int isEmpty(Lista* lista) { 
    return getSize(lista) == 0; // Retorna 1 se a lista estiver vazia.
}

void insertHead(Lista* lista, int data) { 
    Node* newNode = criarNode(data); // Cria um novo nó.

    if (isEmpty(lista)) { // Se a lista estiver vazia, o novo nó é tanto o cabeça quanto o fim.
        lista->head = newNode;
        lista->tail = newNode;
    } else {
        newNode->next = lista->head; // O novo nó aponta para o antigo cabeça.
        lista->head->prev = newNode;  // Atualiza o antigo cabeça para apontar para o novo nó.
        lista->head = newNode;        // Atualiza o cabeça para o novo nó.
    }
    lista->size++; // Incrementa o tamanho da lista.
}

void printLista(Lista* lista) { // Imprime os elementos da lista.
    Node* nodeAtual = lista->head; // Inicia a impressão a partir do cabeça.
    printf("\n[");

    if (isEmpty(lista)) { // Se a lista estiver vazia, imprime []
        printf("[]");
        return;
    }
    
    // Percorre a lista e imprime os dados.
    while (nodeAtual != NULL) {
        printf("%d ", nodeAtual->data);
        nodeAtual = nodeAtual->next;
    }
    printf("]"); // Fecha a impressão da lista.
}

void insertTail(Lista* lista, int data) { // Insere um nó no final da lista.
    if (isEmpty(lista)) { // Se a lista estiver vazia, insere no início.
        insertHead(lista, data);
    } else {
        Node* newNode = criarNode(data); // Cria um novo nó.
        newNode->prev = lista->tail; // O novo nó aponta para o atual fim.
        lista->tail->next = newNode; // O atual fim aponta para o novo nó.
        lista->tail = newNode; // Atualiza o fim da lista.
        lista->size++; // Incrementa o tamanho.
    }
}

void insert(Lista* lista, int data, int position) { // Insere um nó em uma posição específica.
    if (position < 0 || position > getSize(lista)) return; // Verifica posição inválida.

    if (position == 0) { // Insere no início.
        insertHead(lista, data);
    } else if (position == getSize(lista)) { // Insere no final.
        insertTail(lista, data);
    } else {
        Node* newNode = criarNode(data); // Cria um novo nó.
        Node* auxNode = lista->head; // Inicia o ponteiro auxiliar no cabeça.

        // Navega até a posição desejada.
        for (int i = 0; i < position - 1; i++) {
            auxNode = auxNode->next; // Move para o próximo nó.
        }

        // Atualiza ponteiros para inserir o novo nó na posição correta.
        newNode->prev = auxNode;
        newNode->next = auxNode->next;
        if (auxNode->next != NULL) { // Atualiza o próximo nó se não for o último.
            auxNode->next->prev = newNode;
        }
        auxNode->next = newNode; // Insere o novo nó.
        lista->size++; // Incrementa o tamanho da lista.
    }
}
