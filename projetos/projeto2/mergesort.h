#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>

void combine(int *v, int v1_start, int v2_start, int v2_end){
    int i = v1_start, j = v2_start, k = 0;
    int *w = (int*) malloc((v2_end - v1_start + 1) * sizeof(int));

    while(i < v2_start && j <= v2_end){
        if(v[i] <= v[j]) 
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }

    while(i < v2_start)
        w[k++] = v[i++];
    while(j <= v2_end)
        w[k++] = v[j++];

    for(i = v1_start; i <= v2_end; i++)
        v[i] = w[i - v1_start];

    free(w);
}

void merge(int *v, int start, int end){
    if(start < end){
        int middle = (start + end) / 2;

        merge(v, start, middle);
        merge(v, middle + 1, end);

        combine(v, start, middle + 1, end);
    }
}

void printMerge(int *v, int end){
    for(int i = 0; i < end; i++){
        printf("%d", v[i]);
        if(i != end - 1)
            printf(" ");
    }
    printf("\n");
}

#endif