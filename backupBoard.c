#include <stdio.h>
#include <string.h>
#include "nipp.h"
#include "testNipp.h"

void backupBoard(board *brdp, board *bkbrdp) {
    player *pp = brdp->gamePlayer;
    player *bpp = (bkbrdp)->gamePlayer;
    stone *sp = &brdp->stone;
    stone *bsp = &(bkbrdp)->stone;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            (bkbrdp)->sqStatus[i][j]=brdp->sqStatus[i][j];
        }
    }
    (bkbrdp)->turn = brdp ->turn;
    (bkbrdp)->tesuu = brdp ->tesuu;
    (bkbrdp)->winer = brdp ->winer;

    strcpy(bpp->name, pp->name);
    strcpy((bpp+1)->name, (pp+1)->name);
    bpp->preX = pp->preX;
    bpp->preY = pp->preY;
    (bpp+1)->preX = (pp+1)->preX;
    (bpp+1)->preY = (pp+1)->preY;
    for (int i = 0; i < 100; i++){
        bpp->opporSiteStone[0][i]=pp->opporSiteStone[0][i];
        bpp->opporSiteStone[1][i]=pp->opporSiteStone[1][i];
        (bpp+1)->opporSiteStone[0][i]=(pp+1)->opporSiteStone[0][i];
        (bpp+1)->opporSiteStone[1][i]=(pp+1)->opporSiteStone[1][i];
    }

    bsp->black = sp->black;
    bsp->white = sp->white;
    bsp->used = sp->used;
}