// ex1.c
#include "ex1.h"

// Funções da Pilha

// Função para criar uma nova pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (!pilha) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    pilha->top = NULL;
    pilha->tamanho = 0;
    return pilha;
}

// Função para criar um novo nó
Node* criarNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
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
    Node* node = criarNode(data);
    node->next = pilha->top;
    pilha->top = node;
    pilha->tamanho++;
}

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro. Underflow!\n");
        return -1;  // Erro: underflow
    }

    Node* temp = pilha->top;
    char data = temp->data;
    pilha->top = pilha->top->next;
    free(temp);
    pilha->tamanho--;
    return data;
}

// Função para imprimir a pilha (usada apenas para depuração)
void imprimirPilha(Pilha* pilha) {
    Pilha* auxPilha = criarPilha();
    printf("[Top -> ");

    while (!isEmpty(pilha)) {
        char data = pop(pilha);
        printf("%c ", data);
        push(auxPilha, data);
    }

    // Restaura a pilha original
    while (!isEmpty(auxPilha)) {
        char data = pop(auxPilha);
        push(pilha, data);
    }

    printf("]\n");
    free(auxPilha);
}

// Funções da Fila

// Função para inicializar a fila
void criarFila(Fila *fila, int capacity) {
    fila->capacity = capacity;
    fila->data = (char *)malloc(capacity * sizeof(char));
    if (!fila->data) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
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

    if (fila->front == -1) {
        fila->front = 0;
        fila->rear = 0;
    } else if (fila->rear == fila->capacity - 1) {
        fila->rear = 0;
    } else {
        fila->rear += 1;
    }

    fila->data[fila->rear] = data;
    fila->size += 1;
}

// Função para remover um elemento da fila
char dequeue(Fila *fila) {
    if (isEmptyf(fila)) {
        printf("Erro. Underflow!\n");
        return -1;
    }

    char temp = fila->data[fila->front];

    if (fila->size == 1) {
        fila->front = -1;
        fila->rear = -1;
    } else if (fila->front == fila->capacity - 1) {
        fila->front = 0;
    } else {
        fila->front += 1;
    }

    fila->size -= 1;
    return temp;
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
        printf("[ ]\n");
        return;
    }

    Fila auxFila;
    criarFila(&auxFila, fila->capacity);

    printf("[");
    while (!isEmptyf(fila)) {
        char front = dequeue(fila);
        printf(" %c", front);
        enqueue(&auxFila, front);
    }

    // Restaura a fila original
    while (!isEmptyf(&auxFila)) {
        char auxValor = dequeue(&auxFila);
        enqueue(fila, auxValor);
    }
    printf(" ]\n");
    free(auxFila.data);
}

// Função para verificar o balanceamento usando a fila como argumento
int verificarBalanceamento(Fila* fila) {
    // Cria uma pilha auxiliar
    Pilha* pilha = criarPilha();

    // Cria uma fila auxiliar para restaurar a fila original
    Fila tempFila;
    criarFila(&tempFila, fila->capacity);

    // Variável para armazenar o resultado
    int balanceado = 1; // Assume balanceado inicialmente

    // Processa todos os elementos da fila original
    while (!isEmptyf(fila)) {
        // Desenfileira o elemento da fila original
        char caractere = dequeue(fila);

        // Processa o caractere para verificar balanceamento
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            // Se for símbolo de abertura, empilha na pilha auxiliar
            push(pilha, caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            // Se for símbolo de fechamento, verifica a pilha
            if (isEmpty(pilha)) {
                // Pilha vazia, não está balanceado
                balanceado = 0;
            } else {
                char topo = pop(pilha);
                // Verifica se o símbolo de fechamento corresponde ao de abertura
                if ((caractere == ')' && topo != '(') ||
                    (caractere == ']' && topo != '[') ||
                    (caractere == '}' && topo != '{')) {
                    // Não corresponde, não está balanceado
                    balanceado = 0;
                }
            }
        }

        // Enfileira o caractere na fila auxiliar para preservar a ordem original
        enqueue(&tempFila, caractere);
    }

    // Restaura a fila original a partir da fila auxiliar
    while (!isEmptyf(&tempFila)) {
        char caractere = dequeue(&tempFila);
        enqueue(fila, caractere);
    }

    // Verifica se a pilha está vazia após o processamento
    if (!isEmpty(pilha)) {
        // Se ainda houver elementos na pilha, não está balanceado
        balanceado = 0;
    }

    // Libera a memória da pilha auxiliar
    free(pilha);

    // Libera a memória da fila auxiliar
    free(tempFila.data);

    return balanceado;
}
