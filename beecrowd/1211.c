#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s1, char **s2){
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int partition(char **matrix, int start, int end){
    char *pivot = matrix[end];
    int i = start - 1, j = start;
    while(j < end){
        if(strcmp(matrix[j], pivot) < 0)
            swap(&matrix[++i], &matrix[j]);
        j++;
    }
    swap(&matrix[++i], &matrix[end]);

    return i;
}

void quickSort(char **matrix, int start, int end){
    if(start < end){
        int middle = partition(matrix, start, end);

        quickSort(matrix, start, middle - 1);
        quickSort(matrix, middle + 1, end);
    }
}

int compare_nums(char *tel1, char *tel2){
    int count = 0;
    while (tel1[count] != '\0' && tel2[count] != '\0' && tel1[count] == tel2[count])
        count++;
    
    return count;
}

int main(){
    int qt_nums, i;

    while(scanf("%d", &qt_nums) != EOF){
        char **tel_list = (char**) malloc(qt_nums * sizeof(char*));

        char f_num[201];
        memset(f_num, '\0', sizeof(f_num));
        scanf("%200s", f_num);
        int size = strlen(f_num);

        tel_list[0] = (char*) malloc(size + 1);
        strcpy(tel_list[0], f_num);

        char *next_num = (char*) malloc(size + 1);

        for(i = 1; i < qt_nums; i++){
            tel_list[i] = (char*) malloc(size + 1);
            scanf("%s", next_num);
            strcpy(tel_list[i], next_num);
        }

        quickSort(tel_list, 0, qt_nums - 1);

        int counter = 0;
        for(i = 0; i < qt_nums - 1; i++)
            counter += compare_nums(tel_list[i], tel_list[i + 1]);
        printf("%d\n", counter);

        free(next_num);
        for(i = 0; i < qt_nums; i++)
            free(tel_list[i]);
        free(tel_list);
    }

    return 0;
}