#include <stdlib.h>
#include "pilha.h"

//aqui estamos definindo o formato de cada elemento da nossa pilha
typedef struct elem{
  char dado; //aqui vamos guardar o nosso dado
  struct elem *prox; //aqui é um ponteiro que será ligado a outros elementos da pilha, o elo de ligação entre os elementos
}elemento;

//o ponteiro pilha que foi definido na declaração da struct pilhaa é o ponto de entrada para a pilha, é com ele q iremos alocar memória pra nossa estrutura pilhaa e dar inicio a nossa pilha
struct pilhaa{ //ja a struct pilhaa é o inicio da nossa pilha em si, ela possui um ponteiro do tipo elemento que irá apontar sempre para o topo da nossa pilha, ou seja, aponta para o primeiro elemento, permitindo nossas operações
  elemento *topo;
};

pilha criar_pilha(){ //aqui vamos criar a nossa pilha, começamos alocando memória para nossa estrutura pilha, que de início estará vazia sem nenhum elemento, por isso o topo aponta para NULL
  pilha P = (pilha) malloc(sizeof(struct pilhaa)); //definimos p como um ponteiro que vai apontar para a estrutura alocada
  P->topo = NULL; //definimos topo como null pois ainda não temos nenhum elemento na nossa pilha
  return P; //retornamos o ponteiro para a struct alocada
}
//Nesse ponto temos a estrutura pilhaa alocada na memória, que possui apenas um ponteiro (topo) que aponta para null, pois ainda não temos nenhum elemento criado

//Agora com a função empilhar, estaremos criando os elementos de fato (dado, *prox) e fazendo a ligação entre ele e cada elemento novo criado na pilha
void empilhar(pilha P, char c){ //recebe o endereço da estrutura pilha com o ponteiro para o topo e o dado que será guardado no elemento que está sendo criado
  elemento *e = (elemento *) malloc(sizeof(elemento)); //aloca uma estrutura elemento na memória e devolve o endereço do bloco alocado para o ponteiro e.
  e->dado = c; //atribuimos o valor do dado c ao dado do elemento criado
  e->prox = P->topo; //aqui o ponteiro proximo do elemento aponta para o antigo topo da pilha, imagine sempre que estão um embaixo do outro ([topo]->null e agora temos [elemento]->[topo]->null)
  P->topo = e; //aqui definimos que o novo topo da pilha é o elemento que acaba de ser criado e inserido ([topo]->[elemento]->null)
  return;
}

//Agora com a função desimpilhar estaremos removendo o elemento do topo da pilha, liberando a memória q foi alocada para ele
char desempilhar(pilha P){
  elemento * T = P->topo; //criamos um ponteiro auxiliar para guardar onde o atual topo está apontando ([t]->[topo]->[elemento]->null) então [t]->[elemento].
  char r = T->dado; //aqui criamos uma variável para retornar o valor que estava no elemento que estamos removendo
  P->topo = T->prox; //definimos que o novo topo é o próximo elemento, aquele que o elemento que está sendo removido aponta com seu prox
  free(T); //aqui liberamos a memória do elemento q estava no topo da pilha, removendo ele
  return r; //devolvemos o dado que foi removido
}

//Aqui vamos verificar se a nossa pilha está vazia
int pilha_vazia(pilha P){
  if(P == NULL) return 1; //se p que é nossa estrutura pilha estiver null, quer dizer q a estrutura nem existe
  if(P->topo == NULL) return 1; //se o topo for null quer dizer que não existem elementos na nossa pilha
  return 0; //se não, nossa pilha possui elementos
}

//aqui vamos liberar todos os elementos da nossa pilha para poder exclui-la, recebe primeiro o topo da pilha
void liberar_lista_elementos(elemento * e){
  if(e == NULL) return; //caso base se o elemento for null quer dizer que chegamos ao ultimo elemento da pilha
  liberar_lista_elementos(e->prox); //chamamos a função para os proximos elementos
  free(e); //libera a memória alocada para o elemento
}

//aqui liberamos de fato a alocação da pilha, liberando todos seus elementos
void liberar_pilha(pilha P){
  liberar_lista_elementos(P->topo); //liberamos todos os elementos com a função recursiva liberar_lista_elementos, começando pelo topo da pilha
  free(P); //liberamos a alocação da estrutura pilha inicial
}


































