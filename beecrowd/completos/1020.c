#include <stdio.h>

typedef struct
{
    int anos;
    int meses;
    int dias;
} Idade;

int main(void)
{
    Idade usuario;
    int total_dias, aux;

    scanf("%d", &total_dias);

    usuario.anos = total_dias / 365;
    aux = usuario.anos * 365;
    usuario.meses = (total_dias - aux) / 30;
    aux = usuario.meses * 30;
    usuario.dias = (total_dias - aux) % 365;

    printf("%d ano(s)\n", usuario.anos);
    printf("%d mes(es)\n", usuario.meses);
    printf("%d dia(s)\n", usuario.dias);

    return 0;
}