#include <stdio.h>
#include <stdlib.h>

int repeated_position;

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int *vector, int start, int end){
    int pivot = vector[end];
    int i = start - 1, j = start;
    while(j < end){
        if(vector[j] < pivot)
            swap(&vector[++i], &vector[j]);
        j++;
    }
    swap(&vector[++i], &vector[end]);

    return i;
}

void quickSort(int *vector, int start, int end){
    if(start < end){
        int middle = partition(vector, start, end);

        quickSort(vector, start, middle - 1);
        quickSort(vector, middle + 1, end);
    }
}

int checkFrequency(int **matrix, int num){
    for(int i = 0; matrix[0][i] != 0; i++)
        if(matrix[0][i] == num){
            repeated_position = i;
            return 1;
        }
    
    return 0;
}

int main(){
    int n_cases, i = 0, qt_numbers = 0;
    scanf("%d", &n_cases);
    int aux = n_cases;

    int **numbers = (int**) calloc(2, sizeof(int*));
    for(int j = 0; j < 2; j++)
        numbers[j] = calloc(n_cases, sizeof(int));

        
        while(aux--){
            int n;
            scanf("%d", &n);
            
            if(checkFrequency(numbers, n))
            numbers[1][repeated_position]++;
            else{
                numbers[0][i] = n;
                numbers[1][i++] = 1;
                qt_numbers++;
            }
        }
        
    int *correct_order = malloc(qt_numbers * sizeof(int));

    for(i = 0; i < qt_numbers; i++)
        correct_order[i] = numbers[0][i];
    quickSort(correct_order, 0, qt_numbers - 1);

    for(i = 0; i < qt_numbers; i++){
        int j = 0;
        while(numbers[0][j] != correct_order[i])
            j++;
        
        printf("%d aparece %d vez(es)\n", numbers[0][j], numbers[1][j]);
    }

    for(i = 0; i < 2; i++)
        free(numbers[i]);
    free(numbers);
    free(correct_order);

    return 0;
}