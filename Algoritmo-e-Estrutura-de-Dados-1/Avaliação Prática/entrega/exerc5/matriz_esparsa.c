// matriz_esparsa.c

#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

// Função para criar uma matriz esparsa
MatrizEsparsa* criar_matriz(int num_linhas, int num_colunas) {
    // Aloca memória para a estrutura principal da matriz esparsa
    MatrizEsparsa *matriz = (MatrizEsparsa*)malloc(sizeof(MatrizEsparsa));
    if (!matriz) {
        printf("Erro de alocação de memória para a matriz.\n");
        exit(EXIT_FAILURE);
    }
    // Define o número de linhas e colunas da matriz
    matriz->num_linhas = num_linhas;
    matriz->num_colunas = num_colunas;
    // Aloca e inicializa os vetores de cabeças de linha e coluna
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
    // Verifica se a posição é válida dentro das dimensões da matriz
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return;
    }

    if (valor == 0) {
        // Se o valor for zero, remove o elemento da matriz
        remover_elemento(matriz, linha, coluna);
        return;
    }

    // Inserção na lista da linha
    No *anterior_linha = NULL, *atual_linha = matriz->cabecas_linha[linha];
    // Percorre a lista até encontrar a posição correta ou o fim
    while (atual_linha && atual_linha->coluna < coluna) {
        anterior_linha = atual_linha;
        atual_linha = atual_linha->prox_na_linha;
    }

    if (atual_linha && atual_linha->coluna == coluna) {
        // Atualiza o valor existente se o nó já estiver na posição
        atual_linha->valor = valor;
    } else {
        // Cria um novo nó para inserir na matriz
        No *novo_no = (No*)malloc(sizeof(No));
        if (!novo_no) {
            printf("Erro de alocação de memória para o nó.\n");
            exit(EXIT_FAILURE);
        }
        // Inicializa o novo nó com as informações fornecidas
        novo_no->linha = linha;
        novo_no->coluna = coluna;
        novo_no->valor = valor;

        // Insere na lista de linhas
        novo_no->prox_na_linha = atual_linha;
        if (anterior_linha)
            anterior_linha->prox_na_linha = novo_no;
        else
            // Atualiza a cabeça da linha se for o primeiro elemento
            matriz->cabecas_linha[linha] = novo_no;

        // Insere na lista de colunas
        No *anterior_coluna = NULL, *atual_coluna = matriz->cabecas_coluna[coluna];
        // Percorre a lista até encontrar a posição correta ou o fim
        while (atual_coluna && atual_coluna->linha < linha) {
            anterior_coluna = atual_coluna;
            atual_coluna = atual_coluna->prox_na_coluna;
        }
        novo_no->prox_na_coluna = atual_coluna;
        if (anterior_coluna)
            anterior_coluna->prox_na_coluna = novo_no;
        else
            // Atualiza a cabeça da coluna se for o primeiro elemento
            matriz->cabecas_coluna[coluna] = novo_no;
    }
}

// Função para remover um elemento da matriz
void remover_elemento(MatrizEsparsa *matriz, int linha, int coluna) {
    // Verifica se a posição é válida dentro das dimensões da matriz
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return;
    }

    // Remoção da lista da linha
    No *anterior_linha = NULL, *atual_linha = matriz->cabecas_linha[linha];
    // Percorre a lista até encontrar o nó a ser removido
    while (atual_linha && atual_linha->coluna < coluna) {
        anterior_linha = atual_linha;
        atual_linha = atual_linha->prox_na_linha;
    }

    if (atual_linha && atual_linha->coluna == coluna) {
        // Remove o nó da lista de linhas
        if (anterior_linha)
            anterior_linha->prox_na_linha = atual_linha->prox_na_linha;
        else
            matriz->cabecas_linha[linha] = atual_linha->prox_na_linha;
    } else {
        // Elemento não encontrado; não há nada para remover
        return;
    }

    // Remoção da lista da coluna
    No *anterior_coluna = NULL, *atual_coluna = matriz->cabecas_coluna[coluna];
    // Percorre a lista até encontrar o nó a ser removido
    while (atual_coluna && atual_coluna->linha < linha) {
        anterior_coluna = atual_coluna;
        atual_coluna = atual_coluna->prox_na_coluna;
    }

    if (atual_coluna && atual_coluna->linha == linha) {
        // Remove o nó da lista de colunas
        if (anterior_coluna)
            anterior_coluna->prox_na_coluna = atual_coluna->prox_na_coluna;
        else
            matriz->cabecas_coluna[coluna] = atual_coluna->prox_na_coluna;
    }

    // Libera a memória alocada para o nó
    free(atual_linha);
}

