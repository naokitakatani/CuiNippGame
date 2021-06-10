#include <stdio.h>
#include <string.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testDisplayBoard(){
    testStart("displayBoard");
    board mboard;
    mboard.tesuu = 0;
    mboard.turn = 0;
    mboard.stone.white=2;
    mboard.stone.black=2;
    strcpy(mboard.gamePlayer[0].name, "Arradin");
    strcpy(mboard.gamePlayer[1].name, "Jasmin");
    int tempc[8][8] = {
        {16, 16, 0, 0, 0, 0, 16, 16},
        {16, 0, 0, 0, 0, 0, 0, 16},
        {0, 0, 0, 8, 4, 0, 0, 0},
        {0, 0, 8, 1, 2, 4, 0, 0},
        {0, 0, 4, 2, 1, 8, 0, 0},
        {0, 0, 0, 4, 8, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0, 16},
        {16, 16, 0, 0, 0, 0, 16, 16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            mboard.sqStatus[i][j]=tempc[i][j];
        }
    }
    displayBoard(&mboard);
    printf("\n");
    mboard.tesuu = 1;
    mboard.turn = 1;
    mboard.stone.white=1;
    mboard.stone.black=4;
    strcpy(mboard.gamePlayer[0].name, "Arradin");
    strcpy(mboard.gamePlayer[1].name, "Jasmin");
    int tempd[8][8] = {
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 0, 8, 1, 8, 0, 0},
        { 0, 0, 0, 1, 1, 0, 0, 0},
        { 0, 0, 0, 2, 1, 8, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            mboard.sqStatus[i][j]=tempd[i][j];
        }
    }
    displayBoard(&mboard);
}