#include <stdio.h>

int josephus(int n, int k){
    int sobrevivente = 0; // Posição do sobrevivente considerando índice 0
    for(int i = 2; i <= n; i++)
        sobrevivente = (sobrevivente + k) % i;
    return sobrevivente + 1; // Ajustando para índice 1 (posição real no círculo)
}

int main(){
    int nc;
    scanf("%d", &nc);

    for (int i = 1; i <= nc; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k));
    }

    return 0;
}