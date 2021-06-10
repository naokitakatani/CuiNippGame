#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
void displayBoard(board *brdp){
    int count = 0;
    stone *b=&brdp->stone;
    player *p = brdp->gamePlayer;
    for (int i = 0; i < 8; i++){
        printf("\x1b[37m\x1b[42m \x1b[m\033[m");
        for (int j = 0; j < 8; j++){
            printf("%s", assignChar(brdp, i, j, count));
            printf("\x1b[37m\x1b[42m \x1b[m\033[m");
            if(brdp->sqStatus[i][j]==(brdp->turn*4)+4||brdp->sqStatus[i][j]==12){
                #if DEBUG
                printf("%d", count);
                #endif
                count++;
            }
        }
        if(i==0){
            printf(" ---------------------");
        }else if(i==1){
            if(brdp->turn==0){
                printf("  ターン　 : %s", (p)->name);
            }else if(brdp->turn==1){
                printf("  ターン　 : %s", (p+1)->name);
            }
        }else if(i==2){
            printf("  手数　　 : %d", brdp->tesuu);
        }else if(i==3){
            printf("  黒石の数 : %d", b->black);
        }else if(i==4){
            printf("  白石の数 : %d", b->white);
        }else if(i==5){
            printf(" ---------------------");
        }
        printf("\n");
    }
}


