#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char word[201];
    struct node *next;
} instance;

instance *createNode(){
    instance *new = malloc(sizeof(instance));
    new->next = NULL;
    return new; 
}

void push(instance *head, char *string){    
    instance *aux = head;
    while(aux->next != NULL && strcmp(aux->next->word, string) <= 0){
        if(strcmp(aux->next->word, string) == 0)
            return;
        aux = aux->next;
    }
    
    instance *new = createNode();
    strcpy(new->word, string);
    new->next = aux->next;
    aux->next = new;
}

void printList(instance *head){
    instance *aux = head->next;

    while(aux != NULL){
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
    char *entrada = malloc(201 * sizeof(char));
    
    while(scanf("%s", entrada) != EOF){
        int j = 0;
        char palavra[51];

        for(int i = 0; entrada[i] != '\0'; i++){
            entrada[i] = tolower(entrada[i]);
            if(isalpha(entrada[i]) != 0)
                palavra[j++] = entrada[i];
            else if(j > 0){
                palavra[j] = '\0';
                push(head, palavra);
                j = 0;
            }
        }

        if(j > 0){
            palavra[j] = '\0';
            push(head, palavra);
        }
    }

    printList(head);
    
    freeList(head);
    free(entrada);

    return 0;
}