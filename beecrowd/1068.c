#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char elemento[2];
    struct celula *seg;
} celula;

void insere(celula *lst, char *item){
    celula *lstnew = malloc(sizeof(celula));

    strcpy(lstnew->elemento, item);
    lstnew->seg = NULL;

    celula *aux = lst;
    while(aux->seg != NULL)
        aux = aux->seg;
    aux->seg = lstnew;
}

void imprimeLista(celula *lst){
    celula *aux = lst->seg;
    while(aux != NULL){
        printf("%s", aux->elemento);
        if(aux->seg != NULL) printf(" ");

        aux = aux->seg;
    }
    printf("\n");
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
    int qtd_expressoes, i;
    char eq[1001];
    celula *cabeca;
    celula **geral;

    scanf("%d", &qtd_expressoes);
    getchar();

    geral = malloc(qtd_expressoes * sizeof(celula*));

    for(i = 0; i < qtd_expressoes; i++){
        int j = 0;
        cabeca = malloc(sizeof(celula));
        cabeca->seg = NULL;

        fgets(eq, 1001, stdin);

        while(eq[j] != '\0'){
            char item[2] = {eq[j], '\0'};
            insere(cabeca, item);

            j++;
        }

        geral[i] = cabeca;
    }
    for(i = 0; i < qtd_expressoes; i++) imprimeLista(geral[i]);
    
    for(i = 0; i < qtd_expressoes; i++) freeList(geral[i]);
    free(geral);
    return 0;
}