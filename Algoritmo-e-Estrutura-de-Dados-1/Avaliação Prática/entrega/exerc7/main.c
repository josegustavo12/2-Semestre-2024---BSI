#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"

// gcc -o programa main.c exerc7.c -Wall

int main()
{

    Tree* tree = createTree();

//fazendo o teste com a árvore presente no enunciado da questão
    
    tree->root = insert(tree->root, 61);

    tree->root = insert(tree->root, 34);

    tree->root = insert(tree->root, 19);

    tree->root = insert(tree->root, 20);
    
    tree->root = insert(tree->root, 50);
   
    tree->root = insert(tree->root, 55);

    tree->root = insert(tree->root, 67);
   
    tree->root = insert(tree->root, 66);
    
    tree->root = insert(tree->root, 64);

    tree->root = insert(tree->root, 94);

    tree->root = insert(tree->root, 70);

    tree->root = insert(tree->root, 95);


    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);

    printf ("\n\n");

    //função que coordena o processo de achar e somar os caminhos
    caminhos(tree);

    printf ("\n");
    return 0;
}
