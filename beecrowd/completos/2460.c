#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int participante;
    struct node *next;
} Queue;

Queue* createQueue(){
    Queue *head = malloc(sizeof(Queue));
    head->next = NULL;
    return head;
}

int dequeue(int valor, Queue *head, Queue **tail){
    Queue *aux1 = head->next;
    Queue *aux2 = head;
    while(aux1 != NULL && aux1->participante != valor){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(aux1 == NULL){
        return -1;
    }

    // Se o nó for o último, atualiza a cauda
    if(aux1 == *tail)
        *tail = aux2;

    aux2->next = aux1->next;

    if(head->next == NULL) // Caso de fila vazia
        *tail = head;

    int temp = aux1->participante;
    free(aux1);
    return temp;
}

void enqueue(int value, Queue *head, Queue **tail){
    Queue *new = malloc(sizeof(Queue));

    new->participante = value;
    new->next = NULL;

    if(*tail == head || head->next == NULL){
        head->next = new;
    } else{
        (*tail)->next = new;
    }
    *tail = new;
}

void printQueue(Queue *head){
    Queue *aux;

    for(aux = head->next; aux != NULL; aux = aux->next){
        printf("%d", aux->participante);
        if(aux->next != NULL)
            printf(" ");
    }
}

void freeQueue(Queue *head){
    Queue *aux = head->next;

    while(aux != NULL){
        Queue *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(head);
}

int main(void){
    int qtd_participantes, qtd_desistentes, elemento;
    char *entrada;

    Queue *head = createQueue();
    Queue *tail = head;
    // Primeira linha de entrada
    scanf("%d", &qtd_participantes);
    getchar();

    entrada = malloc(350000 * sizeof(char));
    // Segunda linha de entrada
    fgets(entrada, 350000 * sizeof(char), stdin);
    char *token = strtok(entrada, " \n");
    while(token != NULL){
        elemento = strtol(token, NULL, 10);
        enqueue(elemento, head, &tail);
        token = strtok(NULL, " \n");
    }
    // Terceira linha de entrada
    scanf("%d", &qtd_desistentes);
    getchar();
    // Quarta linha de entrada
    fgets(entrada, 350000 * sizeof(char), stdin);
    token = strtok(entrada, " \n");
    while(token != NULL){ 
        elemento = strtol(token, NULL, 10);
        dequeue(elemento, head, &tail);
        token = strtok(NULL, " \n");
    }

    printQueue(head);

    freeQueue(head);
    free(entrada);
    return 0;
}