// Função para buscar um valor na matriz
double buscar(MatrizEsparsa *matriz, int linha, int coluna) {
    // Verifica se a posição é válida dentro das dimensões da matriz
    if (linha < 0 || linha >= matriz->num_linhas || coluna < 0 || coluna >= matriz->num_colunas) {
        printf("Posição inválida\n");
        return 0;
    }

    // Percorre a lista de nós na linha especificada
    No *atual = matriz->cabecas_linha[linha];
    while (atual && atual->coluna < coluna) {
        atual = atual->prox_na_linha;
    }

    if (atual && atual->coluna == coluna) {
        // Retorna o valor encontrado
        return atual->valor;
    } else {
        // Se não encontrar, retorna zero (valor padrão)
        return 0;
    }
}

// Função para imprimir a matriz completa
void imprimir(MatrizEsparsa *matriz) {
    // Percorre cada linha da matriz
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        // Percorre cada coluna da matriz
        for (int j = 0; j < matriz->num_colunas; j++) {
            if (atual && atual->coluna == j) {
                // Imprime o valor do nó se existir na posição
                printf("%.2f ", atual->valor);
                atual = atual->prox_na_linha;
            } else {
                // Imprime zero se não houver nó na posição
                printf("0.00 ");
            }
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }
}

// Função para somar duas matrizes esparsas
MatrizEsparsa* somar(MatrizEsparsa *m1, MatrizEsparsa *m2) {
    // Verifica se as matrizes têm as mesmas dimensões
    if (m1->num_linhas != m2->num_linhas || m1->num_colunas != m2->num_colunas) {
        printf("As matrizes devem ter o mesmo tamanho\n");
        return NULL;
    }

    // Cria uma nova matriz esparsa para armazenar o resultado da soma
    MatrizEsparsa *resultado = criar_matriz(m1->num_linhas, m1->num_colunas);

    // Copia os elementos da primeira matriz para o resultado
    for (int i = 0; i < m1->num_linhas; i++) {
        No *atual = m1->cabecas_linha[i];
        while (atual) {
            inserir(resultado, atual->linha, atual->coluna, atual->valor);
            atual = atual->prox_na_linha;
        }
    }

    // Adiciona os elementos da segunda matriz ao resultado
    for (int i = 0; i < m2->num_linhas; i++) {
        No *atual = m2->cabecas_linha[i];
        while (atual) {
            // Busca o valor existente na posição atual
            double valor_existente = buscar(resultado, atual->linha, atual->coluna);
            // Calcula o novo valor somando os valores correspondentes
            double novo_valor = valor_existente + atual->valor;
            // Insere ou atualiza o valor na matriz resultado
            inserir(resultado, atual->linha, atual->coluna, novo_valor);
            atual = atual->prox_na_linha;
        }
    }

    return resultado; // Retorna a matriz resultante da soma
}

// Função para somar todos os valores da matriz
double somaInterna(MatrizEsparsa *matriz) {
    double total = 0;
    // Percorre cada linha da matriz
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        // Percorre cada nó não nulo na linha
        while (atual) {
            total += atual->valor; // Acumula o valor no total
            atual = atual->prox_na_linha;
        }
    }
    return total; // Retorna a soma total dos valores
}

// Função para calcular a esparsidade da matriz
double calculaEsparsidade(MatrizEsparsa *matriz) {
    int total_elementos = matriz->num_linhas * matriz->num_colunas; // Total de posições na matriz
    int num_nao_zero = 0;

    // Percorre cada linha para contar os elementos não zero
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        while (atual) {
            num_nao_zero++; // Incrementa o contador de elementos não zero
            atual = atual->prox_na_linha;
        }
    }

    int num_zero = total_elementos - num_nao_zero; // Calcula o número de elementos zero
    return (double)num_zero / total_elementos; // Retorna a proporção de zeros na matriz
}

// Função para liberar a memória da matriz
void liberar_matriz(MatrizEsparsa *matriz) {
    // Percorre cada linha da matriz para liberar nós
    for (int i = 0; i < matriz->num_linhas; i++) {
        No *atual = matriz->cabecas_linha[i];
        while (atual) {
            No *temp = atual;
            atual = atual->prox_na_linha;
            free(temp); // Libera cada nó individualmente
        }
    }
    // Libera os vetores de cabeças de linha e coluna
    free(matriz->cabecas_linha);
    free(matriz->cabecas_coluna);
    // Libera a estrutura principal da matriz
    free(matriz);
}
