#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// Função para criar uma nova pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha)); // Aloca memória para a pilha
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }

    pilha->top = NULL; // Inicializa o topo como NULL
    pilha->tamanho = 0; // Inicializa o tamanho da pilha como 0
    return pilha;       // Retorna a pilha criada
}

// Função para criar um novo nó
Node* criarNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node)); // Aloca memória para o nó
    if (node == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    return node;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha* pilha) {
    return pilha->tamanho == 0;
}

// Função para adicionar um elemento no topo da pilha
void push(Pilha* pilha, char data) {
    Node* node = criarNode(data); // Cria um novo nó
    if (node == NULL) {
        printf("Erro ao criar um novo nó para push.\n");
        return;
    }

    node->next = pilha->top; // O novo nó aponta para o topo atual
    pilha->top = node;       // Atualiza o topo para o novo nó
    pilha->tamanho++;        // Incrementa o tamanho da pilha
}

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("\nPilha vazia. Erro (underflow)\n");
        return -1; // Erro: underflow
    }

    Node* temp = pilha->top;       // Preserva o topo atual
    char data = temp->data;        // Armazena o dado do topo
    pilha->top = pilha->top->next; // Atualiza o topo para o próximo nó
    free(temp);                     // Libera a memória do nó removido
    pilha->tamanho--;               // Decrementa o tamanho da pilha
    return data;                    // Retorna o dado removido
}

// Função para imprimir a pilha
void imprimirPilha(Pilha* pilha) {
    Pilha* auxPilha = criarPilha(); // Cria uma pilha auxiliar
    if (auxPilha == NULL) {
        return;
    }

    printf("\n[");
    while (!isEmpty(pilha)) {
        char data = pop(pilha); // Remove o topo da pilha
        printf(" %c", data);    // Imprime o caractere
        push(auxPilha, data);   // Adiciona o caractere à pilha auxiliar
    }

    // Restaura a pilha original a partir da pilha auxiliar
    while (!isEmpty(auxPilha)) {
        char data = pop(auxPilha);
        push(pilha, data);
    }

    printf(" ]\n");
    free(auxPilha); // Libera a memória da pilha auxiliar
}

// Função para inicializar a fila
void criarFila(Fila *fila, int capacity) {
    fila->capacity = capacity;
    fila->data = (char *)malloc(capacity * sizeof(char)); // Aloca memória para os dados
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
void enqueue(Fila *fila, char data) {
    if (isFull(fila)) {
        printf("Erro. Overflow!\n");
        return;
    }

    if (fila->front == -1) { // Se a fila está vazia
        fila->front = 0;
        fila->rear = 0;
    } else if (fila->rear == fila->capacity - 1) { // Se o rear chegou ao final, volta para o início (circular)
        fila->rear = 0;
    } else { // Incrementa o rear
        fila->rear++;
    }

    fila->data[fila->rear] = data; // Adiciona o elemento
    fila->size++;                   // Incrementa o tamanho da fila
}

// Função para remover um elemento da fila
char dequeue(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("Erro. Underflow!\n");
        return -1; // Erro: underflow
    }

    char temp = fila->data[fila->front]; // Armazena o elemento a ser removido

    if (fila->size == 1) { // Se havia apenas um elemento
        fila->front = -1;
        fila->rear = -1;
    } else if (fila->front == fila->capacity - 1) { // Se o front chegou ao final, volta para o início (circular)
        fila->front = 0;
    } else { // Incrementa o front
        fila->front++;
    }

    fila->size--; // Decrementa o tamanho da fila
    return temp;  // Retorna o elemento removido
}

// Função para obter o primeiro elemento da fila
char getFront(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("Fila vazia\n");
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
void imprimir(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("\n[ ]\n");
        return;
    }

    Fila auxFila;
    criarFila(&auxFila, fila->capacity); // Cria uma fila auxiliar
    if (auxFila.data == NULL) {
        return;
    }

    printf("\n[");

    // Desenfileira todos os elementos da fila original, enfileirando-os na auxiliar e imprimindo
    while (!isEmptyf(fila)) {
        char front = dequeue(fila);
        printf(" %c", front);
        enqueue(&auxFila, front);
    }

    printf(" ]\n");

    // Restaura os elementos na fila original a partir da fila auxiliar
    while (!isEmptyf(&auxFila)) {
        char auxValor = dequeue(&auxFila);
        enqueue(fila, auxValor);
    }

    free(auxFila.data); // Libera a memória da fila auxiliar
}

// Função para verificar se a expressão está balanceada usando a fila como argumento
int verificarBalanceamento(Fila* fila) {
    Pilha* pilha = criarPilha();
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return 0; // Considera não balanceado em caso de erro de alocação
    }

    // Cria uma fila auxiliar para preservar os elementos da fila original
    Fila auxFila;
    criarFila(&auxFila, fila->capacity);
    if (auxFila.data == NULL) {
        printf("Erro ao alocar memória para a fila auxiliar.\n");
        free(pilha);
        return 0; // Considera não balanceado em caso de erro de alocação
    }

    int balanceado = 1; // Assume balanceado inicialmente

    while (!isEmptyf(fila)) { // Enquanto a fila original não estiver vazia
        char caractere = dequeue(fila);

        // Processa o caractere para verificação de balanceamento
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            push(pilha, caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (isEmpty(pilha)) {
                balanceado = 0; // Fecha sem abrir correspondente
            } else {
                char topo = pop(pilha);
                if ((caractere == ')' && topo != '(') ||
                    (caractere == ']' && topo != '[') ||
                    (caractere == '}' && topo != '{')) {
                    balanceado = 0; // Tipos de parênteses não correspondem
                }
            }
        }

        // Enfileira o caractere de volta na fila auxiliar para preservar a fila original
        enqueue(&auxFila, caractere);
    }

    // Verifica se ainda há elementos na pilha (aberturas sem fechamentos)
    if (!isEmpty(pilha)) {
        balanceado = 0;
    }

    // Restaura os elementos na fila original a partir da fila auxiliar
    while (!isEmptyf(&auxFila)) {
        char caractere = dequeue(&auxFila);
        enqueue(fila, caractere);
    }

    // Libera a memória alocada para a pilha e a fila auxiliar
    free(pilha);
    free(auxFila.data);

    return balanceado;
}
