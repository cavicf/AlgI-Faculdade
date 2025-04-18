//Tenho um labirinto e quero sair desse labirinto
//Vai colocar na pilha as casas que você já sabe o caminho para ir
//Chamada de Busca por Profundidade ou DFS ou Algoritmo de Backtracking
//Enquanto tiver alguém na pilha --> Vai tirar a casa da pilha e é como se você tivesse na casa 0, 0
//A partir da casa 00 --> Vai olhar os caminhos que você pode seguir e empilhar os caminhos que você descobriu uma direção que pode seguir
//Vai passar para o próximo caminho após a verificação.
//Precisa guardar as casas que você já visitou
//Consequencia de usar a busca em profundidade --> Vai te devolver o primeiro caminho que ele encontrar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
/*
 / Funções Pilha.h
 / pilha criarPilha();
 / void empilhar(pilha P, int x, int y)
 / void desempilhar(pilha P, int *x, int *y);
 / int pilhaVazia(pilha P);
 / void liberarPilha(pilha P);
*/

void resolveLabirinto(int n, char **labirinto);

int main()
{
	int n;
	scanf("%d\n", &n); //lendo o tamanho do labirinto
	
	char **labirinto; //declara ponteiro de ponteiro para alocar a matriz do labirinto
	labirinto = (char**)malloc(sizeof(char *) * n); //aloca o vetor de ponteiros que são as linhas da matriz
	for(int i = 0; i < n; i++)
	{
    //aloca as colunas da matriz do labirinto
	  labirinto[i] = (char *)malloc(sizeof(char) * n); //Vai ler no formato labirinto[x][y] --> Vai ler a coluna 1 como X e a coluna 2 como y
	}
	for(int y = 0; y < n; y++)
	{
	  for(int x = 0; x < n; x++)
	  {
	    scanf("%c", &(labirinto[x][y]));  // faz a leitura do labirinto 
	  }
	  scanf("\n");
	}
	for(int y = 0; y < n; y++)
	{
	  for(int x = 0; x < n; x++)
	  {
	    printf("%c", labirinto[x][y]); //printa o labirinto
	  }
	  printf("\n");
	}
	
	resolveLabirinto(n, labirinto); //chama a função que irá resolver o labirinto, passando seu tamanho e a matriz que é o labirinto em si
	
	return 0;
}

//Função que irá resolver o labirinto
void resolveLabirinto(int n, char **labirinto)
{
  char **visitado = (char **)malloc(sizeof(char *) *n); //aqui vamos criar uma matriz para marcar os lugares que ja foram visitados
  for(int i = 0; i < n; i++)
  {
    visitado[i] = (char *)malloc(sizeof(char) * n);
    for(int j = 0; j < n; j++)
    {
      visitado[i][j] = '0'; //definimos inicialmente a matriz toda com '0'
    }
  }
  
  pilha P = criarPilha(); //Na pilha vao as casas que eu já sei o caminho
  
  empilhar(P, 0, 0); //vamos empilhar o x=0 e y=0 que é a entrada do nosso labirinto
  visitado[0][0] = 'E'; //'E' = entrar, marcamos que na primeira casa é a entrada
  
  //Aqui vai tirar alguem da pilha
  while(!pilhaVazia(P)) //Enquanto a pilha não estiver vazia ele vai fazer o laço
  {
    int xAtual;
    int yAtual;
    desempilhar(P, &xAtual, &yAtual); //A função desempilhar espera receber um endereço de memoria porque são ponteiros, tira da pilha os caminhos q tem lá, q vão ser os atuais
    if(labirinto[xAtual][yAtual] == 'S') //e verifica se eles são a saída
    {
      printf("Cheguei na saída\n"); //se for, emite uma mensagem avisando que chegou
      for(int y = 0; y < n; y++)
      {
        for(int x = 0; x < n; x++)
        {
          printf("%c", visitado[x][y]); //e printa matriz de lugars visitados
        }
        printf("\n");
      }
      return;
    }
  
    //Descobrindo Novos Caminhos -->  Se é do tamanho do labirinto, não é uma parede e não foi visitado, coloca ele na pilha
    //Tentar ir para o sul
    if(yAtual + 1 < n && labirinto[xAtual][yAtual + 1] != 'X' && visitado[xAtual][yAtual + 1] == '0' /*Significa que ainda não foi visitado*/)
    {
      empilhar(P, xAtual, yAtual+1);//marca que vc visitou aquele caminho
      visitado[xAtual][yAtual+1] = 'C'; //'C' --> Indica que você veio do norte (cima) 
    }
    //Tentar ir para o norte
    if(yAtual - 1 >= 0 && labirinto[xAtual][yAtual-1] != 'X' && visitado[xAtual][yAtual-1] == '0')
    {
      empilhar(P, xAtual, yAtual-1);//marca que vc visitou aquele caminho
      visitado[xAtual][yAtual-1] = 'B'; //'B' --> Indica que você veio do sul (baixo) 
    }
    //Tentar ir para o leste
    if(xAtual + 1 < n && labirinto[xAtual+1][yAtual] != 'X' && visitado[xAtual+1][yAtual] == '0')
    {
      empilhar(P, xAtual+1, yAtual);//marca que vc visitou aquele caminho
      visitado[xAtual+1][yAtual] = 'L'; //'L' --> Indica que você veio do oeste (left - esquerda)
    }
    //Tentar ir para o oeste
    if(xAtual - 1 >= 0 && labirinto[xAtual-1][yAtual] != 'X' && visitado[xAtual-1][yAtual] == '0')
    {
      empilhar(P, xAtual-1, yAtual);//marca que vc visitou aquele caminho
      visitado[xAtual-1][yAtual] = 'R'; //'R' --> Indica que você veio do leste (right - direita) 
    }
  }
  printf("Sem saída\n");
  
  liberarPilha(P);  
  return;
}
