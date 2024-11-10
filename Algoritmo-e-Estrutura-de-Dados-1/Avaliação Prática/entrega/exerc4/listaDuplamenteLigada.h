#ifndef LISTADUPLAMENTELIGADA_H_INCLUDED
#define LISTADUPLAMENTELIGADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int valor;
    struct Node* next;
    struct Node* prev;

}Node;


typedef struct Lista{
    Node* head;
    Node* tail;
    int ordenado;
    int size;

}Lista;


// Função para criar um novo nó
Node* criarNode(int valor);

// Função para inicializar uma lista duplamente ligada
Lista* criarLista();

// Função para adicionar um elemento no início da lista
void insertHead(Lista* lista, int valor);

// Função para adicionar um elemento no final da lista
void insertTail(Lista* lista, int valor);

// Função para buscar um elemento na lista
int buscar(Lista* lista, int valor);

// Função para inserir um elemento em uma posição específica da lista
void insert(Lista* lista, int valor, int position);

// Função para remover um elemento da lista
void removeHead(Lista* lista);

// Função para remover um elemento da lista
void removeTail(Lista* lista);

// Função para remover um elemento da lista
void removeNode(Lista* lista, int position);

// Função para limpar a lista
void clear(Lista* lista);

// Função para verificar se a lista está vazia
int isEmpty(Lista* lista);

// Função para retornar o tamanho da lista
int getSize(Lista* lista);

// Função para imprimir a lista
void printLista(Lista* lista);
//Função para ordenar em ordem decrescente
void ordenar(Lista* lista);

//int buscaBinaria(Node* inicio, Node* tail, int valor);
int buscaBinaria(Lista* lista, int valor);

#endif // LISTADUPLAMENTELIGADA_H_INCLUDED
