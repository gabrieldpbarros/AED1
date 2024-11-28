#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int aluno;
    struct node *next;
} Queue;

Queue* createQueue(){
    Queue *head = malloc(sizeof(Queue));  
    head->next = NULL;
    return head;
}

void enqueue(int elemento, Queue *head, Queue **tail){
    Queue *new = malloc(sizeof(Queue));

    new->aluno = elemento;
    new->next = NULL;

    if(*tail == NULL || head->next == NULL)
        head->next = new;
    else
        (*tail)->next = new;
    *tail = new;
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

// Armazena todos os itens que foram trocados
int track(int item1, int item2, int length, int *v){
    int i;
    for(i = 0; i < length; i++){
        if(v[i] == 0){ // O item não está no vetor.
            v[i++] = item1;
            v[i] = item2;
        } else if(v[i] == item1){ // O primeiro item está no vetor.
            item1 = 0;
        } else if(v[i] == item2){ // O segundo item está no vetor.
            item2 = 0;
        } else if (item1 == 0 && item2 == 0){ // Ambos estão no vetor.
            return 1;
        }
    }

    return 0;
}

int counter(int length, int *v){
    int i = 0, count = 0;

    while(i < length && v[i] != 0)
        count++;
    
    return count;
}

int bubbleSort(Queue *head, int length, int *v){
    int temp;
    Queue *aux1, *aux2;

    for(aux1 = head->next; aux1 != NULL; aux1 = aux1->next){
        for(aux2 = aux1->next; aux2 != NULL; aux2 = aux2->next){
            if(aux1->aluno < aux2->aluno){
                temp = aux1->aluno;
                aux1->aluno = aux2->aluno;
                aux2->aluno = temp;
                track(aux1->aluno, aux2->aluno, length, v);
            }
        }
    }
    
    return counter(length, v);
}

int main(void){
    int n, length, i, j, elemento, contador;
    char *entrada, *token;
    Queue *head = malloc(sizeof(Queue));  
    head->next = NULL;
    Queue *tail = head;

    scanf("%d", &n);
    getchar();

    entrada = malloc(3893);
    int num_alunos_fixos[n];


    free(entrada);
    freeQueue(head);
    return 0;
}