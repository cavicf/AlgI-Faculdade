#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[50];
    char matricula[20];
    char *curso;
}aluno;


int main(){
    //alocando um vetor na memória dinamicamente
    int *x = (int*)malloc(sizeof(int)*10);
    if(x==NULL){
        printf("sem memoria");
        return -1;
    }

    for(int i = 0; i<10; i++){
        x[i] = 0;
        printf("%d ", x[i]);
    }
    printf("\n");

    //alocando com a função calloc que ja zera as casas do vetor
    //é meio desnecessário, pois na maioria das vezes ja inicializamos o vetor
    int *y = (int *)calloc(10, sizeof(int));
    for(int i = 0; i<10; i++){
        printf("%d ", y[i]);
    }
    printf("\n");

    //devolve null se não tiver espaço pra alocar
    int *aux = (int *)realloc(y, 200*sizeof(int));
    if(aux != NULL){
        y = aux;
    }

    free(x);
    free(y);
    
    //para guardar 10 endereços de memória que guardam inteiros
    //usa duas ** porque é um endereço que vai guardar outros endereços
    //alocação dinamica de matriz
    int **z = (int**)malloc(10*sizeof(int*));
    for(int i=0; i<10; i++){
         z[i] = (int*)malloc(sizeof(int)*10);
        for(int j = 0; j<10; j++){
            z[i][j]=10*i+j;
        }
    }

    //criando uma string para onde a matriz vai apontar
   char curso[3];
   strcpy(curso, "SIN");

    //criando uma matriz do tipo aluno
    struct aluno **a = (struct aluno**)malloc(10*sizeof(struct aluno*));
    for(int i=0; i<10; i++){
         a[i] = (struct aluno*)malloc(sizeof(struct aluno)*10);
         //apontando o campo curso de aluno para a string curso
        for(int j = 0; j<10; j++){
            a[i][j].curso = curso;
        }
    }

//imprimindo o campo curso da matriz, não precisa do * no a[i][j].curso pois a string ja é um ponteiro
//e o parametro &s ja espera receber um ponteiro
    for(int i=0; i<10; i++){
        for(int j = 0; j<10; j++){
            printf("%s\n", a[i][j].curso);
        }
    }


    free(z);
    free(a);
    


    return 0;
}