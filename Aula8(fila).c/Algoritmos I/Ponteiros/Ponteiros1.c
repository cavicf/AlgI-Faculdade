// 1- Tamanhos. Compile e execute o seguinte programa:

#include <stdio.h>

//o tamanho de uma struct é a soma de bytes dos seu campos;

int main (void) {
   typedef struct {
      int dia, mes, ano; 
   } data;
   printf ("sizeof (data) = %d\n", sizeof (data));
   return 0;
}