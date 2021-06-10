#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void changeTurn(board *brdp){
	int i = 0;
    if(brdp->turn == 0){
        i = whiteAvailable(brdp);
    }else
    {
        i = blackAvailable(brdp);
    }
    if (i == 0){
        if(brdp->turn == 0){
            //printf("Now Turn is 0. Changing to 1\n");
            brdp->turn = 1;
        }else if(brdp->turn == 1){
            //printf("Now Turn is 1. Changing to 0\n");
            brdp->turn = 0;
        }else{
            printf("Unknown Turn. Reset to 0\n");
            brdp->turn = 0;
        }
    }
    brdp->tesuu++;
}