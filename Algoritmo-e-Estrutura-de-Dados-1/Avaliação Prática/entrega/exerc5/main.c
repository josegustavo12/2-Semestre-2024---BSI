#include <stdio.h>
#include "matriz_esparsa.h"

// gcc -o programa main.c matriz_esparsa.c -Wall

int main() {
    // Criar uma matriz esparsa 4x4
    MatrizEsparsa *matriz = criar_matriz(4, 4);

    // Inserir valores em posições diversas
    inserir(matriz, 0, 0, 5);
    inserir(matriz, 0, 3, 10);
    inserir(matriz, 1, 1, 8);
    inserir(matriz, 2, 2, -3);
    inserir(matriz, 3, 0, 7);
    inserir(matriz, 3, 3, 6);

    // Tentar inserir um valor zero (deve remover se existir ou não inserir)
    inserir(matriz, 1, 2, 0);

    // Imprimir a matriz
    printf("Matriz original:\n");
    imprimir(matriz);

    // Buscar valores existentes e não existentes
    printf("\nValor na posição (1,1): %.2f\n", buscar(matriz, 1, 1));
    printf("Valor na posição (1,2): %.2f\n", buscar(matriz, 1, 2)); // Deve ser 0

    // Remover um valor existente
    remover_elemento(matriz, 0, 3);
    printf("\nMatriz após remover o elemento na posição (0,3):\n");
    imprimir(matriz);

    // Remover um valor que não existe (deve manter a matriz inalterada)
    remover_elemento(matriz, 2, 3);
    printf("\nMatriz após tentar remover o elemento na posição (2,3) (não existente):\n");
    imprimir(matriz);

    // Soma interna dos elementos
    printf("\nSoma interna dos elementos da matriz: %.2f\n", somaInterna(matriz));

    // Calcular esparsidade
    printf("Esparsidade da matriz: %.2f\n", calculaEsparsidade(matriz));

    // Criar outra matriz para soma
    MatrizEsparsa *outra_matriz = criar_matriz(4, 4);
    inserir(outra_matriz, 0, 1, 4);
    inserir(outra_matriz, 1, 1, -3);
    inserir(outra_matriz, 2, 2, 7);
    inserir(outra_matriz, 3, 3, -6);

    // Imprimir a outra matriz
    printf("\nOutra matriz:\n");
    imprimir(outra_matriz);

    // Somar matrizes
    MatrizEsparsa *matriz_somada = somar(matriz, outra_matriz);
    printf("\nMatriz resultante da soma:\n");
    if (matriz_somada) {
        imprimir(matriz_somada);
    }

    // Testar soma com matrizes de tamanhos diferentes
    MatrizEsparsa *matriz_diferente = criar_matriz(3, 3);
    MatrizEsparsa *soma_invalida = somar(matriz, matriz_diferente);
    if (!soma_invalida) {
        printf("\n\nNão foi possível somar matrizes de tamanhos diferentes.\n");
    }

    // Testar inserção fora dos limites (deve exibir mensagem de erro)
    inserir(matriz, -1, 0, 5); // Linha inválida
    inserir(matriz, 0, 5, 10); // Coluna inválida

    // Liberar memória
    liberar_matriz(matriz);
    liberar_matriz(outra_matriz);
    liberar_matriz(matriz_somada);
    liberar_matriz(matriz_diferente);

    return 0;
}
