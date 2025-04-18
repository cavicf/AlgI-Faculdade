// Implemente uma fila em uma lista encadeada não circular com célula-cabeça. Será preciso manter o endereço c da célula-cabeça e o endereço u da última célula.
#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int dado;
   struct elem *prox;
}elem;

struct filaa{
    elem *ini;
    elem *fim;
};

typedef struct filaa *fila;

fila criaFila(){
    fila f = (fila)malloc(sizeof(struct filaa));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int filaVazia(fila f){
    if(f == NULL || f->ini == NULL){
        return 1;
    }
    return 0;
}

void colocaFila(fila f, int dado){
    elem *novo = (elem *)malloc(sizeof(elem));
    novo->dado = dado;
    novo->prox = NULL;
    if(filaVazia(f)){
        f->ini = novo;
        f->fim = novo;
    }
    else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}   

int tiraFila(fila f){
    int x;
    elem *aux;
    if(filaVazia(f)){
        return -1;
    }
    aux = f->ini;
    x = aux->dado;
    f->ini = aux->prox;
    free(aux);
    return x;
}

void liberaelem(elem *e){
    if(e == NULL) return;
    liberaelem(e->prox);
    free(e);
}

void liberaFila(fila f){
    liberaelem(f->ini);
    free(f);
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

    liberaFila(f);

    return 0;
}