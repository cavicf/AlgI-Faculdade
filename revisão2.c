#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // int idade[10];
    // int i;
    // double media = 0;
    // int maior;
    // int menor;
    char nome[30];
    char sobrenome[30];

    // for(i=0; i<10; i++){
    //     scanf("%d", &idade[i]);
    // }

    // for(i=0; i<10; i++){
    //     printf("%d\n ", idade[i]);
    // }

    // for(i=0; i<10; i++){
    //     media += idade[i];
    // }
    // media /= 10;
    // printf("a media eh: %.2lf\n", media);

    // maior = idade[0];
    // menor = idade[0];

    // for(i=0; i<10; i++){
    //     if(maior < idade[i]){
    //         maior = idade[i];
    //     }
    // }
    
    // for(i=0; i<10; i++){
    //     if(menor > idade[i]){
    //         menor = idade[i];
    //     }
    // }
    // printf("maior idade: %d  menor idade: %d", maior, menor);

    scanf("%s", nome);
    scanf("%s", sobrenome);

    printf("%s %s", nome, sobrenome);

    return 0;
}