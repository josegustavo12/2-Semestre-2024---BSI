#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H


// Criação do nó da pilha dinamica
typedef struct Node{ // tem que nomear a struct porque utiliza ela dentro da própria struct

    int data; // dado dentro do nó
    struct Node* next; // autoreferencia de dentro da struct

} Node;

typedef struct{

    Node* top; // indica quem é o primeiro valor da pilha
    int tamanho; // indica o tamanho da pilha

} Pilha;

Pilha* criarNode(int data); // função do tipo Pilha pra construir o nó

Pilha* criarPilha(); // função do tipo Pilha para construir a pilha

int getSize(Pilha* pilha);

int isEmpty(Pilha* pilha); // função para retornar se a pilha está vazia ou n

void push(Pilha* pilha, int data); // função para inserir algo na pilha

int pop(Pilha* pilha); // função para retirar algo da pilha

void imprimir(Pilha* pilha);


#endif // PILHADINAMICA_H
