#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} node;

node *createNode(){
    node *head = malloc(sizeof(node));
    head->next = NULL;
    return head;
}

void push(int item, node *queue_head, node *stack_head, node *priorqueue_head){
    // Insere na fila
    node *newQueue = malloc(sizeof(node));

    newQueue->value = item;
    newQueue->next = NULL;

    node *aux;
    for(aux = queue_head; aux->next != NULL; aux = aux->next);
    aux->next = newQueue;

    // Insere na pilha
    node *newStack = malloc(sizeof(node));

    newStack->value = item;
    newStack->next = stack_head->next;
    stack_head->next = newStack;

    // Insere na fila de prioridade
    node *newPriorQueue = malloc(sizeof(node));

    newPriorQueue->value = item;
    newPriorQueue->next = NULL;

    for(aux = priorqueue_head; aux->next != NULL; aux = aux->next){
        if(aux->next->value < item){
            newPriorQueue->next = aux->next;
            aux->next = newPriorQueue;
            break;
        }
    }

    if(aux->next == NULL){
        aux->next = newPriorQueue;
        newPriorQueue->next = NULL;
    }
}

int pop(node *head){
    int item;
    node *aux = head->next;
    item = aux->value;

    // Libera a memória do valor removido
    head->next = aux->next;
    free(aux);

    return item;
}

void freeList(node *head){
    node *temp;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int compare_exit(int size, int *exit, int *q_exit, int *s_exit, int *pq_exit){
    int i, code = 0;
    // Valores de comparação para cada estrutura
    int q_aux = 0;
    int s_aux = 0;
    int pq_aux = 0;

    for(i = 0; i < size && exit[i] != 0; i++){
        if(exit[i] != q_exit[i])
            q_aux = 1;
        if(exit[i] != s_exit[i])
            s_aux = 1;
        if(exit[i] != pq_exit[i])
            pq_aux = 1;
    }

    // Se o valor final for 1, trata-se de uma fila; se for 2, é uma pilha;
    // se for 4, é uma fila de prioridades; se for uma combinação desses
    // valores, pode ser mais de uma estrutura; e se for 0, não é nenhuma
    // das estruturas 
    if(q_aux == 0)
        code += 1;
    if(s_aux == 0)
        code += 2;
    if(pq_aux == 0)
        code += 4;

    return code;
}

int main(void){
    int qtd_comandos;

    // Recebe entradas até que o usuário pare de fornecer
    while(scanf("%d", &qtd_comandos) != EOF){
        int i = 0, j;
        int *saida = calloc(qtd_comandos, sizeof(int));
        int *saida_q = calloc(qtd_comandos, sizeof(int));
        int *saida_s = calloc(qtd_comandos, sizeof(int));
        int *saida_pq = calloc(qtd_comandos, sizeof(int));

        node *qhead = createNode();
        node *shead = createNode();
        node *pqhead = createNode();

        // Preenche os vetores com as saídas de cada estrutura, respectivamente
        for(j = 0; j < qtd_comandos; j++){
            int comando, elemento;

            scanf("%d %d", &comando, &elemento);

            if(comando == 1)
                push(elemento, qhead, shead, pqhead);
            else{
                saida[i] = elemento;
                saida_q[i] = pop(qhead);
                saida_s[i] = pop(shead);
                saida_pq[i] = pop(pqhead);

                i++;
            } 
        }

        int parametro = compare_exit(qtd_comandos, saida, saida_q, saida_s, saida_pq);
        if(parametro == 0)
            printf("impossible\n");   
        else if(parametro == 1)
            printf("queue\n");
        else if(parametro == 2)
            printf("stack\n");
        else if(parametro == 4)
            printf("priority queue\n");
        else
            printf("not sure\n");

        free(saida);
        free(saida_q);
        free(saida_s);
        free(saida_pq);
        freeList(qhead);
        freeList(shead);
        freeList(pqhead);
    }

    return 0;
}