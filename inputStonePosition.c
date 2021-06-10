#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
int inputStonePosition(char *sp, board *brdp, board *bkbrdp){
	char moji;
	char *mojitretu="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *mojitretu_s = "abcdefghijklmnopqrstuvwxyz";
		// char mojitretu[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int ans = 0,
			count = -1, flag = 0;
	moji = *sp;
	/*if ( isalpha(moji) ) {
        puts("アルファベットです．");
    } else {
        puts("アルファベットではありません．");
    }*/
	if (strcmp(sp, "<")==0){
	//boardTimeMachin()関数を使って一つ前(過去)にリストア
		if (boardTimeMachine(brdp, bkbrdp, -1)==1) {//もしもboardTimeMachin()の返り値が1なら
			printf ("これ以上元に戻れません。\n");
			ans=1;
		}
		else {//もしもboardTimeMachin()の返り値が0なら
			printf("一つ前の配置に戻します。\n");
			ans=0;
		}
	}else if (strcmp(sp, ">")==0){
	//boardTimeMachin()関数を使って一つ後(未来)にリストア
		if (boardTimeMachine(brdp, bkbrdp, 1)==1) {//もしもboardTimeMachin()の返り値が1なら
			printf ("これ以上先に行けません。\n");
			ans=1;
		}else {//もしもboardTimeMachin()の返り値が0なら
			printf("一つ先の配置に進みます。\n");
			ans=0;
		}

	}else if (isalpha(moji)!=0) {
		#if DEBUG
		printf("Detect Alphabet.\n");
		#endif
		for (int i=0; i<8; i++){
    	    for (int j=0; j<8; j++){
        	    if (brdp->sqStatus[i][j] == (brdp->turn*4)+4 || brdp->sqStatus[i][j] == 12) {
        	    	count++;
        	    	// printf("%d\n",count );
        	    }

        	    if (strncmp(sp , &mojitretu[count],1 )== 0 || strncmp(sp , &mojitretu_s[count],1 )== 0){
        	    	//printf("%d\n", strncmp(sp , &mojitretu[count],1 ));
        	    	flag=1;
        	    }
        	}
    	}

		if (flag==1) {
			convertToCoodinate(brdp, sp);
			printf("石を置きました\n");
			//今の手数以降のbkbbrdpをinitboardを使って全て初期化
			for (int i=brdp->tesuu+1; i<100;i++){
				#if DEBUG
				//printf("(bkbrdp+%d)->tesuu=%d\n",i,(bkbrdp+i)->tesuu);
				#endif
				initBoard((bkbrdp+i));
				#if DEBUG
				//printf(">%d\n",(bkbrdp+i)->tesuu);
				#endif
			}
			ans=0;
		}else {//候補にない
			printf ("そのような置き場所はありません。\n");
			ans=1;
		}

	}else if(strcmp(sp, ":q") == 0){
		printf("ゲームを中断します。\n");
		exit(0);
	}else if(strcmp(sp, ":s") == 0){
		player *pp = &(brdp->gamePlayer[brdp->turn]);
		brdp->turn == 1 ? (brdp->turn = 0) : (brdp->turn = 1);
		printf("%sがパスしました。\n", pp->name);
		ans = 1;
	}else if(strcmp(sp, ":h") == 0){
		printf("\n石を置く :\n\t盤面上に現れている任意のアルファベットを入力し、Enterを押してください。\n\te.g)A + ↩︎\n");
		printf("元に戻す(Undo) :\n\t<を入力し、Enterを押してください。\n");
		printf("やり直す(Undo) :\n\t>を入力し、Enterを押してください。\n\t盤面を元に戻した後に、違う盤面操作を行うと\n\tやり直しはできなくなります。\n");
		printf("コマンドを使用する :\n\t:と小文字のアルファベットを組み合わせることにより、\n\tいくつかのコマンドを呼び出すことができます。\n\t:h : このヘルプを表示する。\n\t:s : 現在のターンをパスする。\n\t:q : このゲームを中断して、アプリケーションを終了する。\n");

		printf("バグの報告は、m16096@g.metro-cit.ac.jpにお送りください。\n\n");
		ans = 1;
	}
	else
	{
		printf("そのようなコマンドは存在しません。(:hでヘルプを表示)\n");
		ans = 1;
	}

	return ans;
}