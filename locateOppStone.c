#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
int locateOppStone(board *brdp, int x, int y){
	#if DEBUG
	printf("-----Begining of locateOppStone Process.-----\n");
	#endif
	int ans=0, dx[8]={1,1,0,-1,-1,-1,0,1}, dy[8]={0,1,1,1,0,-1,-1,-1};

	player *p = brdp->gamePlayer;
	for (int i = 0; i < 100; i++){
		(p + brdp->turn)->opporSiteStone[0][i] = 0;
		(p + brdp->turn)->opporSiteStone[1][i] = 0;
	}
	if(brdp->sqStatus[y][x]!=1&&brdp->sqStatus[y][x]!=2&&brdp->sqStatus[y][x]!=16){
		for (int i=0; i<8; i++){
			#if DEBUG
			printf("[x:y]=[%d:%d]. dx=%d,dy=%d.\n", x, y, dx[i], dy[i]);
			#endif
			if (prelocateOppStone(brdp, x, y, dx[i], dy[i]) == 1){
				#if DEBUG
				printf("(locateOppStone) Found a complementary stone of [%d:%d] in the direction (dx=%d,dy=%d)\n", x, y, dx[i], dy[i]);
				#endif
				ans = 1;
			}
		}

		if (((x==2 && y== 0) || (x==3 && y== 0) || (x==4 && y== 0) || (x==5 && y== 0) || (x==1 && y== 1) || (x==6 && y== 1) || (x==0 && y== 2) || (x==7 && y== 2) || (x==0 && y== 3) || (x==7 && y== 3) || (x==0 && y== 4) || (x==7 && y== 4) || (x==0 && y== 5) || (x==7 && y== 5) || (x==1 && y== 6) || (x==6 && y== 6) || (x==2 && y== 7) || (x==3 && y== 7) || (x==4 && y== 7) || (x==5 && y== 7))) {
			if (locateOppStoneAround(brdp, x, y) == 1){
				#if DEBUG
				printf("(locateOppStone) Found a complementary stone of [%d:%d] on circle.\n", x, y);
				#endif
				ans = 1;
			}
		}
	}
	#if DEBUG
	printf("-----End of locateOppStone Process.-----\n");
	#endif
	return ans;
}
