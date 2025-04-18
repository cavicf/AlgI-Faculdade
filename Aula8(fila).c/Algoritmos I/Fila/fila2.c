// Módulo de implementação de fila (versão 1).  Escreva um módulo filadeints.c que implemente uma fila de números inteiros em um vetor alocado estaticamente. O módulo deve conter as funções  criafila,  colocanafila,  tiradafila,  filavazia  e  filacheia.  O vetor que abriga a fila bem como os índices que indicam o início e o fim da fila devem ser variáveis globais do módulo.  Escreva também uma interface filadeints.h para o módulo.  [Solução: ./solucoes/fila2.html]

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct filaa{
    int ini;
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


    if(!filacheia(f)){
        colocanafila(f, 16);
        colocanafila(f, 17);
        colocanafila(f, 18);
        colocanafila(f, 19);
        colocanafila(f, 20);
        colocanafila(f, 11);
        colocanafila(f, 12);
        colocanafila(f, 13);
        colocanafila(f, 14);
        colocanafila(f, 15);
    }


    

    int y = comprimentofila(f);
    printf("%d eh o tamanho da fila\n", y);

    if(!filacheia(f)){
        colocanafila(f, 6);
    }

    while(!filavazia(f)){
        x = tiradafila(f);
        printf("%d foi tirado do inicio da fila\n", x);
    }

    return 0;
}

fila criafila(){
    fila f = (fila)malloc(sizeof(struct filaa));
    f->v = (int *)malloc(sizeof(int)*MAX);
    f->ini = 0;
    f->fim = 0;
    return f;
}

void colocanafila(fila f, int d){
    if (!filacheia(f)) {
        f->v[f->fim] = d;
        f->fim = (f->fim + 1) % MAX;
    } else {
        printf("Fila cheia\n");
    }
}

int tiradafila(fila f){
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % MAX;
    return x;
}

int filavazia(fila f){
    if(f->fim == f->ini){
        printf("fila vazia\n");
        return 1;
    }
    return 0;
}

int filacheia(fila f){
    if(((f->fim + 1) % MAX)==f->ini){
        printf("fila cheia\n");
        return 1;
    }
    return 0;
}

int comprimentofila(fila f){
    int x;
    if (f->fim >= f->ini) {
        x = f->fim - f->ini;
    } else {
        x = MAX - (f->ini + f->fim);
    }
    return x;
}