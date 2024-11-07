#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    LNSE lista;
    criarLNSE(&lista, MAX_CAPACITY);

    // Inserindo elementos
    printf("Inserindo 10 na posição 0.\n");
    inserir(&lista, 10, 0); // Lista: 10
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 20 na posição 1.\n");
    inserir(&lista, 20, 1); // Lista: 10 -> 20
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 30 na posição 2.\n");
    inserir(&lista, 30, 2); // Lista: 10 -> 20 -> 30
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 15 na posição 1.\n");
    inserir(&lista, 15, 1); // Lista: 10 -> 15 -> 20 -> 30
    imprimir(&lista, MAX_CAPACITY);

    // Removendo um elemento
    int valor_removido;
    printf("Removendo o elemento na posição 2.\n");
    if(remover(&lista, 2, &valor_removido)) { // Remove o elemento na posição 2 (20)
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    // Buscando um elemento
    int posicao = buscar(&lista, 30);
    if(posicao != -1) {
        printf("Elemento 30 encontrado na posição: %d\n", posicao);
    } else {
        printf("Elemento 30 não encontrado na lista.\n");
    }

    // Tamanho da lista
    int tamanho = size_list(&lista);
    printf("Tamanho da lista: %d\n", tamanho);

    // Inserindo mais elementos até a capacidade
    printf("Inserindo 40 na posição 3.\n");
    inserir(&lista, 40, 3); // Lista: 10 -> 15 -> 30 -> 40
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 50 na posição 4.\n");
    inserir(&lista, 50, 4); // Lista: 10 -> 15 -> 30 -> 40 -> 50
    imprimir(&lista, MAX_CAPACITY);

    // Tentativa de inserir além da capacidade
    printf("Tentando inserir 60 na posição 5.\n");
    inserir(&lista, 60, 5); // Deverá funcionar, pois MAX_CAPACITY=10
    imprimir(&lista, MAX_CAPACITY);

    // Tentando inserir mais para exceder a capacidade
    printf("Tentando inserir 70 na posição 6.\n");
    inserir(&lista, 70, 6); // Continua inserindo até a capacidade
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 80 na posição 7.\n");
    inserir(&lista, 80, 7);
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 90 na posição 8.\n");
    inserir(&lista, 90, 8);
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 100 na posição 9.\n");
    inserir(&lista, 100, 9);
    imprimir(&lista, MAX_CAPACITY);

    // Agora, a fila está cheia. Tentativa de inserir mais.
    printf("Tentando inserir 110 na posição 10.\n");
    inserir(&lista, 110, 10); // Deve falhar
    imprimir(&lista, MAX_CAPACITY);

    // Removendo alguns elementos
    printf("Removendo o elemento na posição 0.\n");
    if(remover(&lista, 0, &valor_removido)) { // Remove o elemento 10
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    printf("Removendo o elemento na posição 3.\n");
    if(remover(&lista, 3, &valor_removido)) { // Remove o elemento 40
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    // Inserindo após remoções
    printf("Inserindo 120 na posição 1.\n");
    inserir(&lista, 120, 1); // Lista: 15 -> 120 -> 30 -> 50 -> 60 -> 70 -> 80 -> 90 -> 100
    imprimir(&lista, MAX_CAPACITY);

    // Limpando a lista
    printf("Limpando a lista.\n");
    clearList(&lista, MAX_CAPACITY);
    printf("Lista após limpeza:\n");
    imprimir(&lista, MAX_CAPACITY);

    return 0;
}
