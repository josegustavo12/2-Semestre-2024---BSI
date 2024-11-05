// matriz_esparsa.c
#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

// Função para criar uma matriz esparsa
MatrizEsparsa* criar_matriz(int num_linhas, int num_colunas) {
    MatrizEsparsa *matriz = (MatrizEsparsa*)malloc(sizeof(MatrizEsparsa));
    if (!matriz) {
        printf("Erro de alocação de memória para a matriz.\n");
        exit(EXIT_FAILURE);
    }
    matriz->num_linhas = num_linhas;
    matriz->num_colunas = num_colunas;
    matriz->cabecas_linha = (No**)calloc(num_linhas, sizeof(No*));
    matriz->cabecas_coluna = (No**)calloc(num_colunas, sizeof(No*));
    if (!matriz->cabecas_linha || !matriz->cabecas_coluna) {
        printf("Erro de alocação de memória para as cabeças.\n");
        free(matriz);
        exit(EXIT_FAILURE);
    }
    return matriz;
}

// Função para inserir ou atualizar um valor na matriz
void inserir(MatrizEsparsa *matriz, int linha, int coluna, double valor) {
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return;
    }

    if (valor == 0) {
        // Se o valor for zero, remove o elemento
        remover_elemento(matriz, linha, coluna);
        return;
    }

    // Inserção na lista da linha
    No *anterior_linha = NULL, *atual_linha = matriz->cabecas_linha[linha];
    while (atual_linha && atual_linha->coluna < coluna) {
        anterior_linha = atual_linha;
        atual_linha = atual_linha->prox_na_linha;
    }

    if (atual_linha && atual_linha->coluna == coluna) {
        // Atualiza o valor existente
        atual_linha->valor = valor;
    } else {
        // Cria um novo nó
        No *novo_no = (No*)malloc(sizeof(No));
        if (!novo_no) {
            printf("Erro de alocação de memória para o nó.\n");
            exit(EXIT_FAILURE);
        }
        novo_no->linha = linha;
        novo_no->coluna = coluna;
        novo_no->valor = valor;

        // Insere na lista de linhas
        novo_no->prox_na_linha = atual_linha;
        if (anterior_linha)
            anterior_linha->prox_na_linha = novo_no;
        else
            matriz->cabecas_linha[linha] = novo_no;

        // Insere na lista de colunas
        No *anterior_coluna = NULL, *atual_coluna = matriz->cabecas_coluna[coluna];
        while (atual_coluna && atual_coluna->linha < linha) {
            anterior_coluna = atual_coluna;
            atual_coluna = atual_coluna->prox_na_coluna;
        }
        novo_no->prox_na_coluna = atual_coluna;
        if (anterior_coluna)
            anterior_coluna->prox_na_coluna = novo_no;
        else
            matriz->cabecas_coluna[coluna] = novo_no;
    }
}

// Função para remover um elemento da matriz
void remover_elemento(MatrizEsparsa *matriz, int linha, int coluna) {
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return;
    }

    // Remoção da lista da linha
    No *anterior_linha = NULL, *atual_linha = matriz->cabecas_linha[linha];
    while (atual_linha && atual_linha->coluna < coluna) {
        anterior_linha = atual_linha;
        atual_linha = atual_linha->prox_na_linha;
    }

    if (atual_linha && atual_linha->coluna == coluna) {
        if (anterior_linha)
            anterior_linha->prox_na_linha = atual_linha->prox_na_linha;
        else
            matriz->cabecas_linha[linha] = atual_linha->prox_na_linha;
    } else {
        // Elemento não encontrado
        return;
    }

    // Remoção da lista da coluna
    No *anterior_coluna = NULL, *atual_coluna = matriz->cabecas_coluna[coluna];
    while (atual_coluna && atual_coluna->linha < linha) {
        anterior_coluna = atual_coluna;
        atual_coluna = atual_coluna->prox_na_coluna;
    }

    if (atual_coluna && atual_coluna->linha == linha) {
        if (anterior_coluna)
            anterior_coluna->prox_na_coluna = atual_coluna->prox_na_coluna;
        else
            matriz->cabecas_coluna[coluna] = atual_coluna->prox_na_coluna;
    }

    // Libera o nó
    free(atual_linha);
}

// Função para buscar um valor na matriz
double buscar(MatrizEsparsa *matriz, int linha, int coluna) {
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return 0;
    }

    No *atual = matriz->cabecas_linha[linha];
    while (atual && atual->coluna < coluna) {
        atual = atual->prox_na_linha;
    }

    if (atual && atual->coluna == coluna) {
        return atual->valor;
    } else {
        return 0;
    }
}

// Função para imprimir a matriz completa
void imprimir(MatrizEsparsa *matriz) {
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        for (int j = 0; j < matriz->num_colunas; j++) {
            if (atual && atual->coluna == j) {
                printf("%.2f ", atual->valor);
                atual = atual->prox_na_linha;
            } else {
                printf("0.00 ");
            }
        }
        printf("\n");
    }
}

// Função para somar duas matrizes esparsas
MatrizEsparsa* somar(MatrizEsparsa *m1, MatrizEsparsa *m2) {
    if (m1->num_linhas != m2->num_linhas || m1->num_colunas != m2->num_colunas) {
        printf("As matrizes devem ter o mesmo tamanho\n");
        return NULL;
    }

    MatrizEsparsa *resultado = criar_matriz(m1->num_linhas, m1->num_colunas);

    // Copia os elementos da primeira matriz
    for (int i = 0; i < m1->num_linhas; i++) {
        No *atual = m1->cabecas_linha[i];
        while (atual) {
            inserir(resultado, atual->linha, atual->coluna, atual->valor);
            atual = atual->prox_na_linha;
        }
    }

    // Soma os elementos da segunda matriz
    for (int i = 0; i < m2->num_linhas; i++) {
        No *atual = m2->cabecas_linha[i];
        while (atual) {
            double valor_existente = buscar(resultado, atual->linha, atual->coluna);
            double novo_valor = valor_existente + atual->valor;
            inserir(resultado, atual->linha, atual->coluna, novo_valor);
            atual = atual->prox_na_linha;
        }
    }

    return resultado;
}

// Função para somar todos os valores da matriz
double somaInterna(MatrizEsparsa *matriz) {
    double total = 0;
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        while (atual) {
            total += atual->valor;
            atual = atual->prox_na_linha;
        }
    }
    return total;
}

// Função para calcular a esparsidade da matriz
double calculaEsparsidade(MatrizEsparsa *matriz) {
    int total_elementos = matriz->num_linhas * matriz->num_colunas;
    int num_nao_zero = 0;

    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        while (atual) {
            num_nao_zero++;
            atual = atual->prox_na_linha;
        }
    }

    int num_zero = total_elementos - num_nao_zero;
    return (double)num_zero / total_elementos;
}

// Função para liberar a memória da matriz
void liberar_matriz(MatrizEsparsa *matriz) {
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        while (atual) {
            No *temp = atual;
            atual = atual->prox_na_linha;
            free(temp);
        }
    }
    free(matriz->cabecas_linha);
    free(matriz->cabecas_coluna);
    free(matriz);
}
