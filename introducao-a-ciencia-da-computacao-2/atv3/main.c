#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variaveis de troca do merge e do insertion global infelizmente (ou não)
int troca_insertion = 0, comparacao_insertion = 0;
int troca_merge = 0, comparacao_merge = 0;


void printfvet(int vet[], int n, char string[100]) {
    printf("\n%s", string);
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}

void insertion(int vet[], int n) {
    int vet_insert[n];
    for (int i = 0; i < n; i++) {
        vet_insert[i] = vet[i];
    }

    // definindo as variaveis globais para 0
    troca_insertion = 0;
    comparacao_insertion = 0;

    for (int i = 1; i < n; i++) {
        troca_insertion++;
        int x = vet_insert[i];  // valor a ser inserido
        int j = i - 1;

        // verifica se j é >= 0 e se o valor no índice j é maior que x
        while (j >= 0 && vet_insert[j] > x) {
            comparacao_insertion++;
            vet_insert[j + 1] = vet_insert[j];  // move o elemento maior para a direita
            troca_insertion++;
            j--;
        }
        if (j>=0)comparacao_insertion++;
        troca_insertion++;
        vet_insert[j + 1] = x;  // insere o valor na posição correta
    }
}
void merge(int a[], int c, int f, int b[]){
    if(c >= f) {    
        //comparacao_merge++;   
        return;
    }
    int m = (c+f)/2;
    merge(a, c, m,b);
    merge(a, m+1,f,b);
    int i1 = c;
    int i2 = m+1;
    int j = 0;
    while (i1 <= m && i2 <= f) {
        comparacao_merge++;
        if(a[i1] <= a[i2]){
            b[j] = a[i1];
            troca_merge++;
            i1++;
            j++;
        } 
        else {
            b[j] = a[i2];
            troca_merge++;
            i2++; 
            j++;
        }
    }
    while (i1 <= m) {
        b[j] = a[i1];
        troca_merge++;
        i1++;
        j++;
    }
    while (i2 <= f) {
        b[j] = a[i2];
        troca_merge++;
        i2++;
        j++;
    }
    j = 0;
    for (int i = c, j = 0; i <= f; i++, j++) {
        troca_merge++;  
        a[i] = b[j];
    }
}


int main() {

    int numvet;
    scanf("%d", &numvet); // recebe o numero de vetores

    // alocando espaço para os vetores
    int **matriz = (int **)malloc(numvet * sizeof(int *)); // aloca matriz de ponteiros para vetores

    int *tamanhovet = (int *)malloc(numvet * sizeof(int)); // armazena os tamanhos de cada vetor

    // recebe o tamanho de cada vetor
    for (int i = 0; i < numvet; i++) {
        scanf("%d", &tamanhovet[i]); // recebe o tamanho do vetor i
        matriz[i] = (int *)malloc(tamanhovet[i] * sizeof(int)); // aloca o vetor de tamanho apropriado
    }

    // preenche cada vetor
    for (int i = 0; i < numvet; i++) {
        for (int j = 0; j < tamanhovet[i]; j++) {
            scanf("%d", &matriz[i][j]); // insere os elementos no vetor
        }
    }


    // Para cada vetor, aplicamos Insertion Sort e Merge Sort
    for (int i = 0; i < numvet; i++) {
        // Cria um vetor auxiliar para o merge
        int *b = (int *)malloc(tamanhovet[i] * sizeof(int));

        // Ordenação por Insertion Sort
        insertion(matriz[i], tamanhovet[i]);
        // Imprime os resultados para o Insertion Sort
        printf("I %d %d %d\n", tamanhovet[i], troca_insertion, comparacao_insertion);

        // Resetar as variáveis globais para merge
        troca_merge = 0;
        comparacao_merge = 0;

        // Ordenação por Merge Sort
        merge(matriz[i], 0, tamanhovet[i] - 1, b);
        // Imprime os resultados para o Merge Sort
        printf("M %d %d %d\n", tamanhovet[i], troca_merge, comparacao_merge);

        // Libera a memória do vetor auxiliar
        free(b);
    }




    // libera a memória alocada
    for (int i = 0; i < numvet; i++) {
        free(matriz[i]); // libera cada vetor
    }
    free(matriz); // libera o array de ponteiros
    free(tamanhovet); // libera o array de tamanhos

    return 0;
}

    