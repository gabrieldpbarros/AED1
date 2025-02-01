#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(int *nums, int *res_num, int *res_den){
    *res_num = nums[0]*nums[3] + nums[2]*nums[1];
    *res_den = nums[1]*nums[3];
}

void subtract(int *nums, int *res_num, int *res_den){
    *res_num = nums[0]*nums[3] - nums[2]*nums[1];
    *res_den = nums[1]*nums[3];
}

void times(int *nums, int *res_num, int *res_den){
    *res_num = nums[0]*nums[2];
    *res_den = nums[1]*nums[3];
}

void divided(int *nums, int *res_num, int *res_den){
    *res_num = nums[0]*nums[3];
    *res_den = nums[2]*nums[1];
}

void operacao(char *eq, int *numbers, int *num_final, int *den_final){
    for(int i = 0; eq[i] != '\0'; i++){
        if(eq[i] == '+'){
            sum(numbers, num_final, den_final);
            break;
        } else if(eq[i] == '-'){
            subtract(numbers, num_final, den_final);
            break;
        } else if(eq[i] == '*'){
            times(numbers, num_final, den_final);
            break;
        } else if(eq[i + 1] == '\0'){
            divided(numbers, num_final, den_final);
            break;
        }
    }
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

    if(*den < 0){
        *den *= -1;
        *num *= -1;
    }
}

int main(void){
    int numeros[4], qtd_testes, i;
    int *num_final, *den_final;
    char entrada[4009], numero[1001];

    scanf("%d", &qtd_testes);
    getchar();

    num_final = malloc(qtd_testes * sizeof(int));
    den_final = malloc(qtd_testes * sizeof(int));
    
    for(i = 0; i < qtd_testes; i++){
        int j = 0, k = 0, l = 0;
        fgets(entrada, 4009, stdin);

        while(entrada[j] != '\0'){
            if(entrada[j] < '0' || entrada[j] > '9' || entrada[j] == '\n'){
                numero[k] = '\0';
                if(numero[0] != '\0'){
                    numeros[l++] = atoi(numero);
                }
                k = 0;
            } else{
                numero[k++] = entrada[j];
            }       
            j++;
        }

        operacao(entrada, numeros, &num_final[i], &den_final[i]);
        
    }

    for(i = 0; i < qtd_testes; i++){
        printf("%d/%d = ", num_final[i], den_final[i]);
        simplify(&num_final[i], &den_final[i]);
        printf("%d/%d\n", num_final[i], den_final[i]);
    }

    free(num_final);
    free(den_final);
    return 0;
}