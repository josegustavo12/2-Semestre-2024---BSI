// main.c
#include "ex1.h"
#include <string.h>

// Função principal com casos de teste
int main() {
    // Definindo os casos de teste
    char* casos[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "(((())))",
        "({[()()]})",
        "({[()()]}",
        "({[()()]})}",
        "([{}])",
        "([{})]",
        "({}[])",
        "([)]",
        "(((((((((())))))))))",
        "(){[]}"
    };

    int numeroCasos = sizeof(casos) / sizeof(casos[0]);

    for (int i = 0; i < numeroCasos; i++) {
        // Cria uma fila para cada caso
        Fila fila;
        int capacidade = strlen(casos[i]) > 0 ? strlen(casos[i]) : 1;
        criarFila(&fila, capacidade > 0 ? capacidade : 1);

        // Enfileira os caracteres do caso de teste na fila
        for (int j = 0; casos[i][j] != '\0'; j++) {
            enqueue(&fila, casos[i][j]);
        }

        // Imprime o caso de teste
        printf("Caso %d: ", i + 1);
        imprimir(&fila);

        // Verifica o balanceamento
        int resultado = verificarBalanceamento(&fila);

        // Imprime o resultado
        if (resultado) {
            printf("Resultado: Balanceado\n\n");
        } else {
            printf("Resultado: Não Balanceado\n\n");
        }

        // Libera a memória alocada para a fila
        free(fila.data);
    }

    return 0;
}
