#include <stdio.h>
#include <stdlib.h>

#define INFINITY 300

void freeMatrix(int **graph, int size){
    for(int i = 0; i < size; i++)
        free(graph[i]);
    free(graph);
}

void dijkstra(int **graph, int matrix_order, int start, int destination){
    // Variáveis
    int i, j, count, mindistance, next_node;
    int *distance = malloc(matrix_order * sizeof(int));
    int *pred = malloc(matrix_order * sizeof(int));
    int *visited = calloc(matrix_order, sizeof(int));
    int **cost = (int**) malloc(matrix_order * sizeof(int*));
    for(i = 0; i < matrix_order; i++)
        cost[i] = malloc(matrix_order * sizeof(int));
    
    for(i = 0; i < matrix_order; i++) // Monta a matriz de custo
        for(j = 0; j < matrix_order; j++)
            if(i == j)
                cost[i][j] = 0;
            else if(graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];

    for(i = 0; i < matrix_order; i++){
        distance[i] = cost[start][i]; // Inicializa a distância do vértice inicial até todos os outros
        pred[i] = start;
    }
    // Ponto de partida
    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < matrix_order - 1){ 
        mindistance = INFINITY;

        for(i = 0; i < matrix_order; i++) // Encontra o vértice com menor distância do início
            if(distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                next_node = i;
            }
        
        visited[next_node] = 1;
        
        for(i = 0; i < matrix_order; i++)
            if(!visited[i])
                if(mindistance + cost[next_node][i] < distance[i]){
                    distance[i] = mindistance + cost[next_node][i];
                    pred[i] = next_node;
                }

        count++;
    }

    printf("%d\n", distance[destination - 1]);

    freeMatrix(cost, matrix_order);
    free(distance);
    free(pred);
    free(visited);
    }

    int main(void){
    int n_cidades, n_estradas, n_servico, v_consertado;
    scanf("%d %d %d %d", &n_cidades, &n_estradas, &n_servico, &v_consertado);

    while(n_cidades != 0 && n_estradas != 0 && n_servico != 0 && v_consertado != 0){
        int c1, c2, cost, i;
        int **graph = (int**) calloc(n_cidades, sizeof(int*)); // Inicializa o grafo
        for(i = 0; i < n_cidades; i++)
            graph[i] = calloc(n_cidades, sizeof(int));

        for(i = 0; i < n_estradas; i++){
            scanf("%d %d %d", &c1, &c2, &cost);
            graph[c1][c2] = cost;
            graph[c2][c1] = cost;
        }

        dijkstra(graph, n_cidades, v_consertado, n_servico);

        freeMatrix(graph, n_cidades);
        
        scanf("%d %d %d %d", &n_cidades, &n_estradas, &n_servico, &v_consertado);
    }

    return 0;
}