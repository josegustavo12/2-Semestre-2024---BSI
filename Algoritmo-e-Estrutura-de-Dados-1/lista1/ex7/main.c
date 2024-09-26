#include <stdio.h>
#include <stdlib.h>

#include "livro.h"

int main()
{

    Livro* livro = criarLivro();
    imprimirLivro(livro);
    atualizarNumerodePaginas(livro, 3689);
    adicionarSubtitulo(livro, "testando na fe");
    imprimirLivro(livro);

    return 0;
}
