#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    int qt_cases;
    scanf("%d", &qt_cases);

    while(qt_cases--){
        int start, vertices, edges;
        scanf("%d", &start);
        scanf("%d %d", &vertices, &edges);

        int graph_order = sqrt(vertices);

        int **graph = (int**) calloc(graph_order, sizeof(int));
        for(int i = 0; i < graph_order; i++)
            graph[i] = calloc(graph_order, sizeof(int));

        while(edges--){
            int node1, node2;
            scanf("%d %d", &node1, &node2);
        }
    }

    return 0;
}