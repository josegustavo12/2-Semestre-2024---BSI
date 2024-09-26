#include <stdio.h>
#include <stdlib.h>
#include "fila_estaticaCircular.h"


int main()
{
    Fila fila;
    criarFila(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 50);
    imprimir(&fila);

    dequeue(&fila);
    imprimir(&fila);
    clear(&fila);
    return 0;
}
