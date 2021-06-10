#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testInsertToOpporSiteStone(){
	testStart("insertToOpporSiteStone");
    board testBoard;
    player *pp = testBoard.gamePlayer;

    initBoard(&testBoard);
    testBoard.turn=0;
    (pp + testBoard.turn)->opporSiteStone[0][0] = 5;
    (pp + testBoard.turn)->opporSiteStone[1][0] = 3;
    insertToOpporSiteStone(&testBoard, 3, 4);
    assertEqualsInt((pp + testBoard.turn)->opporSiteStone[0][1], 3);
    assertEqualsInt((pp + testBoard.turn)->opporSiteStone[1][1], 4);

    initBoard(&testBoard);
    testBoard.turn=0;
    (pp + testBoard.turn)->opporSiteStone[0][0] = 7;
    (pp + testBoard.turn)->opporSiteStone[1][0] = 2;
    (pp + testBoard.turn)->opporSiteStone[0][1] = 9;
    (pp + testBoard.turn)->opporSiteStone[1][1] = 6;
    insertToOpporSiteStone(&testBoard, 1, 7);
    assertEqualsInt((pp + testBoard.turn)->opporSiteStone[0][2], 1);
    assertEqualsInt((pp + testBoard.turn)->opporSiteStone[1][2], 7);
}