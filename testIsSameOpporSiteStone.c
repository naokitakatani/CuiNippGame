#include <stdio.h>
#include <math.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testIsSameOpporSiteStone(){
	testStart("isSameOpporSiteStone");
    board testBoard;
    player *pp = testBoard.gamePlayer;

    initBoard(&testBoard);
    testBoard.turn=0;
    (pp + testBoard.turn)->opporSiteStone[0][0] = 5;
    (pp + testBoard.turn)->opporSiteStone[1][0] = 3;
    (pp + testBoard.turn)->opporSiteStone[0][1] = 2;
    (pp + testBoard.turn)->opporSiteStone[1][1] = 8;
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 5, 3), 0);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 2, 8), 1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 1, 1), -1);
    testBoard.turn=1;
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 5, 3), -1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 2, 8), -1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 1, 1), -1);

    initBoard(&testBoard);
    testBoard.turn=1;
    (pp + testBoard.turn)->opporSiteStone[0][0] = 7;
    (pp + testBoard.turn)->opporSiteStone[1][0] = 2;
    (pp + testBoard.turn)->opporSiteStone[0][1] = 9;
    (pp + testBoard.turn)->opporSiteStone[1][1] = 6;
    (pp + testBoard.turn)->opporSiteStone[0][2] = 5;
    (pp + testBoard.turn)->opporSiteStone[1][2] = 2;
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 7, 2), 0);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 9, 6), 1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 5, 2), 2);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 1, 1), -1);
    testBoard.turn=0;
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 7, 2), -1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 9, 6), -1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 5, 2), -1);
    assertEqualsInt(isSameOpporSiteStone(&testBoard, 1, 1), -1);
}