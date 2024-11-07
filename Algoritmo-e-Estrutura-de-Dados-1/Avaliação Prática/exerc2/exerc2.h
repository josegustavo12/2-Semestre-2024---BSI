#ifndef EXERC2_H_INCLUDED
#define EXERC2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int list [MAX]; //vetor com os elementos da pilha dupla
    int topA; // indice do topo da Pilha A
    int topB; // indice topo da Pilha B
} PilhaDupla;

void inicializarPilhaDupla(PilhaDupla* pilha);

void pushA (PilhaDupla* pilha, int data);

void pushB (PilhaDupla* pilha, int data);

int popA(PilhaDupla*pilha);

int popB(PilhaDupla* pilha);

void clearA(PilhaDupla* pilha);

void clearB(PilhaDupla* pilha);

void imprimirA (PilhaDupla* pilha);

void imprimirB(PilhaDupla* pilha);

#endif // EXERC2_H_INCLUDED
