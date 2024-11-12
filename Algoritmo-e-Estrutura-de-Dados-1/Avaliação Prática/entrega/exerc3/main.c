#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>

// gcc -o programa main.c ex3.c -Wall

int main() {
    LNSE lista;  // Declara��o de uma lista do tipo LNSE
    criarLNSE(&lista, CAPACITY_MAX);  // Inicializa a lista

    printf("Inserindo 10 na posi��o 0.\n");
    inserir(&lista, 10, 0);  // Insere o valor 10 na posi��o 0
    imprimir(&lista);  // Imprime a lista

    printf("\nInserindo 20 na posi��o 1.\n");
    inserir(&lista, 20, 1);  // Insere o valor 20 na posi��o 1
    imprimir(&lista);  //Imprime a lista

    printf("\nInserindo 30 na posi��o 2.\n");
    inserir(&lista, 30, 2);  // Insere o valor 30 na posi��o 2
    imprimir(&lista);  //Imprime a lista

    printf("\nInserindo 15 na posi��o 1.\n");
    inserir(&lista, 15, 1);  // Insere o valor 15 na posi��o 1 (ap�s o 10)
    imprimir(&lista);  //Imprime a lista

    int valor_removido;  // Vari�vel para armazenar o valor removido
    printf("\nRemovendo o elemento na posi��o 2.\n");
    valor_removido = remover(&lista, 2);  // Remove o elemento da posi��o 2 (valor 20)
    if (valor_removido != -1) {  // Verifica se a remo��o deu certo
        printf("Valor removido: %d\n", valor_removido);  // Mostra o valor removido
    } else {
        printf("Falha na remo��o.\n");
    }
    imprimir(&lista);  //Imprime a lista

    // Buscando um elemento
    int posicao = buscar(&lista, 30);  // Busca o valor 30 na lista
    if (posicao != -1) {
        printf("\nElemento 30 encontrado na posi��o: %d\n", posicao);  // Exibe a posi��o se encontrado
    } else {
        printf("\nElemento 30 n�o encontrado na lista.\n");
    }

    // Obtendo o tamanho da lista
    int tamanho = size_listaLNSE(&lista);  // Obt�m o n�mero de elementos na lista
    printf("Tamanho da lista: %d\n", tamanho);

    // Inserindo mais elementos at� a capacidade m�xima
    printf("\nInserindo 40 na posi��o 3.\n");
    inserir(&lista, 40, 3);  // Insere o valor 40 na posi��o 3
    imprimir(&lista);  //Imprime a lista

    printf("\nInserindo 50 na posi��o 4.\n");
    inserir(&lista, 50, 4);  // Insere o valor 50 na posi��o 4
    imprimir(&lista);  //Imprime a lista

    printf("\nTentando inserir 60 na posi��o 5.\n");
    inserir(&lista, 60, 5);  // Tenta inserir o valor 60 na posi��o 5
    imprimir(&lista);  //Imprime a lista

    printf("\nTentando inserir 70 na posi��o 6.\n");
    inserir(&lista, 70, 6);  // Tenta inserir o valor 70
    imprimir(&lista);  //Imprime a lista

    printf("\nTentando inserir 80 na posi��o 7.\n");
    inserir(&lista, 80, 7);  // Tenta inserir o valor 80
    imprimir(&lista);  //Imprime a lista

    printf("\nTentando inserir 90 na posi��o 8.\n");
    inserir(&lista, 90, 8);  // Tenta inserir o valor 90
    imprimir(&lista);  //Imprime a lista

    printf("\nTentando inserir 100 na posi��o 9.\n");
    inserir(&lista, 100, 9);  // Tenta inserir o valor 100
    imprimir(&lista);  //Imprime a lista

    // Fila cheia: Tentando inserir mais elementos
    printf("\nTentando inserir 110 na posi��o 10.\n");
    inserir(&lista, 110, 10);  //Tenta inserir o valor 110
    imprimir(&lista);  //Imprime a lista

    printf("\nRemovendo o elemento na posi��o 0.\n");
    valor_removido = remover(&lista, 0);  // Remove o elemento na posi��o 0 (valor 10)
    if (valor_removido != -1) {
        printf("Valor removido: %d\n", valor_removido);  // Mostra o valor removido
    } else {
        printf("Falha na remo��o.\n");
    }
    imprimir(&lista);  //Imprime a lista

    printf("\nRemovendo o elemento na posi��o 3.\n");
    valor_removido = remover(&lista, 3);  // Remove o elemento na posi��o 3 (valor 40)
    if (valor_removido != -1) {
        printf("Valor removido: %d\n", valor_removido);  // Mostra o valor removido
    } else {
        printf("Falha na remo��o.\n");
    }
    imprimir(&lista);  //Imprime a lista

    printf("\nInserindo 120 na posi��o 1.\n");
    inserir(&lista, 120, 1);  // Insere o valor 120 na posi��o 1
    imprimir(&lista);  //Imprime a lista

    printf("\nRemovendo o elemento na posi��o 8.\n");
    valor_removido = remover(&lista, 8);  // Remove o elemento na posi��o 8 (valor 100)
    if (valor_removido != -1) {
        printf("Valor removido: %d\n", valor_removido);  // Mostra o valor removido
    } else {
        printf("Falha na remo��o.\n");
    }
    imprimir(&lista);  //Imprime a lista

    // Limpando a lista
    printf("Limpando a lista.\n");
    clearListaLNSE(&lista);  // Limpa a lista
    printf("\nLista ap�s limpeza:\n");
    imprimir(&lista);  // Imprime a lista ap�s a limpeza

    return 0;
}
