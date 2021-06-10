#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"

void testBoardTimeMachine() {//4326田口雅将が記述
	testStart("boardTimeMachine");
	board mboard;
	board bkpboard[100];
	for (int i = 0; i < 100; i++){
		initBoard(&bkpboard[i]);
	}

	int tempbkpzero[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 8, 4, 0, 0, 0},
		{ 0, 0, 8, 1, 2, 4, 0, 0},
		{ 0, 0, 4, 2, 1, 8, 0, 0},
		{ 0, 0, 0, 4, 8, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	int tempbkpone[8][8]={
		{16,16, 1, 1, 1, 1,16,16},
		{16, 1, 1, 1, 1, 1, 1,16},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{16, 1, 1, 1, 1, 1, 1,16},
		{16,16, 1, 1, 1, 1,16,16},
	};
	int tempbkptwo[8][8]={
		{16,16, 2, 2, 2, 2,16,16},
		{16, 2, 2, 2, 2, 2, 2,16},
		{ 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2},
		{16, 2, 2, 2, 2, 2, 2,16},
		{16,16, 2, 2, 2, 2,16,16},
	};

	bkpboard[0].tesuu=0;
	bkpboard[1].tesuu=1;
	bkpboard[2].tesuu=2;
	mboard.tesuu = 1;
	for (int i=0; i<=7; ++i){
		for (int j=0; j<=7; ++j){
				mboard.sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[0].sqStatus[i][j]=tempbkpzero[i][j];
				bkpboard[1].sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[2].sqStatus[i][j]=tempbkptwo[i][j];
		}
	}

	assertEqualsInt(boardTimeMachine(&mboard, bkpboard, 1), 0);
	assertEqualsInt(mboard.tesuu, 2);
	for (int i=0; i<=7; i++) {
		for (int j=0; j<=7; j++) {
			assertEqualsInt(bkpboard[2].sqStatus[i][j], mboard.sqStatus[i][j]);
		}
	}

	mboard.tesuu = 2;
	for (int i=0; i<=7; ++i){
		for (int j=0; j<=7; ++j){
				mboard.sqStatus[i][j]=tempbkptwo[i][j];
				bkpboard[0].sqStatus[i][j]=tempbkpzero[i][j];
				bkpboard[1].sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[2].sqStatus[i][j]=tempbkptwo[i][j];
		}
	}
	assertEqualsInt(boardTimeMachine(&mboard, bkpboard, 1),1);
	for (int i=0; i<=7; i++) {
		for (int j=0; j<=7; j++) {
			assertEqualsInt(mboard.sqStatus[i][j], tempbkptwo[i][j]);
		}
	}

	mboard.tesuu = 1;
	for (int i=0; i<=7; ++i){
		for (int j=0; j<=7; ++j){
				mboard.sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[0].sqStatus[i][j]=tempbkpzero[i][j];
				bkpboard[1].sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[2].sqStatus[i][j]=tempbkptwo[i][j];
		}
	}
	assertEqualsInt(boardTimeMachine(&mboard, bkpboard, -1),0);
	for (int i=0; i<=7; i++) {
		for (int j=0; j<=7; j++) {
			assertEqualsInt(bkpboard[0].sqStatus[i][j], mboard.sqStatus[i][j]);
		}
	}
	
	mboard.tesuu = 0;
	for (int i=0; i<=7; ++i){
		for (int j=0; j<=7; ++j){
				mboard.sqStatus[i][j]=tempbkpzero[i][j];
				bkpboard[0].sqStatus[i][j]=tempbkpzero[i][j];
				bkpboard[1].sqStatus[i][j]=tempbkpone[i][j];
				bkpboard[2].sqStatus[i][j]=tempbkptwo[i][j];
		}
	}
	assertEqualsInt(boardTimeMachine(&mboard, bkpboard, -1),1);
	for (int i=0; i<=7; i++) {
		for (int j=0; j<=7; j++) {
			assertEqualsInt(mboard.sqStatus[i][j], tempbkpzero[i][j]);
		}
	}
}