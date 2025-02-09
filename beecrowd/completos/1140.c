#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    while(1){
        char a[1001];
        fgets(a, sizeof(a), stdin);

        if(a[0] == '*')
            break;

        char c = toupper(a[0]);

        int ans = 1;

        for(int i = 1; i < strlen(a); ++i)
            if(a[i] == ' ' && toupper(a[i + 1]) != c){
                ans = 0;
                break;
            }

        if(ans) 
            printf("Y\n");
        else 
            printf("N\n");
    }

    return 0;
}