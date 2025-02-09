#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        int a, c;
        scanf("%d %d", &a, &c);

        if (!a && !c) break;

        int *arr = malloc((c + 2) * sizeof(int));

        int ans = 0;
        arr[c + 1] = a;

        for(int i = 1; i <= c; ++i)
            scanf("%d", &arr[i]);

        for(int i = 1; i <= c; ++i)
            if(arr[i] < arr[i + 1])
                ans += arr[i + 1] - arr[i];

        printf("%d\n", ans);
        free(arr);
    }

    return 0;
}