// 2- Compile e execute o seguinte programa. (O cast (long int) é necessário para que &i possa ser impresso no formato %ld.
// É mais comum imprimir endereços em notação hexadecimal, usando formato %p, que exige o cast (void *).)

#include <stdio.h>

//No primeiro printf está sendo impresso o valor guardado na variável i, que é 1234;
//No segundo printf está sendo impresso o endereço da variável i na memória do computador em formato de long int, por isso o cast long int;
//Já o terceiro printf também imprime o endereço de memória da variável no computador, porém em formato hexadecimal e para isso usa o cast (void *);

int main (void) {
   int i = 1234; 
   printf (" i = %d\n", i);
   printf ("&i = %ld\n", (long int) &i);
   printf ("&i = %p\n", (void *) &i);
   return 0;
}
