// Permutações produzidas pelo desempilhar.  Suponha que objetos  1, 2, 3, 4  são colocados, nessa ordem, numa pilha inicialmente vazia. Depois de empilhar um objeto, você pode tirar zero ou mais elementos da pilha. Cada elemento desempilhado é impresso numa folha de papel. Por exemplo, a sequência de operações
// empilha 1, empilha 2, desempilha, empilha 3, desempilha, desempilha, empilha 4, desempilha,
// produz a impressão da sequência 2, 3, 1, 4. Quais das 24 permutações de 1, 2, 3, 4 podem ser obtidas dessa maneira?
// criapilha,  empilha,  desempilha,  pilhavazia,  pilhacheia

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct pilha{
    int qtd;
    int vetor[MAX];
}pilha;

pilha* criarPilha(){
    pilha *a = (pilha *)malloc(sizeof(pilha));
    if(a != NULL){
        a->qtd = 0;
    }
    return a;
}

int pilhaVazia(pilha *a){
    if(a->qtd == 0) return 1;
    return 0;
}

int pilhaCheia(pilha *a){
    if(a->qtd == MAX) return 1;
    return 0;
}

void empilha(pilha *a, int n){
    if(pilhaCheia(a)){
        printf("nao foi possivel empilhar, pilha cheia!\n");
    }
    a->vetor[a->qtd] = n;
    a->qtd++;
}

int desimpilha(pilha *a){
    int n;
    if(pilhaVazia(a)) return 1;
    n = a->vetor[a->qtd-1];
    a->qtd--;
    return n;
}

void limparPilha(pilha *a){
    a->qtd = 0;
}


int main(int argc, char *argv[]){

    pilha *a = criarPilha();
    //com os numeros 1,2,3,4 podemos ter a seguintes permutações:
    empilha(a, 1);
    empilha(a,2);
    printf("%d ", desimpilha(a));
    printf("%d ", desimpilha(a));
    empilha(a, 3);
    empilha(a, 4);
    printf("%d ", desimpilha(a));
    printf("%d ", desimpilha(a));
    
    limparPilha(a);
    printf("\nOutra permutacao: \n");

    empilha(a, 1);
    printf("%d ", desimpilha(a));
    empilha(a,2);
    empilha(a, 3);
    printf("%d ", desimpilha(a));
    empilha(a, 4);
    printf("%d ", desimpilha(a));
    printf("%d ", desimpilha(a));

    free(a);
    return 0;
}