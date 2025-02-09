#include <stdio.h>
#include <math.h>
#include <string.h>

void toBinary(long long a, char* aBin){
    int i = 0;
    
    if(a == 0){
        aBin[i++] = '0';
    }else {
        while (a > 0) {
            if (a % 2 == 0)
                aBin[i++] = '0';
            else
                aBin[i++] = '1';
            a /= 2;
        }
    }
    
    aBin[i] = '\0';
    for(int j = 0; j < i / 2; ++j){
        char temp = aBin[j];
        aBin[j] = aBin[i - j - 1];
        aBin[i - j - 1] = temp;
    }
}

int main(){
    long long x, y;
    while(scanf("%lld %lld", &x, &y) != EOF){
        char aBin[65], bBin[65];
        toBinary(x, aBin);
        toBinary(y, bBin);

        char num1[32] = {0}, num2[32] = {0}, result[32] = {0};
        int j = 31;

        for(int i = strlen(aBin) - 1; i >= 0; --i){
            num1[j] = aBin[i];
            j--;
        }

        j = 31;
        for(int i = strlen(bBin) - 1; i >= 0; --i){
            num2[j] = bBin[i];
            j--;
        }

        for(int i = 0; i < 32; ++i){
            if(num1[i] == '1' && num2[i] == '1')
                result[i] = '0';
            else if(num1[i] == '1' || num2[i] == '1')
                result[i] = '1';
        }

        long long dec = 0, pot = 0;
        for(int i = 31; i >= 0; --i, ++pot)
            if (result[i] == '1') 
                dec += (long long)(pow(2, pot));

        printf("%lld\n", dec);
    }

    return 0;
}