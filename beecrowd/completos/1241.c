#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char a[1001], b[1001];
        scanf("%s %s", a, b);
        
        int len_a = strlen(a);
        int len_b = strlen(b);
        
        int flag = 0;
        
        if(len_a >= len_b)
            if (strcmp(a + len_a - len_b, b) == 0)
                flag = 1;
        
        printf(flag ? "encaixa\n" : "nao encaixa\n");
    }
    
    return 0;
}