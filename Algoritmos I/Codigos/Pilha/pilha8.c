#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
char pilha[N];
int t;

// Esta função recebe uma expressão infixa inf
// e devolve a correspondente expressão posfixa.

void criapilha(){
   t = 0;
}

void empilha(char y) {
   if (t < N) {
        pilha[t++] = y;
    } 
}

char desempilha() {
   if (t > 0) {
        return pilha[--t];
    } else {
        return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
    }
}

int pilhaVazia() {
    return t == 0;
}

char *infixaParaPosfixa (char *inf) {
   int n = strlen(inf); //pega o tamanho da string
   char *posf =malloc ((n+1) * sizeof (char)); //aloca dinamicamente o vetor para a string resultante
   criapilha (); //aloca uma pilha
   empilha (inf[0]); // empilha '(' que é garantido ser o primeiro caractere sempre

   int j = 0; //controla a string resultado
   for (int i = 1; inf[i] != '\0'; ++i) { //começa em 1 pq ja empilhamos o 0
        char x;
      switch (inf[i]) {
         case '(': empilha (inf[i]); //caso seja abertura, empilha
                   break;
         case ')': x = desempilha (); // caso seja de fechamento, desempilha guardando numa variavel x
                   while (x != '(') {  //enquanto não for o caractere de abertura
                      posf[j++] = x; // a gnt vai salvando tudo na resultante
                      x = desempilha (); //vai desempilhando até achar o )
                   }
                   break;
         case '+':  
         case '-': x = desempilha (); //se for um + ou um - vai desempilhando tudo
                   while (x != '(') { //até achar um de abertura;
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x); //acho o de abertura, empilha ele
                   empilha (inf[i]); //e continua empilhando o restante
                   break;
         case '*':
         case '/': x = desempilha (); //se for um */ 
                   while (x != '(' && x != '+' && x != '-') { //desempilha tudo até achar um de abertura ou +-
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x); //se achar, volta o que foi desempilhado
                   empilha (inf[i]); // empilha o restante
                   break;
         default:  posf[j++] = inf[i]; //se não atender as condições faz a copia
      }
   }
   posf[j] = '\0';       //termine a string
   return posf; // devolve ela
}  

int main(){
    char* inf = (char *)malloc(sizeof(char)*100);
    scanf("%s", inf);

    char* posfixa = infixaParaPosfixa(inf);
    printf("%s", posfixa);

    free(posfixa);
    return 0;
}