#include <stdio.h>

int soma_positivos(int *v, int n){
    if(n==0){
        return 0;
    }
    int atual = v[0];
    int subproblema = soma_positivos(++v ,n-1);
    int problema_original;
    if(atual>0){
        problema_original = atual + subproblema;
    }
    else{
        problema_original = subproblema;
    }
    return problema_original;
}

int main(){
    int v[] = {5, -5, 10, 0, 10};
    printf("%d\n", soma_positivos(v, 5));

    return 0;
}