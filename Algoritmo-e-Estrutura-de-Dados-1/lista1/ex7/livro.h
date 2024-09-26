#ifndef LIVRO_H
#define LIVRO_H


typedef struct {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int numeroPaginas;
} Livro;

Livro* livros[]; // criação do array de ponteiros 
// Declara��o da fun��o para criar um livro
Livro* criarLivro();
void atualizarNumerodePaginas(Livro* livro, int pag);
void adicionarSubtitulo(Livro* livro, const char* sub);
void imprimirLivro(Livro* livro);
void menu();


#endif // LIVRO_H
