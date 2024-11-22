#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
} Fila;

// Função para inicializar a fila
void inicializaFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
}

// Função para inserir (enqueue)
void enqueue(Fila *fila, int valor) {
    if (fila->tras == MAX - 1) {
        printf("Fila cheia\n");
        return;
    }
    fila->dados[++fila->tras] = valor;
}

// Função para remover (dequeue)
int dequeue(Fila *fila) {
    if (fila->frente > fila->tras) {
        printf("Fila vazia\n");
        return -1;
    }
    return fila->dados[fila->frente++];
}
