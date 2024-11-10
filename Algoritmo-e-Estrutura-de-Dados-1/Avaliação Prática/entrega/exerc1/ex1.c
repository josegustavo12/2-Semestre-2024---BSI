// ex1.c
#include "ex1.h"

// Funções da Pilha

// Função para criar uma nova pilha
Pilha* criarPilha() {

    // Usaremos malloc para que a pilha possa ser usada em outras funcoes e para evitar ter que retornar uma copia dela
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha)); //aloca mem�ria pra nossa pilha

    //inicializa��o da pilha
    pilha->top = NULL; //topo como null
    pilha->tamanho = 0; //tamanho da pilha como 0
    return pilha;       //retorna a pilha que foi criada
}

// Função para criar um novo nó
Node* criarNode(char data) {

    // Usaremos malloc para que o noh possa ser usada em outras funcoes e para evitar ter que retornar uma copia dele
    Node* node = (Node*)malloc(sizeof(Node)); //aloca mem�ria pro n� da nossa pilha

    node->data = data;
    node->next = NULL;

    return node;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha* pilha) {
    //verifica o tamanho da pilha, se estiver vazia retorna 1 sen�o retorna 0
    if (pilha->tamanho==0){
        return 1;
    }
    else{
        return 0;
    }

    // Outras maneiras v lidas
    //------------------------
    // return pilha->tamanho==0;
    // return pilha->top == NULL;
    //------------------------
}

// Função para adicionar um elemento no topo da pilha
void push(Pilha* pilha, char data) {
    Node* node = criarNode(data); //cria um novo n�

    // O novo noh ira apontar para o noh que era o topo antes
    node->next = pilha->top;

    // Substitui o topo pelo novo noh
    pilha->top = node;
    pilha->tamanho++; //aumenta o tamanho da pilha
}

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha) {

    if ( isEmpty(pilha) ) {
        printf("\nPilha vazia. Erro (underflow)");
        return -1;  // Erro: underflow
    }

    Node* temp = pilha->top; //preserva o topo atual
    char data = temp->data;  //armazena ele

    // O novo noh sera o que estava apontado pelo noh que sera excluido
    pilha->top = pilha->top->next;

    // Libera o espa o de mem ria que foi alocado para o noh
    free(temp);

    pilha->tamanho--; //diminui o tamanho da pilha

    return data; //retorna o que foi removida
}

// Função para imprimir a pilha (usada apenas para depuração)
void imprimirPilha(Pilha* pilha) {
    Pilha* auxPilha = criarPilha();
    printf("\n[");

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
    if (fila->size >= fila->capacity) {
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
    if (fila->size == 0) {
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
        fila->front = fila->front +1;
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
    // Seguindo as regras da fila, a unica forma de
    // acessar todos os seus valores, eh destruindo ela
    while (!isEmptyf(fila)) {
        char front = dequeue(fila);
        // Salva na fila auxiliar para recuperar depois
        enqueue(&auxFila, front);
        printf(" %c", front);
    }

    // Restaura a fila original
    while (!isEmptyf(&auxFila)) {
        char auxValor = dequeue(&auxFila);
         // Recupera o valor na fila principal
        enqueue(fila, auxValor);
    }
    printf(" ]\n");
    free(auxFila.data);
}

// Função para verificar se a express�o est� balanceada usando a fila como argumento
int verificarBalanceamento(Fila* fila) {
    Pilha* pilha = criarPilha();

    // Cria uma fila auxiliar para preservar os elementos da fila original
    Fila auxFila;
    criarFila(&auxFila, fila->capacity);

    int balanceado = 1; // Assume balanceado inicialmente


    while (fila->front != -1) { // Usando o front da fila para verificar se ela não está vazia
        char caractere = dequeue(fila); //atribui o elemento que foi retirado da fila na variavel topo

        if (caractere == '(' || caractere == '[' || caractere == '{') { // se caractere for um simbolo  do tipo abertura ele é adicionado na pilha
            push(pilha, caractere); //acrescenta o caractere na pilha
        } else if (caractere == ')' || caractere == ']' || caractere == '}') { // se caractere for um simbolo for do tipo fechamento ele é verificado
            if (isEmpty(pilha)) {
                balanceado = 0;// Não está balanceada, se a pilha estiver vazia
            }else{
                char topo = pop(pilha); //atribui o top da pilha que foi retirado na variavel topo
                if ((caractere == ')' && topo != '(') || (caractere == ']' && topo != '[') || (caractere == '}' && topo != '{')) {  //verifica se o caractere de fechamento corresponde ao caractere de abertura
                    balanceado = 0;//quando retorna 0, significa que não estábalanceada
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

    // Libera a mem�ria alocada para a pilha e a fila auxiliar
    free(pilha);
    free(auxFila.data);

    return balanceado;
}

