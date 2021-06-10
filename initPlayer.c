#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void initPlayer(player *pyp){
    char cha[] ="";
    for(int i = 0; i < 30; i++){
        pyp->name[i] = cha[i];
    }
    for(int i = 0; i < 100; i++){
        pyp->opporSiteStone[0][i] = 0;
        pyp->opporSiteStone[1][i] = 0;
        (pyp+1)->opporSiteStone[0][i] = 0;
        (pyp+1)->opporSiteStone[1][i] = 0;
    }
    pyp->preX = 0;
    pyp->preX = 0;
}