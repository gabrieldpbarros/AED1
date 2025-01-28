#include <stdio.h>
#include <string.h>

int main() {
    char digito;
    char numero[101];

    while (1) {
        scanf(" %c %s", &digito, numero);

        if(digito == '0' && strcmp(numero, "0") == 0)
            break;

        char resultado[101];
        int index = 0;

        for (int i = 0; numero[i] != '\0'; ++i)
            if (numero[i] != digito)
                resultado[index++] = numero[i];

        resultado[index] = '\0';

        int start_index = 0;
        while(resultado[start_index] == '0')
            start_index++;

        if(resultado[start_index] == '\0')
            printf("0\n");
        else
            printf("%s\n", &resultado[start_index]);
    }

    return 0;
}