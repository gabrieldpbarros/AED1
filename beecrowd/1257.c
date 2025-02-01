#include <stdio.h>
#include <string.h>

int main(void){
    int n, l, hash, i, elemento;
    
    scanf("%d", &n);
    
    while(n--){
        scanf("%d", &l);
        hash = 0;
        elemento = 0;
        
        char palavra[51];
        
        while(l--){
            scanf("%s", palavra);
            int len = strlen(palavra);
            
            for(i = 0; i < len; i++)
                hash += (palavra[i] - 'A') + elemento + i;
            
            elemento++;
        }
        
        printf("%d\n", hash);
    }
    
    return 0;
}