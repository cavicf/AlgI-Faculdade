#include <stdio.h>
#include <string.h>
#include "pilha.h"

int casa_caracter(char topo, char c){
  if(topo == '(' && c == ')') return 1;
  if(topo == '[' && c == ']') return 1;
  if(topo == '{' && c == '}') return 1;
  return 0;
}

int main(int argc, char *argv[]){
  //aqui fazemos a criação da pilha
  pilha P = criar_pilha();
  char sequencia[100];
  //lemos um dado q o usuário vai inserir que será colocado na pilha
  scanf("%s", sequencia);
  
  for(int i = 0; i < strlen(sequencia); i++){
    char c = sequencia[i]; //pegamos caractere por caractere do que o usuário escreveu
    if(c == '(' || c == '[' || c == '{'){ //conferimos se ele é algum caractere de abertura
      empilhar(P, c); //se for, nós empilhamos ele
    }else if(c == ')' || c == ']' || c == '}'){ //mas se for algum caractere de fechamento
      if(pilha_vazia(P)){ //verificamos se a pilha ta vazia, se estiver vazia então aquele caractere de fechamento não possui uma abertura empilhada, logo a sequencia é inválida
        printf("Sequencia desbalanceada!\n");
        return 0;
      }
      char topo = desempilhar(P); //mas se a pilha não estiver vazia, vamos desimpilhar o ultimo caracter q foi colocado na pilha e verificar se é o caracter de abertura correspondente do fechamento com a função casa_caracter
      if(casa_caracter(topo, c) == 0){//se o return for 0, a sequencia é invalida
      	printf("Sequencia desbalanceada!\n");
      	return 0;
      }
    }
  }
  //se ele fez todas as verificações e não possuiu nenhuma mensagem de erro
  if(pilha_vazia(P)){ //verificamos se a pilha está vazia, ou seja, todos os caracteres passsaram no teste
    printf("Sequencia balanceada!\n"); //portanto sequencia válida
  }else{
    printf("Sequencia desbalanceada!\n");//se sobrou algum caractere na pilha quer dizer que algo deu errado
  }
  
  liberar_pilha(P); //liberando a memória alocada
  return 0;
}