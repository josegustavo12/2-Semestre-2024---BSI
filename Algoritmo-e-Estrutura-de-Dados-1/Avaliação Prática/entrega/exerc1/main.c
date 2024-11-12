#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// gcc -o programa main.c ex1.c -Wall

//Função que cria a fila recebendo como argumento o valor da capacidade, que é igual à quantidade de elementos da sequência.
Fila stringparafila(int tamanho, const char *sequencia) {
    // Verifica se o tamanho é negativo ou igual a 0 , ou se a sequência contém caracteres inválidos
    for (int i = 0; i<tamanho; i++) {
        if ((tamanho <= 0) ||
            (sequencia[i] != '{' && sequencia[i] != '(' && sequencia[i] != '[' && sequencia[i] != '}' && sequencia[i] != ')' && sequencia[i] != ']')) {
            printf("Tamanho ou sequencia são invalidos\n\n");
            Fila filaVazia = {0}; //cria uma fila vazia
            return filaVazia;  // Retorna a fila para main
        }
    }

    // Verifica se a sequência está vazia
    if (sequencia == NULL || sequencia[0] == '\0' || sequencia[0] == ' ') {
        printf("Tamanho ou sequência são inválidos\n\n");
        Fila filaVazia = {0}; //cria uma fila vazia
        return filaVazia;     //retorna a fila para main
    }

    Fila fila;
    criarFila(&fila, tamanho); // Chama a função criarFila

    //Adiciona cada elemento da sequencia na fila
    for (int i = 0; i < tamanho; i++) {
        enqueue(&fila, sequencia[i]);
    }

    return fila; // retorna a fila para main

}

// Função principal com casos de testes
int main() {


    Fila teste1 = stringparafila(7, "()[]{}}");  // Teste 1

    if (teste1.size > 0) {  // Verifica se a fila foi criada corretamente
        // Verifica se a sequencia está balanceada
        int resultado = verificarBalanceamento(&teste1);

        imprimir(&teste1);

        // Com o valor retornado da função verificarBalanceamento, ele verifica se o valor � 0 (balanceada) diferente desse valor (n�o balanceada)
        if (resultado) {
            printf("Resultado: Balanceado\n\n");
        } else {
            printf("Resultado: Não Balanceado\n\n");
        }
    }

    Fila teste2 = stringparafila(4, "{[]}");   // Teste 2

    if (teste2.size > 0) {  // Verifica se a fila foi criada corretamente
        // Verifica se a sequencia está balanceada
        int resultado = verificarBalanceamento(&teste2);

        imprimir(&teste2);

        // Com o valor retornado da função verificarBalanceamento, ele verifica se o valor � 0 (balanceada) diferente desse valor (n�o balanceada)
        if (resultado) {
            printf("Resultado: Balanceado\n\n");
        } else {
            printf("Resultado: Não Balanceado\n\n");
        }
    }


    Fila teste3 = stringparafila(8, "   "); // Teste 3

    if (teste3.size > 0) {  // Verifica se a fila foi criada corretamente
        // Verifica se a sequencia está balanceada
        int resultado = verificarBalanceamento(&teste3);

        imprimir(&teste3);

        // Com o valor retornado da função verificarBalanceamento, ele verifica se o valor � 0 (balanceada) diferente desse valor (n�o balanceada)
        if (resultado) {
            printf("Resultado: Balanceado\n\n");
        } else {
            printf("Resultado: Não Balanceado\n\n");
        }
    }

    Fila teste4 = stringparafila(6, "{([])}");    // Teste 4

    if (teste4.size > 0) {  // Verifica se a fila foi criada corretamente
        // Verifica se a sequencia está balanceada
        int resultado = verificarBalanceamento(&teste4);

        imprimir(&teste4);

        // Com o valor retornado da função verificarBalanceamento, ele verifica se o valor � 0 (balanceada) diferente desse valor (n�o balanceada)
        if (resultado) {
            printf("Resultado: Balanceado\n\n");
        } else {
            printf("Resultado: Não Balanceado\n\n");
        }
    }
    return 0;
}
