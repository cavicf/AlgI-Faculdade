#include <stdio.h>
#include <stdlib.h>

char* conversor(char c);

int main(){

    char a;
    char *b = NULL;  
    scanf(" %c", &a);

    b = conversor(a); //aqui diz que b aponta para o endereço de memória alocado pela função

    printf("%s", b);

    free(b);
    return 0;
}

char* conversor(char c){
    char *d = malloc( 2 * sizeof(char)); //aloca a memória
    d[0] = c;
    d[1] = '\0';

    return d; // retorna o endereço dessa memória alocada, que é apontado por b
}
