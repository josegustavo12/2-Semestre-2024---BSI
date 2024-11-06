#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"
#define maximo 100

int contsoma = 0;
int vetorsoma[maximo];


Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) );

    node->data = data;
    node->left = NULL;
    node->right = NULL;

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

    printf("\n%d", node->data);
    return node;
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

    return node;
}

void strPreorder(Node *node){
    if( node != NULL ){

        printf("%d ", node->data );
        strPreorder(node->left);
        strPreorder(node->right);
    }
}


// Fun��o para percorrer a �rvore em ordem
void strInorder(Node *node) {
    if (node != NULL) {

        strInorder(node->left);
        printf("%d ", node->data);
        strInorder(node->right);
    }
}

// Fun��o para percorrer a �rvore em p�s-ordem
void strPostorder(Node *node) {
    if (node != NULL) {

        strPostorder(node->left);
        strPostorder(node->right);
        printf("%d ", node->data);
    }
}


void somaCaminhos(int caminho[], int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += caminho[i];
    }

    if(contsoma < maximo){ //verifica se o número de somas é menor que o tamanho do vetor que armazena as somas
        vetorsoma[contsoma++] = soma;
    }
}


void encontrarCaminhos (Node* raiz, int caminho[], int n ){
    //Node* raiz = (Node*) malloc( sizeof(Node) ); //n� que vai receber a raiz da arvore e a partir dela ir percorrendo at� achar as folhas
    if(raiz == NULL){ //se a �rvore n�o tem raiz, a soma dos valores ser� 0.
        return;
    }

    else{
       caminho[n] = raiz->data; //n � inicializado como 0
       n++;
       if (raiz->left == NULL && raiz->right == NULL){ //significa que � um n� folha, isto �, n�o tem filho
            somaCaminhos (caminho, n);
       }

       encontrarCaminhos(raiz->left, caminho, n);
       encontrarCaminhos(raiz->right, caminho, n);
    }
}

// Função principal que coordena o processo de encontrar e imprimir as somas dos caminhos
void caminhos(Tree* tree){
    contsoma = 0; // Reinicia o contador de somas
    int caminho [100];

    encontrarCaminhos(tree->root, caminho, 0);

    // Imprime as somas como uma lista
    printf("Somas dos caminhos das folhas até a raiz: [");
    for(int i = 0; i < contsoma; i++){
        printf("%d", vetorsoma[i]);
        if(i < contsoma - 1){
            printf(", ");
        }
    }
    printf("]\n");
}
