#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{
    Tree* tree = createTree();

    printf("\n\nInsert 3");
    tree->root = insert(tree->root, 3);

    printf("\n\nInsert 2");
    tree->root = insert(tree->root, 2);

    printf("\n\nInsert 1");
    tree->root = insert(tree->root, 1);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 4);

    printf("\n\nInsert 5");
    tree->root = insert(tree->root, 5);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 6);

    printf("\n\nInsert 7");
    tree->root = insert(tree->root, 7);

    printf("\n\nInsert 16");
    tree->root = insert(tree->root, 16);

    printf("\n\nInsert 15");
    tree->root = insert(tree->root, 15);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pós-ordem\n");
    strPostorder(tree->root);

    printf("\n\nAltura da raiz: %d", getHeight(tree->root));
    printf("\n\nBalanceamento da raiz: %d", getBalance(tree->root));



    printf("\n\nTestando o deletar");

    tree = createTree();

    // Inserindo elementos na árvore
    tree->root = insert(tree->root, 17);
    tree->root = insert(tree->root, 6);
    tree->root = insert(tree->root, 35);
    tree->root = insert(tree->root, 23);
    tree->root = insert(tree->root, 48);


    printf("\n\nDelete o 6: \n");
    tree->root = deleteNode(tree->root, 6, 'D');

    // Exibindo a árvore em diferentes ordens
    printf("\nstrInorder(): ");
    strInorder(tree->root);
    printf("\n");

    printf("strPreorder(): ");
    strPreorder(tree->root);
    printf("\n");

    printf("strPostorder(): ");
    strPostorder(tree->root);
    printf("\n");

    printf("\n\nDelete o 35: \n");
    tree->root = deleteNode(tree->root, 35, 'D');

    // Exibindo a árvore em diferentes ordens
    printf("\nstrInorder(): ");
    strInorder(tree->root);
    printf("\n");

    printf("strPreorder(): ");
    strPreorder(tree->root);
    printf("\n");

    printf("strPostorder(): ");
    strPostorder(tree->root);
    printf("\n");
}
