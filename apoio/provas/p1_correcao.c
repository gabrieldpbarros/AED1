#include <stdio.h>
#include <stdlib.h>

// 1) Busque em lista.
typedef struct cel{
    int x;
    struct cel *prox;
} celula;

celula *busca(celula *head, int key){
    celula *p = head->prox;
    while((p != NULL) && (p->x != key))
        p = p->prox;
    return p;
}

// 2) HeapMax.
// - Remove o primeiro elemento;
// - Ajustar a árvore olhando pais e filhos (pai >= filhos);
// 
// [36, ]