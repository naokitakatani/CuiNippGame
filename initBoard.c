#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void initBoard(board *brdp){

    int tempa[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 8, 4, 0, 0, 0},
		{ 0, 0, 8, 1, 2, 4, 0, 0},
		{ 0, 0, 4, 2, 1, 8, 0, 0},
		{ 0, 0, 0, 4, 8, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
    };
     for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            brdp->sqStatus[i][j]=tempa[i][j];
        }
     }
     brdp->tesuu = -1;
     brdp->turn = 0;
     brdp->winer = 3;
     initPlayer(brdp->gamePlayer);
     initStone(&brdp->stone);
}