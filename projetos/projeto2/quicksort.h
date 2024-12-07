#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int selectPivot(int *v, int start, int end){  // Seleciona o pivô baseado no método mediana de três
    int middle = start + (end - start) / 2;

    // Encontra a mediana
    if(v[start] > v[middle])
        swap(&v[start], &v[middle]);
    else if(v[start] > v[end])
        swap(&v[start], &v[end]);
    else if(v[middle] > v[end])
        swap(&v[middle], &v[end]);

    return middle; // Retorna o índice do pivô
}

int partition(int *v, int start, int pivot, int end){
    swap(&v[pivot], &v[end]); // Insere o pivô no final do vetor
    int i = start - 1, j = start;
    while(j < end){
        if(v[j] < v[end])// Posiciona todos os valores menores que o pivô no início do vetor
            swap(&v[++i], &v[j]);
        j++;
    }

    // Insere o pivô na posição correta
    swap(&v[++i], &v[end]);

    return i; // Retorna a nova posição do pivô
}

void quickSort(int *v, int start, int end){
    if(start < end){
        int pivot_index = selectPivot(v, start, end);

        int middle = partition(v, start, pivot_index, end);

        quickSort(v, start, middle - 1);
        quickSort(v, middle + 1, end);
    }
    
}

void printQuick(int *v, int end){
    for(int i = 0; i < end; i++){
        printf("%d", v[i]);
        if(i != end - 1)
            printf(" ");
    }
    printf("\n");
}

#endif