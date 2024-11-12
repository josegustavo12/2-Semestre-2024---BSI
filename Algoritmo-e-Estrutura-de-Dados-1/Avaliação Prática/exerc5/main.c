// main.c
#include <stdio.h>
#include "matriz_esparsa.h"

int main() {
    MatrizEsparsa *matriz = criar_matriz(3, 3);

    inserir(matriz, 0, 0, 5); // insere no primeiro 
    inserir(matriz, 0, 2, 3);
    inserir(matriz, 1, 1, 8);
    inserir(matriz, 2, 0, -2);
    inserir(matriz, 2, 2, 6); // insere no ultimo

    printf("Matriz original:\n");
    imprimir(matriz);

    printf("\nValor na posição (2,2): %.2f\n", buscar(matriz, 2, 2));

    remover_elemento(matriz, 0, 0);
    printf("\nMatriz após remover o elemento na posição (0,0):\n");
    imprimir(matriz);

    printf("\nSoma interna dos elementos da matriz: %.2f\n", somaInterna(matriz));

    printf("Esparsidade da matriz: %.2f\n", calculaEsparsidade(matriz));

    MatrizEsparsa *outra_matriz = criar_matriz(3, 3);
    inserir(outra_matriz, 0, 1, 4);
    inserir(outra_matriz, 1, 1, -3);
    inserir(outra_matriz, 2, 2, 7);

    MatrizEsparsa *matriz_somada = somar(matriz, outra_matriz);
    printf("\nMatriz resultante da soma:\n");
    if (matriz_somada) { 
        imprimir(matriz_somada);
    }

    liberar_matriz(matriz);
    liberar_matriz(outra_matriz);
    liberar_matriz(matriz_somada);

    return 0;
}
