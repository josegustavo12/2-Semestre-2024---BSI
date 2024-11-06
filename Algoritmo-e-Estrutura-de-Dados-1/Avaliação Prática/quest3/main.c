#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main(){
    // 1. Cria uma LNSE com capacidade para 10 elementos
    int capacidade = 10;
    LNSE* minhaLNSE = crialistaLNSE(capacidade);
    printf("LNSE criada com capacidade para %d elementos.\n", capacidade);
    
    // 2. Insere elementos na LNSE
    printf("\nInserindo elementos na LNSE:\n");
    inserir(minhaLNSE, 5, 0);  // Insere 5 na posição 0 (início)
    printf("Inserido 5 na posição 0.\n");
    imprimirLNSE(minhaLNSE);
    
    inserir(minhaLNSE, 10, 1); // Insere 10 na posição 1 (final)
    printf("Inserido 10 na posição 1.\n");
    imprimirLNSE(minhaLNSE);
    
    inserir(minhaLNSE, 15, 1); // Insere 15 na posição 1 (meio)
    printf("Inserido 15 na posição 1.\n");
    imprimirLNSE(minhaLNSE);
    
    inserir(minhaLNSE, 20, 2); // Insere 20 na posição 2 (meio)
    printf("Inserido 20 na posição 2.\n");
    imprimirLNSE(minhaLNSE);
    
    inserir(minhaLNSE, 25, 4); // Insere 25 na posição 4 (final)
    printf("Inserido 25 na posição 4.\n");
    imprimirLNSE(minhaLNSE);
    
    // 3. Busca elementos na LNSE
    printf("\nBuscando elementos na LNSE:\n");
    int elementosParaBuscar[] = {10, 15, 30};
    int numElementos = sizeof(elementosParaBuscar)/sizeof(elementosParaBuscar[0]);
    for(int i = 0; i < numElementos; i++){
        int pos = buscar(minhaLNSE, elementosParaBuscar[i]);
        if(pos != -1){
            printf("Elemento %d encontrado na posição %d.\n", elementosParaBuscar[i], pos);
        }
        else{
            printf("Elemento %d não encontrado na LNSE.\n", elementosParaBuscar[i]);
        }
    }
    
    // 4. Verifica o tamanho da LNSE
    printf("\nTamanho atual da LNSE: %d\n", sizeLNSE(minhaLNSE));
    
    // 5. Remove elementos da LNSE
    printf("\nRemovendo elementos da LNSE:\n");
    remover(minhaLNSE, 1); // Remove o elemento na posição 1 (15)
    printf("Removido elemento da posição 1.\n");
    imprimirLNSE(minhaLNSE);
    
    remover(minhaLNSE, 0); // Remove o elemento na posição 0 (5)
    printf("Removido elemento da posição 0.\n");
    imprimirLNSE(minhaLNSE);
    
    remover(minhaLNSE, sizeLNSE(minhaLNSE) - 1); // Remove o último elemento (25)
    printf("Removido elemento da última posição.\n");
    imprimirLNSE(minhaLNSE);
    
    // 6. Verifica novamente o tamanho da LNSE
    printf("\nTamanho atual da LNSE após remoções: %d\n", sizeLNSE(minhaLNSE));
    
    // 7. Tenta remover um elemento de uma posição inválida
    printf("\nTentando remover elemento de posição inválida (10):\n");
    remover(minhaLNSE, 10); // Posição inválida
    imprimirLNSE(minhaLNSE);
    
    // 8. Insere mais elementos para testar a fila
    printf("\nInserindo mais elementos na LNSE para testar a fila:\n");
    inserir(minhaLNSE, 30, 1); // Insere 30 na posição 1
    printf("Inserido 30 na posição 1.\n");
    imprimirLNSE(minhaLNSE);
    
    inserir(minhaLNSE, 35, 2); // Insere 35 na posição 2
    printf("Inserido 35 na posição 2.\n");
    imprimirLNSE(minhaLNSE);
    
    // 9. Busca novamente após inserções
    printf("\nBuscando elementos na LNSE após inserções adicionais:\n");
    int novosElementosParaBuscar[] = {5, 30, 35};
    int numNovosElementos = sizeof(novosElementosParaBuscar)/sizeof(novosElementosParaBuscar[0]);
    for(int i = 0; i < numNovosElementos; i++){
        int pos = buscar(minhaLNSE, novosElementosParaBuscar[i]);
        if(pos != -1){
            printf("Elemento %d encontrado na posição %d.\n", novosElementosParaBuscar[i], pos);
        }
        else{
            printf("Elemento %d não encontrado na LNSE.\n", novosElementosParaBuscar[i]);
        }
    }
    
    // 10. Verifica o tamanho final da LNSE
    printf("\nTamanho final da LNSE: %d\n", sizeLNSE(minhaLNSE));
    
    // 11. Limpa a LNSE
    printf("\nLimpando a LNSE:\n");
    clearLNSE(minhaLNSE);
    printf("LNSE limpa.\n");
    imprimirLNSE(minhaLNSE);
    
    // 12. Tenta buscar em uma LNSE limpa
    printf("\nTentando buscar elemento em LNSE limpa:\n");
    int posFinal = buscar(minhaLNSE, 10);
    if(posFinal != -1){
        printf("Elemento 10 encontrado na posição %d.\n", posFinal);
    }
    else{
        printf("Elemento 10 não encontrado na LNSE.\n");
    }
    
    // 13. Libera a memória alocada para a LNSE
    clearLNSE(minhaLNSE); // Já limpa a lista e a fila
    free(minhaLNSE->lista); // Libera a lista
    free(minhaLNSE); // Libera a LNSE
    printf("\nMemória alocada para a LNSE foi liberada.\n");
    
    return 0;
}
