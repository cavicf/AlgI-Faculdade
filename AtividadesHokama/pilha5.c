// O fragmento de programa abaixo opera uma pilha de objetos do tipo char.  (A função espia devolve uma cópia do topo da pilha, mas não tira esse elemento da pilha.)  Diga, em português, o que o fragmento faz.  Escreva um fragmento de código equivalente que seja bem mais curto e mais simples.
// if (pilhavazia ())  empilha ('B');
// else {
//    if (espia () != 'A')  empilha ('B');
//    else {
//       while (!pilhavazia () && espia () == 'A') 
//          desempilha ();
//       empilha ('B'); } }

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct pilha{
    int qtd;
    char vetor[MAX];
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

void empilha(pilha *a, char n){
    if(pilhaCheia(a)){
        printf("nao foi possivel empilhar, pilha cheia!\n");
    }
    a->vetor[a->qtd] = n;
    a->qtd++;
}

char desimpilha(pilha *a){
    char n;
    if(pilhaVazia(a)) return 1;
    n = a->vetor[a->qtd-1];
    a->qtd--;
    return n;
}

char espia(pilha *a){
    if(pilhaVazia(a)) return 1;
    char c = a->vetor[a->qtd-1];
    return c;
}

int main(int argc, char *argv[]){

    pilha *a = criarPilha();
    //com os numeros 1,2,3,4 podemos ter a seguintes permutações:
    char c;
    if (espia(a) != 'A') empilha (a, 'B');
    else {
       while (espia(a) == 'A'){
            c = desimpilha(a);
            printf("o caractere %c foi removido do topo: \n", c);
       } 
       empilha(a, 'B'); 
    } 

    for(int i=0; i<MAX; i++){
        printf("%c", a->vetor[i]);
    }

    free(a);
    return 0;
}