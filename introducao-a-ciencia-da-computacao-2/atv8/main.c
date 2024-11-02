#include <stdio.h>

int buscabinaria(int vet[], int n, int valor){
    int ini = 0;
    int fim = n-1;
    while(ini <= fim){
        int i = (ini + fim) / 2;
        if (vet[i] == valor){
            return 1;
        }
        if (vet[i] < valor) {  
            ini = i + 1;
        } 
        else {  
            fim = i - 1;
        }
    }
    return 0;
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

void printfvet(int n, int vet[]){
    for (int i = 0; i < n; i++){
        printf("%d\n", vet[i]);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int vet[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    heap(vet, n);

    int m; // tamanho do vetor que dos elementos que vão ser buscados
    scanf("%d", &m);

    int vetbuscas[m];
    for (int j = 0; j < m; j++){
        scanf("%d", &vetbuscas[j]);
    }

    int vetresp[m]; // vetor para armazenar as respostas
    for (int k = 0; k < m; k++){
        vetresp[k] = buscabinaria(vet, n, vetbuscas[k]);
    }

    printfvet(m, vetresp);


}