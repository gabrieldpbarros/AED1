#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 301

typedef struct node{
    char data;
    struct node *next;
} Stack;

// Função para empilhar um elemento
void push(Stack **top, char c){
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char pop(Stack **top){
    if (*top == NULL)
        return '\0';
    Stack *temp = *top;
    char c = temp->data;
    *top = temp->next;
    free(temp);
    return c;
}

// Função para verificar o topo da pilha sem remover
char peek(Stack *top){
    return (top != NULL) ? top->data : '\0';
}

int isEmpty(Stack *top){
    return top == NULL;
}

// Função para definir a precedência dos operadores
int precedence(char op){
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char *infix, char *postfix){
    Stack *stack = NULL;
    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];

        // Se for operando (letra ou número), adiciona diretamente à saída
        if(isalnum(c)) 
            postfix[j++] = c;
        // Se for '(', empilha
        else if(c == '(')
            push(&stack, c);
        // Se for ')', desempilha até encontrar '('
        else if(c == ')'){
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(&stack);
            pop(&stack); // Remove '(' da pilha
        }
        // Se for operador, trata a precedência
        else{
            while(!isEmpty(stack) && precedence(peek(stack)) >= precedence(c) && peek(stack) != '('){
                if (c == '^' && peek(stack) == '^')
                    break; // Para associatividade direita de '^'
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while(!isEmpty(stack))
        postfix[j++] = pop(&stack);

    postfix[j] = '\0'; // Finaliza a string
}

int main(){
    int N;
    scanf("%d", &N);

    while(N--){
        char infix[MAX], postfix[MAX];
        scanf("%s", infix);

        infixToPostfix(infix, postfix);

        printf("%s\n", postfix);
    }

    return 0;
}