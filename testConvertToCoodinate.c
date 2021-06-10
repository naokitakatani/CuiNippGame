#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testConvertToCoodinate(){
	testStart("convertToCoodinate");
	board mboard;
	char *a="A";

	player *b=mboard.gamePlayer;

	int tempM[8][8]={
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
			mboard.sqStatus[i][j]=tempM[i][j];
		}
	}
	mboard.turn=0;
	convertToCoodinate(&mboard, a);
	assertEqualsInt(b->preX, 4);
	assertEqualsInt(b->preY, 2);
	mboard.turn=1;
	convertToCoodinate(&mboard, a);
	assertEqualsInt((b+1)->preX, 3);
	assertEqualsInt((b+1)->preY, 2);

	int tmpa[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 8, 1, 8, 0, 0},
		{ 0, 0, 0, 1, 1, 0, 0, 0},
		{ 0, 0, 4, 2, 1, 8, 0, 0},
		{ 0, 0, 4, 4, 0, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			mboard.sqStatus[i][j]=tmpa[i][j];
		}
	}
	mboard.turn=1;
	convertToCoodinate(&mboard, "C");
	assertEqualsInt((b+1)->preX, 5);
	assertEqualsInt((b+1)->preY, 4);
}