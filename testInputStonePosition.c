#include <stdio.h>
#include <ctype.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testInputStonePosition(){
    testStart("inputStonePosition");
    board sboard;
    initBoard(&sboard);
    board bkpboard[100];
    for (int i = 0; i < 100; i++){
		initBoard(&bkpboard[i]);
	}

    char *a = "A";
    char *b = "B";
    char *c = "C";
    char *d = "D";
    char *e = "E";
    char *n = ">";
    char *m = "<";

    int temps[8][8]={
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
            sboard.sqStatus[i][j]=temps[i][j];
        }
    }
    sboard.turn = 0;
    sboard.tesuu = 3;
    sboard.winer = 3;
    for (int i = 0; i < 10; i++){
        bkpboard[i].tesuu=i;  
    }  
    assertEqualsInt(inputStonePosition(a,&sboard,bkpboard),0);
    #if DEBUG
    printf("sboard.tesuu=%d\n", sboard.tesuu);
    #endif
    assertEqualsInt(sboard.tesuu,3);
    for (int i = 0; i <= 3; i++){
        assertEqualsInt(bkpboard[i].tesuu,i);
    }
    for (int i = 4; i < 10; i++){
        assertEqualsInt(bkpboard[i].tesuu,-1);
    }
    assertEqualsInt(inputStonePosition(b,&sboard,bkpboard),0);
    assertEqualsInt(inputStonePosition(c,&sboard,bkpboard),0);
    assertEqualsInt(inputStonePosition(d,&sboard,bkpboard),0);
    assertEqualsInt(inputStonePosition(e,&sboard,bkpboard),0);
    sboard.turn = 0;
    sboard.tesuu = 0;
    sboard.winer = 3;
	bkpboard[0].tesuu=0;
	bkpboard[1].tesuu=1;
    assertEqualsInt(inputStonePosition(n, &sboard, bkpboard), 0);
    sboard.turn = 0;
    sboard.tesuu = 0;
    sboard.winer = 3;
    assertEqualsInt(inputStonePosition(m,&sboard,bkpboard),1);
     for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            bkpboard[1].sqStatus[i][j]=temps[i][j];
        }
    }
    bkpboard[1].turn = 1;
    bkpboard[1].tesuu = 1;
    bkpboard[1].winer = 3;
    assertEqualsInt(inputStonePosition(n,&sboard,bkpboard),0);
    sboard.turn = 1;
    sboard.tesuu = 1;
    sboard.winer = 3;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            bkpboard[0].sqStatus[i][j]=temps[i][j];
        }
    }
    assertEqualsInt(inputStonePosition(m,&sboard,bkpboard),0);
}