#include <stdio.h>
#include <stdlib.h>
#include "exerc2.h"

void inicializarPilhaDupla(PilhaDupla* pilha){
    pilha->topA = MAX;
    pilha->topB = -1;
}

void pushA (PilhaDupla* pilha, int data){
    if(pilha->topA - 1 == pilha->topB){
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
    if(pilha->topB + 1 == pilha->topA){
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
    if (pilha->topA == MAX){ //verifica se a pilha esta vazia
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

void clearA(PilhaDupla* pilha){
    while (pilha->topA <= MAX -1){
        popA(pilha);
    }

    return;
}


void clearB(PilhaDupla* pilha){
    while (pilha->topB >= 0){
        popB(pilha);
    }

    return;
}

void imprimirA (PilhaDupla* pilha){
    if (pilha->topA == MAX){
        return;
    }
    else{
        printf ("[");
        for (int i = pilha->topA; i < MAX; i++){
            printf ("%d", pilha->list[i]);
            if (i < MAX - 1){
                printf (",");
            }
        }
         printf ("]\n");
    }
}

void imprimirB (PilhaDupla* pilha){
    if (pilha->topB == -1){
        return;
    }
    else{
        printf ("[");
        for (int i = pilha->topB; i > -1; i--){
            printf ("%d", pilha->list[i]);
            if (i > 0){
                 printf (",");
            }
        }
         printf ("]\n");
    }
}
