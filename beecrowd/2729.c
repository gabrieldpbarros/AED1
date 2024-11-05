#include <stdio.h>
#include <stdlib.h>

typedef struct listaCompras{
    char compras[20];
    struct celula *seg;
}celula;

int main(void){
    // Declaração das variáveis.
    int qtdCompras;
    char *itens, *item;
    celula *lst, *lstnew;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;

    scanf("%d", &qtdCompras);
    for(int i = 0; i < qtdCompras; i++){
        itens = malloc(sizeof(1000));
        fgets(itens, 1000, stdin);

        int j = 0;
        int k = 0;
        item = malloc(sizeof(20));
        do{
            // Insere na lista o produto.
            if(itens[j] == ' '){
                lstnew = malloc(sizeof(celula));
                for(int l = 0; l < k; l++) lstnew->compras[l] = item[l];
                lst->seg = lstnew;

                k = 0;
            }

            item[k] = itens[j];
            j++;
            k++;
        }while(itens[j] != '\0');

        free(itens);
        free(item);
    }

    free(lst);
    free(lstnew);
    return 0;
}