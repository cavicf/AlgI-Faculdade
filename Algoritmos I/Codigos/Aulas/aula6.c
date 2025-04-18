#include <stdio.h>

typedef struct celula celula;

struct celula{
    int valor;
    celula *prox;
};

void imprime_lista(celula *l){
    if(l==NULL) return;
    printf("%d, ", l->valor);
    imprime_lista(l->prox);
}

celula * insere_lista(celula *l, int v){
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->valor = v;
    nova-> prox = l;
    return nova;
}

int main(){
    
    celula *l=NULL;
    l = insere_lista(l,2);
    l = insere_lista(l,5);
    l = insere_lista(l,3);
    l = insere_lista(l,8);
    l = insere_lista(l,4);

    imprime_lista(l);
    printf("\n");

    return 0;
}