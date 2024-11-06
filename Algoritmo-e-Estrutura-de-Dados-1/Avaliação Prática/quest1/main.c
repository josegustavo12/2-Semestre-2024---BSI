#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// Função de teste para verificar o balanceamento de uma sequência
void teste(int tamanho, const char *sequencia) {
    Fila fila;
    criarFila(&fila, tamanho); // Chama a função criarFila

    // Adiciona cada elemento da sequência na fila
    for (int i = 0; i < tamanho; i++) {
        enqueue(&fila, sequencia[i]);
    }

    // Verifica se a sequência está balanceada
    int resultado = verificarBalanceamento(&fila);

    // Imprime a fila
    imprimir(&fila);

    // Com base no resultado, imprime se está balanceada ou não
    if (resultado) {
        printf("Sequência está balanceada.\n");
    } else {
        printf("Sequência não está balanceada.\n");
    }
}

// Casos de teste
int main() {
    printf("Teste 1: \"()[{}\"\n");
    teste(5, "()[{}");  // Teste 1

    printf("\nTeste 2: \"{[]}\"\n");
    teste(4, "{[]}");   // Teste 2

    printf("\nTeste 3: \"([{()}])\"\n");
    teste(8, "([{()}])"); // Teste 3

    printf("\nTeste 4: \"{([])}\"\n");
    teste(6, "{([])}");    // Teste 4

    printf("\nTeste 5: \"[)))()]\"\n");
    teste(7, "[)))()]");    // Teste 5

    return 0;
}
