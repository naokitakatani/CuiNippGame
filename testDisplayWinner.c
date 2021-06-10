#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testDisplayWinner(){//4326田口雅将が記述
	board mboard;
    testStart("displayWinner");
    char name0[]="hogehoge2";
    char name1[]="hogehoge1";
    for(int i=0; i<20; i++){
            mboard.gamePlayer[0].name[i]=name0[i];
    }
    for(int i=0; i<20; i++){
            mboard.gamePlayer[1].name[i]=name1[i];
    }
    mboard.winer = 0;
    displayWinner(&mboard);
    mboard.winer = 1;
    displayWinner(&mboard);
    mboard.winer = 2;
    displayWinner(&mboard);
}