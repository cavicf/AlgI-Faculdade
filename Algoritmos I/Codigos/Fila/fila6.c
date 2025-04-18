#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do elemento da fila
typedef struct elem {
    int dado;
    struct elem *prox;
} elem;

// Definição da estrutura da célula-cabeça da fila
struct filaa {
    elem *cabeca; // Célula-cabeça
    elem *fim;    // Ponteiro para o último elemento
};

typedef struct filaa *fila;

// Função para criar a fila
fila criaFila() {
    fila f = (fila)malloc(sizeof(struct filaa));
    f->cabeca = (elem *)malloc(sizeof(elem)); // Cria a célula-cabeça
    f->cabeca->prox = NULL; // Inicializa o próximo da cabeça como NULL
    f->fim = NULL; // Inicializa o último elemento como NULL
    return f;
}

// Verifica se a fila está vazia
int filaVazia(fila f) {
    return (f == NULL || f->cabeca->prox == NULL);
}

// Função para adicionar um elemento na fila
void colocaFila(fila f, int dado) {
    elem *novo = (elem *)malloc(sizeof(elem));
    novo->dado = dado;
    novo->prox = NULL; // O próximo do novo elemento será NULL

    if (filaVazia(f)) {
        f->cabeca->prox = novo; // O próximo da cabeça aponta para o novo
    } else {
        f->fim->prox = novo; // O próximo do último elemento aponta para o novo
    }
    f->fim = novo; // Atualiza o ponteiro do último elemento
}

// Função para remover um elemento da fila
int tiraFila(fila f) {
    int x;
    elem *aux;

    if (filaVazia(f)) {
        return -1; // Retorna -1 se a fila estiver vazia
    }

    aux = f->cabeca->prox; // O primeiro elemento é o próximo da cabeça
    x = aux->dado; // Pega o valor do primeiro elemento
    f->cabeca->prox = aux->prox; // Atualiza o próximo da cabeça
    free(aux); // Libera a memória do elemento removido

    if (f->cabeca->prox == NULL) { // Se a fila ficou vazia, atualiza o último também
        f->fim = NULL;
    }

    return x; // Retorna o valor removido
}

// Função para liberar a memória da fila
void liberaFila(fila f) {
    elem *aux;
    while (f->cabeca->prox != NULL) {
        aux = f->cabeca->prox; // Guarda o próximo elemento
        f->cabeca->prox = f->cabeca->prox->prox; // Atualiza o próximo da cabeça
        free(aux); // Libera a memória do elemento
    }
    free(f->cabeca); // Libera a célula-cabeça
    free(f); // Libera a estrutura da fila
}

// Função principal para demonstrar o funcionamento da fila
int main() {
    int x;
    fila f = criaFila(); // Cria a fila

    // Adiciona elementos à fila
    colocaFila(f, 2);
    colocaFila(f, 3);
    colocaFila(f, 5);

    // Remove e imprime elementos da fila
    while (!filaVazia(f)) {
        x = tiraFila(f);
        printf("%d foi tirado da fila\n", x);
    }

    liberaFila(f); // Libera a memória da fila

    return 0;
}
