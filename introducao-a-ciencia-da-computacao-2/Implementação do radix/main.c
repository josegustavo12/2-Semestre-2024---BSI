#include <stdio.h>

int main(){

    int x = 9;
    int primeirobit = x&1;
    printf("\n%d \nPrimeiro Bit:%d ", x, primeirobit);
    printf("\n%d \nPrimeiro Bit:%d ", x, x&2);

    for (int i = 0; i < 4; i++){
        int bit = x&i;
        printf("%d",bit);
    }
    return 0;
}