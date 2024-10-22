#include <stdio.h>
#include <stdlib.h>

#define N 100
char pilha[N];
int t; // Variável global usada para o índice da pilha

// Esta função devolve 1 se a string ASCII s 
// contém uma sequência bem-formada de 
// parênteses e colchetes; devolve 0 se 
// a sequência é malformada.
int bemFormada(char s[], int index);

void criapilha();
void empilha(char y);
char desempilha();
int pilhavazia();

int bemFormada(char s[], int index) {
    if (s[index] == '\0') {
        return pilhavazia();
    }

    char c = s[index];
    char topo;

    if (c == ')' || c == ']') {
        if (pilhavazia()) return 0;
        topo = desempilha();
        if ((c == ')' && topo != '(') || (c == ']' && topo != '[')) {
            return 0;
        }
    } else if (c == '(' || c == '[') {
        empilha(c);
    }
   
    return bemFormada(s, index + 1);
}

void criapilha() {
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

int main(int argc, char *argv[]) {
    char sequencia[100];
    int index = 0;

    printf("Digite a sequencia: ");
    scanf("%s", sequencia);

    criapilha(); // Inicializa a pilha antes de começar a verificação

    if (bemFormada(sequencia, index)) {
        printf("Sequencia bem formada\n");
    } else {
        printf("Sequencia mal formada\n");
    }

    return 0;
}
