#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char str[51];

    while(fgets(str, sizeof(str), stdin)){
        int idx = 0;
        int len = strlen(str);

        for(int i = 0; i < len; ++i){
            if(str[i] != ' ' && str[i] != '\n'){
                if(idx % 2 == 0){
                    str[i] = toupper(str[i]);
                } else{
                    str[i] = tolower(str[i]);
                }
                idx++;
            }
        }

        printf("%s", str);
    }
    
    return 0;
}