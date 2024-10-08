#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int vet[], int i, int f){

    int temp;
    temp = vet[i];
    vet[i] = vet[f];
    vet[f] = temp;

}

void selectionsort(int vet[], int n) {
    int posmenor = 0; // posição do menor valor

    for (int i = 0; i < n - 1 ; i++){ 

        posmenor = i; // a medida que o laço for evoluindo a posicao inicial da posmenor vai ser igual a i
        for (int j = i+1; j < n; j++){// for para percorrer o vetor e achar o menor valor
        // j = i+1 -> ele sempre vai iniciar na posição +1 da primeira posição 

            if (vet[j] < vet[posmenor]){
                posmenor = j; // caso ele ache um vetor na posição j que seja menor que o vetor da posição posmenor, ele troca o posmenor para ser igual a j
            }
        }
        swap(vet, posmenor, i); // função de trocar os elementos de lugar 
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
    printf("Digite o tamanho do Vetor:");
    int n;
    scanf("%d", &n);
    int *vet = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {

        scanf("%d", &vet[i]);
    }

    char text[100] = "Vetor nao ordenado: ";
    printfvet(vet, n, text);
    selectionsort(vet, n);
    strcpy(text, "Vetor ordenado: ");
    printfvet(vet, n, text);

    free(vet);
    return 0;
}
