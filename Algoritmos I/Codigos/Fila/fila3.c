// Módulo de implementação de fila (versão 1).  Escreva um módulo filadeints.c que implemente uma fila de números inteiros em um vetor alocado estaticamente. O módulo deve conter as funções  criafila,  colocanafila,  tiradafila,  filavazia  e  filacheia.  O vetor que abriga a fila bem como os índices que indicam o início e o fim da fila devem ser variáveis globais do módulo.  Escreva também uma interface filadeints.h para o módulo.  [Solução: ./solucoes/fila2.html]

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct filaa{
    int fim;
    int *v;
};

typedef struct filaa *fila;

fila criafila();
void colocanafila(fila f, int d);
int tiradafila(fila f);
int filavazia(fila f);
int filacheia(fila f);
int comprimentofila(fila f);

int main(){

    fila f = criafila();
    int x;
    int z;

    if(!filacheia(f)){
        colocanafila(f, 1);
        colocanafila(f, 2);
        colocanafila(f, 3);
        colocanafila(f, 4);
        colocanafila(f, 5);
    }

    if(!filavazia(f)){
        z = tiradafila(f);
        printf("%d foi tirado\n", z);
    }

    int y = comprimentofila(f);
    printf("%d eh o tamanho da fila\n", y);

    if(!filacheia(f)){
        colocanafila(f, 6);
    }

    int j = comprimentofila(f);
    printf("%d eh o tamanho da fila\n", j);

    while(!filavazia(f)){
        x = tiradafila(f);
        printf("%d foi tirado do inicio da fila\n", x);
    }

    return 0;
}

fila criafila(){
    fila f = (fila)malloc(sizeof(struct filaa));
    f->v = (int *)malloc(sizeof(int)*MAX);
    f->fim = 0;
    return f;
}

void colocanafila(fila f, int d){
    f->v[f->fim] = d;
    f->fim++;
    return;
}

int tiradafila(fila f){
    int x = f->v[0];
    for(int i=0; i<f->fim; i++){
        f->v[i] = f->v[i+1];
    }
    f->fim--;
    return x;
}

int filavazia(fila f){
    if(f->fim == 0){
        printf("fila vazia");
        return 1;
    }
    return 0;
}

int filacheia(fila f){
    if(f->fim == MAX){
        printf("fila cheia");
        return 1;
    }
    return 0;
}

int comprimentofila(fila f){
    int x = f->fim;
    return x;
}