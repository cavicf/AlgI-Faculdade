#include <stdio.h>
#include <stdlib.h>

void desaloca(int **m, int m_size); // Adicione o tamanho de m(linhas) como argumento

int main() {
    int m = 3; // Defina um valor apropriado para m
    int n = 4; // Defina um valor apropriado para n

    int **M; 
    M = malloc(m * sizeof(int *));
    if (M == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < m; ++i) {
        M[i] = malloc(n * sizeof(int));
        if (M[i] == NULL) {
            perror("Erro ao alocar memória");
            desaloca(M, i); // Libere a memória alocada até o ponto do erro
            exit(EXIT_FAILURE);
        }
    }

    // Liberação da memória
    desaloca(M, m); // passa o array e o tamanho dele

    return 0;
}

void desaloca(int **m, int m_size) {
    for (int i = 0; i < m_size; ++i) { //desaloca primeiro o que foi alocado em cada linha(colunas)
        free(m[i]); // Libera cada linha
    }
    free(m); //depois desaloca as linhas q é um array de ponteiros
}
