#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamanho máximo da pilha

// Definição da pilha, utilizando um array para armazenar os elementos e um índice para o topo
typedef struct stack {
    int arr[MAX]; // Array para armazenar os elementos
    int top;      // Índice do topo da pilha
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack) {
    stack->top = -1; // Inicia o topo como -1 (indicando que a pilha está vazia)
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1; // Se o topo for -1, a pilha está vazia
}

// Função para verificar se a pilha está cheia
int isFull(Stack *stack) {
    return stack->top == MAX - 1; // Se o topo for o último índice, a pilha está cheia
}

// Função para adicionar um elemento à pilha (push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Pilha cheia! Não é possível adicionar mais elementos.\n");
        return;
    }
    stack->arr[++stack->top] = value; // Incrementa o topo e adiciona o valor
    printf("Elemento %d adicionado à pilha.\n", value);
}

// Função para remover um elemento da pilha (pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia! Não é possível remover o elemento.\n");
        return -1; // Retorna um valor inválido se a pilha estiver vazia
    }
    return stack->arr[stack->top--]; // Retorna o valor do topo e decrementa o topo
}

// Função para acessar o topo da pilha (peek)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia! Não há topo.\n");
        return -1; // Retorna um valor inválido se a pilha estiver vazia
    }
    return stack->arr[stack->top]; // Retorna o valor do topo
}

// Função para imprimir os elementos da pilha
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack); // Inicializa a pilha

    push(&stack, 10); // Adiciona o elemento 10 à pilha
    push(&stack, 20); // Adiciona o elemento 20 à pilha
    push(&stack, 30); // Adiciona o elemento 30 à pilha

    printStack(&stack); // Imprime os elementos da pilha

    printf("Topo da pilha: %d\n", peek(&stack)); // Mostra o topo da pilha

    printf("Elemento removido: %d\n", pop(&stack)); // Remove o topo da pilha
    printStack(&stack); // Imprime os elementos após o pop

    return 0;
}
