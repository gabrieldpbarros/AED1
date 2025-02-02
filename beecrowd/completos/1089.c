#include <stdio.h>

int main(){
    int n, i, picos;

    while(scanf("%d", &n) && n != 0){
        picos = 0;
        int *amostras = malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            scanf("%d", &amostras[i]);

        for(i = 1; i < n-1; i++){
            if(amostras[i] < amostras[i-1] && amostras[i] < amostras[i+1])
                picos++;
            else if(amostras[i] > amostras[i-1] && amostras[i] > amostras[i+1])
                picos++;
        }

        //Verifica se há picos no inicio e no fim do loop.
        if(amostras[n-1] > amostras[n-2] && amostras[n-1] > amostras[0])
            picos++;
        else if(amostras[n-1] < amostras[n-2] && amostras[n-1] < amostras[0])
            picos++;
        
        if(amostras[0] > amostras[1] && amostras[0] > amostras[n-1])
            picos++;
        else if(amostras[0] < amostras[1] && amostras[0] < amostras[n-1])
            picos++;

        printf("%d\n", picos);
        free(amostras);
    }


    return 0;
}