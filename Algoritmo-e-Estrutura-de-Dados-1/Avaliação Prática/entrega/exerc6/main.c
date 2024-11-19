#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

// gcc -o programa main.c tree.c -Wall

int main()
{

    Tree* tree = createTree();

    tree->root = insert(tree->root, 61);
    tree->root = insert(tree->root,34);
    tree->root = insert(tree->root, 19);
    tree->root = insert(tree->root, 20);
    tree->root = insert(tree->root, 50);
    tree->root = insert(tree->root, 55);
    tree->root = insert(tree->root, 67);
    tree->root = insert(tree->root, 94);
    tree->root = insert(tree->root, 95);
    tree->root = insert(tree->root, 70);
    tree->root = insert(tree->root, 66);
    tree->root = insert(tree->root, 64);

    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);

    int subnos = 0;
    int valor = 67;
    subnos = procurarecontarsubnodes(tree->root, valor);
    printf("\nSubnós de %d: %d", valor, subnos);
}
