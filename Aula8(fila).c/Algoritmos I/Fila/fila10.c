#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int x;
    int y;
    struct elem *prox;
} elem;

struct filaa {
    elem *ini;
    elem *fim;
};

typedef struct filaa *fila;

fila criaFila() {
    fila f = (fila)malloc(sizeof(struct filaa));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int filaVazia(fila f) {
    return f == NULL || f->ini == NULL;
}

void colocanafila(fila f, int x, int y) {
    elem *novo = (elem *)malloc(sizeof(elem));
    novo->x = x;
    novo->y = y;
    novo->prox = NULL;
    if (filaVazia(f)) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void tiradaFila(fila f, int *x, int *y) {
    if (filaVazia(f)) {
        printf("fila vazia \n");
        return;
    }
    elem *aux = f->ini;
    *x = aux->x;
    *y = aux->y;
    f->ini = aux->prox;
    free(aux);
}

void liberaelem(elem *e) {
    if (e == NULL) return;
    liberaelem(e->prox);
    free(e);
}

void liberaFila(fila f) {
    liberaelem(f->ini);
    free(f);
}

void distancias(int n, int m, char **labirinto) {
    char **visitado = (char **)malloc(n * sizeof(char *));
    for (int k = 0; k < n; k++) {
        visitado[k] = (char *)malloc(m * sizeof(char));
    }

    // Inicializar a matriz de visitados com '0'
    for (int k = 0; k < n; k++) {
        for (int z = 0; z < m; z++) {
            visitado[k][z] = '0';
        }
    }

    fila f = criaFila();
    colocanafila(f, 0, 0); // Corrigido para começar na posição (0, 0)
    visitado[0][0] = 'E';

    while (!filaVazia(f)) {
        int xAtual, yAtual;
        tiradaFila(f, &xAtual, &yAtual);

        if (labirinto[xAtual][yAtual] == 's') { // Verifica se é a saída
            printf("Cheguei na saida\n");
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    printf("%c", visitado[y][x]);
                }
                printf("\n");
            }
            liberaFila(f);
            return;
        }

        // Tentar ir para o leste
        if (yAtual + 1 < m && labirinto[xAtual][yAtual + 1] != '#' && visitado[xAtual][yAtual + 1] == '0') {
            colocanafila(f, xAtual, yAtual + 1);
            visitado[xAtual][yAtual + 1] = 'L'; // Veio do oeste
        }
        // Tentar ir para o oeste
        if (yAtual - 1 >= 0 && labirinto[xAtual][yAtual - 1] != '#' && visitado[xAtual][yAtual - 1] == '0') {
            colocanafila(f, xAtual, yAtual - 1);
            visitado[xAtual][yAtual - 1] = 'R'; // Veio do leste
        }
        // Tentar ir para o norte
        if (xAtual - 1 >= 0 && labirinto[xAtual - 1][yAtual] != '#' && visitado[xAtual - 1][yAtual] == '0') {
            colocanafila(f, xAtual - 1, yAtual);
            visitado[xAtual - 1][yAtual] = 'B'; // Veio do sul
        }
        // Tentar ir para o sul
        if (xAtual + 1 < n && labirinto[xAtual + 1][yAtual] != '#' && visitado[xAtual + 1][yAtual] == '0') {
            colocanafila(f, xAtual + 1, yAtual);
            visitado[xAtual + 1][yAtual] = 'C'; // Veio do norte
        }
    }
    printf("Sem saída\n");
    liberaFila(f);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char **labirinto = (char **)malloc(n * sizeof(char *));
    for (int k = 0; k < n; k++) {
        labirinto[k] = (char *)malloc(m * sizeof(char));
    }

    // Ler o labirinto
    for (int k = 0; k < n; k++) {
        for (int y = 0; y < m; y++) {
            scanf(" %c", &labirinto[k][y]);
        }
    }

    distancias(n, m, labirinto);

    // Liberar memória do labirinto
    for (int k = 0; k < n; k++) {
        free(labirinto[k]);
    }
    free(labirinto);

    return 0;
}
