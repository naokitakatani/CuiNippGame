#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
/*滝澤和人*/
void testPrelocateOppStone(){
	testStart("prelocateOppStone");
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
	mboard.turn=1;
	/*prelocateOppStone(board *brdp, int x, int y, int dx, int dy)*/
	// printf("x=3, y=2, dx=0, dy=-1のテスト\n");
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, 0, -1), 0);
	// printf("x=3, y=2, dx=0, dy=1のテスト\n");
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, 0, 1), 1);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, 1, -1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, 1, 0), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, 1, 1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, -1, -1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, -1, 0), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 3, 2, -1, 1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 0, 0, 0, 1), 0);/*16の位置*/
	assertEqualsInt(prelocateOppStone(&mboard, 2, 3, 1, 1), 0);/*0の位置*/

	mboard.turn=0;
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, 0, -1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, 0, 1), 1);
	// printf("x=5, y=3, dx=-1, dy=0のテスト\n");
	assertEqualsInt(prelocateOppStone(&mboard, 5, 3, -1, 0), 1);
	// printf("x=3, y=5, dx=0, dy=-1のテスト\n");
	assertEqualsInt(prelocateOppStone(&mboard, 3, 5, 0, -1), 1);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, 1, -1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, 1, 0), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, 1, 1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, -1, -1), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, -1, 0), 0);
	assertEqualsInt(prelocateOppStone(&mboard, 4, 2, -1, 1), 0);
}