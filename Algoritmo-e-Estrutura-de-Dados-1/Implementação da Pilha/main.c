#include <stdio.h>
#include <stdlib.h>

#include "pilhadinamica.h"

int main()
{
    Pilha* pilha = criarPilha();

    int temp = isEmpty(pilha);

    printf("Est� vazia? %d", temp);

    push(pilha, 5);
    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 50);
    imprimir(pilha);
    pop(pilha);
    imprimir(pilha);
    return 0;
}
