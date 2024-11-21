#include <stdio.h>
#include <stdlib.h>

// Busca de ordem O(n).
int buscaSequencial(int x, int n, int v[]){
    int j = 0;
    while(j < n && v[j] < x) j++;
    return j;
}

int main(){
    int array[3] = {1, 2, 3};
    int position = buscaSequencial(3, 3, array);
    printf("%d", position);

    return 0;
}