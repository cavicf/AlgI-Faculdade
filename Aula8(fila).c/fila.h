//o arquivo .h serve como um anual de instruções das funções
//que serão implementadas no main.c 

//aqui está a declaração da estrutura fila
//filaa é o nome da estrutura que será definida depois
//o ponteiro indica o endereço de memória onde a struct filaa estará armazenada
//na memória, permitindo uma manipulação mais eficiente
//typedef é usada paraa criar apelidos em linguagem C
// o fila é o apelido dado para o tipo struct filaa
//traduzindo de forma literal o comando todo seria:
//Defina para a estrutura filaa o apelido de fila que é um ponteiro para a estrutura filaa
typedef struct filaa * fila;

//Função para criar uma fila.
fila criar_fila();

//Insere um inteiro numa fila passada por parametro, pois fila é um ponteiro q aponta pra estrutura
void insere_fila(fila, int);

//remove o primeiro da fila e retorna o valor removido
int remover_fila(fila);

//Apaga a fila
void liberar_fila(fila);