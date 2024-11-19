#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char objeto;
    struct stack *seg;
} Stack;

int isEmpty(Stack *head){
    return head->seg == NULL;
}

void push(char objeto, Stack *head){
    Stack *new = malloc(sizeof(Stack));

    new->objeto = objeto;
    new->seg = head->seg;
    head->seg = new;
}

void pop(Stack *head){
    Stack *aux = head->seg;

    if(aux != NULL){
        head->seg = aux->seg;
        free(aux);
    }
}

void liberaPilha(Stack *top){
    Stack *aux;

    while(top != NULL){
        aux = top->seg;
        free(top);
        top = aux;
    }    
}

int main(void){
    int qtd_casos, i, *resultados;
    char *entrada;
    Stack *head;

    scanf("%d", &qtd_casos);
    getchar();
    // Vetor que vai armazenar 
    resultados = calloc(qtd_casos, sizeof(int));
    entrada = malloc(qtd_casos * 1001);

    for(i = 0; i < qtd_casos; i++){
        int j = 0, counter = 0;
        head = malloc(sizeof(Stack));
        head->seg = NULL;

        fgets(entrada, 1001, stdin);

        while(entrada[j] != '\0' && entrada[j] != '\n'){
            if(entrada[j] == '<') 
                push(entrada[j], head);
            else if(entrada[j] == '>' && !isEmpty(head)){
                pop(head);
                counter++;
            }
            j++;
        }

        resultados[i] = counter;
        liberaPilha(head);
    }

    for(i = 0; i < qtd_casos; i++) printf("%d\n", resultados[i]);
    free(entrada);
    free(resultados);
    return 0;
}