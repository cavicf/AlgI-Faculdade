#include <stdio.h>

void mm(int v[30], int *max, int *min);

int main(){
    int v[30];
    int i;
    int max , min;

    for(i=0; i<30; i++){
        v[i] = i*2;
    }

    mm(v, &max, &min);

    printf("o valor maximo eh %d e o minimo eh %d", max, min);

    return 0;
}

void mm(int v[30], int *max, int *min){
    int i;
    *max = v[0];
    *min = v[0];

    for(i=0; i<30; i++){
        if(v[i] < *min) *min = v[i];
        if(v[i] > *max) *max = v[i];
    }
}