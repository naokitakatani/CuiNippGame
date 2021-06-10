#include <stdio.h>
#include <string.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"

void testBackupBoard() {//4326田口雅将が記述
	board mboard;
	board bkpboard[200];
	int tempAns[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 8, 4, 0, 0, 0},
		{ 0, 0, 8, 1, 2, 4, 0, 0},
		{ 0, 0, 4, 2, 1, 8, 0, 0},
		{ 0, 0, 0, 4, 8, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};

	testStart("backupBoard");
	
	for (int i=0; i<=7; ++i){
		for (int j=0; j<=7; ++j){
			mboard.sqStatus[i][j]=tempAns[i][j];
		}
	}
	mboard.tesuu = 1;
	mboard.turn = 1;
	mboard.winer = 3;

	strcpy(mboard.gamePlayer[0].name, "Arradin");
	strcpy(mboard.gamePlayer[1].name, "Jasmin");
	mboard.gamePlayer[0].preX = 3;
	mboard.gamePlayer[0].preY = 4;
	mboard.gamePlayer[1].preX = 5;
	mboard.gamePlayer[1].preY = 6;
	for (int i = 0; i < 100; i++){
		mboard.gamePlayer[0].opporSiteStone[0][i] = i;
		mboard.gamePlayer[0].opporSiteStone[1][i] = i;
		mboard.gamePlayer[1].opporSiteStone[0][i] = i;
		mboard.gamePlayer[1].opporSiteStone[1][i] = i;
	}

	mboard.stone.black = 2;
	mboard.stone.white = 5;
	mboard.stone.used = 7;
	backupBoard(&mboard, &bkpboard[mboard.tesuu]);

	for (int i=0; i<=7; i++) {
		for (int j=0; j<=7; j++) {
			assertEqualsInt(bkpboard[mboard.turn].sqStatus[i][j], mboard.sqStatus[i][j]);
		}
	}	
	assertEqualsInt(bkpboard[mboard.turn].tesuu, 1);
	assertEqualsInt(bkpboard[mboard.turn].turn, 1);
	assertEqualsInt(bkpboard[mboard.turn].winer, 3);

	assertEqualsString(bkpboard[mboard.turn].gamePlayer[0].name, mboard.gamePlayer[0].name);
	assertEqualsString(bkpboard[mboard.turn].gamePlayer[1].name, mboard.gamePlayer[1].name);
	assertEqualsInt(bkpboard[mboard.turn].gamePlayer[0].preX, 3);
	assertEqualsInt(bkpboard[mboard.turn].gamePlayer[0].preY, 4);
	assertEqualsInt(bkpboard[mboard.turn].gamePlayer[1].preX, 5);
	assertEqualsInt(bkpboard[mboard.turn].gamePlayer[1].preY, 6);
	for (size_t i = 0; i < 100; i++){
		assertEqualsInt(bkpboard[mboard.turn].gamePlayer[0].opporSiteStone[0][i], i);
		assertEqualsInt(bkpboard[mboard.turn].gamePlayer[0].opporSiteStone[1][i], i);
		assertEqualsInt(bkpboard[mboard.turn].gamePlayer[1].opporSiteStone[0][i], i);
		assertEqualsInt(bkpboard[mboard.turn].gamePlayer[1].opporSiteStone[1][i], i);
	}
	

	assertEqualsInt(bkpboard[mboard.turn].stone.black, 2);
	assertEqualsInt(bkpboard[mboard.turn].stone.white, 5);
	assertEqualsInt(bkpboard[mboard.turn].stone.used, 7);

}