#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int matriz[5][3];
    int linha, coluna;
    int maior;
    int idc1, idc2;

    for(linha = 0; linha<5; linha++){
        for(coluna = 0; coluna <3; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }

    for(linha = 0; linha<5; linha++){
        for(coluna = 0; coluna <3; coluna++){
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    maior = matriz[0][0];

    for(linha = 0; linha<5; linha++){
        for(coluna = 0; coluna <3; coluna++){
            if(maior < matriz[linha][coluna]){
                maior = matriz[linha][coluna];
                idc1 = linha;
                idc2 = coluna;
            }
        }
    }

    printf("o maior valor da matriz eh: %d e se encontra na linha %d e coluna %d", maior, idc1, idc2);
    return 0;
}