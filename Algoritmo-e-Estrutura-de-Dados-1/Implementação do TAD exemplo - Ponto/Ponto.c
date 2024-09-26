#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h" // Inclui os protótipos

// Definição da estrutura interna (tipo opaco)
struct ponto {
    float x; // Coordenada x do ponto
    float y; // Coordenada y do ponto
};

// Função que cria e retorna um novo ponto
Ponto* Ponto_cria(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto)); // Aloca memória para o ponto
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p; // Retorna o ponteiro para o ponto criado
}

// Função que libera a memória alocada para um ponto
void Ponto_libera(Ponto* p) {
    free(p); // Libera a memória do ponto
}

// Função que acessa os valores das coordenadas de um ponto
int Ponto_acessa(Ponto* p, float* x, float* y) {
    if (p == NULL) return 0; // Verifica se o ponto é válido
    *x = p->x;
    *y = p->y;
    return 1; // Retorna 1 se a operação foi bem-sucedida
}

// Função que atribui novos valores às coordenadas de um ponto
int Ponto_atribui(Ponto* p, float x, float y) {
    if (p == NULL) return 0; // Verifica se o ponto é válido
    p->x = x;
    p->y = y;
    return 1; // Retorna 1 se a operação foi bem-sucedida
}

// Função que calcula a distância entre dois pontos
float Ponto_distancia(Ponto* p1, Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return -1; // Verifica se os pontos são válidos
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy); // Retorna a distância euclidiana
}
