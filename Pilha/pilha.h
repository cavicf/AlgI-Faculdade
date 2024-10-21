//definição da estrutura pilha, que possui um ponteiro que aponta para a estrutura
typedef struct pilhaa *pilha;

//função para criar a pilha
pilha criar_pilha();

//função para criar elementos e empilhar
void empilhar(pilha P, char c);

//função para apagar o elemento do topo
char desempilhar(pilha P);

//função para verificar se a pilha está vazia
int pilha_vazia(pilha P);

//função para excluir a pilha
void liberar_pilha(pilha P);
