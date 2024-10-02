#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int oper_shell, oper_quick;

void shell(int v[], int n) {
    int gap = 1;
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while(gap > 0) {
            for (int i = gap; i < n; i++){
                int x = v[i];
                oper_shell++;
                int j = i - gap;
                while(j >= 0 && v[j] > x) {
                    oper_shell++;
                    v[j + gap] = v[j];
                    oper_shell++;
                    j -= gap;
                }
                if(j >= 0){
                    oper_shell++;
                }
                v[j + gap] = x;
                oper_shell++;

            }
        gap /= 2;
    }
}

void quick(int v[], int f, int l) {
        if (f >= l) {
            return;
        }
        int m = (l + f)/2;
        int pivot = v[m];
        oper_quick++;
        int i = f;
        int j = l;
        while(1) {
                while(v[i] < pivot) {
                    oper_quick++;
                    i++;
                }
                while(v[j] > pivot) {
                    oper_quick++;
                    j--;
                }
                oper_quick += 2;
                if (i >= j) {
                        break;
                }
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                oper_quick += 3;
                i++;
                j--;
        }
        quick(v, f, j);
        quick(v, j+1, l);
}

void printVet(int* vet, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d ", &n);
    int* vet = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    for (int j = 1; j <= n; j++){

        int* subvetquick = (int*)malloc(j * sizeof(int)); // declaração do subvetor
        int* subvetshell = (int*)malloc(j * sizeof(int)); // declaração do subvetor

            for (int w = 0; w < j; w++){
                subvetquick[w] = vet[w];
                subvetshell[w] = vet[w];
            }
        quick(subvetquick, 0, j - 1);
        shell(subvetshell, j);

        if (oper_quick < oper_shell){
            printf("Q ");
        }
        if (oper_shell < oper_quick){
            printf("S ");
        }
        if(oper_quick == oper_shell){
            printf("- ");
        }

        oper_quick = 0;
        oper_shell = 0;

        free(subvetquick);
        free(subvetshell);
    }

    

    free(vet); 
    return 0;
}