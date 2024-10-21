#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

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
    if(!pilhaVazia(a)){
        char r = a->vetor[a->t-1];
        a->t--;
        return r;
    }
    return '\0';
}

void empilha(pilha *a, char c){
    if(!pilhaCheia(a)){
        a->vetor[a->t] = c;
        a->t++;   
    }
}

int main(int argc, char *argv[]){
    
    pilha *a = criarPilha();
    char string[50];
    char string2[50];
    char c;
    int i;
    
    int tam;
    printf("digite uma frase:\n");
    fgets(string, sizeof(string), stdin);

    tam = strlen(string);
    int j = 0; 

    for(i=0; i<tam; i++){
        c = string[i];
        
        if(c == ' ' || c == '\n'){
            while(!pilhaVazia(a)){
                string2[j] = desimpilha(a);
                j++;
            }
            if(c == ' '){
                string2[j] = ' ';
                j++;
            }
        } else {
            empilha(a, c);  
        }
    }
    

    string2[j] = '\0';
    
    printf("%s", string2);

    return 0;
}