#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 2500
typedef struct filaa * fila;
struct filaa{ //define a estrutura da fila
  int ini; //armazena o índice do inicio da fila
  int fim; //armazena o índice do final da fila
  int *vetor; //é um ponteiro para um array que vai armazenar os elementos da fila
};

fila criar_fila(){ //indica que a função vai retornar uma estrutura do tipo fila
  fila f = (fila) malloc(sizeof(struct filaa)); //cria uma estrutura do tipo fila
  //faz a criação agora de cada campo da estrutura
  f->vetor = (int *) malloc(sizeof(int) * MAX_CAPACITY); //cria-se o vetor que armazenará os elementos da fila
  f->ini = 0; //define que o indice inial é 0
  f->fim = 0; //define que o indice final é 0
  return f; // devolve a fila ja criada
}

void insere_fila(fila f, int v){ //função para inserir valores na fila, recebe a fila e o valor
  if(f->fim == MAX_CAPACITY){ //verifica se a fila está cheia, vendo se o indice do fim é igual ao valor da capacidade maxima
    printf("Erro: fila cheia\n");
    return;
  }
  f->vetor[f->fim] = v; //insere o valor no final da fila, utilizando o indice fim
  f->fim++; //incrementa o indice fim para apontar para a próxima posição
  return;
}

int comprimento_fila(fila f){
    return f->fim - f->ini;
}

int remover_fila(fila f){ //função para remover valores da fila
  if(f->ini == f->fim){ //se o valor de inicio e fim forem iguais quer dizer que a fila está vazia
    printf("Erro: fila vazia");
    return -1; //retorna um erro
  }
  int v = f->vetor[f->ini]; //cria-se uma variavel para guardar o valor que estava no inicio
  //da fila e que será removido
  f->ini++; //incrementa na posição inicio indicando que o próximo elemento será atendido e é o novo primeiro lugar
  return v; //retorna esse valor que estava no início da fila
}


void liberar_fila(fila f){ //função para apagar a fila
  free(f->vetor); //aqui temos que liberar primeiro a alocação do vetor
  free(f); //para depois leberar a alocação da estrutura 
  return;
}

int main(int argc, char *argv[]){
  fila f = criar_fila(); //cria um ponteiro que receberá o endereço da fila criada pela função
  insere_fila(f, 10);//insere valores na fila
  insere_fila(f, 20);//insere valorea na fila
  insere_fila(f, 30);
  insere_fila(f,40);
  int aux = remover_fila(f);//cria um auxiliar que receberá o primeiro valor da fila que será removido
  printf("%d\n", aux);//imprime o valor removido
  insere_fila(f, 5);//insere valor na fila 
  aux = remover_fila(f);//remove o novo primeiro lugar da fila
  printf("%d\n", aux);//imprime ele
  printf("%d", comprimento_fila(f));
  liberar_fila(f);//exclui a fila
  return 0;
}
