#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"

int main()
{

    Tree* tree = createTree();

    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 61);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 34);

    printf("\n\nInsert 35");
    tree->root = insert(tree->root, 19);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 20);

    printf("\n\nInsert 14");
    tree->root = insert(tree->root, 50);

    printf("\n\nInsert 23");
    tree->root = insert(tree->root, 55);

    printf("\n\nInsert 48");
    tree->root = insert(tree->root, 67);
    tree->root = insert(tree->root, 66);
    tree->root = insert(tree->root, 64);
    tree->root = insert(tree->root, 94);
    tree->root = insert(tree->root, 70);
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

    printf("\n\nPercurso pr�-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso p�s-ordem\n");
    strPostorder(tree->root);


    printf ("\n\nSoma dos caminhos\n:");
    caminhos(tree);

}
