#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

int main(){

    Lista* lista = criarLista();
    insertHead(lista, 50);
    insertHead(lista, 40);
    printf("Está Vazia?: %d", isEmpty(lista));
    printf("Tamanho: %d", getSize(lista));
    printLista(lista);
    insertTail(lista, 30);
    printLista(lista);
    insert(lista, 90, 1);


    return 0;
}