#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteLigada.h"

//  gcc -o programa main.c listaDuplamenteLigada.c -Wall

int main()
{

    Lista* lista = criarLista();

    printf("\nEstá vazia? %d", isEmpty(lista));

    printf("\nTamanho: %d", getSize(lista));

   
     insertHead(lista, 10);
    printLista(lista);

     insertHead(lista, 5);
     printLista(lista);

    insertTail(lista, 3);
    printLista(lista);

    insert(lista, 8, 2);
     printLista(lista);


     insertTail(lista, 9);
    printLista(lista);


     insert(lista, 7, 4);
    printLista(lista);


    printf("\nBusca antes de ordenar:");

    printf("\nbusca(5)");
    int pos = buscar(lista,5);
    printf("\nPosicao: %d", pos);


    ordenar(lista);


    printLista(lista);


    printf("\nBusca depois de ordenar:");

    printf("\n\nbusca(5)");
    int pos1 = buscar(lista,5);
    printf("\nPosicao: %d \n", pos1);



    return 0;
}
