#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionsort(int vet[], int n) {
    int atual, posmenor;

    // Loop para percorrer todos os elementos do vetor, começando do segundo elemento
    for (int i = 1; i < n; i++) { 
        atual = vet[i]; // O elemento atual a ser inserido na posição correta

        // Move os elementos que são maiores que o atual para a direita
        for (posmenor = i; (posmenor > 0) && (atual < vet[posmenor - 1]); posmenor--) {
            vet[posmenor] = vet[posmenor - 1]; // Desloca o elemento para a direita
        }
        vet[posmenor] = atual; // Insere o elemento atual na posição correta
    }
}


void printfvet(int vet[], int n, char string[100]) {

    printf("\n%s", string);
    for (int i = 0; i < n; i++) {

        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int *vet = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {

        scanf("%d", &vet[i]);
    }

    char text[100] = "Vetor nao ordenado: ";
    printfvet(vet, n, text);
    insertionsort(vet, n);
    strcpy(text, "Vetor ordenado: ");
    printfvet(vet, n, text);

    free(vet);
    return 0;
}
