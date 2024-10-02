# Introdução a Ciência da Computação 2


## Bubble Sort

### Como funciona?
Bubble Sort é um dos algoritmos de ordenação mais simples e intuitivos, apesar de ser ineficiente para grandes volumes de dados. O algoritmo percorre repetidamente a lista, comparando pares de elementos adjacentes e trocando-os se estiverem na ordem errada. O nome "Bubble" (bolha) refere-se ao fato de que, a cada passagem pelo array, os maiores elementos "flutuam" gradualmente para o topo (fim) da lista.

Mesmo com sua simplicidade, o **Bubble Sort** tem uma desvantagem significativa em termos de eficiência, pois no pior caso, sua complexidade é **O(n²)**. Devido a essa ineficiência, ele é raramente utilizado na prática quando comparado a algoritmos mais avançados como **Quick Sort** ou **Merge Sort**.

### Funcionamento do Bubble Sort:
A ideia básica do Bubble Sort é percorrer o array várias vezes e realizar comparações de pares de elementos adjacentes, realizando trocas quando necessário, até que a lista esteja ordenada. Cada passagem "empurra" o maior elemento ainda não ordenado para sua posição correta no final do array.

#### Etapas do Bubble Sort:

1. **Comparação de Pares**: 
   - A cada iteração, o algoritmo compara pares de elementos consecutivos no array. Se o elemento à esquerda é maior que o da direita, ocorre uma troca.

2. **Troca de Elementos**:
   - Sempre que o algoritmo encontra dois elementos fora de ordem, ele realiza uma troca, colocando o maior valor mais à direita. Isso é repetido até que todos os elementos maiores "flutuem" para o final da lista.

3. **Repetição de Passagens**:
   - Após cada passagem completa, o maior elemento não ordenado se encontra em sua posição correta. O processo é repetido para o restante do array até que nenhuma troca seja necessária.

4. **Verificação de Trocas**:
   - O algoritmo pode ser otimizado para interromper a ordenação se, em uma passagem completa, nenhuma troca ocorrer. Isso significa que o array já está ordenado.

#### Exemplo:
Dado o array `[5, 2, 9, 1, 5, 6]`, o Bubble Sort funcionaria da seguinte forma:

1. Primeira passagem: `[5, 2, 9, 1, 5, 6]` → `[2, 5, 1, 5, 6, 9]` (9 flutua para a posição correta)
2. Segunda passagem: `[2, 5, 1, 5, 6, 9]` → `[2, 1, 5, 5, 6, 9]`
3. Terceira passagem: `[2, 1, 5, 5, 6, 9]` → `[1, 2, 5, 5, 6, 9]`

O array já está ordenado após três passagens.

#### Importância:
Apesar de sua simplicidade, o **Bubble Sort** não é utilizado em aplicações que requerem alto desempenho devido à sua ineficiência para grandes conjuntos de dados. Seu uso prático é limitado a casos educacionais ou situações em que a lista a ser ordenada é muito pequena.

### Complexidade do Bubble Sort comparado a outros métodos

| Caso  | Bubble Sort        | Quick Sort      | Insertion Sort  |
|:-----:|:------------------:|:---------------:|:---------------:|
| Pior  |        O(n²)       | O(n²)           | O(n²)           |
| Médio |        O(n²)       | O(nLog(n))      | O(n²)           |
| Melhor|        O(n)        | O(nLog(n))      | O(n)            |

No **melhor caso**, quando o array já está ordenado, o Bubble Sort pode ser eficiente com complexidade **O(n)**, mas no caso médio e no pior caso, seu desempenho é **O(n²)**.

### Implementação do Método

Aqui está a implementação básica do Bubble Sort em C:

```c
void bubbleSort(int a[], int n) {

    // Variável de controle para verificar se houve troca
    int swapped;

    // Laço externo que percorre toda a lista
    for(int i = 0; i < n - 1; i++) {
        swapped = 0; // Reseta a variável de controle para cada iteração

        // Laço interno para comparar e trocar os elementos
        for(int j = 0; j < n - i - 1; j++) {
            // Se o elemento à esquerda for maior que o da direita, troca-os
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1; // Marca que houve uma troca
            }
        }

        // Se nenhuma troca ocorreu na iteração, o array já está ordenado
        if(swapped == 0) {
            break;
        }
    }
}
```

### Explicação do Código:

1. **Laços**: O algoritmo utiliza dois laços aninhados. O laço externo controla o número de passagens pelo array, enquanto o laço interno realiza as comparações e trocas de elementos adjacentes.
2. **Verificação de Trocas**: A variável `swapped` controla se houve ou não trocas durante uma passagem. Se não houver trocas, o laço externo é interrompido, indicando que o array já está ordenado.
3. **Trocas**: Quando dois elementos estão fora de ordem (ou seja, o elemento da esquerda é maior que o da direita), ocorre uma troca.

