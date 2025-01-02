#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
    char tel[201];
    struct List *next;
} list;

list *createList(){
    list *head = malloc(sizeof(list));
    head->next = NULL;
    return head;
}

void push(char *item, list *head){
    list *new = malloc(sizeof(list));
    strcpy(new->tel, item);
    new->next = NULL;

    list *aux = head;
    while(aux->next != NULL)
        aux = aux->next;
    aux->next = new;
}

void freeList(list *head){
    list *temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void bubbleSort(list *head){
    list *aux1, *aux2;
    char temp[201];
    for(aux1 = head->next; aux1->next != NULL; aux1 = aux1->next){
        for(aux2 = aux1->next; aux2 != NULL; aux2 = aux2->next){
            if(strcmp(aux1->tel, aux2->tel) > 0){
                strcpy(temp, aux1->tel);
                strcpy(aux1->tel, aux2->tel);
                strcpy(aux2->tel, temp);
            }
        }
    }
}

int compare_nums(char *tel1, char *tel2){
    int count = 0;
    while(tel1[count] == tel2[count])
        count++;

    return count;
}

int main(void){
    int qt_nums;
    while(scanf("%d", &qt_nums) != EOF){
        list *head = createList();

        for(int i = 0; i < qt_nums; i++){
            char num[201];
            scanf("%200s", num);
            
            push(num, head);
        }

        bubbleSort(head);

        int counter = 0;
        list *aux = head->next;
        while(aux != NULL && aux->next != NULL){
            counter += compare_nums(aux->tel, aux->next->tel);
            aux = aux->next;
        }

        printf("%d\n", counter);
        freeList(head);
    }

    return 0;
}