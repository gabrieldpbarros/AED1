#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define INFINITY INT_MAX
#define UNDEFINED -1

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
    int *previous = malloc(matrix_order * sizeof(int));
    int *visited = malloc(matrix_order * sizeof(int));

    // Valores iniciais
    for(i = 0; i < matrix_order; i++) 
        distance[i] = INFINITY;
    distance[start] = 0;
    for(i = 0; i < matrix_order; i++)
        previous[i] = UNDEFINED;  
    memset(visited, false, matrix_order * sizeof(int));
    vertex[0] = 0; // Distância
    vertex[1] = start; // Vértice atual

    push(head, vertex);

    while(head->next != NULL){
        free(vertex);
        vertex = pop(head); // Define o vértice atual e a distância da origem

        if(visited[vertex[1]]) // Se já foi visitado, pula a iteração
            continue;

        visited[vertex[1]] = true;
        for(i = 0; i < matrix_order; i++){
            if(graph[vertex[1]][i] == 0)
                continue;

            int next_node = i; // Variável desnecessária, mas facilita a compreensão
            int next_distance = vertex[0] + graph[vertex[1]][i]; // Distância da origem até o vértice atual

            if(!visited[next_node] && next_distance < distance[next_node]){
                int *new_vertex = malloc(2 * sizeof(int));
                new_vertex[0] = next_distance;
                new_vertex[1] = next_node;

                distance[next_node] = next_distance;
                previous[next_node] = vertex[1];
                push(head, new_vertex);
            }
        }
    }

    int final_distance = distance[end];
    free(vertex);
    free(distance);
    free(previous);
    free(visited);

    priorQueue *aux;
    while(head != NULL){
        aux = head;
        head = head->next;
        free(aux);
    }

    return final_distance;
}