#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testJudgeGameSet(){
    testStart("judgeGameSet");
    board mboard;
    board cboard;
    board sboard;
    board gboard;
    board jboard;

    int tempc[8][8]={
		{16,16, 1, 1, 1, 8,16,16},
		{16, 1, 1, 2, 1, 1, 1,16},
		{ 1, 1, 1, 2, 1, 1, 1, 1},
		{ 2, 1, 2, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 2},
		{ 2, 1, 1, 1, 1, 1, 1, 8},
		{16, 1, 1, 1, 1, 1, 2,16},
		{16,16, 1, 1, 2, 8,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            mboard.sqStatus[i][j]=tempc[i][j];
        }
    }
    mboard.stone.white=16;
    mboard.stone.black=15;
    judgeGameSet(&mboard);
    assertEqualsInt(mboard.winer,3);
    
    int tempd[8][8]={
		{16,16, 2, 1, 2, 2,16,16},
		{16, 2, 1, 2, 2, 2, 2,16},
		{ 2, 2, 2, 2, 1, 2, 2, 1},
		{ 2, 2, 1, 1, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 1, 1, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2},
		{16, 2, 2, 2, 2, 2, 2,16},
		{16,16, 2, 2, 2, 1,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cboard.sqStatus[i][j]=tempd[i][j];
        }
    }
    cboard.stone.white=20;
    cboard.stone.black=15;
    judgeGameSet(&cboard);
    assertEqualsInt(cboard.winer,1);
    
    int templ[8][8]={
	    {16,16, 1, 1, 1, 1,16,16},
		{16, 1, 1, 1, 1, 1, 1,16},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 2, 1, 1, 2},
		{ 1, 1, 1, 1, 1, 1, 1, 2},
		{ 1, 1, 1, 1, 1, 1, 1, 2},
		{16, 1, 1, 1, 1, 2, 2,16},
		{16,16, 1, 1, 1, 1,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            sboard.sqStatus[i][j]=templ[i][j];
        }
    }
    sboard.stone.white=10;
    sboard.stone.black=15;
    judgeGameSet(&sboard);
    assertEqualsInt(sboard.winer,0);

     int tempg[8][8]={
	    {16,16, 4, 4, 1, 1,16,16},
		{16, 1, 1, 4, 1, 1, 1,16},
		{ 4, 1, 1, 1, 1, 1, 1, 1},
		{ 4, 1, 1, 1, 2, 1, 1, 2},
		{ 1, 1, 1, 1, 1, 1, 1, 2},
		{ 1, 1, 1, 1, 1, 1, 1, 2},
		{16, 1, 1, 1, 1, 2, 2,16},
		{16,16, 1, 1, 1, 1,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            gboard.sqStatus[i][j]=tempg[i][j];
        }
    }
    gboard.stone.white=20;
    gboard.stone.black=15;
    judgeGameSet(&gboard);
    assertEqualsInt(gboard.winer,3);

       int tempj[8][8]={
	    {16,16, 1, 1, 2, 2,16,16},
		{16, 1, 1, 1, 2, 2, 2,16},
		{ 1, 1, 1, 1, 2, 2, 2, 2},
		{ 1, 1, 1, 1, 2, 2, 2, 2},
		{ 1, 1, 1, 1, 2, 2, 2, 2},
		{ 1, 1, 1, 1, 2, 2, 2, 2},
		{16, 1, 1, 1, 2, 2, 2,16},
		{16,16, 1, 1, 2, 2,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            jboard.sqStatus[i][j]=tempj[i][j];
        }
    }
    jboard.stone.white=20;
    jboard.stone.black=20;
    judgeGameSet(&jboard);
    assertEqualsInt(jboard.winer,2);
}
