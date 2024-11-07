#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"

int main()
{

    Tree* tree = createTree();

//fazendo o teste com a árvore presente no enunciado da questão
    printf("\n\nInsert 61");
    tree->root = insert(tree->root, 61);

    printf("\n\nInsert 34");
    tree->root = insert(tree->root, 34);

    printf("\n\nInsert 19");
    tree->root = insert(tree->root, 19);

    printf("\n\nInsert 20");
    tree->root = insert(tree->root, 20);

    printf("\n\nInsert 50");
    tree->root = insert(tree->root, 50);

    printf("\n\nInsert 55");
    tree->root = insert(tree->root, 55);

    printf("\n\nInsert 67");
    tree->root = insert(tree->root, 67);

    printf("\n\nInsert 66");
    tree->root = insert(tree->root, 66);

    printf("\n\nInsert 64");
    tree->root = insert(tree->root, 64);

    printf("\n\nInsert 94");
    tree->root = insert(tree->root, 94);

    printf("\n\nInsert 70");
    tree->root = insert(tree->root, 70);

    printf("\n\nInsert 95");
    tree->root = insert(tree->root, 95);

    printf("\n\nBuscar 14\n");
    int achou = search(tree->root, 14);
    printf("%d", achou);

    Node* node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    node = getMaxNode(tree->root);
    printf("\n\nMaior: %d", node->data);

    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);

    node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);


    printf ("\n\nSomas dos caminhos:");
    caminhos(tree);

}
