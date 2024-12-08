#include "quicksort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define TAM 20000 // Constante para tamanho do vetor

void initializeRandom(void){
    srand((unsigned) time(NULL));
}

int randomInteger(int low, int high){
    return rand() % (high - low + 1) + low;
}

void printAll(int *v1, int *v2, int *v3, int size, clock_t start, clock_t end){
    // Verificando tempo de execução do algoritmo de ordenação => t1
    start = clock(); // Armazena tempo
    insertion(v1, TAM);
    end = clock(); // tempo final - tempo inicial
    // Imprime o tempo na tela
    printf("Tempo de execucao (Insertion Sort): %lf\n", (double) (end - start) / CLOCKS_PER_SEC); //Conversão para segundos

    // Verificando tempo de execução do algoritmo de ordenação => t2
    start = clock(); // Armazena tempo
    merge(v2, 0, size);
    end = clock(); // tempo final - tempo inicial
    // Imprime o tempo na tela
    printf("Tempo de execucao (Merge Sort): %lf\n", (double) (end - start) / CLOCKS_PER_SEC); //Conversão para segundos

    // Verificando tempo de execução do algoritmo de ordenação => t3
    start = clock(); // Armazena tempo
    merge(v3, 0, size);
    end = clock(); // tempo final - tempo inicial
    // Imprime o tempo na tela
    printf("Tempo de execucao (Quick Sort): %lf\n\n", (double) (end - start) / CLOCKS_PER_SEC); //Conversão para segundos
}

int main(void){
    clock_t start, end; // Variável para armazenar tempo
    int vetor1[TAM], vetor2[TAM], vetor3[TAM];
    int p, r, a;
    p = 0;
    r = TAM - 1;

    // Inicializa a semente do gerador
    initializeRandom();

    // Geração aleatória dos valores do vetor
    for(int i = 0; i < 5; i++){
        for(a = 0; a < TAM; a++){
            vetor1[a] = randomInteger(0, TAM);
            vetor2[a] = vetor1[a];
            vetor3[a] = vetor1[a];
        }
        printAll(vetor1, vetor2, vetor3, r, start, end);
    }
}