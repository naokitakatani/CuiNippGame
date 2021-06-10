#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"

void insertToOpporSiteStone(board *brdp, int x, int y){
    for (int i=0; i<100; i++) {
        if (brdp->gamePlayer[brdp->turn].opporSiteStone[0][i] == 0 && brdp->gamePlayer[brdp->turn].opporSiteStone[1][i] ==0) {
            brdp->gamePlayer[brdp->turn].opporSiteStone[0][i] = x;
            brdp->gamePlayer[brdp->turn].opporSiteStone[1][i] = y;
        break;	
        }
    }
}