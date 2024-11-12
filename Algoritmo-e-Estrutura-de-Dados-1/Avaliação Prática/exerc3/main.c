#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    LNSE lista;
    criarLNSE(&lista, MAX_CAPACITY);

    // Inserindo elementos
    printf("Inserindo 10 na posi��o 0.\n");
    inserir(&lista, 10, 0); // Lista: 10
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 20 na posi��o 1.\n");
    inserir(&lista, 20, 1); // Lista: 10 -> 20
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 30 na posi��o 2.\n");
    inserir(&lista, 30, 2); // Lista: 10 -> 20 -> 30
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 15 na posi��o 1.\n");
    inserir(&lista, 15, 1); // Lista: 10 -> 15 -> 20 -> 30
    imprimir(&lista, MAX_CAPACITY);

    // Removendo um elemento
    int valor_removido;
    printf("Removendo o elemento na posi��o 2.\n");
    if(remover(&lista, 2, &valor_removido)) { // Remove o elemento na posi��o 2 (20)
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    // Buscando um elemento
    int posicao = buscar(&lista, 30);
    if(posicao != -1) {
        printf("Elemento 30 encontrado na posi��o: %d\n", posicao);
    } else {
        printf("Elemento 30 n�o encontrado na lista.\n");
    }

    // Inserindo mais elementos at� a capacidade
    printf("Inserindo 40 na posi��o 3.\n");
    inserir(&lista, 40, 3); // Lista: 10 -> 15 -> 30 -> 40
    imprimir(&lista, MAX_CAPACITY);

    printf("Inserindo 50 na posi��o 4.\n");
    inserir(&lista, 50, 4); // Lista: 10 -> 15 -> 30 -> 40 -> 50
    imprimir(&lista, MAX_CAPACITY);

    // Tentativa de inserir al�m da capacidade
    printf("Tentando inserir 60 na posi��o 5.\n");
    inserir(&lista, 60, 5); // Dever� funcionar, pois MAX_CAPACITY=10
    imprimir(&lista, MAX_CAPACITY);

    // Tentando inserir mais para exceder a capacidade
    printf("Tentando inserir 70 na posi��o 6.\n");
    inserir(&lista, 70, 6); // Continua inserindo at� a capacidade
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 80 na posi��o 7.\n");
    inserir(&lista, 80, 7);
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 90 na posi��o 8.\n");
    inserir(&lista, 90, 8);
    imprimir(&lista, MAX_CAPACITY);

    printf("Tentando inserir 100 na posi��o 9.\n");
    inserir(&lista, 100, 9);
    imprimir(&lista, MAX_CAPACITY);

    // Agora, a fila est� cheia. Tentativa de inserir mais.
    printf("Tentando inserir 110 na posi��o 10.\n");
    inserir(&lista, 110, 10); // Deve falhar
    imprimir(&lista, MAX_CAPACITY);

    // Removendo alguns elementos
    printf("Removendo o elemento na posi��o 0.\n");
    if(remover(&lista, 0, &valor_removido)) { // Remove o elemento 10
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    printf("Removendo o elemento na posi��o 3.\n");
    if(remover(&lista, 3, &valor_removido)) { // Remove o elemento 40
        printf("Valor removido: %d\n", valor_removido);
    }
    imprimir(&lista, MAX_CAPACITY);

    // Inserindo ap�s remo��es
    printf("Inserindo 120 na posi��o 1.\n");
    inserir(&lista, 120, 1); // Lista: 15 -> 120 -> 30 -> 50 -> 60 -> 70 -> 80 -> 90 -> 100
    imprimir(&lista, MAX_CAPACITY);

    // Limpando a lista
    printf("Limpando a lista.\n");
    clearList(&lista, MAX_CAPACITY);
    printf("Lista ap�s limpeza:\n");
    imprimir(&lista, MAX_CAPACITY);

    return 0;
}
