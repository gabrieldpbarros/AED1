#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCompras{
    char compras[20];
    struct listaCompras *seg;
}celula;

void imprimeLista(celula *lst){
    celula *aux;
    for(aux = lst->seg; aux != NULL; aux = aux->seg)
        printf("%s ", aux->compras);
    printf("\n");
}

int repeticao(celula *lst, char *item){
    celula *aux;
    for(aux = lst->seg; aux != NULL; aux = aux->seg)
        if(strcmp(aux->compras, item) == 0) return 1;   
    return 0;
}

int main(void){
    // Declaração das variáveis.
    int qtdCompras, i;
    char *itens, *item;
    celula *lst, *lstnew, *aux;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;
    // Recebe a quantidade de listas.
    scanf("%d", &qtdCompras);
    getchar(); // Descarta o caractere de nova linha.

    itens = malloc(1000);
    item = malloc(20);

    for(i = 0; i < qtdCompras; i++){
        fgets(itens, 1000, stdin);

        int j = 0, k = 0;

        while(itens[j] != '\0'){
            if(itens[j] == ' ' || itens[j] == '\n'){
                item[k] = '\0';
                
                if(!repeticao(lst, item)){
                    // Cria uma lista contendo apenas o último produto lido.
                    lstnew = malloc(sizeof(celula));
                    // Insere o produto na lista.
                    for(int l = 0; l < k; l++)
                        lstnew->compras[l] = item[l];
                    lstnew->compras[k] = ' ';
                    lst->seg = lstnew;

                    // Percorre toda a lista e adiciona o produto ao final da lista.
                    aux = lst;
                    while (aux->seg != NULL){
                        aux = aux->seg;
                    }
                    aux->seg = lstnew;
                }

                k = 0;
            } else{
                item[k] = itens[j];
                k++;
            }

            j++;
        }
    }
    
    imprimeLista(lst);
    
    // Liberação dos espaços de memória alocados.
    free(itens);
    free(item);

    aux = lst;
    while(aux != NULL){
        celula *temp = aux;
        aux = aux->seg;
        free(temp);
    }

    return 0;
}
