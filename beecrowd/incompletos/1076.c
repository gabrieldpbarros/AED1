#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **grafo; // Matriz de adjacência dinâmica
int *grau; // Vetor para armazenar o grau de cada vértice
int *visitado;
int vertices, arestas; // Número de vértices e arestas

// Função para alocar a matriz de adjacência e vetores auxiliares
void alocarMemoria(int vertices){
    grafo = (int **) malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) 
        grafo[i] = (int *) calloc(vertices, sizeof(int));
    grau = (int *) calloc(vertices, sizeof(int));
    visitado = (int *) calloc(vertices, sizeof(int));
}

// Função para liberar a memória alocada
void liberarMemoria(int vertices){
    for(int i = 0; i < vertices; i++) 
        free(grafo[i]);
    free(grafo);
    free(grau);
    free(visitado);
}

// Função para adicionar aresta ao grafo
void adicionarAresta(int u, int v){
    grafo[u][v]++;
    grafo[v][u]++;
    grau[u]++;
    grau[v]++;
}

// Busca em Profundidade (DFS) para verificar se o grafo é conexo
void dfs(int v){
    visitado[v] = 1;
    for(int i = 0; i < vertices; i++) 
        if(grafo[v][i] > 0 && !visitado[i]) 
            dfs(i);
}

// Verifica se o grafo é conexo (considerando apenas os vértices com grau > 0)
int ehConexo(){
    int inicio = -1;
    for(int i = 0; i < vertices; i++) 
        if(grau[i] > 0){
            inicio = i;
            break;
        }
    if(inicio == -1)
        return 1; // Grafo vazio é considerado conexo
    
    // Zerando o vetor visitado antes da DFS
    for(int i = 0; i < vertices; i++)
        visitado[i] = 0;
    
    dfs(inicio);
    for(int i = 0; i < vertices; i++) 
        if (grau[i] > 0 && !visitado[i]) return 0;
    return 1;
}

// Conta a quantidade de vértices com grau ímpar
int contaImpares(){
    int count = 0;
    for(int i = 0; i < vertices; i++)
        if (grau[i] % 2 != 0) count++;
    
    return count;
}

int main(){
    int qt_casos;
    scanf("%d", &qt_casos);

    while(qt_casos--){
        int inicio;
        scanf("%d", &inicio);
        scanf("%d %d", &vertices, &arestas);
        
        alocarMemoria(vertices);
        
        for(int i = 0; i < arestas; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adicionarAresta(u, v);
        }
        
        // Verifica conectividade
        if(!ehConexo()){
            liberarMemoria(vertices);
            continue;
        }
        
        // Verifica grau ímpar
        int impares = contaImpares();
        if(impares > 0){
            liberarMemoria(vertices);
            continue;
        }
        
        printf("%d\n", 2 * arestas); // Número mínimo de movimentos
        liberarMemoria(vertices);
    }
    return 0;
}