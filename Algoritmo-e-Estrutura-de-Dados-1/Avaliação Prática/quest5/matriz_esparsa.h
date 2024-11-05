#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct No {
    int linha;                 // Índice da linha correspondente ao valor
    int coluna;                // Índice da coluna correspondente ao valor
    double valor;              // Valor não-nulo da matriz
    struct No *prox_na_linha;  // Ponteiro para o próximo elemento não-nulo na mesma linha
    struct No *prox_na_coluna; // Ponteiro para o próximo elemento não-nulo na mesma coluna
} No;

typedef struct {
    int num_linhas;
    int num_colunas;
    No **cabecas_linha;   // Vetor de ponteiros para as cabeças das listas de linhas
    No **cabecas_coluna;  // Vetor de ponteiros para as cabeças das listas de colunas
} MatrizEsparsa;


MatrizEsparsa* criar_matriz(int num_linhas, int num_colunas);

// Função para inserir ou atualizar um valor na matriz
void inserir(MatrizEsparsa *matriz, int linha, int coluna, double valor);

// Função para remover um elemento da matriz
void remover_elemento(MatrizEsparsa *matriz, int linha, int coluna);

// Função para buscar um valor na matriz
double buscar(MatrizEsparsa *matriz, int linha, int coluna);

// Função para imprimir a matriz completa
void imprimir(MatrizEsparsa *matriz);

// Função para somar duas matrizes esparsas
MatrizEsparsa* somar(MatrizEsparsa *m1, MatrizEsparsa *m2);

// Função para somar todos os valores da matriz
double somaInterna(MatrizEsparsa *matriz);

// Função para calcular a esparsidade da matriz
double calculaEsparsidade(MatrizEsparsa *matriz);

// Função para liberar a memória da matriz
void liberar_matriz(MatrizEsparsa *matriz);

#endif // MATRIZ_ESPARSA_H
