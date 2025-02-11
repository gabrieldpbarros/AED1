#include <stdio.h>
#include <stdbool.h>

int main(){
    int test = 1;

    while(1){
        char horse[3];
        scanf("%s", horse);

        if(horse[0] == '0')
            break;

        bool chessBoard[8][8] = {false};

        for(int i = 0; i < 8; ++i){
            char pawn[3];
            scanf("%s", pawn);

            int x = pawn[0] - '0' - 1;
            int y = pawn[1] - 'a';

            if(x > 0){
                if(y > 0)
                    chessBoard[x - 1][y - 1] = true;
            
                if(y < 7)
                    chessBoard[x - 1][y + 1] = true;
            }
        }

        int x = horse[0] - '0' - 1;
        int y = horse[1] - 'a';

        int ans = 0;

        if(y - 2 >= 0){
            if(x + 1 <= 7)
                ans += !chessBoard[x + 1][y - 2];
            if(x - 1 >= 0)
                ans += !chessBoard[x - 1][y - 2];  
        }

        if(y - 1 >= 0){
            if(x + 2 <= 7)
                ans += !chessBoard[x + 2][y - 1];
            if(x - 2 >= 0)
                ans += !chessBoard[x - 2][y - 1];
        }

        if (y + 2 <= 7){
            if(x + 1 <= 7)
                ans += !chessBoard[x + 1][y + 2];
            if(x - 1 >= 0) 
                ans += !chessBoard[x - 1][y + 2];
        }

        if(y + 1 >= 0){
            if (x + 2 <= 7) 
                ans += !chessBoard[x + 2][y + 1];
            if(x - 2 >= 0)
                ans += !chessBoard[x - 2][y + 1];
        }

        printf("Caso de Teste #%d: %d movimento(s).\n", test++, ans);
    }

    return 0;
}