#include <stdio.h>
#include "Ponto.h" // Inclui os protótipos do TAD Ponto

int main() {
    // Criação de dois pontos
    Ponto* p1 = Ponto_cria(2.0, 3.0);
    Ponto* p2 = Ponto_cria(5.0, 7.0);

    // Acessa e imprime as coordenadas dos pontos
    float x, y;
    Ponto_acessa(p1, &x, &y);
    printf("Ponto 1: (%.2f, %.2f)\n", x, y);
    Ponto_acessa(p2, &x, &y);
    printf("Ponto 2: (%.2f, %.2f)\n", x, y);

    // Calcula e imprime a distância entre os dois pontos
    float distancia = Ponto_distancia(p1, p2);
    printf("Distância entre p1 e p2: %.2f\n", distancia);

    // Modifica as coordenadas do ponto 1
    Ponto_atribui(p1, 4.0, 6.0);
    Ponto_acessa(p1, &x, &y);
    printf("Ponto 1 atualizado: (%.2f, %.2f)\n", x, y);

    // Libera a memória dos pontos
    Ponto_libera(p1);
    Ponto_libera(p2);

    return 0;
}
