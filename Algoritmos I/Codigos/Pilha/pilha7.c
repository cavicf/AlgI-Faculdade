#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
char pilha[N];
int t; 

int bemFormada(char s[], char guarda1[], char guarda2[]);
void criapilha();
void empilha(char y);
char desempilha();
int pilhavazia();

int bemFormada(char s[], char guarda1[], char guarda2[]){
    char x;
    int i;
    
    if(s[0]=='c' && s[1]=='\0') return 1;

    for(i=0; s[i]!='\0'; i++){
        empilha(s[i]);
    }

    i = 0;
    while(x != 'c'){
        if(pilhavazia()) return 0;
        x = desempilha();
        guarda1[i] = x;
        i++;
    }
    guarda1[i] = '\0';
    desempilha();
    i = 0;
    while(!pilhavazia()){
        x = desempilha();
        guarda2[i] = x;
        i++;
    }
    guarda2[i] = '\0';

    int j = strlen(guarda2) - 1;
    for(i=0; guarda1[i] != '\0'; i++){
        if(guarda1[i]==guarda2[j]){
            return 1;
            j--;
        }
        else{
            return 0;
        }
    }
}
void criapilha(){
   t = 0;
}

void empilha(char y) {
   pilha[t++] = y;
}

char desempilha() {
   return pilha[--t];
}

int pilhavazia() {
   return t == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    char sequencia[100];
    char guarda1[100];
    char guarda2[100];
    printf("Digite a sequencia: ");
    scanf("%s", sequencia);

    criapilha(); 

    if (bemFormada(sequencia, guarda1, guarda2)) {
        printf("Sequencia bem formada\n");
    } else {
        printf("Sequencia mal formada\n");
    }

    return 0;
}
