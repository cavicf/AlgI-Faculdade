#include <stdio.h>

int main (void) {
   int i; //criação de uma variavel inteira
   int *p; //criação de um ponteiro para inteiro
   i = 1234; //declaração da variavel
   p = &i; //apontando o ponteiro P para o endereço da variável i
   printf ("*p = %d\n", *p); //imprimindo o conteúdo do que p aponta, ou seja, o conteúdo da variavel i
   printf (" p = %ld\n", (long int) p); //imprimindo o conteúdo de p, que é um ponteiro para i, ou seja, seu conteúdo é o endereço de i em formato long int
   printf (" p = %p\n", (void *) p); //imprimindo o conteúdo de p, que é um ponteiro para i, ou seja, seu conteúdo é o endereço de i em formato hexadecimal
   printf("int &i = %ld\n", (long int) &i); //imprimindo o endereço de i diretamente para comparação em long int
   printf("hexa &i = %p\n", (void *) &i); //imprimindo o endereço de i diretamente para comparação em hexadecimal
   printf ("&p = %p\n", (void *) &p); //imprimindo o enderço do ponteiro, que é um tipo especial de variável, portanto também possui um endereço de memória no computador
   return 0;
}