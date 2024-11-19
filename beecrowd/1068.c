#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct stack{
    char elemento[2];
    struct stack *seg;
} Stack;

int isEmpty(Stack *top){
    return top->seg == NULL;
}

void push(Stack *top, char *item){
    Stack *lstnew = malloc(sizeof(Stack));

    strcpy(lstnew->elemento, item);
    lstnew->seg = top->seg;
    top->seg = lstnew;
}

void retira(Stack *top){
    Stack *aux = top->seg;
    if(aux != NULL){
        top->seg = aux->seg;
        free(aux);
    }
}

int main(void){
    int max_expressoes = MAX, qtd_expressoes = 0, i; 
    int *geral;
    char eq[1001];
    Stack head, *h;

    // Vetor que armazena a correção de cada expressão.
    geral = malloc(max_expressoes * sizeof(int));

    for(i = 0; i < max_expressoes; i++){
        int j = 0, aux = 0;
        h = &head;
        h->seg = NULL;
        // Verifica se o usuário terminou de entrar com expressões.
        if(fgets(eq, 1001, stdin) == NULL){
            break;
        }
        qtd_expressoes++;

        while(eq[j] != '\0' && eq[j] != '\n'){
            if(eq[j] == '('){
                char item[2] = {eq[j], '\0'};
                push(h, item);
            } else if(eq[j] == ')'){
                if(isEmpty(h)){
                    aux = 1;
                    break;
                } else{
                    retira(h);
                }
            }
            j++;
        }
        // Parênteses que não foi fechado.
        if(!isEmpty(h)){
            aux = 1;
        }

        retira(h);
        geral[i] = aux;
    }
    for(i = 0; i < qtd_expressoes; i++){
        if(geral[i] == 0) printf("correct\n");
        else printf("incorrect\n");
    }
    
    free(geral);
    return 0;
}