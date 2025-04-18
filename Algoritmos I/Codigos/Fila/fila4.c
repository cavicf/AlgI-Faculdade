// criafila,  colocanafila,  tiradafila,  filavazia,  liberafila.
// fila circular sem cabeça

#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int dado;
   struct elem *prox;
}elem;

struct filaa{
    elem *fim;
};

typedef struct filaa *fila;

fila criaFila(){
    fila f = (fila)malloc(sizeof(struct filaa));
    f->fim = NULL;
    return f;
}

int filaVazia(fila f){
    if(f->fim == NULL){
        return 1;
    }
    return 0;
}

void colocaFila(fila f, int dado){
    elem *novo = (elem *)malloc(sizeof(elem));
    novo->dado = dado;
    if(filaVazia(f)){
        novo->prox = novo;
        f->fim = novo;
    }
    else{
        novo->prox = f->fim->prox;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int tiraFila(fila f){
    int x;
    elem *aux;
    if(!filaVazia(f)){
        if(f->fim->prox == f->fim){
            aux = f->fim;
            x= aux->dado;
            f->fim = NULL;
        }
        else{
            aux = f->fim->prox;
            x = aux->dado;
            f->fim->prox = aux->prox;
        }
        free(aux);
        return x;
    }
    return -1;
}

int main(){
    int x;
    fila f = criaFila();
    colocaFila(f, 2);
    colocaFila(f, 3);
    colocaFila(f, 5);
    while(!filaVazia(f)){
        x = tiraFila(f);
        printf("%d foi tirado da fila\n", x);
    }

    return 0;
}