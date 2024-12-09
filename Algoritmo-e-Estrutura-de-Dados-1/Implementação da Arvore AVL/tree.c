#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) );

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Tree* createTree(){
    Tree* tree = (Tree*) malloc( sizeof(Tree) );

    tree->root = NULL;
    return tree;
};

Node* insert( Node* node, int data ){

    if (node == NULL){
        Node* newNode = createNode(data);
        printf("\n%d", newNode->data);
        return newNode;
    }

    // verifica se vai para o lado esquerdo
    if (data < node->data){
        node->left = insert(node->left, data);
    }
    // vai para o lado direito
    else{
        node->right = insert(node->right, data);
    }

    node->height = 1 + max( getHeight(node->left),
                            getHeight(node->right));

    int balance = getBalance(node);

    if(balance>1 && data < node->left->data){
        // rotacao direita
        return rightRotation(node);
    }
    else if(balance<-1 && data > node->right->data){
        // rotacao esquerda
        return leftRotation(node);
    }
    else if(balance>1 && data > node->left->data){
        // rotacao esquerda-direita
        return leftRightRotation(node);
    }
    else if(balance<-1 && data < node->right->data){
        // rotacao direita-esquerda
        return rightLeftRotation(node);
    }

    //printf("\n%d", node->data);
    return node;
}

Node* leftRotation(Node* root){
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = 1+max( getHeight(root->left),
                          getHeight(root->right));

    newRoot->height = 1+max( getHeight(newRoot->left),
                          getHeight(newRoot->right));

    return newRoot;
}

Node* rightRotation(Node* root){

    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = 1+max( getHeight(root->left),
                          getHeight(root->right));

    newRoot->height = 1+max( getHeight(newRoot->left),
                          getHeight(newRoot->right));

    return newRoot;
}

Node* leftRightRotation(Node* root){
    root->left = leftRotation( root->left );
    Node* newRoot = rightRotation(root);

    return newRoot;
}

Node* rightLeftRotation(Node* root){
    root->right = rightRotation( root->right );
    Node* newRoot = leftRotation(root);

    return newRoot;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int search( Node* node, int data ){

    if (node == NULL){
        return 0;
    }

    if (data == node->data){
        return 1;
    }

    int achou;
    // verifica se vai para o lado esquerdo
    if (data < node->data){
        achou = search(node->left, data);
    }
    // vai para o lado direito
    else{
        achou = search(node->right, data);
    }

    return achou;

}

Node* getMaxNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode( node->right );

}

Node* getMinNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->left == NULL){
        return node;
    }

    return getMinNode( node->left );

}

Node* deleteNode( Node* node, int data,
                    char filhoSubstituto){

    if (node == NULL){
        return node;
    }

    if (data < node->data){
        node->left = deleteNode( node->left, data,
                                      filhoSubstituto);
    }
    else if( data > node->data ){
         node->right = deleteNode( node->right, data,
                                      filhoSubstituto);
    }
    else{
        // encontrou o noh que sera excluido
        if(node->left == NULL){
            Node* tempNode = node->right;
            free(node);
            return tempNode;
        }
        else if( node->right == NULL ){
            Node* tempNode = node->left;
            free(node);
            return tempNode;
        }
        else{
            // o noh possui dois filhos
            Node* tempNode;
            if( filhoSubstituto == 'D' ){
                // o menor de todos do lado direito
                tempNode = getMinNode(node->right);
                node->data = tempNode->data;
                node->right = deleteNode(node->right,
                                        tempNode->data,
                                        filhoSubstituto);
            }
            else{
                // o maior de todos do lado esquerdo
                tempNode = getMaxNode(node->left);
                node->data = tempNode->data;
                node->left = deleteNode(node->left,
                                        tempNode->data,
                                        filhoSubstituto);
            }
        }
    } // fecha o else

    node->height = 1 + max( getHeight(node->left),
                            getHeight(node->right));

    int balance = getBalance(node);
    int rightBalance = getBalance(node->right);
    int leftBalance = getBalance(node->left);

    if(balance > 1 && leftBalance>=0){
        return rightRotation(node);
    }
    else if(balance > 1 && leftBalance<0){
        return leftRightRotation(node);
    }
    else if(balance<-1 && rightBalance<=0){
        return leftRotation(node);
    }
    else if(balance<-1 && rightBalance>0){
        return rightLeftRotation(node);
    }

    return node;
}

void strPreorder(Node *node){
    if( node != NULL ){

        printf("%d ", node->data );
        strPreorder(node->left);
        strPreorder(node->right);
    }
}


// Função para percorrer a árvore em ordem
void strInorder(Node *node) {
    if (node != NULL) {

        strInorder(node->left);
        printf("%d ", node->data);
        strInorder(node->right);
    }
}

// Função para percorrer a árvore em pós-ordem
void strPostorder(Node *node) {
    if (node != NULL) {

        strPostorder(node->left);
        strPostorder(node->right);
        printf("%d ", node->data);
    }
}

int getHeight(Node* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node* node){
    if(node==NULL){
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}


