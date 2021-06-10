#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"

int main() {
    printf("##### Test start #####\n");
    // ここから下は 43ww WWWW が記述

    // ここから下は 4326 田口雅将 が記述
	/*  	testAssignChar();
	testBackupBoard();
	testBoardTimeMachine();
	testDisplayWinner();*/
	testInitStone();
    // ここから下は 4325 滝澤 が記述
	testInitBoard();
	testChangeTurn();
	testInitPlayer();
	testLocatePlaceable();
	testLocateOppStone();
	testPrelocateOppStone();
	testLocateOppStoneAround();
	testConvertToCoodinate();
	testIsSameOpporSiteStone();
    // ここから下は 4305 五十嵐碧唯 が記述
	testBlackAvailable();
 	testChangeStone();
	testWhiteAvailable();
	testDisplayBoard();
	//testInputStonePosition();
	testJudgeGameSet();
	testBoardContent();
	testInsertToOpporSiteStone();
	// 最終エラー統計処理
	testErrorCheck(); // この行は絶対に消さないこと
	printf("##### Test finish #####\n");
	return 0;
}
