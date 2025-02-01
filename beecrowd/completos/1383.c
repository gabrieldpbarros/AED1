/*
 * nome: Gabriel Delgado Panovich de Barros
 * descrição: O programa recebe n matrizes de
 * ordem 9 do usuário, as quais devem ser lidas
 * e analisadas se são possíveis soluções para
 * um jogo de Sudoku ou não.
 * data: 18/10/2024 
 */
#include <stdio.h>

int verLinCol(int *vector, int n);
int verSubMatrix(int matrix[][9], int startRow, int startCol);

int main(void)
{
    // Introdução das variáveis.
    int n, i, j, k;
    int coluna[9];
    scanf("%d", &n); // Recebe do usuário a quantidade de matrizes.

    int **matrix = malloc(n * 9 * sizeof(int *));
    for(i = 0; i < n * 9; i++){
        matrix[i] = malloc(9 * sizeof(int));
    }

    for(i = 0; i < 9 * n; i++)
    {
        for(j = 0; j < 9; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Loop que se repete de acordo com a quantidade de matrizes
    // fornecidas pelo usuário.
    for(int block = 0; block < n; block++)
    {
        printf("Instancia %d\n", block + 1);
        int aux = 0;
        // Percorre cada matriz 9x9 individualmente.
        for(i = 9 * block; i < 9 * (block + 1); i++)
        {
            // Verifica a linha.
            if(verLinCol(matrix[i], 9) == 0)
            {
                printf("NAO\n\n");
                aux = 1;
                break;
            }
            // Verifica a coluna.
            for(k = 0; k < 9; k++)
            {                
                coluna[k] = matrix[9 * block + k][i % 9];
            }
            if(verLinCol(coluna, 9) == 0)
            {
                printf("NAO\n\n");
                aux = 1;
                break;
            }
        }
        if(aux == 0)
        {
            // Percorre cada submatriz 3x3 individualmente.
            for (i = 9 * block; i < 9 * (block + 1); i += 3)
            {
                for (j = 0; j < 9; j += 3)
                {
                    if(verSubMatrix(matrix, i, j) == 0)
                    {
                        printf("NAO\n\n");
                        aux = 1;
                        break;
                    }
                }
                if(aux == 1) break;
            }            
            if(aux == 0)
            {
                printf("SIM\n\n");
            }
        }
    }

    for(i = 0; i < n * 9; i++)
        free(matrix[i]);

    free(matrix);

    return 0;
}

int verLinCol(int *vector, int n)
{
    if(n <= 1)
    {
        return 1;
    }
        for(int i = 1; i < n; i++)
            if(vector[0] == vector[i]) return 0;
        return verLinCol(&vector[1], n - 1);
}

int verSubMatrix(int matrix[][9], int startRow, int startCol)
{
    int sub_matriz[9]; // Vetor temporário que armazena os valores do 3x3.
    int index = 0;
    // Insere os valores no vetor sub_matriz.
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            sub_matriz[index] = matrix[startRow + row][startCol + col];
            index++;
        }
    }
    // Verifica através da função verLinCol se há repetições.
    return verLinCol(sub_matriz, 9);
}