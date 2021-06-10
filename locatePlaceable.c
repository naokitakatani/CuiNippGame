#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void locatePlaceable(board *brdp){
	#if DEBUG
	printf("-----Begining of locatePlaceable Process.-----\n");
	#endif
	int bkturn = brdp->turn;

	brdp->turn = 0;//自分の石が黒
		for (int y=0; y<8; y++){
			for (int x=0; x<8; x++){
				// printf("turn = %d\n", brdp->turn);
				// ans = locateOppStone(brdp, x, y);
				// printf("ここまでおｋ\n");
				// printf("x=%d, y=%d, locateOppStoneの返り値=%d\n", x, y, locateOppStone(brdp, x, y));
				if (locateOppStone(brdp, x, y) == 1){
					#if DEBUG
					printf("sqStatus[%d][%d]=%d\n", y, x, brdp->sqStatus[y][x]);
					#endif
					brdp->sqStatus[y][x] = 4;
					#if DEBUG
					printf("> %d\n", brdp->sqStatus[y][x]);
					#endif
					// printf("brbdのsqStatus[%d][%d] = %d\n",x, y, brdp->sqStatus[y][x]);
				}else if(brdp->sqStatus[y][x]==4 || brdp->sqStatus[y][x]==8 || brdp->sqStatus[y][x]==12){
					#if DEBUG
					printf("sqStatus[%d][%d]=%d\n", y, x, brdp->sqStatus[y][x]);
					#endif
					brdp->sqStatus[y][x] = 0;
					#if DEBUG
					printf("> %d\n", brdp->sqStatus[y][x]);
					#endif
				}
			}
		}
	brdp->turn = 1;//自分の石が白
		for (int x=0; x<8; x++){
			for (int y=0; y<8; y++){
				// printf("turn = %d\n", brdp->turn);
				// ans = locateOppStone(brdp, x, y);
				// printf("x=%d, y=%d, 返り値=%d\n", x, y, locateOppStone(brdp, x, y));
				if (locateOppStone(brdp, x, y) == 1){
					#if DEBUG
					printf("sqStatus[%d][%d]=%d\n", y, x, brdp->sqStatus[y][x]);
					#endif
					if (brdp->sqStatus[y][x] == 4){
						brdp->sqStatus[y][x] = 12;
					}
					else {
						brdp->sqStatus[y][x] = 8;
					}
					#if DEBUG
					printf("> %d\n", brdp->sqStatus[y][x]);
					#endif
					// printf("sqStatus[%d][%d] = %d\n",x, y, brdp->sqStatus[y][x]);
				}else if(brdp->sqStatus[y][x]==8 || brdp->sqStatus[y][x]==12){
					#if DEBUG
					printf("sqStatus[%d][%d]=%d\n", y, x, brdp->sqStatus[y][x]);
					#endif
					brdp->sqStatus[y][x] = 0;
					#if DEBUG
					printf("> %d\n", brdp->sqStatus[y][x]);
					#endif
				}
						}
		}
		// printf("turn = %d\n", bkturn);
	brdp->turn = bkturn;
	#if DEBUG
	printf("-----End of locatePlaceable Process.-----\n");
	#endif
}