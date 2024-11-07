#include <stdio.h>
#include <stdlib.h>
#include "exerc7.h"
#define maximo 100

int contsoma = 0; //inicializa o contador de somas presentes na lista final com as somas de cada caminho em 0, pois ainda não foi realizada nenhuma soma.
int vetorsoma[maximo]; //declara o vetor soma (vetor que armazenará as somas de cada caminho da árvore) como tendo no máximo tamanho 100, ou seja, armazena no máximo 100 somas.

//função que cria os nós da árvore
Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) );

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//função que inicializa a árvore
Tree* createTree(){
    Tree* tree = (Tree*) malloc( sizeof(Tree) );

    tree->root = NULL;
    return tree;
};

//função para inserir novos valores na árvore
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

//função para procurar um valor na árvore
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

//função para achar o maior valor 
Node* getMaxNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode( node->right );

}

//função para achar o menor valor
Node* getMinNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->left == NULL){
        return node;
    }

    return getMinNode( node->left );

}

//função para deletar um nó
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
        // encontrou o nó que será excluido
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
            // o nó possui dois filhos
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

//função pré-ordem para percorrer a árvore 
void strPreorder(Node *node){
    if( node != NULL ){

        printf("%d ", node->data );
        strPreorder(node->left);
        strPreorder(node->right);
    }
}


//função em ordem para percorrer a árvore
void strInorder(Node *node) {
    if (node != NULL) {

        strInorder(node->left);
        printf("%d ", node->data);
        strInorder(node->right);
    }
}

//função pós-ordem para percorrer a árvore
void strPostorder(Node *node) {
    if (node != NULL) {

        strPostorder(node->left);
        strPostorder(node->right);
        printf("%d ", node->data);
    }
}

//função que soma os elementos de cada caminho
void somaCaminhos(int caminho[], int n){ //função recebe um caminho da árvore e o tamanho desse caminho
    int soma = 0; //inicializa a soma valendo 0 
    for(int i = 0; i < n; i++){ //for para percorrer cada elemento do vetor caminho, a fim de somar eles
        soma += caminho[i];
    }

    if(contsoma < maximo){ //verifica se o número de somas do contador é menor que o tamanho máximo do vetor que armazena as somas de cada caminho
        vetorsoma[contsoma++] = soma; //armazena o valor de soma no vetor soma e já increme o contador do número de somas
    }
}

//função para econtrar os caminhos da árvore
void encontrarCaminhos (Node* raiz, int caminho[], int n ){ //recebe como argumentos o nó que vai receber a raiz da arvore e a partir dela ir percorrendo o caminho de tamanho n até achar as folhas
    if(raiz == NULL){ //se a árvore não tem raiz significa que não tem o que somar
        return;
    }

    else{ //caso a árvore possua raiz 
       caminho[n] = raiz->data; //aqui será armazenado o valor da raiz na variável caminho com n valendo 0 no início
       n++;
       if (raiz->left == NULL && raiz->right == NULL){ //significa que é um nó folha, isto é, não tem filho
            somaCaminhos (caminho, n); //chamo a função soma, pois já cheguei até o final do meu caminho
       }

//caso o nó tenha filhos, chamo a função encontrarCaminhos de forma recursiva até entrar dentro do if acima e chamar a função somaCaminhos
       encontrarCaminhos(raiz->left, caminho, n);
       encontrarCaminhos(raiz->right, caminho, n);
    }
}

// Função principal que coordena o processo de encontrar e imprimir as somas dos caminhos
void caminhos(Tree* tree){
    contsoma = 0; //reinicia o contador de somas
    int caminho [100]; //cria uma variável temporária caminho de tamanho 100 para armazenas os elementos do caminho da árvore

    encontrarCaminhos(tree->root, caminho, 0); 

    //imprime as somas como uma lista
    printf("Somas dos caminhos das folhas ate a raiz: [");
    for(int i = 0; i < contsoma; i++){ //for para percorrer e imprimir as somas de cada caminho presente no vetor soma
        printf("%d", vetorsoma[i]);
        if(i < contsoma - 1){ 
            printf(", ");
        }
    }
    printf("]\n");
}
