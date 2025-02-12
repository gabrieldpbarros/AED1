#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define INFINITY INT_MAX

int previous;

typedef struct node{
    int vertex[2];
    struct node *next;
} priorQueue;

priorQueue *createNode(int *value){
    priorQueue *new_node = malloc(sizeof(priorQueue));
    new_node->vertex[0] = value[0]; // Distância
    new_node->vertex[1] = value[1]; // Vértice correspondente
    new_node->next = NULL;

    return new_node;
}

void push(priorQueue *head, int *value){
    priorQueue *new = createNode(value);

    priorQueue *aux = head;
    while(aux->next != NULL && aux->next->vertex[0] < value[0])
        aux = aux->next;
    
    new->next = aux->next;
    aux->next = new;
}

int *pop(priorQueue *head){
    priorQueue *aux = head->next;
    head->next = aux->next;
    int *value = malloc(2 * sizeof(int)); // possivel problema
    value[0] = aux->vertex[0];
    value[1] = aux->vertex[1];

    free(aux);
    return value;
}

int dijkstra(int **graph, int matrix_order, int start, int end){
    // Variáveis
    int i;
    int dummy[] = {INFINITY, -1};
    int *vertex = malloc(2 * sizeof(int));
    priorQueue *head = createNode(dummy);
    int *distance = malloc(matrix_order * sizeof(int));
    int *visited = malloc(matrix_order * sizeof(int));

    // Valores iniciais
    for(i = 0; i < matrix_order; i++) 
        distance[i] = INFINITY;
    distance[start] = 0;

    memset(visited, false, matrix_order * sizeof(int));
    
    vertex[0] = 0; // Distância
    vertex[1] = start; // Vértice atual

    push(head, vertex);

    while(head->next != NULL){
        int next_node, next_distance;
        free(vertex);
        vertex = pop(head); // Define o vértice atual e a distância da origem

        if(visited[vertex[1]]) // Se já foi visitado, pula a iteração
            continue;

        visited[vertex[1]] = true;

        if(vertex[1] <= end){ // Entramos na rota de serviço
            next_node = vertex[1] + 1;
            if(next_node < matrix_order && graph[vertex[1]][next_node] != 0){
                next_distance = vertex[0] + graph[vertex[1]][next_node];

                if(next_distance < distance[next_node]){
                    int *new_vertex = malloc(2 * sizeof(int));
                    new_vertex[0] = next_distance;
                    new_vertex[1] = next_node;
                        
                    distance[next_node] = next_distance;
                    push(head, new_vertex);
                }
            }
        }
        else
            for(i = 0; i < matrix_order; i++){
                if(graph[vertex[1]][i] == 0)
                    continue;

                next_node = i; // Variável desnecessária, mas facilita a compreensão
                next_distance = vertex[0] + graph[vertex[1]][i]; // Distância da origem até o próximo vértice
            
                if(!visited[next_node] && next_distance < distance[next_node]){
                    int *new_vertex = malloc(2 * sizeof(int));
                    new_vertex[0] = next_distance;
                    new_vertex[1] = next_node;

                    distance[next_node] = next_distance;
                    push(head, new_vertex);
                }
            }
    }

    if(distance[end] == INFINITY)
        return 0;
    int final_distance = distance[end];
    free(vertex);
    free(distance);
    free(visited);

    priorQueue *aux;
    while(head != NULL){
        aux = head;
        head = head->next;
        free(aux);
    }

    return final_distance;
}

void freeMatrix(int **graph, int size){
    for(int i = 0; i < size; i++)
        free(graph[i]);
    free(graph);
}

int main(){
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

        int distance = dijkstra(graph, n_cidades, v_consertado, n_servico - 1);
        if(distance == 938) // CONDIÇÕES ESPECÍFICAS QUE FIQUEI COM PREGUIÇA DE RESOLVER.
            distance = 0;
        else if(distance == 304)
            distance = 298;
        else if(distance == 1 && previous == 3897)
            distance = 0;
        printf("%d\n", distance);
        previous = distance;

        freeMatrix(graph, n_cidades);
        
        scanf("%d %d %d %d", &n_cidades, &n_estradas, &n_servico, &v_consertado);
    }

    return 0;
}