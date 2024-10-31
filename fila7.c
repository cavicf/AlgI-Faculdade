// Deque.  Uma fila dupla (= deque, pronuncia-se deck) permite inserção e remoção em qualquer das duas extremidades da fila. Implemente uma fila dupla (em um vetor ou uma lista encadeada) e escreva as funções de manipulação da estrutura.

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

void colocaFilaFinal(fila f, int dado){
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

void colocaFilaInicio(fila f, int dado){
    elem *novo = (elem *)malloc(sizeof(elem));
    novo->dado = dado;
    novo->prox = f->ini;
    f->ini = novo;
    if(filaVazia(f)){
        f->ini = novo;
        f->fim = novo;
    }
}   


int tiraFilaInicio(fila f){
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


int tiraFilaFinal(fila f){
    int x;
    elem *aux;
    if(filaVazia(f)){
        return -1;
    }
    aux = f->fim;
    x = aux->dado;
    f->fim = aux->prox;
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
    colocaFilaFinal(f, 2);
    colocaFilaFinal(f, 3);
    colocaFilaFinal(f, 5);
    colocaFilaInicio(f, 1);
    colocaFilaInicio(f, 12);
    
    x = tiraFilaInicio(f);
    printf("%d foi tirado da fila\n", x);
    
    int z = tiraFilaFinal(f);
    printf("%d foi tirado da fila\n", z);

    int y = tiraFilaInicio(f);
    printf("%d foi tirado da fila\n", y);

    liberaFila(f);

    return 0;
}