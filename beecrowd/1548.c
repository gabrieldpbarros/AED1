#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
    int aluno;
    struct queue *next;
} Queue;

Queue *createQueue(){
    Queue *head = malloc(sizeof(Queue));  
    head->next = NULL;
    return head;
}

void enqueue(int elemento, Queue *head, Queue **tail){
    Queue *new = malloc(sizeof(Queue));

    new->aluno = elemento;
    new->next = NULL;

    if(*tail == NULL)
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
            return 0;
        } else if(v[i] == item1){ // O primeiro item está no vetor.
            item1 = 0;
        } else if(v[i] == item2){ // O segundo item está no vetor.
            item2 = 0;
        } else if (item1 == 0 && item2 == 0){ // Ambos estão no vetor.
            return 1;
        }
    }
}

int counter(int length, int *v){
    int i = 0, count = 0;

    while(i < length && v[i] != 0){
        count++;
        i++;
    }
    
    return count;
}

int bubbleSort(Queue *head, int length){
    int temp, *v;
    int i = 0;
    Queue *aux1, *aux2;

    v = calloc(length, sizeof(int));

    for(aux1 = head->next; aux1 != NULL; aux1 = aux1->next){
        for(aux2 = aux1->next; aux2 != NULL; aux2 = aux2->next){
            if(aux1->aluno < aux2->aluno){
                temp = aux1->aluno;
                aux1->aluno = aux2->aluno;
                aux2->aluno = temp;
                v[i] = aux1->aluno;
                v[++i] = aux2->aluno; 
                track(aux1->aluno, aux2->aluno, length, v);
                i++;
            }
        }
    }
    
    int repeticoes = counter(length, v);
    free(v);
    return repeticoes;
}

int main(void){
    int n, length, i, j, num, *contador;
    char *token;

    scanf("%d", &n);
    char *entrada = malloc(4000);
    contador = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        Queue *head = createQueue();
        Queue *tail = head;
        scanf("%d", &length);

        if(fgets(entrada, 4000, stdin) != NULL){
            entrada[strcspn(entrada, "\n")] = '\0';
            token = strtok(entrada, " ");
            while(token != NULL){
                num = atoi(token);
                enqueue(num, head, &tail);
                token = strtok(NULL, " ");
            }
        }

        contador[i] = length - bubbleSort(head, length);
        freeQueue(head);
    }

    for(i = 0; i < n; i++)
        printf("%d\n", contador[i]);

    free(entrada);
    free(contador);
    return 0;
}