#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
int locateOppStoneAround(board *brdp, int x, int y){
	#if DEBUG
	printf("-----Begining of locateOppStoneAround Process.-----\n");
	#endif
	int ans=0, enemyStone=0, myStone=0, xplace[20]={2,3,4,5,6,7,7,7,7,6,5,4,3,2,1,0,0,0,0,1},yplace[20]={0,0,0,0,1,2,3,4,5,6,7,7,7,7,6,5,4,3,2,1},preplaces, places, nextplaces;

	if ((x==2 && y== 0) || (x==3 && y== 0) || (x==4 && y== 0) || (x==5 && y== 0) || (x==1 && y== 1) || (x==6 && y== 1) || (x==0 && y== 2) || (x==7 && y== 2) || (x==0 && y== 3) || (x==7 && y== 3) || (x==0 && y== 4) || (x==7 && y== 4) || (x==0 && y== 5) || (x==7 && y== 5) || (x==1 && y== 6) || (x==6 && y== 6) || (x==2 && y== 7) || (x==3 && y== 7) || (x==4 && y== 7) || (x==5 && y== 7)) {
		if (brdp->turn == 0) {//ターンによって先手のプレイヤーか後手のプレイヤーか判断
				enemyStone = 2;//先手は黒石だから敵の石は白
				myStone = 1;//自分の石は黒
				// printf("自分の石は%dで、敵の石は%dです\n",myStone, enemyStone );
		}
		else if (brdp->turn == 1){
				enemyStone = 1;//後手は白石だから敵の石は黒
				myStone = 2;//自分の石白
				// printf("自分の石は%dで、敵の石は%dです\n",myStone, enemyStone );
		}
		if (x==2 && y==0){
			preplaces=0;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==3 && y==0){
			preplaces=1;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==4 && y==0){
			preplaces=2;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==5 && y==0){
			preplaces=3;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==6 && y==1){
			preplaces=4;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==7 && y==2){
			preplaces=5;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==7 && y==3){
			preplaces=6;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==7 && y==4){
			preplaces=7;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==7 && y==5){
			preplaces=8;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==6 && y==6){
			preplaces=9;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==5 && y==7){
			preplaces=10;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==4 && y==7){
			preplaces=11;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==3 && y==7){
			preplaces=12;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==2 && y==7){
			preplaces=13;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==1 && y==6){
			preplaces=14;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==0 && y==5){
			preplaces=15;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==0 && y==4){
			preplaces=16;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==0 && y==3){
			preplaces=17;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==0 && y==2){
			preplaces=18;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		if (x==1 && y==1){
			preplaces=19;
			#if DEBUG
			printf("(locateOppStoneAround) [%d:%d] is on circle No. %d\n", x, y, preplaces);
			#endif
		}
		// int bkplaces = places;
		// printf("first plases=%d\n",places);
		places = preplaces;
		#if DEBUG
		printf("Inspect clockwise. places is %d\n", places);
		#endif
		for (int i = 0; i < 20; i++){ //時計回り
			places == 19? places = 0: places++;//placesをカウントアップして時計回りに動かす。
			places == 19 ? nextplaces = 0 : (nextplaces=places+1);//placesの一つ先を示すようにする。
			#if DEBUG
			printf("Inspecting [%d:%d](places=%d, sqStatus[%d][%d]=%d) and Next [%d:%d](nextplaces=%d, sqStatus[%d][%d]=%d)\n", xplace[places], yplace[places], places, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]], xplace[nextplaces], yplace[nextplaces], nextplaces, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]]);
			#endif
			if (brdp->sqStatus[yplace[places]][xplace[places]] == enemyStone&&brdp->sqStatus[yplace[nextplaces]][xplace[nextplaces]] == myStone){//現在のマスに敵石があり、次のマスに自分の石があるなら	
				#if DEBUG
				printf("(locateOppStoneAround) Found a complementary stone at [%d:%d](1). sqStatus[%d][%d]=%d. Direction is clockwise.\n", xplace[nextplaces], yplace[nextplaces], yplace[nextplaces], xplace[nextplaces], brdp->sqStatus[yplace[nextplaces]][xplace[nextplaces]]);
				#endif
				ans=1;//対石がある事を返して、
				//見つけた対石の座標をopporSiteStoneに格納する。
				insertToOpporSiteStone(brdp, xplace[nextplaces], yplace[nextplaces]);
			}else if(brdp->sqStatus[yplace[places]][xplace[places]] != enemyStone){
				#if DEBUG
				if(ans==0){
					printf("There is no Complementary Stone on clockwise.\n");
				}
				#endif
				break;
			}
		}	
		// printf("after plases=%d\n", places);
		places = preplaces;
		#if DEBUG
		printf("Inspect couterclockwise. places is %d\n", places);
		#endif
		for (int i = 20; i > 0; i--){ //反時計回り
			places == 0? places = 19: places--;
			places == 0 ? nextplaces = 19 : (nextplaces=places-1);
			#if DEBUG
			printf("Inspecting [%d:%d](places=%d, sqStatus[%d][%d]=%d) and Next [%d:%d](nextplaces=%d, sqStatus[%d][%d]=%d)\n", xplace[places], yplace[places], places, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]], xplace[nextplaces], yplace[nextplaces], nextplaces, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]]);
			#endif
			//if (places == 0) {
			if (brdp->sqStatus[yplace[places]][xplace[places]] == enemyStone && brdp->sqStatus[yplace[nextplaces]][xplace[nextplaces]] == myStone){
				#if DEBUG
				printf("(locateOppStoneAround) Found a complementary stone at [%d:%d](1). sqStatus[%d][%d]=%d. Direction is counterclockwise.\n", xplace[nextplaces], yplace[nextplaces], yplace[nextplaces], xplace[nextplaces], brdp->sqStatus[yplace[nextplaces]][xplace[nextplaces]]);
				#endif
				ans=1;
				//見つけた対石の座標をopporSiteStoneに格納する。
				insertToOpporSiteStone(brdp, xplace[nextplaces], yplace[nextplaces]);
			}else if(brdp->sqStatus[yplace[places]][xplace[places]] != enemyStone){
				#if DEBUG
				if(ans==0){
					printf("There is no Complementary Stone on clockwise.\n");
				}
				#endif
				break;
			}
		}
	}else {//盤の円周上になければ
		ans=0;
	}
	#if DEBUG
	printf("-----End of locateOppStoneAround Process.-----\n");
	#endif
	return ans;
}