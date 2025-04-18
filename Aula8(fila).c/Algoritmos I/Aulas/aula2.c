#include <stdio.h>
#include <stdlib.h>

//criando uma strcut que recebe as informações de um aluno
typedef struct aluno
{
    char nome[50];
    char matricula[20];
    char curso[3];
}aluno;



//função que gera um vetor, utilizando alocação dinamica
int * gera_arranjo(int ini, int fim){

    int tam = fim - ini + 1;
//para que a função consiga retornar um vetor, deve-se alocar memória pra esse vetor
//pois a função em si não consegue retornar um vetor de forma comum pois a memória será perdida depois
//que a execução da função terminar
    int *p = (int *) malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++){
        p[i] = ini+i;
    }

    return p;
}

//função que recebe o endereço da struct
//nesse caso a função não retorna nada, pois ela mesma executa um printf
void verifica_curso(aluno *a){
//a seta é um modo de apontar o ponteiro para um campo específixo da struct
    if(a->curso[0]=='S' && a->curso[1]=='I' && a->curso[2]=='N'){
        printf("aluno no curso de SIN\n");
    }
    return;
}

int main(int argc, char * argv[]){
    //cria-se dois ponteiros que chamam a função, utiliza-se ponteiros pois a função trabalha
    //com alocação dinamica da memória
    int *X = gera_arranjo(0,10);
    int *W = gera_arranjo(10,20);

//imprimindo os vetores criados com a função, aqui não precisa ser *x[i] pra imprimir o conteúdo
//pois agora essas variáveis se comportam como vetores comuns ao terem memória alocada dinamicamente
    printf("X = ");
    for(int i=0; i<11; i++){
        printf("%d ,", X[i]);
    }

    printf("\n");
    
    printf("w = ");
    for(int i=0; i<11; i++){
        printf("%d ,", W[i]);
    }
    printf("\n");

//dependendo da quantidade de memória que quer utilizar o stack não é suficiente, ent tem q usar o heap
//alocando memoria dinamicamente acessa o heap
    int tamanho = 5;
    //printf("y = ");
    int *Y = (int *)malloc(sizeof(int)*tamanho);
    for(int i=0; i < tamanho; i++){
        Y[i] = i+20;
        //printf("%d ,", Y[i]);
    }
    printf("\n");

    //tamanho que as variaveis ocupam na memoria dependendo do seu tipo
    //printf("%d %d\n", sizeof(float), sizeof(double));

//criando variáveis do tipo aluno que foi criado
    aluno camily;
    aluno julia;

//passanso manualmente o valor do campo curso da varivel camily do tipo aluno
    camily.curso[0] = 'S';
    camily.curso[1] = 'I';
    camily.curso[2] = 'N';

//passando o endereço de memoria de uma struct para ser mais eficiente na função, mas também poderia
//passar a struct de forma normal que funciona
    for(int i = 0; i<tamanho; i++){
        verifica_curso(&camily);
    }

    free(X);
    free(W);
    return 0;
}