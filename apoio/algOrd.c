#include <stdio.h>
#include <stdlib.h>

// Busca de teto O(n)
int buscaSequencial(int x, int n, int v[]){
    int j = 0;
    while(j < n && v[j] < x) j++;
    return j;
}

void intercala(int p, int q, int r, int *v){
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r){
        if(v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }

    while(j < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for(i = p; i < r; i++) v[i] = w[i - p];

    free(w);
}

// Ordenação de teto O(n^2)
void boboSort(int n, int *v){
    int i, j, aux;
    int length = n;
    for(i = 0; i < length; i++){
        for(j = 0; j < length; j++){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Ordenação de teto O(n^2), mas mais rápido que o Bobo Sort.
void bubbleSort(int n, int *v){
    int i, j, aux;
    int length = n;
    for(i = 0; i < length; i++){
        for(j = i + 1; j < length; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// Ordenação de teto O(n^2)
void selectionSort(int n, int *v){
    int i, j, min, x;
    int length = n;
    for(i = 0; i < length - 1; i++){
        min = i;
        // Varre todo o vetor até encontrar o menor valor
        for(j = i + 1; j < length; j++)
            if(v[j] < v[min]) min = j; // Guarda a posição do menor valor.
        if(v[i] != v[min]){
            x = v[i];
            v[i] = v[min];
            v[min] = x;
        }
    }
}

// Ordenação de teto O(n^2)
void insertionSort(int n, int *v){
    int i, j, x;
    int length = n;
    for(j = 1; j < length; j++){
        x = v[j];
        for(i = j - 1; i <= 0 && v[i] > x; i--)
            v[i + 1] = v[i];
        v[i + 1] = x;
    }
}

void mergeSort(int p, int r, int *v){
    if(p < r - 1){
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main(){
    int array[3] = {1, 2, 3};
    int position = buscaSequencial(3, 3, array);

    int desordenado[5] = {5, 2, 7, 3, 10};
    int length = sizeof(desordenado)/sizeof(desordenado[0]);
    // printf("%d", position);
    selectionSort(length, desordenado);
    printf("selection = ");
    for(int i = 0; i < 5; i++)
        printf("%d ", desordenado[i]);

    return 0;
}