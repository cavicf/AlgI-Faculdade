#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(int argc, char *argv[]){
  fila f = criar_fila(); //cria um ponteiro que receberá o endereço da fila criada pela função
  insere_fila(f, 10);//insere valores na fila
  insere_fila(f, 20);//insere valorea na fila
  int aux = remover_fila(f);//cria um auxiliar que receberá o primeiro valor da fila que será removido
  printf("%d\n", aux);//imprime o valor removido
  insere_fila(f, 5);//insere valor na fila 
  aux = remover_fila(f);//remove o novo primeiro lugar da fila
  printf("%d\n", aux);//imprime ele
  liberar_fila(f);//exclui a fila
  return 0;
}
