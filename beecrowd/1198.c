#include <stdio.h>
#include <stdlib.h>

int main(void){
	long long int a, b, diferenca;

	while(scanf("%lld %lld", &a, &b) != EOF){
        if(a >= b)
			diferenca = a - b;
		else
			diferenca = b - a;

		printf("%lld\n", diferenca);
	}
	return 0;
}