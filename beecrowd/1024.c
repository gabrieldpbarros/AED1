#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int n, i, j, k, cont;

    scanf("%d ", &n);

    char aux[10001];
    char **linhas = (char**) malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
        linhas[i] = malloc(1001 * sizeof(char));

    for(i = 0; i < n; i++){
        scanf(" %[^\n]s\n", linhas[i]);

        int len = strlen(linhas[i]);
        for(k = 0; k < len; k++){
            if((linhas[i][k] >= 65 && linhas[i][k] <= 90) || (linhas[i][k] >= 97 && linhas[i][k] <= 122))
                linhas[i][k] = linhas[i][k] + 3;
        }
        
        //Criando uma cópia auxiliar da string
        strcpy(aux, linhas[i]);
        cont = strlen(linhas[i]) - 1;
        for(k = 0; k < len; k++){
            linhas[i][k] = aux[cont];
            cont--;
        }
        //Deslocando uma posição para a esquerda
        for(k = strlen(linhas[i]) / 2; k < len; k++)
            linhas[i][k] = linhas[i][k] - 1;
    }

    for(i = 0; i < n; i++)
        printf("%s\n", linhas[i]);
        
    for(i = 0; i < n; i++)
        free(linhas[i]);
    free(linhas);
    
    return 0;
}