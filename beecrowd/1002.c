#include <stdio.h>

int main(void)
{
    double area, raio;
    double n = 3.14159;

    scanf("%lf", &raio);
    area = n * raio * raio;
    printf("A=%.4lf\n", area);

    return 0;
}