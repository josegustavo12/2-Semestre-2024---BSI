#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printfvet(int vet[], int n, char string[100]) {

    printf("\n%s", string);
    for (int i = 0; i < n; i++) {

        printf("%d ", vet[i]);
    }
    printf("\n");
}

void heapify(int vet[], int p, int u) {
    if (p <= u) { // vrifica se o índice do pai está dentro dos limites do vetor

        int c = 2 * p + 1; // indice do filho à esquerda
        if (c <= u) { // verifica se o filho à esquerda existe

            if (c + 1 <= u && vet[c + 1] > vet[c]) { // verifica se o filho à direita existe e é maior que o filho à esquerda

                c++; // se sim, o índice do filho direito é atualizado para 'c'
            }

            if (vet[c] > vet[p]) { // se o filho for maior que o pai, troque-os

                int temp = vet[c]; // troca o valor do pai com o filho
                vet[c] = vet[p];
                vet[p] = temp;
                heapify(vet, c, u); // recursivamente chama a função para garantir que o heap esteja correto a partir do novo pai
            }
        }
    }
}

// função para ordenar o vetor usando o algoritmo Heap Sort
void heap(int vet[], int n) {
    // construir o heap inicial (reorganizando o vetor)
    for (int i = n / 2 - 1; i >= 0; i--) { // vai do meio do vetor até o início (índice 0)

        heapify(vet, i, n - 1); // chamando heapify para garantir que a propriedade de heap seja mantida
    }

    // extração do maior elemento do heap e reorganização do restante
    for (int j = n - 1; j >= 1; j--) {

        int temp = vet[0]; // troca o maior elemento (na raiz do heap) com o último elemento não ordenado
        vet[0] = vet[j];
        vet[j] = temp;
        heapify(vet, 0, j - 1); // reorganiza o heap considerando o vetor reduzido (sem o elemento já ordenado)
    }
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
    heap(vet, n);
    strcpy(text, "Vetor ordenado: ");
    printfvet(vet, n, text);

    free(vet);
    return 0;
}
