#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int a[], int n){
    // Variável de controle para verificar se houve troca
    int swapped;

    // Laço externo que percorre toda a lista
    for(int i = 0; i < n - 1; i++) {
        swapped = 0; // Reseta a variável de controle para cada iteração

        // Laço interno para comparar e trocar os elementos
        for(int j = 0; j < n - i - 1; j++) {
            // Se o elemento à esquerda for maior que o da direita, troca-os
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1; // Marca que houve uma troca
            }
        }

        // Se nenhuma troca ocorreu na iteração, o array já está ordenado
        if(swapped == 0) {
            break;
        }
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
    bubble(vet, n);
    strcpy(text, "Vetor ordenado: ");
    printfvet(vet, n, text);

    free(vet);
    return 0;
}
