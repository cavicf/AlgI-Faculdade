#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char nomes[5][30];
    int linhas;
    for(linhas = 0; linhas<5; linhas++){
        scanf("%s", nomes[linhas]);
    }
    
    for(linhas = 0; linhas<5; linhas++){
        if (nomes[linhas][0] == 'A'|| nomes[linhas][0] == 'a'){
            printf("o nome %s comeca com A", nomes[linhas]);
        }
    }   

    return 0;
}