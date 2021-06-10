#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testLocateOppStone(){
    testStart("locateOppStone");
    board mboard;


    int tempboard1[8][8]={
		{16,16, 1, 1,12, 2,16,16},
		{16, 1, 0, 0, 0, 0, 2,16},
		{ 1, 0, 0, 8, 4, 0, 0, 2},
		{ 2, 0, 8, 1, 2, 4, 0, 2},
		{ 0, 0, 4, 2, 1, 8, 0, 1},
		{ 0, 0, 0, 4, 8, 0, 0, 0},
		{16, 0, 0, 0, 0, 0, 0,16},
		{16,16, 0, 0, 0, 0,16,16},
	};
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			mboard.sqStatus[i][j]=tempboard1[i][j];
			// printf("mboard.sqStatus[%d][%d] = %d\n", i, j, mboard.sqStatus[i][j]);
		}
	}
	mboard.turn=1;/*白石*/
	assertEqualsInt(locateOppStone(&mboard, 3, 2), 1);

	mboard.turn=0;/*黒石*/
	assertEqualsInt(locateOppStone(&mboard, 4, 2), 1);
	
	// printf("turn1,x=4,y=0で石無し\n");
	mboard.turn=1;/*外周の白石*/
	assertEqualsInt(locateOppStone(&mboard, 4, 0), 1);

	// printf("turn0,x=4,y=0で石無し\n");
	mboard.turn=0;/*外周の黒石*/
	assertEqualsInt(locateOppStone(&mboard, 4, 0), 1);

	mboard.turn=1;/*対石無し*/
	assertEqualsInt(locateOppStone(&mboard, 2, 2), 0);

	mboard.turn=0;/*対石無し*/
	assertEqualsInt(locateOppStone(&mboard, 2, 2), 0);

	mboard.turn=1;/*外周の対石無し*/
	assertEqualsInt(locateOppStone(&mboard, 1, 5), 0);


}