#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char content;
    struct node *left;
    struct node *right;
} tree;

tree* createRoot(char value){
    tree *new_root = malloc(sizeof(tree));
    new_root->content = value;
    new_root->left = NULL;
    new_root->right = NULL;

    return new_root;
}

tree* buildTree(char *preOrder, char *inOrder, int start, int end, int *preIndex){
    if(start > end)
        return NULL;

    char rootValue = preOrder[*preIndex];
    tree *root = createRoot(rootValue); // Raiz conforme a forma prefixa
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex; // Raiz conforme a forma infixa
    for(inIndex = start; inIndex <= end; inIndex++)
        if (inOrder[inIndex] == rootValue)
            break;

    root->left = buildTree(preOrder, inOrder, start, inIndex - 1, preIndex); // Sub-árvore da esquerda
    root->right = buildTree(preOrder, inOrder, inIndex + 1, end, preIndex); // Sub-árvore da direita

    return root;
}

void postOrder(tree *root){
    if(root != NULL){ 
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->content);
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
    int cases;
    scanf("%d", &cases);

    while(cases--){
        int qt_nodes;
        char *preOrder = malloc(53 * sizeof(char));
        char *inOrder = malloc(53 * sizeof(char));
        
        scanf("%d %s %s", &qt_nodes, preOrder, inOrder);
        
        int preIndex = 0;
        tree *root = buildTree(preOrder, inOrder, 0, qt_nodes - 1, &preIndex);

        postOrder(root);
        printf("\n");

        freeTree(root);
    }


    return 0;
}