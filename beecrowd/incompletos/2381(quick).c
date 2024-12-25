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

void insert(char *name, list *head, list *old_address, list *new_address){
    list *lstnew, *aux = head;
    if(name != NULL){
        lstnew = malloc(sizeof(list));
        strcpy(lstnew->nome, name);
        lstnew->next = NULL;

        while(aux->next != new_address)
        aux = aux->next;
        aux->next = lstnew;
    } else{
        
    }
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

void swap(){

}

int selectPivot(){

}

void partition(){

}

void quickSort(list *lststart, int start, int end){
    if(start < end){

    }
}

int main(void){
    int n, k, i; // n = total de alunos, k = posição do aluno sorteado
    char aluno[21];
    list *head = createList();
    scanf("%d %d", &n, &k);

    char *entrada = malloc(n * 21);

    for(i = 0; i < n; i++){
        fgets(aluno, 21, stdin);
        strtok(aluno, "\n");
        insert(aluno, head, NULL, NULL);
    }


    free(entrada);
    return 0;
}