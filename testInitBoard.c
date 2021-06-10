#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testInitBoard(){
	testStart("initBoard");
	board mboard;
	board Ansboard;

	Ansboard.turn=0;
	Ansboard.tesuu=-1;
	Ansboard.winer=3;

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
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			Ansboard.sqStatus[i][j]=tempAns[i][j];
		}
	}
	mboard.turn=1;
	mboard.tesuu=64;
	mboard.winer=1;
	int tempData[8][8]={
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			mboard.sqStatus[i][j]=tempData[i][j];
		}
	}

	initBoard(&mboard);

	assertEqualsInt(Ansboard.turn, mboard.turn);
	assertEqualsInt(Ansboard.tesuu, mboard.tesuu);
	assertEqualsInt(Ansboard.winer, mboard.winer);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			assertEqualsInt(Ansboard.sqStatus[i][j], mboard.sqStatus[i][j]);
		}
	}
	
}