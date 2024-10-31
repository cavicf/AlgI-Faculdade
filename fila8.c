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

void colocanafila(fila f, int dado){
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

int tiradaFila(fila f){
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
// Esta função recebe uma matriz A
// que representa as interligações entre
// cidades 0..N-1 e preenche o vetor dist
// de modo que dist[i] seja a distância
// da cidade c à cidade i, para cada i.

int* distancias (int n, int c) {
    int *dist = (int *)malloc(n*sizeof(int));
    int **A = (int **)malloc(n*sizeof(int *));
    for(int k=0; k<n; k++){
        A[k] = (int *)malloc(n*sizeof(int));
    } 
    for(int k=0; k<n; k++){
        for(int y=0; y<n; y++){
            scanf("%d", &A[k][y]);
        }
    }

    for(int j = 0; j < n; ++j)  dist[j] = n;
    dist[c] = 0;
    fila f = criaFila();
    colocanafila(f, c);

    while (!filaVazia(f)) { 
        int i = tiradaFila(f);
        for (int j = 0; j < n; ++j)
            if (A[i][j] == 1 && dist[j] >= n) {
            dist[j] = dist[i] + 1;
            colocanafila (f, j);
        }
    }
    return dist;
}

int main(){
    int n;
    int c;
    int *dist;
    scanf("%d", &n);
    scanf("%d", &c);
    dist = distancias(n, c);

    for(int i = 0; i<n; i++){
        printf("a distancia ate %d eh %d\n",i, dist[i]);
    }

    return 0;
}

//0 1 0 0 0 1 0 1 1 0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 0