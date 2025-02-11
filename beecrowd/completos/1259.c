#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// Ordem crescente
int partition_ascending(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) 
        if (arr[j] < pivot) 
            swap(&arr[++i], &arr[j]);

    swap(&arr[++i], &arr[high]);
    return i;
}

void quicksort_ascending(int arr[], int low, int high){
    if(low < high){
        int pi = partition_ascending(arr, low, high);

        quicksort_ascending(arr, low, pi - 1);
        quicksort_ascending(arr, pi + 1, high);
    }
}

// Ordem decrescente
int partition_descending(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
        if(arr[j] > pivot)
            swap(&arr[++i], &arr[j]);

    swap(&arr[++i], &arr[high]);
    return i;
}

void quicksort_descending(int arr[], int low, int high){
    if(low < high){
        int pi = partition_descending(arr, low, high);

        quicksort_descending(arr, low, pi - 1);
        quicksort_descending(arr, pi + 1, high);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    
    int *pares = (int*) malloc(N * sizeof(int));
    int *impares = (int*) malloc(N * sizeof(int));
    int count_par = 0, count_impar = 0;
    
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);

        if(num % 2 == 0) 
            pares[count_par++] = num;
        else 
            impares[count_impar++] = num;
        
    }
    
    // Ordena os pares em ordem crescente
    quicksort_ascending(pares, 0, count_par - 1);
    
    // Ordena os ímpares em ordem decrescente
    quicksort_descending(impares, 0, count_impar - 1);
    
    for(int i = 0; i < count_par; i++)
        printf("%d\n", pares[i]);
    
    for(int i = 0; i < count_impar; i++)
        printf("%d\n", impares[i]);
    
    free(pares);
    free(impares);
    
    return 0;
}