#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int elemento;
    struct stack *seg;
} Stack;

void push(int valor, Stack *h){
    Stack *new;
    new = malloc(sizeof(Stack));

    new->elemento = valor;
    new->seg = h->seg;
    h->seg = new;
}

int pop(Stack *h){
    int temp;
    Stack *aux;

    aux = h->seg;
    temp = aux->elemento;
    h->seg = aux->seg;
    free(h);

    return temp;
}

int printStack(Stack *h){
    int i = 1;
    Stack *aux = h->seg;
    while(aux != NULL){
        printf("Elemento %d = %d\n", i, aux->elemento);
        aux = aux->seg;
        i++;
    }
}

int main(void){
    int qtd_elementos, elemento, i;
    Stack head, *p;
    p = &head;
    p->seg = NULL;

    printf("Insira a quantidade de elementos a ser inseridos na pilha: ");
    scanf("%d", &qtd_elementos);

    for(i = 0; i < qtd_elementos; i++){
        scanf("%d", &elemento);

        push(elemento, p);
    }
    
    printStack(p);

    return 0;
}