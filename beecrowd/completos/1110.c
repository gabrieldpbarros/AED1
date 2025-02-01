#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int card;
    struct Node *next;
} list;

list *createNode(){
    list *node = malloc(sizeof(list));
    node->next = NULL;
    return node;
}

void push(list *head, int value){
    list *new = createNode();
    new->card = value;

    list *aux = head;
    while(aux->next != NULL)
        aux = aux->next;
    aux->next = new;
}

int pop(list *head){
    list *aux = head->next;
    head->next = aux->next;
    int value = aux->card;
    free(aux);

    return value;
}

int main(void){
    int n_cards;
    while(scanf("%d", &n_cards) && n_cards != 0){
        list *head = createNode();
        int i = 1;
        while(i <= n_cards)
            push(head, i++);

        printf("Discarded cards: ");
        while(i > 2){
            int discarded = pop(head);
            if(discarded != 1)
                printf(", ");
            printf("%d", discarded);

            int bottom = pop(head);
            push(head, bottom);
            i--;
        }

        int last = pop(head);
        printf("\nRemaining card: %d\n", last);

        free(head);
    }

    return 0;
}