## Quick Sort

### Como funciona?
Quick Sort é um algoritmo eficiente de ordenação por **divisão e conquista.** Apesar de ser da mesma classe de complexidade do Merge Sort e do Heap Sort, o Quick Sort é na prática o mais veloz deles, pois suas constantes são menores. Contudo, é importante destacar de antemão que, em seu pior caso, o Quick Sort é **O(n2)**
, enquanto que o Merge Sort e o Heap Sort garantem **n∗logn**
 para todos os casos. A boa notícia é que há estratégias simples com as quais podemos minimizar as chances de ocorrência do pior caso.

O funcionamento do Quick Sort baseia-se em uma rotina fundamental cujo nome é **particionamento**. Particionar significa escolher um número qualquer presente no array, chamado de pivot, e colocá-lo em uma posição tal que todos os elementos à esquerda são menores ou iguais e todos os elementos à direita são maiores.

### Particionamento
O **particionamento do Quick Sort** é uma etapa crucial desse algoritmo de ordenação, onde o array é dividido em duas partes em torno de um elemento chamado **pivô**. O objetivo é reorganizar o array de modo que todos os elementos menores que o pivô fiquem à esquerda e os maiores fiquem à direita.

#### Etapas do Particionamento:

1. **Escolha do Pivô**: 
   - O pivô pode ser o primeiro elemento, o último, um elemento aleatório ou o elemento mediano do array. A escolha do pivô afeta o desempenho do algoritmo.

2. **Reorganização dos Elementos**:
   - O algoritmo percorre o array e compara cada elemento com o pivô. Elementos menores são movidos para a esquerda, e os maiores, para a direita.

3. **Posicionamento Final do Pivô**:
   - Após a reorganização, o pivô é colocado em sua posição final, onde todos os elementos à esquerda são menores que ele e os da direita são maiores.

4. **Recursão**:
   - O processo é repetido recursivamente para as duas sublistas (à esquerda e à direita do pivô) até que todas as partições tenham tamanho 1 ou 0, o que significa que o array está ordenado.

#### Exemplo:
Dado o array `[8, 3, 1, 7, 0, 10, 2]` e escolhendo `7` como pivô:
- Elementos menores que `7`: `[3, 1, 0, 2]`
- Elementos maiores que `7`: `[8, 10]`
- Após o particionamento, a lista fica assim: `[3, 1, 0, 2, 7, 8, 10]`.

#### Importância:
O particionamento é o coração do **Quick Sort**, e a eficiência do algoritmo depende de como o array é dividido. No melhor caso, o particionamento divide o array em partes de tamanho aproximadamente igual, resultando em um desempenho de `O(n log n)`. No pior caso, quando o pivô divide o array de maneira desigual, o tempo de execução pode ser `O(n²)`.

#### Estratégias de Pivô:
- **Pivô Aleatório**: Reduz a chance de particionamento ruim.
- **Mediana de Três**: Usa a mediana de três elementos para uma divisão mais balanceada.

O particionamento bem-sucedido é o que garante a eficiência do Quick Sort na maioria dos cenários práticos.


### Complexidade do QS comparado a outros métodos

| Caso  | Quick Sort         | Insertion Sort  | Heap Sort |
|:-----:|:------------------:|:---------------:|:---------:|
| Pior  |        O(n²)       | O(n²)           |O(nLog(n)) |
| Médio |         O(nLog(n)) | O(n²)           |O(nLog(n)) |
| Melhor|       O(nLog(n))   | O(n)            |O(nLog(n)) |


### Implementação do Método

```c
void QS(int a[], int c, int f){

    // Caso base: Se o índice inicial (c) for maior ou igual ao final (f),
    // a sublista já está ordenada ou contém apenas um elemento.
    if(c >= f){
        return;
    }

    // Calcula o índice do meio da lista (pivot), usado para a partição.
    int m = (c + f) / 2;

    // Define o pivô como o valor do meio do array.
    int p = a[m];

    // Inicializa os ponteiros i e j, que percorrem a lista dos dois lados.
    int i = c;
    int j = f;

    // Inicia o laço de particionamento.
    while(1){
        // Avança o ponteiro 'i' enquanto o elemento for menor que o pivô.
        while (a[i] < p ){ 
            i++;
        }

        // Retrocede o ponteiro 'j' enquanto o elemento for maior que o pivô.
        while (a[j] > p ){
            j--;
        }

        // Se 'i' for menor que 'j', realiza a troca dos elementos que estão fora de ordem.
        if (i < j){
            int t = a[i];  // Armazena o valor de 'a[i]' temporariamente.
            a[i] = a[j];   // Coloca 'a[j]' na posição 'i'.
            a[j] = t;      // Coloca 'a[i]' na posição 'j' (efetuando a troca).

            // Incrementa o índice 'i' e decrementa 'j' para continuar a partição.

```

