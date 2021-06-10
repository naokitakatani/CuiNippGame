#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testAssignChar() {//4326田口雅将が記述
	board board;
	char *a = "\x1b[30m\x1b[42m●\x1b[m\033[m";
	char *b = "\x1b[37m\x1b[42m●\x1b[m\033[m";
	char *c = "\x1b[37m\x1b[42mA\x1b[m\033[m";
	char *d = "\x1b[37m\x1b[42m \x1b[m\033[m";
	char *e = "\x1b[37m\x1b[42m*\x1b[m\033[m";
	//テストはとりあえず初期の配置のことを考えています
	testStart("assignChar");
	board.sqStatus[3][1] = 0;
	char *position1 = assignChar(&board, 3, 1, 0); //sqStatusが0の時
	// printf("compare : %s, %s\n",a, b);
	assertEqualsString(position1, e);
	board.sqStatus[0][0] = 16;
	char *position2 = assignChar(&board, 0, 0, 0); //sqStatusが16の時
	assertEqualsString(position2, d);
	board.sqStatus[4][3] = 8;
	board.turn = 1;
	char *position3 = assignChar(&board, 4, 3, 0); //turn=0でsqStatusが8の時はこっち
	assertEqualsString(position3, c);
	board.sqStatus[5][3] = 4;
	board.turn = 0;
	char *position4 = assignChar(&board, 5, 3, 0); //turn=1でsqStatusが4の時こっち
	assertEqualsString(position4, c);
	board.sqStatus[5][4] = 2;
	char *position5 = assignChar(&board, 5, 4, 0); //sqStatusが2の時
	assertEqualsString(position5, b);
	board.sqStatus[4][4] = 1;
	char *position6 = assignChar(&board, 4, 4, 0); //sqStatusが1の時
	assertEqualsString(position6, a);
}