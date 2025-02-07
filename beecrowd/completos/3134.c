#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparator(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int balance(int *numbers){
    int total = 0;
    // Se a soma de dois pesos distintos ou um único peso for igual à metade da
    // soma de todos os pesos, logo o restante também satisfaz à propriedade,
    // portanto a balança pode ser equilibrada 
    for(int i = 0; i < 4; i++)
        total += numbers[i];
        
    // Divisão impossível
    if(total % 2 != 0)
        return 0;

    int half = total / 2;

    return (
        numbers[0] == half ||
        numbers[0] + numbers[1] == half ||
        numbers[0] + numbers[2] == half ||
        numbers[0] + numbers[3] == half
    );
}

int main(){
    int weights[4];

    for(int i = 0; i < 4; i++){
        float temp;
        scanf("%f", &temp);
        weights[i] = roundf(temp * 10);
    }
    qsort(weights, 4, sizeof(int), comparator);

    int parameter = balance(weights);

    if(parameter)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}