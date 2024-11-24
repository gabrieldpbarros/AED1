#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int aluno;
    struct node *next;
} Queue;

Queue* createQueue(){
    Queue *head = malloc(sizeof(Queue));
    head->next = NULL;
    return head;
}



int main(void){

    return 0;
}