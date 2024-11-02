#include <stdio.h>




// nesse código vamos inserir diferentes tipos de buscas

int buscaseq(int vet[], int n, int valor){ // funciona em qualquer tipo de vetor: ordenado ou não
   for(int i=0; i<n; i++){
      if(vet[i] == valor) {
         return i;
         // return 1 caso queira retornar apenas se o valor existe
      }
   }
   return -1; // return 0 caso queira retornar apenas se o valor não existe

}

int buscaord(int vet[], int n, int valor){

    ordenar(vet, n); // ordena o vetor para realizar a busca

    int i = 0;
    while(i < n && valor > vet[i]){
    // Enquanto o índice 'i' for menor que 'n' (tamanho do vetor) e o valor buscado for maior que o elemento atual,
    // a busca continua. Isso se aproveita do fato de que o vetor está ordenado.
        i++; // incrementa para passar para o prox elemento
    }

    if ( i < n && vet[i] == valor){
    // Verifica se o valor foi encontrado no vetor. Se o índice 'i' ainda está dentro dos limites do vetor
    // e o elemento na posição 'i' é igual ao valor buscado, retorna o índice.
        return i;
    }
    else{
        return -1; // caso não tenha achado retorna -1
    }


}

int buscabinaria(int vet[], int n, int valor){
    return buscabinariarec(vet, 0, n-1, valor);
}

int buscabinariarec(int vet[], int ini, int fim, int valor){

    if (ini > fim){
        return -1; // caso o valor inicial seja maior que o final, o valor procurado não existe dentro do vetor
    }

    int media = (ini + fim) / 2;
    if(valor == vet[media]){
        return media; // indice do valor buscado
    }

    if (valor > vet[media]){
        return buscabinariarec(vet, media+1, fim, valor);
    }

    return buscabinariarec(vet, ini, media-1, valor);


}

void ordenar(int vet[], int n){
    int atual, posmenor;

    for (int i = 1; i < n; i++) { 
        atual = vet[i]; 
        for (posmenor = i; (posmenor > 0) && (atual < vet[posmenor - 1]); posmenor--) {
            vet[posmenor] = vet[posmenor - 1];
        }
        vet[posmenor] = atual; 
    }
}
