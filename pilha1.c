#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct pilha{
    char vetor[MAX];
    int t;
}pilha;

pilha* criarPilha(){
    pilha *a = (pilha*)malloc(sizeof(pilha));
    if(a != NULL){
        a->t = 0;
    }
    return a;
}

int pilhaCheia(pilha *a){
    if(a->t == MAX) return 1;
    return 0;
}

int pilhaVazia(pilha *a){
    if(a->t==0) return 1;
    return 0;
}

char desimpilha(pilha *a){
    char r = a->vetor[a->t-1];
    a->t--;
    return r;
}

void empilha(pilha *a, char c){
    a->vetor[a->t] = c;
    a->t++;
}

int main(int argc, char *argv[]){
    
    pilha *a = criarPilha();
    char r;

    if(!pilhaCheia(a)){
        empilha(a, 'A');
        empilha(a, 'B');
        empilha(a, 'C');
        empilha(a, 'D');
        empilha(a, 'E');
    }

    while(!pilhaVazia(a)){
        r = desimpilha(a);
        printf("tirando %c do topo\n", r);
    }
    
    return 0;
}