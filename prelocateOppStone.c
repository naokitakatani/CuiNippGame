#include <stdio.h>
#include <math.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
//黒が先手、白が後手
int prelocateOppStone(board *brdp, int x, int y, int dx, int dy){
	#if DEBUG
	printf("-----Begining of preLocateOppStone Process.-----\n");
	#endif
	int ans = 0, enemyStone = 0, myStone = 0;
	// int xhaji[20]={2,3,4,5,6,7,7,7,7,6,5,4,3,2,1,0,0,0,0,1,}, yhaji[20]={0,0,0,0,1,2,3,4,5,6,7,7,7,7,6,5,4,3,2,1,};
	int judge=0;
	if (dx==0 && dy==0) {
		// printf("error1\n");
		judge = 1;
		ans = 0;
	}
	if(brdp->sqStatus[y][x]!=1&&brdp->sqStatus[y][x]!=2){
		#if DEBUG
		printf("sqStatus is not Stone. sqStatus[%d][%d]=%d\n", y, x, brdp->sqStatus[y][x]);
		#endif
		// printf("confirm abs : %d\n", abs(dx));
		/*if ((dx == 1 || dx ==-1) && (dy == 1 || dy==-1)) {
			judge = 0;
		}
		else {
			printf("error2\n");
			judge = 1;
		}*/
		x += dx;
		y += dy;
		if (x == 8 || x == -1){
			judge = 1;//xにdxを加算して盤面の外に出るかどうか		
		}
		if (y == 8 || y == -1) {
			judge = 1;
		}

		if (judge == 0) {//dxdyが1,-1,0のどれかで(0,0)で動かさない場合でないか
			// printf("ok\n");
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
			// printf("x=%d, y=%d\n", x, y);
			// printf("%d\n", y);
			// printf("sqStatus[%d][%d]=%d\n", x, y, brdp->sqStatus[x][y]);
			// printf("%d\n",enemyStone );
			if (brdp->sqStatus[y][x] == enemyStone) {//加算後のsqStatusに敵の石がある場合
				#if DEBUG
				printf("(preLocateOppStone)brdp->sqStatus[y][x]=%d. So found a enemystone.\n", brdp->sqStatus[y][x]);
				#endif
				for (int i=0; -1<x+dx && x+dx<8 && -1<y+dy && y+dy<8 && brdp->sqStatus[y][x] != 16 ; i++) {//端の座標になるまでループ
					x += dx;
					y += dy;
					#if DEBUG
					printf("Current coodinate is [x:y]=[%d:%d]\n", x, y);
					#endif
					if (brdp->sqStatus[y][x] == enemyStone){
						#if DEBUG
						printf("Enemy stone Continued.\n");
						#endif
						// printf("%d\n", x);
						// printf("%d\n", y);
						// printf("自分の石は%dで、敵の石は%dです\n",myStone, enemyStone );
						// printf("sqStatus[%d][%d]=%d\n", x, y, brdp->sqStatus[x][y]);
						// printf("myStone = %d\n",myStone );
						// printf("x=%d,y=%d\n", x,y);
						// printf("prelocateOppStoneのなかまできたよ\n");
						/*for (int i=0; i<10; i++) {
						if ((xhaji[i] == x && yhaji[i] == y) || brdp->sqStatus[x][y] == 16) {
							// printf("ok\n");
							// printf("xhaji = %d, yhaji = %d\n",xhaji[i], yhaji[i]);
							ans=0;
							// goto loopend;
							return ans;
						}
						// printf("sqStatus[%d][%d]=%d\n", x, y, brdp->sqStatus[x][y]);
					}
					if (brdp->sqStatus[x][y] == myStone) {//端につくまでに対石があった場合
							// printf("ans代入前のans=%d\n",ans);
							// printf("sqStatus[%d][%d]=%d, dx=%d, dy=%d\n", x, y, brdp->sqStatus[x][y], dx, dy);
							ans=1;
							// printf("ans代入後のans=%d\n",ans);
							// goto loopend;
							return ans;
					}*/
						// printf("%d\n", myStone);				
					}else if (brdp->sqStatus[y][x] == myStone){
						#if DEBUG
						printf("Find my stone. So it can be Opp Stone. This coodinate will be reported.\n");
						#endif
						insertToOpporSiteStone(brdp, x, y);
						//printf("Ans=1 point 1.[%d:%d]\n", x, y);
						ans = 1;
							#if DEBUG
						printf("-----End of preLocateOppStone Process.-----\n");
						#endif
						return ans;
					}
					else {
						#if DEBUG
						printf("-----End of preLocateOppStone Process.-----\n");
						#endif
						return ans;
					}
				}
			}
		}
	}
	// loopend:
	// printf("最終的なans%d\n", ans);
	#if DEBUG
	if(ans==1){
		printf("Result : There is a opp stone.\n");	
	}else if(ans==0){
		printf("Result : Opp stone not founded.\n");
	}
	
	#endif
	#if DEBUG
	printf("-----End of preLocateOppStone Process.-----\n");
	#endif
	return ans;
	// return 0;
}