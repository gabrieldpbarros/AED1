#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista
typedef struct node {
    int nota;
    struct node *next;
} Node;

// Função para criar um novo nó
Node* createNode(int nota) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nota = nota;
    newNode->next = NULL;
    return newNode;
}

// Função para dividir a lista ao meio
void splitList(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    // Avança o ponteiro 'fast' duas vezes mais rápido que 'slow'
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Divide a lista em duas partes
    *front = source;
    *back = slow->next;
    slow->next = NULL;  // Termina a primeira metade
}

// Função para mesclar duas listas ordenadas
Node* mergeSortedLists(Node* a, Node* b) {
    // Caso base: se uma das listas estiver vazia
    if (!a) return b;
    if (!b) return a;

    Node* result = NULL;

    // Escolhe o menor valor entre as duas listas
    if (a->nota >= b->nota) {  // Ordenação decrescente
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

// Função principal do Merge Sort
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;  // Lista vazia ou com um único elemento

    Node* a;
    Node* b;

    // Divide a lista em duas metades
    splitList(head, &a, &b);

    // Ordena cada metade recursivamente
    mergeSort(&a);
    mergeSort(&b);

    // Mescla as duas metades ordenadas
    *headRef = mergeSortedLists(a, b);
}

// Função para imprimir a lista
void printList(Node* head) {
    while (head) {
        printf("%d ", head->nota);
        head = head->next;
    }
    printf("\n");
}

// Exemplo de uso
int main() {
    // Criar uma lista de exemplo
    Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(4);
    head->next->next->next = createNode(2);

    printf("Lista original:\n");
    printList(head);

    // Ordenar a lista
    mergeSort(&head);

    printf("Lista ordenada (decrescente):\n");
    printList(head);

    // Liberar memória
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}