#include <stdio.h>
#include <stdlib.h>

#define INFINITY 300

void freeMatrix(int **graph, int size){
    for(int i = 0; i < size; i++)
        free(graph[i]);
    free(graph);
}

void dijkstra(int **graph, int matrix_order, int start){
    int i, j, count, mindistance, next_node;
    int *distance = malloc(matrix_order * sizeof(int));
    int *pred = malloc(matrix_order * sizeof(int));
    int *visited = calloc(matrix_order, sizeof(int));
    int **cost = (int**) malloc(matrix_order * sizeof(int*));
    for(i = 0; i < matrix_order; i++)
        cost[i] = malloc(matrix_order * sizeof(int));
    
    for(i = 0; i < matrix_order; i++)
        for(j = 0; j < matrix_order; j++)
            if(graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];

    for(i = 0; i < matrix_order; i++){

    }


    free(distance);
    free(pred);
    free(visited);
    freeMatrix(graph, matrix_order);
    }

    int main(void){
    int n_cidades, n_estradas, n_servico, v_consertado;
    scanf("%d %d %d %d", &n_cidades, &n_estradas, &n_servico, &v_consertado);

    while(n_cidades != 0 && n_estradas != 0 && n_estradas != 0 && v_consertado != 0){
        for(int i = 0; i < n_estradas; i++){

        }
    }

    return 0;
}