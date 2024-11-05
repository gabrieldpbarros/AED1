#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//facil 29
//medio 25
//dificil 21

int VerificaMatriz(int **mat){
	return 0;
}

int main(int argc, char *argv){
	if(argc != 2 || argv[1] < 1 || argv[1] > 3){
		printf("ERRO. Comando esperado: sudoku.exe <dificuldade>");
		return 0;
	}
	int rcol, rvalue, rrow, start;
	srand(time(0));
	int **mat = (int **)malloc(9 * sizeof(int*));
	for(int i = 0; i < 9; i++){
		mat[i] = (int *)calloc(9, sizeof(int)); 
	}
	if(argv[1] == 1){
		start = 29;
	} else if(argv[1] == 2){
		start = 25;
	} else{
		start = 21;
	}

	for(int i = 0; i < start ; i++){
		rcol = rand() % (9-1+1);
		rrow = rand() % (9-1+1);
		rvalue = rand() % (10-1)+1;
		mat[rcol][rrow] = rvalue;
	}

	printf("+ - - - - - - - - - - - - - - + \n");
	for(int i = 0; i < 9 ; i++){
		if(i % 3 == 0 && i > 0){
			printf("| - - - - + - - - - + - - - - | \n");
		}
		for(int j = 0; j < 9; j++){
			if(j % 3 == 0){
				printf("|");
			} 
			if(mat[i][j] != 0){
				printf(" %d ",mat[i][j]);
			} else {
				printf(" * ");
			}
		}	
		printf("|\n");
	}
	printf("+ - - - - - - - - - - - - - - + \n");	


	free(mat);
	return 0;
}
