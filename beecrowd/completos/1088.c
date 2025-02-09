#include <stdio.h>
#include <stdlib.h>

int *temp;

// Função para contar o número de inversões usando Merge Sort
long long merge(int *arr, int *temp, int left, int mid, int right){
    int i = left, j = mid, k = left;
    long long inv_count = 0;
    
    while ((i <= mid - 1) && (j <= right)){
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i); // Conta as inversões
        }
    }
    
    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    
    return inv_count;
}

long long mergeSort(int *arr, int *temp, int left, int right){
    long long inv_count = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long countInversions(int *arr, int n){
    temp = malloc(n * sizeof(int));
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int n;
    while(scanf("%d", &n) && n != 0){
        int *arr = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        
        long long inversions = countInversions(arr, n);
        free(temp);
        
        // Marcelo começa jogando, então se o número de inversões for ímpar, ele perde
        if(inversions % 2 == 0)
            printf("Carlos\n");
        else
            printf("Marcelo\n");

        free(arr);
    }
    return 0;
}