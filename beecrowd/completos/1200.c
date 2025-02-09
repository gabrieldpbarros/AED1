#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char letter;
    struct node *left;
    struct node *right;
} tree;

tree *createNode(char value){
    tree *new_node = malloc(sizeof(tree));
    new_node->letter = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

tree *insert(tree *root, char value){
    if(root == NULL)
        return createNode(value);

    if(value < root->letter)
        root->left = insert(root->left, value);
    else if(value > root->letter)
        root->right = insert(root->right, value);

    return root;
}

int search(tree *root, char value){
    if(root == NULL)
        return 0;
    
    if(root->letter == value)
        return 1;

    if(value < root->letter)
        return search(root->left, value);
    return search(root->right, value);

}

void preOrder(tree *root, int *first){
    if(root != NULL){
        if(*first){
            printf("%c", root->letter);
            *first = 0;
        } else
            printf(" %c", root->letter);
        preOrder(root->left, first);
        preOrder(root->right, first);
    }
}

void inOrder(tree *root, int *first){
    if(root != NULL){
        inOrder(root->left, first);
        if(*first){
            printf("%c", root->letter);
            *first = 0;
        } else
            printf(" %c", root->letter);
        inOrder(root->right, first);
    }
}

void postOrder(tree *root, int *first){
    if(root != NULL){       
        postOrder(root->left, first);
        postOrder(root->right, first);
        if(*first){
            printf("%c", root->letter);
            *first = 0;
        } else
            printf(" %c", root->letter);
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
    char buffer[9];
    tree *root = NULL;
    
    while(fgets(buffer, sizeof(buffer), stdin)){
        buffer[strcspn(buffer, "\n")] = '\0';
            
        char *token = strtok(buffer, " ");
        for(int i = 0; token[i] != '\0'; i++)
            token[i] = tolower(token[i]);

        if(strlen(token) == 1){
            if(token[0] == 'i'){
                token = strtok(NULL, " ");
                root = insert(root, token[0]);
            } else{
                token = strtok(NULL, " ");
                int aux = search(root, token[0]);

                if(aux == 1)
                    printf("%c existe\n", token[0]);
                else
                    printf("%c nao existe\n", token[0]);
            }
        } else{
            int first = 1;
            if(strcmp(token, "prefixa") == 0){
                preOrder(root, &first);
                printf("\n");
            } else if(strcmp(token, "infixa") == 0){
                inOrder(root, &first);
                printf("\n");
            } else if(strcmp(token, "posfixa") == 0){
                postOrder(root, &first);
                printf("\n");
            }
        }
    }
    freeTree(root);

    return 0;
}