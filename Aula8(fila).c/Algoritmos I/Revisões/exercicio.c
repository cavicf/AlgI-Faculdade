#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * concatena(char * a, char * b){
    int contA = 0, contB = 0;
    int tam;
    int i=0;
    int j = 0;
    while(a[i]!='\0'){
        contA++;
        i++;
    }

    i=0;

    while(b[i]!='\0'){
        contB++;
        i++;
    }

    tam = contA + contB + 1;
    char *frase = (char*)malloc(sizeof(char)*tam);
    for(i=0; i<contA; i++){
        frase[i] = a[i];
    }


//c u r s o :   s i n \0
//0 1 2 3 4 5 6 7 8 9 10
//0 1 2 3 4 5 6 0 1 2

    for(i=contA; i<tam; i++){
        frase[i]= b[j];
        j++;
    }
    
    return frase;
}

int main(){
    char *str = concatena("CURSO: ", "SIN");
    printf("%s\n", str);

    return 0;
}