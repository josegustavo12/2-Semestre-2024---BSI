// main.c
#include <stdio.h>
#include "matriz_esparsa.h"

int main() {
    // Criar uma matriz esparsa 3x3
    MatrizEsparsa *matriz = criar_matriz(3, 3);

    // Inserir valores
    inserir(matriz, 0, 0, 5);
    inserir(matriz, 0, 2, 3);
    inserir(matriz, 1, 1, 8);
    inserir(matriz, 2, 0, -2);
    inserir(matriz, 2, 2, 6);

    // Imprimir a matriz
    printf("Matriz original:\n");
    imprimir(matriz);

    // Buscar um valor
    printf("\nValor na posição (1,1): %.2f\n", buscar(matriz, 1, 1));

    // Remover um valor
    remover_elemento(matriz, 0, 2);
    printf("\nMatriz após remover o elemento na posição (0,2):\n");
    imprimir(matriz);

    // Soma interna dos elementos
    printf("\nSoma interna dos elementos da matriz: %.2f\n", somaInterna(matriz));

    // Calcular esparsidade
    printf("Esparsidade da matriz: %.2f\n", calculaEsparsidade(matriz));

    // Criar outra matriz para soma
    MatrizEsparsa *outra_matriz = criar_matriz(3, 3);
    inserir(outra_matriz, 0, 1, 4);
    inserir(outra_matriz, 1, 1, -3);
    inserir(outra_matriz, 2, 2, 7);

    // Somar matrizes
    MatrizEsparsa *matriz_somada = somar(matriz, outra_matriz);
    printf("\nMatriz resultante da soma:\n");
    if (matriz_somada) { // Verifica se a soma foi bem-sucedida
        imprimir(matriz_somada);
    }

    // Liberar memória
    liberar_matriz(matriz);
    liberar_matriz(outra_matriz);
    liberar_matriz(matriz_somada);

    return 0;
}
