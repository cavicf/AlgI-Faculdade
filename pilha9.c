#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    char dado;
    struct celula *prox;
}celula;

void empilha(celula **topo, char y){
    celula *nova = (celula *)malloc(sizeof(celula));
    if(!nova){
        exit(1);
    }
    nova->dado = y;
    nova->prox = *topo;

    *topo = nova;
}

char desempilha(celula **topo){
    char x;
    celula *aux;
    aux = *topo;
    x = aux->dado;
    *topo = aux->prox;
    free(aux);
    return x;
}

int pilhaVazia(celula *topo){
    if(topo == NULL) return 1;
    return 0;
}

void liberapilha(celula *topo){
    if(topo == NULL){
        return;
    }
    liberapilha(topo->prox);
    free(topo);
}


int main(){

    celula *topo = NULL;

    empilha(&topo, '!');
    empilha(&topo, 'E');
    empilha(&topo, 'C');
    empilha(&topo, 'O');
    empilha(&topo, 'V');
    empilha(&topo, 'O');
    empilha(&topo, 'M');
    empilha(&topo, 'A');

    while(!pilhaVazia(topo)){
        printf("%c foi tirado do topo da pilha\n", desempilha(&topo));
    }

    return 0;
}