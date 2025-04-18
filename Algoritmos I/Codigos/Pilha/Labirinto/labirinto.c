#include <stdlib.h>
#include "pilha.h"
/*
 / Funções Pilha.h
 / pilha criarPilha();
 / void empilhar(pilha P, int x, int y)
 / void desempilhar(pilha P, int *x, int *y);
 / int pilhaVazia(pilha P);
 / void liberarPilha(pilha P);
*/

//estrutura dos elementos da pilha, como se trata de uma matriz vamos ter x e y
typedef struct elemento
{
	int x;
	int y;
	struct elemento * prox; //apontador para o próximo elemento da pilha
}elemento;

//definindo a struct criada no pilha.h para um ponteiro pilha
//vai funcionar como a cabeça de uma lista --> para guardar o topo da pilha
//sempre vai ser no topo da pilha e um elemento aponta para o de baixo
struct pilhaa
{
	elemento * topo; //apontado para o elemento da pilha
};

pilha criarPilha()
{
	//Se colocar somente pilha ao invés de struct pilha vai criar um  espaço para guardar o endereço de memoria, com struct pilha você cria um bloco de memoria
	//Esse bloco de memória vai te permitir realizar as demais funções
	pilha P = (pilha)malloc(sizeof(struct pilhaa)); 
	P->topo = NULL; //Quando se está criando uma pilha o topo não tem nada
	return P;
}

void empilhar(pilha P, int x, int y)
{
	elemento * e = (elemento *)malloc(sizeof(elemento)); //criando um apontador para o elemento
	e->x = x;
	e->y = y;
	e->prox = P->topo; //Meu dado agora passou a ser o topo da pilha
	P->topo = e; //Faz com que o bloco pilha aponte para o elemento 'e' como o topo --> na hora de desimpilhar irá apontar para ele
	
	return;
}

void desempilhar(pilha P, int *x, int *y) //O desempilhar vai preencher o x e o y
{
	elemento * T = P->topo; 
	*x = T->x; 
	*y = T->y;
	P->topo = T->prox; 
	free(T);
	return;
}

int pilhaVazia(pilha P)
{
	if(P == NULL) return 1; //se a pilha for nula por qualquer motivo
	if(P->topo == NULL) return 1; //se a  pilha foi criada e nenhum dado armazenado ou se carregou todos os dados
	else return 0;
}

//Função recursiva para liberar todos os apontadores da lista
//Precisa de duas funções diferentes pois há duas structs diferente ou seja dois elementos diferentes
void liberarListaElementos(elemento *e)
{
	if(e == NULL) return; //Caso base da lista, quando chega a lista vazia
	liberarListaElementos(e->prox);
	free(e);
}

void liberarPilha(pilha P)
{
	liberarListaElementos(P->topo);
	free(P);
}


