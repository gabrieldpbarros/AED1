#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char nome[21];
    struct node *next;
} list;

list *createList(){
    list *head = malloc(sizeof(list));
    head->next = NULL;
    return head;
}

void insert(char *name, list *head){
    list *lstnew = malloc(sizeof(list));
    if (lstnew == NULL) 
        exit(0);
    strcpy(lstnew->nome, name);
    lstnew->next = NULL;

    list *aux = head;
    while(aux->next != NULL)
        aux = aux->next;
    aux->next = lstnew;
}

void freeList(list *head){
    list *aux = head->next;
    while(aux != NULL){
        list *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(head);
}

void bubbleSort(list *head){
    list *aux1, *aux2;
    char temp[21];
    for(aux1 = head->next; aux1 != NULL; aux1 = aux1->next){
        for(aux2 = aux1->next; aux2 != NULL; aux2 = aux2->next){
            if((strcmp(aux1->nome, aux2->nome) > 0)){
                strcpy(temp, aux2->nome);
                strcpy(aux2->nome, aux1->nome);
                strcpy(aux1->nome, temp);
            }
        }
    }
}

void printChosen(list *head, int position){
    list *aux = head->next;
    for(int i = 0; i < position; i++)
        aux = aux->next;
    printf("%s\n", aux->nome);
}

int main(void){
    int n, k, i; // n = total de alunos, k = posição do aluno sorteado
    char aluno[21], *token;
    list *head = createList();
    
    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++){
        scanf("%s", aluno);
        token = strtok(aluno, "\n");
        if(token != NULL)
             insert(token, head);
    }

    bubbleSort(head);
    printChosen(head, k - 1);

    freeList(head);
    return 0;
}