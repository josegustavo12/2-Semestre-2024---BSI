#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

Livro* criarLivro() {
    Livro* livro = (Livro*)malloc(sizeof(Livro)); // aloca memoria para um Livro

    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int numeroPaginas;

    printf("\nInsira o nome do Titulo: \n");
    scanf("%99[^\n]", titulo);
    getchar();

    printf("Insira o nome do Autor: \n");
    scanf("%99[^\n]", autor);
    getchar();

    printf("Insira o ano da Publica��o: \n");
    scanf("%d", &anoPublicacao); // pega o ano da publica��o

    printf("Insira o N�mero de P�ginas: \n");
    scanf("%d", &numeroPaginas); // pega o n�mero de p�ginas

    // copia as strings e inicializa os outros campos
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);

    livro->anoPublicacao = anoPublicacao;
    livro->numeroPaginas = numeroPaginas;

    return livro;
}

void atualizarNumerodePaginas(Livro* livro, int pag){

    livro->numeroPaginas = pag;

}

void adicionarSubtitulo(Livro* livro, const char* sub){

    const char* prefix = ": "; // indica que o ponteiro prefix aponta para um char que � imutavel 
 
 // char prefix[] = ": "; // posso usar assim tbm

    strcat(livro->titulo, prefix); // concatena o titulo com o prefixo 
    strcat(livro->titulo, sub); // concatena o titulo (que j� esta com o prefixo) com o subtitulo escolhido, tenho que por depois uma verifica��o do tamanho

}


void imprimirLivro(Livro* livro){

    printf("\nTitulo: %s\nAutor: %s\nData de Lan�amento: %d\nNumero de paginas: %d\n", livro->titulo,
           livro->autor, livro->anoPublicacao, livro->numeroPaginas);

}

void menu(){

    printf("\n********************* MENU *********************\n");
    printf("\n[1] Adicionar novo livo, [2] \n");





}
