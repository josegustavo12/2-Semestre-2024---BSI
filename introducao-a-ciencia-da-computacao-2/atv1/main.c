#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printfvet(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void bolha(int vet[], int n) {
    int temporario;
    int ultimaTroca;

    for (int i = 0; i < n - 1; i++) {
        ultimaTroca = n - 1;  

        for (int j = 0; j < ultimaTroca; j++) {
            printf("C %d %d \n", j, j + 1);
    int temporario, ultimatroca, troca;

    for (int i = 0; i < n-1; i++) {
        troca = 0;
        ultimatroca = 0;
        for (int j = 0; j < n-1 - i; j++) {
            printf("C %d %d \n", j, j+1);
            if (vet[j] > vet[j + 1]) {
                printf("T %d %d \n", j, j + 1);
                temporario = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temporario;
                ultimaTroca = j;  
            }
        }


        if (ultimaTroca == n - 1) {
                vet[j] = vet[j+1];
                vet[j+1] = temporario;
                troca = 1;
                ultimatroca = j;
            }
        }

        if (troca == 0) {
            break;
        }
        i = n - 2 - ultimatroca;
    }
}


void selecao(int vet[], int n){
    int min, temporario;

    for (int i = 0; i < n-1; i++){

        min = i;
        for (int j = i + 1; j < n; j++){

            printf("C %d %d \n", min, j);
            if (vet[j] < vet[min]){

                min = j;
            }
        }

        printf("T %d %d \n", i, min);
        temporario = vet[i];
        vet[i] = vet[min];
        vet[min] = temporario;
    }
}


int main() {
    char metodo[10];
    scanf("%s", metodo);

    int n;
    scanf("%d", &n);
    int *vet = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    if (strcmp(metodo, "selecao") == 0) {
        selecao(vet, n);
        printfvet(vet, n);
    } else if (strcmp(metodo, "bolha") == 0) {
        bolha(vet, n);
        printfvet(vet, n);
    }

    free(vet);
    return 0;
}
