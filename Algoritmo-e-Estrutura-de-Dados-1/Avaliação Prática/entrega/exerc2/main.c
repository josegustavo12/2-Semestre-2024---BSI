#include <stdio.h>
#include <stdlib.h>
#include "exerc2.h"

// gcc -o programa main.c exerc2.c -Wall

int main() {
    PilhaDupla pilha;
    inicializarPilhaDupla(&pilha);

    // Empilhando na Pilha A
    printf ("Empilhando em A:");
    pushA(&pilha, 100);
    imprimirA(&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 90);
    imprimirA (&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 80);
    imprimirA(&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 70);
    imprimirA (&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 60);  // 5 valores empilhados na Pilha A
    imprimirA(&pilha);

    // Empilhando na Pilha B
    printf ("Empilhando em B:");
    pushB(&pilha, 10);
    imprimirB(&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 20);
    imprimirB(&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 30);
    imprimirB(&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 40);  // 4 valores empilhados na Pilha B
    imprimirB(&pilha);

    printf("\n\nImprimindo as pilhas apos novo empilhamento:\n");
    imprimirA(&pilha);
    imprimirB(&pilha);

    // Desempilhar 2 valores da Pilha A e 1 valor da Pilha B
      
      printf ("\n\nDesempilhando de A: ");
       popA(&pilha);
       imprimirA(&pilha);
      printf ("Desempilhando de A: ");
       popA(&pilha);
       imprimirA(&pilha);
      printf ("Desempilhando de B: ");
       popB(&pilha);
       imprimirB(&pilha);


    // Empilhar mais valores para testar o limite
    
    printf ("\n\nEmpilhando em A:");
    pushA(&pilha, 50);
    imprimirA (&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 50); 
    imprimirB(&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 40); 
    imprimirA(&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 60);
    imprimirB (&pilha);
    printf ("Empilhando em B:");
    pushB(&pilha, 35); //nao entrou
    imprimirB (&pilha);
    printf ("Empilhando em A:");
    pushA(&pilha, 90); //nao entrou
    imprimirA(&pilha);

    printf ("\nImprimindo as pilhas apos novo empilhamento:\n");
     printf("pilha A:");
            imprimirA(&pilha);
     printf("pilha B:");
            imprimirB(&pilha);

//testando o caso de Underflow
      
      popA(&pilha);
      printf ("\n\nDesempilhando de A: " );
       imprimirA(&pilha);
      popA(&pilha);
      printf ("Desempilhando de A: " );
       imprimirA(&pilha);
      popA(&pilha);
      printf ("Desempilhando de A: " );
       imprimirA(&pilha);
      popA(&pilha);
      printf ("Desempilhando de A: " );
       imprimirA(&pilha);
      popA(&pilha);
      printf ("Desempilhando de A: " );
       imprimirA(&pilha);
       popA(&pilha);
      printf ("Desempilhando de A: " );
       imprimirA(&pilha);
       popA(&pilha);

     
      popB(&pilha);
      printf ("\nDesempilhando de B: "); 
      imprimirB(&pilha);
      popB(&pilha);
      printf ("Desempilhando de B: ");
       imprimirB(&pilha);
      popB(&pilha);
      printf ("Desempilhando de B: ");
       imprimirB(&pilha);
      popB(&pilha);
      printf ("Desempilhando de B: ");
       imprimirB(&pilha);
      popB(&pilha);
      printf ("Desempilhando de B: ");
       imprimirB(&pilha);
       popB(&pilha);
      printf ("Desempilhando de B: ");
       imprimirB(&pilha);
       popB(&pilha);

       printf ("\nLimpando a Pilha A...");
       clearA (&pilha);
       printf ("\nPilha A: [");
       imprimirA (&pilha);
       printf ("]");

       printf ("\nLimpando a pilha B...");
       clearB (&pilha);
       printf ("\nPilha B: [");
       imprimirB (&pilha);
       printf("]");

    return 0;
}
