#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int participante;
    struct node *next;
} Queue;

Queue* createQueue(){
    Queue *head = malloc(sizeof(Queue));
    head->next = NULL;
    return head;
}

int dequeue(Queue *head, Queue **tail){

}

void enqueue(int value, Queue *head, Queue **tail){
    Queue *new = malloc(sizeof(Queue));

    new->participante = value;
    new->next = NULL;

    if(*tail == head){
        head->next = new;
        *tail = new;
    } else{

        *tail = new;
    }
}

int main(void){


    return 0;
}