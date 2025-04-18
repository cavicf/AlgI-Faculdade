#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaa *pilha;

typedef struct elem{
    int dado;
    struct elem *prox;
}elem;

struct pilhaa{
    elem *topo;
};

//----------------------------------------------------------------------

pilha criarPilha(){
    pilha p = (pilha)malloc(sizeof(struct pilhaa));
    p->topo = NULL;
    return p;
}

void empilha(pilha p, int d){
    elem *celula = (elem*)malloc(sizeof(elem));
    celula->dado = d;
    celula->prox = p->topo;
    p->topo = celula;
    return;
}

int desempilha(pilha p){
    int x;
    elem *aux = p->topo;
    x = aux->dado;
    p->topo = aux->prox;
    free(aux);
    return x;
}

int pilhaVazia(pilha p){
    if(p == NULL) return 1;
    if(p->topo == NULL) return 1;
    return 0;
}

void liberarCelula(elem *celula){
    if(celula == NULL) return;
    liberarCelula(celula->prox);
    free(celula);   
}

void excluiPilha(pilha p){
    liberarCelula(p->topo);
    free(p);
}

int ttt(int x[], int n){
    pilha p = criarPilha();
    int r = 0;
    if(x[n]>0){
        while(n>=0){
            if(n==0){
                empilha(p, 0);
                break;
            }
            else{
                empilha(p, x[n]);
            }
            n--;
        }
        while(!pilhaVazia(p)){
            r+= desempilha(p);
        }
    }
    else{
        do{
            n--;
            if(x[n]>0){
                while(n>=0){
                    if(n==0){
                        empilha(p, 0);
                        break;
                    }
                    else{
                        empilha(p, x[n]);
                    }
                    n--;
                }
                while(!pilhaVazia(p)){
                    r+= desempilha(p);
                }
            }
        }while(x[n]<0);
    }

    excluiPilha(p);
    return r;
}

//------------------------------------------------------------------------------------------

int main(){
    
    int n, r, i;

    scanf("%d", &n);
    int *x = (int *)malloc(sizeof(int)*n+1);
    
    x[0] = 0;

    for(i=1; i<n+1;i++){
        scanf("%d", &x[i]);
    }
    r = ttt(x, n);

    printf("%d", r);

    return 0;
}