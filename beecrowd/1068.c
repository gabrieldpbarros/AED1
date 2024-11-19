#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char elemento[2];
    struct stack *seg;
} Stack;

void insere(Stack *lst, char *item){
    Stack *lstnew = malloc(sizeof(Stack));

    strcpy(lstnew->elemento, item);
    lstnew->seg = NULL;

    Stack *aux = lst;
    while(aux->seg != NULL)
        aux = aux->seg;
    aux->seg = lstnew;
}

void imprimeLista(Stack *lst){
    Stack *aux = lst->seg;
    while(aux != NULL){
        printf("%s", aux->elemento);
        if(aux->seg != NULL) printf(" ");

        aux = aux->seg;
    }
    printf("\n");
}

void freeList(Stack *lst){
    Stack *aux = lst;
    while(aux != NULL){
        Stack *temp = aux;
        aux = aux->seg;
        free(temp);
    }
}

int main(void){
    int qtd_expressoes, i;
    char eq[1001];
    Stack *cabeca;
    Stack **geral;

    scanf("%d", &qtd_expressoes);
    getchar();

    geral = malloc(qtd_expressoes * sizeof(Stack*));

    for(i = 0; i < qtd_expressoes; i++){
        int j = 0;
        cabeca = malloc(sizeof(Stack));
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