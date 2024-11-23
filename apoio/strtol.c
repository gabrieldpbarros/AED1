#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *numero;
    numero = "18462";
    int num = strtol(numero, NULL, 10);

    printf("%d", num);

    return 0;
}