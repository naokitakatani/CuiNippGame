#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testLocateOppStoneAround(){
	testStart("locateOppStoneAround");
	board mboard;

	int tempboard1[8][8]={
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
			mboard.sqStatus[i][j]=tempboard1[i][j];
		}
	}
	mboard.turn = 1;
	assertEqualsInt(locateOppStoneAround(&mboard, 3, 2), 0);

	int tempboard2[8][8]={
		{16,16, 2, 2, 4, 2,16,16},
		{16, 0, 0, 0, 0, 0, 2,16},
		{ 2, 0, 0, 8, 4, 0, 0, 2},
		{ 0, 0, 8, 1, 2, 4, 0, 2},
		{ 1, 0, 4, 2, 1, 8, 0, 1},
		{ 0, 0, 0, 4, 8, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			mboard.sqStatus[i][j]=tempboard2[i][j];
		}
	}
	mboard.turn = 0;
	assertEqualsInt(locateOppStoneAround(&mboard, 4, 0), 1);

}