#include "insertionsort.h"
#include "mergesort.h"
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define TAM 100000 // Constante para tamanho do vetor

void initializeRandom(){
    srand((unsigned) time(NULL));
}

int randomInteger(int low, int high){
    return rand() % (high - low + 1) + low;
}

int main(){
    clock_t start, end; // Variável para armazenar tempo
    int vetor1[TAM], vetor2[TAM];
    int p, r, a;
    p = 0;
    r = TAM - 1;

    // Inicializa a semente do gerador
    initializeRandom();

    // Geração aleatória dos valores do vetor
    for(a = 0; a < TAM; a++){
        vetor1[a] = randomInteger(0, TAM);
        vetor2[a] = vetor1[a];
    }

    // Verificando tempo de execução do algoritmo de ordenação => t1
    start = clock(); // Armazena tempo
    insertion(vetor1, TAM);
    end = clock(); // tempo final - tempo inicial
    // Imprime o tempo na tela
    printf("Tempo de execucao (Insertion Sort): %lf\n", (double) (end - start) / CLOCKS_PER_SEC); //Conversão para segundos

    // Verificando tempo de execução do algoritmo de ordenação => t2
    start = clock(); // Armazena tempo
    merge(vetor2, 0, r);
    end = clock(); // tempo final - tempo inicial
    // Imprime o tempo na tela
    printf("Tempo de execucao (Merge Sort): %lf\n", (double) (end - start) / CLOCKS_PER_SEC); //Conversão para segundos
}