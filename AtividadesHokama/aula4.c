#include <stdio.h>
//unsigned é o dobro de bits do int e mais o long tem mais o dobro
long unsigned fatorial(long unsigned n){
    if(n == 0){
        return 1;
    }
    return n * fatorial(n-1);
}

//função para imprimir os movimentos para levar n discos de ini até dest
//usando aux para ajudar
void hanoi(int n, int ini, int dest, int aux){
    if(n == 1) {
        printf("Mova disco %d, de torre %d para torre %d\n", n, ini, dest);
        return;
    }

// mover os n-1 de ini ate aux, posso usar dest como auxiliar
    hanoi(n-1,ini, aux, dest);
//mover o disco grande de ini ate dest
    printf("Mova disco %d, de torre %d para torre %d\n", n, ini, dest);
//mover n-1 discos de aux, ate dest, posso usar ini como auxiliar
    hanoi(n-1, aux, dest, ini);
    return;
}

//função basica para procurar valor em vetor
int encontra(int v[], int n, int x){
    for(int i=0; i < n; i++){
        if(v[i]==x) return 1;
    }
    return 0;
}


//só encontra x em um vetor ordenado
int encontra2(int v[], int n, int x){
    for(int i=0; i < n; i++){
        if(v[i]==x) return 1;
        if(v[i]>x) return 0;
    }
    return 0;
}

//encontra x em um vetor ordenado de forma recursiva
int busca_binaria(int *v, int ini, int fim, int x){
    int meio = (fim+ini)/2;

    if(fim<ini){
        //vetor vazio
        return 0;
    }


    if(v[meio]==x) return 1;
    if(v[meio]>x) return busca_binaria(v, ini, meio-1, x);
    if(v[meio]>x) return busca_binaria(v, meio+1, fim, x);
    
    return 0;
}

int main(){
    //chamando a função recursiva de fatorial
    long unsigned x;
    printf("digite um valor para fatorial: \n");
    scanf("%ld", &x);
    printf("o fatorial eh %ld\n", fatorial(x));

    //chamando a função recursiva de hanoi
    hanoi(4,1,3,2);

    int v[] = {50, 52, 56, 60, 61, 67, 70, 91};
    int z = 60;

    //chamando a função basica de vetor
    printf("encontrou? %d\n", encontra(v, 8, z));

    //chamando a função de busca binaria
    printf("encontrou? %d\n", busca_binaria(v, 0, 7, z));


    return 0;
}