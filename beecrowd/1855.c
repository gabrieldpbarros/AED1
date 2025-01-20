#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trackVisited(char **matrix, int x, int y){
    matrix[x][y] = 'X';
}

int vertical(char **matrix, int *x, int *y, int total_cols){
    if(matrix[*x][*y] == 'v'){
        trackVisited(matrix, *x, *y);
        while(++(*x) < total_cols){
            if(matrix[*x][*y] != '.')
                return 1;
        }
    } else{
        trackVisited(matrix, *x, *y);
        while(--(*x) >= 0){
            if(matrix[*x][*y] != '.')
                return 1;
        }
    }
    return 0;
}

int horizontal(char **matrix, int *x, int *y, int total_rows){
    if(matrix[*x][*y] == '>'){
        trackVisited(matrix, *x, *y);
        while(++(*y) < total_rows){
            if(matrix[*x][*y] != '.')
                return 1;
        }
        return 0;
    } else{
        trackVisited(matrix, *x, *y);
        while(--(*y) >= 0){
            if(matrix[*x][*y] != '.')
                return 1;
        }
        return 0;
    }
}

void freeMap(char **map, int x){
    while(x-- > 0)
        free(map[x]);

    free(map);
}

int main(void){
    char **map;
    int x, y;

    scanf("%d", &y);
    scanf("%d", &x);

    map = malloc(x * sizeof(char*)); // Aloca as linhas do mapa

    for(int i = 0; i < x; i++){
        map[i] = malloc(y* sizeof(char)); // Aloca as colunas do mapa

        scanf("%s", map[i]);
    }

    if(map[0][0] == '<' || map[0][0] == '^' || map[0][0] == '.'){ // Mapa inválido na primeira posição
        printf("!\n");
        freeMap(map, x);
        return 0; // return 1
    }

    int i = 0, j = 0, instruction = 1, k = 0;

    while(instruction){
        if(map[i][j] == '*'){
            printf("*\n");
            freeMap(map, x);
            return 0;
        } else if(map[i][j] == 'X'){
            printf("!\n");
            freeMap(map, x);
            return 0; // return 1
        } else if(map[i][j] == '>' || map[i][j] == '<')
            instruction = horizontal(map, &i, &j, y);
        else if(map[i][j] == 'v' || map[i][j] == '^')
            instruction = vertical(map, &i, &j, x);
    
    }
    printf("!\n");

    freeMap(map, x);

    return 0; // return 1
}