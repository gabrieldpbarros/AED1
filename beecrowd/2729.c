#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCompras{
    char compras[20];
    struct listaCompras *seg;
}celula;

void imprimeLista(celula *lst){
    celula *aux;
    for(aux = lst->seg; aux != NULL; aux = aux->seg){
        printf("%s", aux->compras);
        if(aux->seg != NULL) printf(" ");
    }
    printf("\n");
}

int repeticao(celula *lst, char *item){
    celula *aux;
    for(aux = lst->seg; aux != NULL; aux = aux->seg)
        if(strcmp(aux->compras, item) == 0) return 1;   
    return 0;
}
// Algoritmo de bubble sort.
void ordenaLista(celula *lst){ // O algoritmo considera que a lista existe.
    celula *i, *j;
    char temp[20];

    for(i = lst->seg; i != NULL; i = i->seg){
        for(j = i->seg; j != NULL; j = j->seg){
            if(strcmp(i->compras, j->compras) > 0){
                strcpy(temp, i->compras);
                strcpy(i->compras, j->compras);
                strcpy(j->compras, temp);
            }
        }
    }
}

int main(void){
    // Declaração das variáveis.
    int qtdCompras, i;
    char *itens, item[20];
    celula *lst, *lstnew, *aux;
    celula **listas; // Armazena as listas independentes.

    // Recebe a quantidade de listas.
    scanf("%d", &qtdCompras);
    getchar(); // Descarta o caractere de nova linha.

    itens = malloc(1000);
    listas = malloc(qtdCompras * sizeof(celula*));

    for(i = 0; i < qtdCompras; i++){
        // Variáveis auxiliares.
        int j = 0, k = 0;

        // Cria a lista cabeça.
        lst = malloc(sizeof(celula));
        lst->seg = NULL;

        // Recebe a lista do usuário.
        fgets(itens, 1000, stdin);


        while(itens[j] != '\0'){
            if(itens[j] == ' ' || itens[j] == '\n'){
                item[k] = '\0';
                
                if(!repeticao(lst, item)){
                    // Cria uma lista contendo apenas o último produto lido.
                    lstnew = malloc(sizeof(celula));

                    // Insere o produto na lista.
                    for(int l = 0; item[l] != '\0'; l++)
                        lstnew->compras[l] = item[l];
                    lstnew->seg = NULL;
                    lstnew->compras[k] = '\0';

                    // Percorre toda a lista e adiciona o produto ao final da lista.
                    aux = lst;
                    while (aux->seg != NULL){
                        aux = aux->seg;
                    }
                    aux->seg = lstnew;
                }

                k = 0;
            } else{
                item[k++] = itens[j];
            }
            j++;
        }
        ordenaLista(lst);

        listas[i] = lst;
    }
    
    for(i = 0; i < qtdCompras; i++) imprimeLista(listas[i]);
    
    // Liberação dos espaços de memória alocados.
    for(i = 0; i < qtdCompras; i++){
        aux = listas[i];
        while(aux != NULL){
            celula *temp = aux;
            aux = aux->seg;
            free(temp);
        }
        
    }
    free(listas);
    free(itens);

    return 0;
}
