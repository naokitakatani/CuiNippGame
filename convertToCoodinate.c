#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void convertToCoodinate(board *brdp, char *ipp){
    int count=0;
    int order=0;

    player *b=brdp->gamePlayer;
    if ('A' <= *ipp && *ipp <= 'Z') {
        order = *ipp - 'A' + 1;
        // printf("%cは%d番目のアルファベットです\n", *ipp, order);
    } else if ('a' <= *ipp && *ipp <= 'z') {
        order = *ipp - 'a' + 1;
        // printf("%cは%d番目のアルファベットです\n", *ipp, order);
    } else {
        printf("%cはアルファベットではありません\n", *ipp);
    }
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if(brdp->sqStatus[i][j]==(brdp->turn*4)+4||brdp->sqStatus[i][j]==12){
                #if DEBUG
                printf("Counting(%d/%d)\n", count, order);
                #endif
                count++;
                if(count==order){
                    (b+brdp->turn)->preX = j;
                    (b+brdp->turn)->preY=i;
                    #if DEBUG
                    printf("%d -> preX=%d\n", j, (b+brdp->turn)->preX);
                    printf("%d -> preY=%d\n", i, (b+brdp->turn)->preY);
                    #endif
                }
            }
        }
    }
}
