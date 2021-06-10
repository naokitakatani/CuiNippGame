#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testInitPlayer(){
	testStart("initplayer");
	player mplayer[2];

	mplayer[0].preX=0;
	mplayer[0].preY=0;
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 100; ++j){
			mplayer[0].opporSiteStone[i][j]=0;
		}
	}
	
	initPlayer(mplayer);
	assertEqualsInt(mplayer[0].preX, 0);
	assertEqualsInt(mplayer[0].preY, 0);
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 100; ++j){
			assertEqualsInt(mplayer[0].opporSiteStone[i][j], 0);
		}
	}
}