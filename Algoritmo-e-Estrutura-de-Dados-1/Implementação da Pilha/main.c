#include <stdio.h>
#include <stdlib.h>

#include "pilhadinamica.h"

int main()
{
    Pilha* pilha = criarPilha();

    int temp = isEmpty(pilha);

    printf("Está vazia? %d", temp);

    push(pilha, 5);
    temp = isEmpty(pilha);
    printf("\nEstá Vazia? %d", temp);
    printf("\nTamanho? %d",getSize(pilha));
    pop(pilha);
    imprimir(pilha);
    return 0;
}
