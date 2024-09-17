#include <stdio.h>
#include <stdlib.h>

//Os seguintes jeitos de declarar a estrutura de uma lista estão corretos

// typedef struct reg {
//    int         conteudo;
//    struct reg *prox;
// } celula;

// typedef struct reg celula;
// struct reg {
//    int     conteudo; 
//    celula *prox;
// };

typedef struct celula celula;
struct celula {
   int conteudo;
   celula *prox;
}; 

//-------------------------------------------------------------------------

//FUNÇÕES

void imprime_lista(celula *l){
    if(l==NULL) return;
    printf("%d, ", l->conteudo);
    imprime_lista(l->prox);
}

celula * insere_lista(celula *l, int v){
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = v;
    nova-> prox = l;
    return nova;
}

celula * busca(celula * l, int v){
    if(l==NULL){
        return NULL;
    }
    celula * atual = l;
    if(atual->conteudo==v){
        return atual;
    }
    return busca(atual->prox, v);
}


celula * busca_antecessor(celula * l, int v){
    if(l==NULL || l->prox==NULL){
        return NULL;
    }
    if(l->prox->conteudo==v){
        return l;
    }
    return busca_antecessor(l->prox, v);
}

void insere_depois(celula*l , int v){
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = v;
    nova->prox = l->prox;
    l->prox = nova;
}

void remove_prox(celula *l){
    celula *del = l->prox;
    l->prox = del->prox;
    free(del);
}

void liberalista(celula *l){
    if(l == NULL) return;
    liberalista(l->prox);
    free(l);
    return;
}

int contalista(celula *l){
    if(l==NULL) return 0;
    return 1 + contalista(l->prox);
}

int alturalista(celula *l){
    if(l==NULL||l->prox==NULL){
        return 0;
    }
    return 1 + alturalista(l->prox);
}

int profundidadelista(celula *inicio, celula *fim){
    celula *atual = inicio;
    if(atual == fim){
        return 0;
    }
    return 1 + profundidadelista(inicio->prox, fim);
}


//------------------------------------------------------------------------

//PROGRAMA PRINCIPAL MAIN

int main(){
    
    //vendo o tamanho que uma célula ocupa na memória em bytes
    printf ("sizeof (celula) = %d\n", sizeof (celula));

    celula *l=NULL;
    l = insere_lista(l,2);
    l = insere_lista(l,5);
    l = insere_lista(l,3);
    l = insere_lista(l,8);
    l = insere_lista(l,4);

    celula*b = busca(l,7);
    if(b==NULL) printf("nao achou 7\n");
    else printf("achou\n");
    b = busca(l,4);
    if(b==NULL) printf("nao achou 4\n");
    else printf("achou\n");
    b = busca(l,2);
    if(b==NULL) printf("nao achou 2\n");
    else printf("achou\n");

    imprime_lista(l);
    printf("\n");

    insere_depois(busca(l,3), 30);

    imprime_lista(l);
    printf("\n");

    b = busca_antecessor(l,30);
    remove_prox(b);

    imprime_lista(l);
    printf("\n");

    
    printf("a lista tem %d elementos\n", contalista(l));

    printf("a lista tem %d de altura\n", alturalista(l));

    celula *alvo = NULL;
    alvo = busca(l,3);
    printf("a lista do inicio ate %d tem %d de profundidade\n", alvo->conteudo, profundidadelista(l, alvo));

    liberalista(l);


    return 0;
}

//valgrind .arquivo devolve o comportamento do computador durante o programa
