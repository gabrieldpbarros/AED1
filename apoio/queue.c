#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int content;
    struct Node *next;
} Queue;

Queue* createQueue(){
    Queue *head = malloc(sizeof(Queue));
    head->next = NULL;
    return head;
}

// 't' é o final da fila
int dequeue(Queue *head, Queue **address_t){
    // Verifica se a fila está vazia
    if(head->next == NULL)
        return -1;

    Queue *aux = head->next;
    int temp = aux->content;
    head->next = aux->next; // A fila avança uma posição

    if(head->next == NULL) // Se o novo endereço de 's' aponta para uma célula vazia,
        *address_t = head; // logo a fila está vazia
    
    // A posição inicial é liberada
    free(aux);
    return temp;
}

void enqueue(int value, Queue *head, Queue **address_t){
    Queue *new = malloc(sizeof(Queue));
    // Nova célula
    new->content = value;
    new->next = NULL;
    // Se a fila está vazia, então 'new' é o primeiro nó
    if(*address_t == head){
        head->next = new;
    } else{
        (*address_t)->next = new; // Cauda atual aponta para o novo nó
    }

    *address_t = new; // Atualiza o endereço da cauda
}

void printQueue(Queue *head){
    int i = 1;
    Queue *aux;

    for(aux = head->next; aux != NULL; aux = aux->next)
        printf("Posicao %d = %d\n", i++, aux->content);
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
    Queue *head = createQueue(); // Cabeça da fila
    Queue *tail = head; // Cauda aponta para a cabeça

    enqueue(10, head, &tail);
    enqueue(20, head, &tail);
    enqueue(30, head, &tail);

    printQueue(head);
    printf("\n");

    dequeue(head, &tail);
    // dequeue(head, &tail);

    printQueue(head);

    freeQueue(head);

    return 0;
}