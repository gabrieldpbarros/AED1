#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stdio.h>

void insertion(int *v, int n){
    int i, j, number;
    for(i = 1; i < n; i++){
        number = v[i];
        for(j = i - 1; j >= 0 && v[j] > number; j--)
            v[j + 1] = v[j];
        v[j + 1] = number; // j reduziu em 1 após a iteração.
    }
}

void printInsertion(int *v, int end){
    for(int i = 0; i < end; i++){
        printf("%d", v[i]);
        if(i != end - 1)
            printf(" ");
    }
    printf("\n");
}

#endif