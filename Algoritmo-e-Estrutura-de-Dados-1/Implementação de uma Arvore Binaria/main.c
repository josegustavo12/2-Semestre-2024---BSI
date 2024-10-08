#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


int main(){

    Tree* tree = creatTree();

    tree->root = insert(tree->root, 6);
    tree->root = insert(tree->root, 10);
    tree->root = insert(tree->root, 7);
    tree->root = insert(tree->root, 9);
    tree->root = insert(tree->root, 1);




    return 0;
}