#include <stdio.h>

//calcula p+q
//calcula p-q

//utiliza void pois a função não vai retornar uma variavel e sim utilizará ponteiros pra trocar o valor de variaveis do main
void soma_e_sub(int p, int q, int *soma, int *sub){
    int r;
    int t;

    r = p+q;
    t = p-q;

    *soma = r;
    *sub = t;

    return;
}

int soma(int *v, int n){
    int i;
    int s = 0;
    
    for(i=0; i<n; i++){
        s = s+v[i];
    }

    return s;
}

int main(int argc, char * argv[]){

    int x;
    x = 5;
    int y;
    y = 7;

    int z;
    int w;

//passando o endereço de memoria para a função que recebe ponteiros
//aqui z e w mudam seus valores por referencia com os ponteiros 
    soma_e_sub(x,y, &z, &w);
    printf("z = %d\n", z);
    printf("w = %d\n", w);

    int X[4];
    
//aqui cria-se um ponteiro e o aponta pra primeira casa do vetor
//altera o valor da primeira casa do vetor
    int *p = X;
    *p = 26;

//irá imprimir a posição 0 do vetor
    printf("X = %d\n", X);

//vetores são sequenciais e é somado 1 unidade de tamanho (4 bytes por ser inteiro) para percorrer
//por exemplo 0x120 vai pra 0x124 nos endereços e assim por diante
    X[0]=10;
    X[1]=20;
    X[2]=35;
    X[3]=-5;
   
//chama a função para somar os valores do vetor, tem q passar o tamanho do vetor pra função sempre
//vetores são sempre passados por referência para funções pois os mesmo são ponteiros que possuem 
//endereços sequenciais na memória
    printf("soma = %d\n", soma(X, 4));

//criação do ponteiro que recebe o endereço de x
    int *px = &x;

//imprime o endereço de memoria apontado por px, ou seja, endereço de x
    printf("px %d\n", px);

//imprime o conteudo da variavel apontada por px, ou seja, o valor 5
    printf("na variavel apontada por px = %d\n", *px);

//altera o valor da variavel apontada utilizando o ponteiro, ou seja, altera o valor de x de 5 para 10
    *px=10;
    printf("x = %d\n", x);

//demonstração de que não funciona colocar x = w antes de determinar o valor de w, ou seja, o valor de x
//permanece inalterado
    x = w;
    w = 15;

    printf("x = %d\n", x);

//criação de um ponteiro que aponta para outro ponteiro
    int *pa;

    //aponta pa para px que aponta para x então altera o valor de x no *pa = 9 porque acaba recebendo
    //o endereço de px que é o próprio x
    pa = px;
    *pa = 9;
    printf("na variavel apontada por pa %d\n", *pa);

    return 0;
}

//para compilar no editor de texto é gcc -pedantic-errors -Wall nomearquivo.c -o exec
//para executar ./exec
