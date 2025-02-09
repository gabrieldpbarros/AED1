#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
} tree;

tree *createNode(int value){
    tree *new_node = malloc(sizeof(tree));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

tree *insert(tree *root, int value){
    if(root == NULL) // Caso base
        return createNode(value);

    if(root->value > value)
        root->left = insert(root->left, value);
    else if(root->value < value)
        root->right = insert(root->right, value);

    return root; // Retorna o endereço da raiz da árvore
}

void preOrder(tree *root){
    if(root != NULL){
        printf(" %d", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(tree *root){
    if(root != NULL){
        inOrder(root->left);
        printf(" %d", root->value);
        inOrder(root->right);
    }
}

void postOrder(tree *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->value);
    }
}

void freeTree(tree *root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    int cases, i = 1;
    scanf("%d", &cases);

    while(cases--){
        int qt_nodes, number;
        tree *root = NULL;

        scanf("%d", &qt_nodes);
        while(qt_nodes--) // Cria a árvore binária
            if(scanf("%d", &number) == 1)
                root = insert(root, number);

        printf("Case %d:\n", i++);
        printf("Pre.:");
        preOrder(root);
        printf("\nIn..:");
        inOrder(root);
        printf("\nPost:");
        postOrder(root);
        printf("\n\n");
        
        freeTree(root);
    }
    
    return 0;
}