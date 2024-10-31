//lista encadeada com cabeça

#include <stdio.h>
#include <stdlib.h>

struct celula{
    int dado;
    struct celula *prox;
};

typedef struct celula *cel;

cel criaLista();
void insereLista(cel lista, int x);
void liberaLista(cel lista);
int listaVazia(cel lista);
void imprimeLista(cel lista);
cel busca(cel lista, int x);
void crescente(cel lista);



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]){

    cel lista = criaLista();

    if(listaVazia(lista)==1){
        printf("lista vazia\n");
    }

    insereLista(lista, 6);
    insereLista(lista, 5);
    insereLista(lista, 4);
    insereLista(lista, 3);
    insereLista(lista, 2);
    insereLista(lista, 1);

    if(listaVazia(lista)==0){
        printf("lista possui elementos\n");
    }
    else{
        printf("lista vazia\n");
    }

    imprimeLista(lista);

    if(busca(lista, 3) == NULL){
        printf("3 nao esta na lista\n");
    }
    else{
        printf("3 esta na lista\n");
    }

    crescente(lista);

    liberaLista(lista);
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

cel criaLista(){
    cel lista = (cel)malloc(sizeof(struct celula));
    lista->prox = NULL;
    return lista;
}

void insereLista(cel lista, int x){
    cel novo = (cel)malloc(sizeof(struct celula));
    novo->dado = x;
    novo->prox = lista->prox;
    lista->prox = novo;
}

int listaVazia(cel lista){
    if(lista->prox == NULL){
        return 1;
    }
    return 0;
}

void liberaLista(cel lista){
    if(lista==NULL || lista->prox == NULL) return;
    liberaLista(lista->prox);
    free(lista);    
}

void imprimeLista(cel lista){
    if(lista == NULL || lista->prox == NULL) return;    
    printf("%d \n", lista->prox->dado);
    imprimeLista(lista->prox);
}


cel busca(cel lista, int x){
    if(lista == NULL || lista->prox == NULL) return NULL;
    if(lista->prox->dado == x) return lista->prox;
    return busca(lista->prox, x);
}


void crescente(cel lista){
    if(lista->prox == NULL || lista->prox->prox == NULL){
        printf("esta em ordem crescente\n");
    }
    else if(lista->prox->dado < lista->prox->prox->dado){
        crescente(lista->prox);
    }
    else{
        printf("nao esta em ordem crescente\n");
    }
}


