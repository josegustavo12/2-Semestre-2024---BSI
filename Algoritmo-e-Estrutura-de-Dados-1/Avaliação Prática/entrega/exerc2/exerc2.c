#include <stdio.h>
#include <stdlib.h>
#include "exerc2.h"

//função que inicializa a pilha dupla 
void inicializarPilhaDupla(PilhaDupla* pilha){
    pilha->topA = MAX;
    pilha->topB = -1;
}

void pushA (PilhaDupla* pilha, int data){
    if(pilha->topA - 1 == pilha->topB){ //verifica se a pilha está cheia
        printf ("Erro. Overflow.");
        return;
    }
    else{
            pilha->topA--;
            pilha->list[pilha->topA] = data;
            return;
}
}

void pushB (PilhaDupla* pilha, int data){
    if(pilha->topB + 1 == pilha->topA){ //verifica se a pilha está cheia
        printf ("Erro. Overflow.");
        return;
    }
    else{
            pilha->topB++;
            pilha->list[pilha->topB] = data;
            return;
}
}

int popA(PilhaDupla* pilha){
    if (pilha->topA == MAX){ //verifica se a pilha está vazia
        printf("Erro. Underflow\n");
        return 0;
    }
    else{
        int valor = pilha->list[pilha->topA];
        pilha->topA++;
        return valor;

    }
}

int popB(PilhaDupla* pilha){
    if (pilha->topB == -1){ //verifica se a pilha esta vazia
        printf("Erro. Underflow\n");
        return 0;
    }
    else{
        int valor = pilha->list[pilha->topB];
        pilha->topB--;
        return valor;

    }
}

//função para limpar a pilha A
void clearA(PilhaDupla* pilha){
    while (pilha->topA <= MAX -1){ //verifica se ainda há elementos na pilha A para apagar
        popA(pilha);
    }

    return;
}

//função para limpar a pilha B
void clearB(PilhaDupla* pilha){
    while (pilha->topB >= 0){ //verifica se ainda há elementos na pilha B para apagar
        popB(pilha);
    }

    return;
}

//função para impriir a pilha A
void imprimirA (PilhaDupla* pilha){
    if (pilha->topA == MAX){ //verifica se a pilha A está vazia
        return;
    }
    else{
        printf ("[");
        for (int i = pilha->topA; i < MAX; i++){ //for que percorre cada elemento da pilha A para imprimir
            printf ("%d", pilha->list[i]);
            if (i < MAX - 1){
                printf (",");
            }
        }
         printf ("]\n");
    }
}

//função para imprimir a pilha B
void imprimirB (PilhaDupla* pilha){
    if (pilha->topB == -1){
        return;
    }
    else{
        printf ("[");
        for (int i = pilha->topB; i > -1; i--){ //for que percorre cada elemento da pilha B para imprimir
            printf ("%d", pilha->list[i]);
            if (i > 0){
                 printf (",");
            }
        }
         printf ("]\n");
    }
}
