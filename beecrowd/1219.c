#include <stdio.h>
#include <math.h>

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.1415926535897

int main(void){
    int a, b, c;
    
    while(scanf("%d %d %d", &a, &b, &c) == 3){
        double a1 = (double)a, b1 = (double)b, c1 = (double)c;

        double p = (a1 + b1 + c1) / 2;
        double violets = sqrt(p * (p - a1) * (p - b1) * (p - c1));

        double rs = a1 * b1 * c1 / sqrt((a1 + b1 + c1) * (b1 + c1 - a1) * (c1 + a1 - b1) * (a1 + b1 - c1));
        double sunflowers = rs * rs * PI;

        double rr = sqrt((p - a1) * (p - b1) * (p - c1) / p);
        double roses = rr * rr * PI;

        printf("%.4lf %.4lf %.4lf\n", sunflowers - violets, violets - roses, roses);
    }

    return 0;
}