#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort (ordem decrescente)
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n; // Número de casos de teste
    scanf("%d", &n);

    // Para armazenar os resultados de cada caso de teste
    int *count = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int m; // Número de alunos
        scanf("%d", &m);

        int *notas = malloc(m * sizeof(int));
        int *ordenado = malloc(m * sizeof(int));

        for (int j = 0; j < m; j++) {
            scanf("%d", &notas[j]);
            ordenado[j] = notas[j];
        }

        // Ordena a cópia em ordem decrescente
        qsort(ordenado, m, sizeof(int), compare);

        // Conta os alunos que não mudaram de posição
        count[i] = 0;
        for (int j = 0; j < m; j++) {
            if (notas[j] == ordenado[j])
                count[i]++;
        }

        free(notas);
        free(ordenado);
    }

    // Imprime os resultados para cada caso de teste
    for (int i = 0; i < n; i++) {
        printf("%d\n", count[i]);
    }

    free(count);
    return 0;
}