#include <stdio.h>
#include <stdlib.h>

#define VAZIO 0
#define OCUPADO 1
#define REMOVIDO 2

typedef struct {
    int chave;
    int status;
} EntradaHash;

int funcaoHash(int chave, int M) {
    return chave % M;
}

void inserir(EntradaHash *tabela, int M, int chave) {
    int indice = funcaoHash(chave, M);
    int indiceOriginal = indice;
    int primeiroRemovido = -1;

    while (tabela[indice].status != VAZIO) {
        if (tabela[indice].status == OCUPADO && tabela[indice].chave == chave) {
            // Elemento já está na tabela
            return;
        }
        if (tabela[indice].status == REMOVIDO && primeiroRemovido == -1) {
            primeiroRemovido = indice;
        }
        indice = (indice + 1) % M;
        if (indice == indiceOriginal) {
            // Tabela está cheia
            return;
        }
    }

    if (primeiroRemovido != -1) {
        indice = primeiroRemovido;
    }
    tabela[indice].chave = chave;
    tabela[indice].status = OCUPADO;
}

void remover(EntradaHash *tabela, int M, int chave) {
    int indice = funcaoHash(chave, M);
    int indiceOriginal = indice;

    while (tabela[indice].status != VAZIO) {
        if (tabela[indice].status == OCUPADO && tabela[indice].chave == chave) {
            tabela[indice].status = REMOVIDO;
            return;
        }
        indice = (indice + 1) % M;
        if (indice == indiceOriginal) {
            // Elemento não encontrado
            return;
        }
    }
}

int buscar(EntradaHash *tabela, int M, int chave) {
    int indice = funcaoHash(chave, M);
    int indiceOriginal = indice;

    while (tabela[indice].status != VAZIO) {
        if (tabela[indice].status == OCUPADO && tabela[indice].chave == chave) {
            return indice;
        }
        indice = (indice + 1) % M;
        if (indice == indiceOriginal) {
            break;
        }
    }
    return -1;
}

int main() {
    int M, N, D, B;
    int i, chave;

    scanf("%d", &M);
    EntradaHash *tabela = (EntradaHash *)malloc(M * sizeof(EntradaHash));
    for (i = 0; i < M; i++) {
        tabela[i].status = VAZIO;
    }

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &chave);
        inserir(tabela, M, chave);
    }

    scanf("%d", &D);
    for (i = 0; i < D; i++) {
        scanf("%d", &chave);
        remover(tabela, M, chave);
    }

    scanf("%d", &B);
    int *resultados = (int *)malloc(B * sizeof(int));
    for (i = 0; i < B; i++) {
        scanf("%d", &chave);
        resultados[i] = buscar(tabela, M, chave);
    }

    for (i = 0; i < B; i++) {
        printf("%d", resultados[i]);
        if (i < B - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(tabela);
    free(resultados);
    return 0;
}
