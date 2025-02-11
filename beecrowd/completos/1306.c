#include <stdio.h>

int main(){
    int r, n, caso = 1, intdiv;
    float div;
    while(1){
        scanf("%d %d", &r, &n);

        if(!n && !r)
            break;

        if(r > (n*26 + n)) 
            printf("Case %d: impossible\n", caso);
        else{
            if(r <= n)  
                printf("Case %d: 0\n", caso);
            else{
                intdiv = r /n;
                div = (float)r/n;

                if(div <= intdiv)
                    printf("Case %d: %d\n", caso, intdiv - 1);
                else
                    printf("Case %d: %d\n", caso, intdiv);
            }
        }

        caso++;
    }

    return 0;
}