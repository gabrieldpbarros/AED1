#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore binária
typedef struct node {
    char content;
    struct node *left;
    struct node *right;
} tree;

// Função para criar um novo nó com um valor específico
tree* createNode(char value) {
    tree *new_node = (tree*)malloc(sizeof(tree));
    new_node->content = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Função para inserir um novo nó na árvore binária de busca
tree* insert(tree *root, char value) {
    if (root == NULL) { // Caso base: encontrou um local para inserir
        return createNode(value);
    }

    if (value < root->content) {
        root->left = insert(root->left, value);
    } else if (value > root->content) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função de busca na árvore binária
tree* search(tree *root, char value) {
    if (root == NULL || root->content == value) {
        return root; // Retorna o nó encontrado ou NULL se não estiver na árvore
    }

    if (value < root->content) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Percurso em ordem (in-order)
void inOrder(tree *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->content);
        inOrder(root->right);
    }
}

// Função para liberar a memória da árvore
void freeTree(tree *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função principal para testar o código
int main() {
    tree *root = NULL;

    // Inserindo elementos na árvore
    root = insert(root, 'F');
    root = insert(root, 'D');
    root = insert(root, 'J');
    root = insert(root, 'B');
    root = insert(root, 'E');
    root = insert(root, 'G');
    root = insert(root, 'K');

    // Exibindo a árvore em ordem
    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");

    // Testando a busca
    char target = 'E';
    tree *found = search(root, target);
    if (found) {
        printf("Elemento '%c' encontrado na árvore!\n", target);
    } else {
        printf("Elemento '%c' não encontrado.\n", target);
    }

    // Liberando memória
    freeTree(root);

    return 0;
}