## Counting Sort

O **Counting Sort** é um algoritmo de ordenação baseado em contagem de ocorrências, eficiente principalmente para ordenar elementos inteiros em um intervalo limitado. Ele não utiliza comparações entre elementos como a maioria dos algoritmos de ordenação clássicos (como o Merge Sort ou o Quick Sort), mas sim distribui os elementos diretamente em posições corretas com base em suas frequências.

### Como funciona?

O Counting Sort segue três passos principais: **contagem**, **acumulação** e **ordenamento final**.

1. **Contagem de Frequências**:
   - O algoritmo percorre o array de entrada e conta quantas vezes cada valor aparece. Esses valores são armazenados em um array auxiliar chamado `count[]`, onde cada índice representa um valor do array original, e cada posição do array `count[]` guarda a quantidade de vezes que esse valor ocorre.

2. **Acumulação**:
   - O próximo passo é modificar o array de contagem (`count[]`) para armazenar a posição de cada valor no array ordenado. Para fazer isso, soma-se os valores cumulativamente no array de contagem.

3. **Construção do Array de Saída**:
   - O último passo consiste em percorrer o array de entrada novamente e, com base nos valores do array `count[]`, colocar os elementos de entrada em suas posições corretas no array de saída.

### Passo a Passo do Algoritmo

#### 1. Entrada

Dado o array de entrada:
```plaintext
Entrada: [4, 2, 2, 8, 3, 3, 1]
```

#### 2. Contagem de Frequências

Cria-se um array `count[]` que conta a frequência de cada elemento:
```plaintext
count[] = [0, 1, 2, 2, 1, 0, 0, 0, 1] 
```
Isso indica, por exemplo, que o número `1` aparece 1 vez, o número `2` aparece 2 vezes, o número `3` aparece 2 vezes, e assim por diante.

#### 3. Acumulação

Agora, acumulamos os valores no array de contagem, para indicar as posições finais dos elementos:
```plaintext
count[] = [0, 1, 3, 5, 6, 6, 6, 6, 7]
```
Aqui, o valor `1` estará na posição 1, o valor `2` começa na posição 3, o valor `3` começa na posição 5, e o valor `8` estará na posição 7.

#### 4. Construção do Array de Saída

Finalmente, percorremos o array de entrada e colocamos os valores nas posições corretas no array de saída:
```plaintext
Saída: [1, 2, 2, 3, 3, 4, 8]
```

### Complexidade do Counting Sort

O Counting Sort tem uma complexidade de tempo e espaço distinta, dependendo de duas variáveis: o número de elementos no array (`n`) e o maior valor presente no array (`k`).

#### Complexidade de Tempo:

- **Fase de Contagem**: O algoritmo percorre o array de entrada para contar a frequência de cada valor, o que leva tempo **O(n)**, onde `n` é o número de elementos.
- **Fase de Acumulação**: Para calcular as posições finais dos elementos, percorremos o array de contagem de tamanho `k`. Isso leva tempo **O(k)**.
- **Construção do Array de Saída**: Novamente, o algoritmo percorre o array de entrada para preencher o array de saída ordenado, o que leva mais tempo **O(n)**.

No geral, a complexidade de tempo do Counting Sort é **O(n + k)**, onde:
- `n` é o número de elementos no array.
- `k` é o valor máximo no array de entrada.

#### Complexidade de Espaço:

- O Counting Sort utiliza um array de contagem com tamanho **k + 1**, onde `k` é o valor máximo do array. Portanto, a complexidade de espaço também é **O(n + k)**, pois precisamos armazenar tanto o array de contagem quanto o array de saída.

### Comparação com Outros Algoritmos de Ordenação

Aqui está a tabela comparando as complexidades de tempo do **Counting Sort**, **Merge Sort**, **Radix Sort** e **Bubble Sort** em seus piores, médios e melhores casos:

| Caso  | Counting Sort     | Merge Sort      | Quick Sort     | Bubble Sort |
|:-----:|:-----------------:|:---------------:|:--------------:|:-----------:|
| Pior  | O(n + k)          | O(nLog(n))      | O(n²)       | O(n²)       |
| Médio | O(n + k)          | O(nLog(n))      | O(nLog(n))       | O(n²)       |
| Melhor| O(n + k)          | O(nLog(n))      | O(nLog(n))       | O(n)        |

### Quando Usar Counting Sort?

- **Intervalo Pequeno**: Counting Sort é mais eficiente que algoritmos de ordenação baseados em comparação quando o intervalo de valores (`k`) é pequeno em comparação ao número de elementos (`n`).
- **Dados Inteiros**: É ideal para ordenar listas de números inteiros não negativos ou dados que possam ser mapeados para números inteiros.
- **Estabilidade**: Counting Sort é estável, o que significa que mantém a ordem relativa de elementos com o mesmo valor.

### Implementação do Counting Sort 
    
