#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"

int main()
{

    Tree* tree = createTree();

    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 17);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 6);

    printf("\n\nInsert 35");
    tree->root = insert(tree->root, 35);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 4);

    printf("\n\nInsert 14");
    tree->root = insert(tree->root, 14);

    printf("\n\nInsert 23");
    tree->root = insert(tree->root, 23);

    printf("\n\nInsert 48");
    tree->root = insert(tree->root, 48);

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
