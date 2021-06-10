#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testLocatePlaceable(){
	testStart("locatePlaceable");
	board mboard;
	board nboard;
	board ansboard;
	board ans2board;

	
	int tempboard1[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 1, 2, 0, 0, 0},
		{ 0, 0, 0, 2, 1, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			mboard.sqStatus[i][j]=tempboard1[i][j];
		}
	}

	int Ansboard[8][8]={
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
			ansboard.sqStatus[i][j]=Ansboard[i][j];
		}
	}

	int tempboard2[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 2, 0, 0, 0, 0},
		{ 0, 0, 0, 1, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 2, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			nboard.sqStatus[i][j]=tempboard2[i][j];
		}
	}

	int Ans2board[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 4, 0, 0, 0,16},
		{ 0, 0, 8, 2, 0, 0, 0, 0},
		{ 0, 0, 0, 1, 0, 0, 0, 0},
		{ 0, 0, 0, 12,2, 1, 8, 0},
		{ 0, 0, 0, 0, 0, 4, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			ans2board.sqStatus[i][j]=Ans2board[i][j];
		}
	}
	

	mboard.turn=0;
	locatePlaceable(&mboard);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			// printf("sqStatus[%d][%d] = %d\n", j, i, mboard.sqStatus[j][i]);
			// printf("ansのsqStatus[%d][%d] = %d\n", j, i, ansboard.sqStatus[j][i]);
			assertEqualsInt(mboard.sqStatus[j][i], ansboard.sqStatus[j][i]);
		}
	}
	

	mboard.turn=1;
	locatePlaceable(&mboard);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			assertEqualsInt(mboard.sqStatus[j][i], ansboard.sqStatus[j][i]);
		}
	}
	
	nboard.turn=0;
	locatePlaceable(&nboard);
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			// printf("sqStatus[%d][%d] = %d\n",i, j, ans2board.sqStatus[i][j]);
			assertEqualsInt(nboard.sqStatus[i][j], ans2board.sqStatus[i][j]);
		}
	}
	

	nboard.turn=1;
	locatePlaceable(&nboard);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			assertEqualsInt(nboard.sqStatus[j][i], ans2board.sqStatus[j][i]);
		}
	}
	
}