#include <stdio.h>
#include <stdlib.h>

#include "tree.h" // Supondo que você tenha implementado as funções insert, deleteNode e search

int main()
{
    // Criar uma nova árvore
    Tree* tree = createTree();

    // Inserção de nós
    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 17);

    printf("\n\nInsert 12");
    tree->root = insert(tree->root, 12);

    printf("\n\nInsert 15");
    tree->root = insert(tree->root, 15);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 4);

    printf("\n\nInsert 2");
    tree->root = insert(tree->root, 2);

    // Busca por um valor
    printf("\n\nBuscar 14\n");
    Node* achou = search(tree->root, 14); // A função 'search' deve retornar um ponteiro para o nó
    if (achou != NULL) {
        printf("Valor 14 encontrado\n");

        // Excluir o nó encontrado
        printf("\nDeletando 14...\n");
        tree->root = deleteNode(tree->root, 14, 'E'); // Passar o nó e o tipo de substituição (E - Esquerda ou D - Direita)
        
        // Verificar se a exclusão foi bem-sucedida
        Node* novoAchou = search(tree->root, 14);
        if (novoAchou == NULL) {
            printf("Valor 14 excluído com sucesso\n");
        } else {
            printf("Erro ao excluir o valor 14\n");
        }
    } else {
        printf("Valor 14 não encontrado\n");
    }

    return 0;
}
