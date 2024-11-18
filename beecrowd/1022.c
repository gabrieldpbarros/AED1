#include <stdio.h>
#include <stdlib.h>

void sum(int num1, int den1, int num2, int den2, int *res_num, int *res_den){
    *res_num = num1*den2 + num2*den1;
    *res_den = den1*den2;
}

void subtract(int num1, int den1, int num2, int den2, int *res_num, int *res_den){
    *res_num = num1*den2 - num2*den1;
    *res_den = den1*den2;
}

void times(int num1, int den1, int num2, int den2, int *res_num, int *res_den){
    *res_num = num1*num2;
    *res_den = den1*den2;
}

void divided(int num1, int den1, int num2, int den2, int *res_num, int *res_den){
    *res_num = num1*den2;
    *res_den = num2*den1;
}

void operacao(char *eq){
    
}

void simplify(int *num, int *den){
    int a = *num;
    int b = *den;
    // Algoritmo de Euclides
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    int mdc = a;
    // Simplifica
    if(mdc != 1){
        *num /= mdc;
        *den /= mdc;
    }
}

int main(void){
    int numeros[4], qtd_testes;
    int *num_final, *den_final;
    char *entrada;

    scanf("%d", qtd_testes);
    get_char();

    num_final = malloc(qtd_testes * sizeof(int));
    den_final = malloc(qtd_testes * sizeof(int));
    entrada = malloc(4009);
    
    for(int i = 0; i < qtd_testes; i++){
        int j = 0;
        int num1, num2, den1, den2;
        fgets(entrada, 4009, stdin);

        
    }

    free(num_final);
    free(den_final);
    free(entrada);
    return 0;
}