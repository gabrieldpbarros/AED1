#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[201];
    struct node *next;
} instance;

instance *createNode(){
    instance *new = malloc(sizeof(instance));
    new->next = NULL;
    return new; 
}

int push(instance *head, char *string){
    instance *new = createNode();
    strcpy(new->word, string);

    instance *aux = head;
    while(aux->next != NULL && strcmp(aux->next->word, string) <= 0){
        if(strcmp(aux->word, string) == 0)
            return 0;
        aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
}

void printList(instance *head){
    instance *aux = head->next;

    while(aux->next != NULL){
        printf("%s\n", aux->word);
        aux = aux->next;
    }
}

void freeList(instance *head){
    while(head->next != NULL){
        instance *temp = head;
        head = head->next;
        free(temp);
    }

}

int main(){
    instance *head = createNode();
    char *entrada = malloc(200 * sizeof(char));

    while((scanf("%s"), entrada)){
        char *token = strtok(entrada, " ");
        push(head, token);
        token = strtok(NULL, " ");
    }

    printList(head);
    
    freeList(head);
    free(entrada);

    return 0;
}