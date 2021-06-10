#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testBlackAvailable(){
    testStart("blackAvailable");
    board cboard;
	board mboard;
    board aboard;
    board sboard;

    int tempc[8][8]={
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
            mboard.sqStatus[i][j]=tempc[i][j];
        }
    }
    assertEqualsInt(blackAvailable(&mboard),0);
    
    int tempd[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 1, 1, 0, 0, 0},
		{ 0, 0, 1, 1, 2, 8, 0, 0},
		{ 0, 0, 1, 2, 1, 1, 0, 0},
		{ 0, 0, 0, 8, 1, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cboard.sqStatus[i][j]=tempd[i][j];
        }
    }
    assertEqualsInt(blackAvailable(&cboard),1);

    int tempe[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 0, 0, 0,16},
		{ 0, 0, 0, 12, 4, 0, 0, 0},
		{ 0, 0, 12, 1, 2, 4, 0, 0},
		{ 0, 0, 4, 2, 1, 12, 0, 0},
		{ 0, 0, 0, 4, 12, 12, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            aboard.sqStatus[i][j]=tempe[i][j];
        }
    }
    assertEqualsInt(blackAvailable(&aboard),0);

    int tempf[8][8]={
		{16,16, 0, 0, 0, 0,16,16},
		{16, 0, 0, 0, 12, 0, 0,16},
		{ 0, 0, 0, 8, 4, 0, 0, 0},
		{ 0, 0, 8, 1, 2, 4, 12, 0},
		{ 0, 0, 4, 2, 1, 8, 0, 0},
		{ 0, 0, 0, 4, 8, 0, 12, 0},
		{16, 0, 0, 12, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            sboard.sqStatus[i][j]=tempf[i][j];
        }
    }
    assertEqualsInt(blackAvailable(&sboard),0);
}
