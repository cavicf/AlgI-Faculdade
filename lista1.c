#include <stdio.h>
#include <stdlib.h>

struct celula{
    int dado;
    struct celula *prox;
};

typedef struct celula *cel;

cel criaLista();
cel insereLista(cel lista, int x);
void liberaLista(cel lista);
int listaVazia(cel lista);
void imprimeLista(cel lista);
int quantidade(cel lista);
int altura(cel lista);
cel busca(cel lista, int x);
int profundidade(cel lista, cel alvo);
void crescente(cel lista);
int minimo(cel lista);
int listasiguais(cel lista, cel lista2);
cel pontoMedio(cel lista);

void copiaLista(cel lista, cel lista2);

int main(int argc, char *argv[]){

    cel lista = criaLista();
    cel lista2 = criaLista();

    if(listaVazia(lista)==1){
        printf("lista vazia\n");
    }

    lista = insereLista(lista, 1);
    lista = insereLista(lista, 2);
    lista = insereLista(lista, 3);
    lista = insereLista(lista, 4);
    lista = insereLista(lista, 5);
    lista = insereLista(lista, 6);

    copiaLista(lista, lista2);

    if(listaVazia(lista)==0){
        printf("lista possui elementos\n");
    }
    else{
        printf("lista vazia\n");
    }

    imprimeLista(lista);

    printf("existem %d elementos na lista\n", quantidade(lista));
    printf("a altura da lista eh %d \n", altura(lista));

    if(busca(lista, 3) == NULL){
        printf("3 nao esta na lista\n");
    }
    else{
        printf("3 esa na lista\n");
    }

    cel alvo = busca(lista, 2);
    printf("a profundidade do comeco da lista ate %d eh: %d\n", alvo->dado, profundidade(lista, alvo));

    crescente(lista);
    printf("o menor da lista eh %d\n", minimo(lista));

    if(listasiguais(lista, lista2)==1){
        printf("as listas sao iguais\n");
    }
    else{
        printf("as listas sao diferentes\n");
    }

    cel pontomedio = pontoMedio(lista);
    printf("%d eh o ponto medio da lista 1\n", pontomedio->dado);

    liberaLista(lista);
    return 0;
}


cel criaLista(){
    return NULL;
}

cel insereLista(cel lista, int x){
    cel novo = (cel)malloc(sizeof(struct celula));
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

int listaVazia(cel lista){
    if(lista == NULL){
        return 1;
    }
    return 0;
}

void liberaLista(cel lista){
    if(lista==NULL) return;
    liberaLista(lista->prox);
    free(lista);    
}

void imprimeLista(cel lista){
    if(lista == NULL) return;    
    printf("%d \n", lista->dado);
    imprimeLista(lista->prox);
}

int quantidade(cel lista){
    if(lista == NULL) return 0;
    return  1 + quantidade(lista->prox);
}

int altura(cel lista){
    if(lista == NULL || lista->prox == NULL) return 0;
    return 1 + altura(lista->prox);
}

cel busca(cel lista, int x){
    if(lista == NULL) return NULL;
    if(lista->dado == x) return lista;
    return busca(lista->prox, x);
}


int profundidade(cel lista, cel alvo){
    if(lista == NULL) return -1;
    if(lista == alvo) return 0;
    return 1 + profundidade(lista->prox, alvo);
}

void crescente(cel lista){
    if(lista->prox == NULL){
        printf("esta em ordem crescente\n");
    }
    else if(lista->dado < lista->prox->dado){
        crescente(lista->prox);
    }
    else{
        printf("nao esta em ordem crescente\n");
    }
}

int minimo(cel lista) {
    if(lista == NULL){
        return -1;
    }
    if(lista->prox == NULL){
        return lista->dado;
    }
    int proxmenor = minimo(lista->prox);
    if(lista->dado < proxmenor){
        return lista->dado;
    }
    return proxmenor;
}

int listasiguais(cel lista, cel lista2){
    if(lista == NULL && lista2 == NULL) return 1;
    if(lista == NULL || lista2 == NULL) return 0;

    if(lista->dado == lista2->dado){
        return listasiguais(lista->prox, lista2->prox);
    }
    return 0;
}

cel pontoMedio(cel lista){
    int quant = quantidade(lista);
    quant = quant / 2;
    int i = 0;
    cel r;
    while(lista != NULL){
        if(i == quant){
            r = lista;
        }
        i++;
        lista = lista->prox;
    }
    return r;
}

void copiaLista(cel lista, cel lista2){
    
}