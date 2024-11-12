#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct equacao{
    char *elemento[2];
    struct celula *seg;
} celula;

int insere(celula *lst, char *item){
    celula *lstnew;

    strcpy(lstnew->elemento, item);

    celula *aux = lst;
    while(aux->seg != NULL)
        aux->seg;
    aux->seg = lstnew;
}

void freeList(celula *lst){
    celula *aux = lst;
    while(aux != NULL){
        celula *temp = aux;
        aux = aux->seg;
        free(temp);
    }
}

int main(void){
    int qtd_expressoes;
    char eq[1001];
    celula *cabeca;
    celula **geral;

    cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;

    for(int i = 0; i < qtd_expressoes; i++){

    }
    
    freeList(cabeca);
    return 0;
}