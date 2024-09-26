#include <stdio.h>
#include <stdlib.h>

#include "pilhadinamica.h"

int main()
{
    Pilha* pilha = criarPilha();

    int temp = isEmpty(pilha);

    printf("Est� vazia? %d", temp);

    push(pilha, 5);
    temp = isEmpty(pilha);
    printf("\nEst� Vazia? %d", temp);
    printf("\nTamanho? %d",getSize(pilha));
    pop(pilha);
    imprimir(pilha);
    return 0;
}
