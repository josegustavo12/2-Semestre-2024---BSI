#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{

    Tree* tree = createTree();

    tree->root = insert(tree->root, 61);
    tree->root = insert(tree->root, 34);
    tree->root = insert(tree->root, 19);
    tree->root = insert(tree->root, 50);
    tree->root = insert(tree->root, 20);
    tree->root = insert(tree->root, 55);
    tree->root = insert(tree->root, 67);
    tree->root = insert(tree->root, 66);
    tree->root = insert(tree->root, 64);
    tree->root = insert(tree->root, 94);
    tree->root = insert(tree->root, 70);
    tree->root = insert(tree->root, 95);

    // printf("\nArvore: ");
    // strPreorder(tree);
    
    int valor = 94;
    printf("\nValor: %d", valor);

    int subnos = 0;
    subnos = procurarecontarsubnodes(tree, valor);
    printf("\nSubnós: %d", subnos);



}
