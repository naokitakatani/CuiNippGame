#include <stdio.h>
#include <math.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
int isSameOpporSiteStone(board *brdp, int x, int y){
    player *p = &brdp->gamePlayer[brdp->turn];
    for (int i = 0; i < 100; i++){
        #if DEBUG
            printf("x=%d, opporSiteStone[0][%d]=%d. y=%d, opporSiteStone[1][%d]=%d.\n", x, i, p->opporSiteStone[0][i], y, i, p->opporSiteStone[1][i]);
        #endif
        if(p->opporSiteStone[0][i]==x&&p->opporSiteStone[1][i]==y){
            #if DEBUG
            printf("Match.\n");
            #endif
            return i;
        }
        if(p->opporSiteStone[0][i]==0&&p->opporSiteStone[1][i]==0){
            #if DEBUG
            printf("No Match.\n");
            #endif
            return -1;
        }
    }
    #if DEBUG
    printf("No Match.\n");
    #endif
    return -1;
}