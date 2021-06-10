#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
void displayWinner(board *brdp){
	if(brdp->winer == 0){
		printf("%sの勝ちです\n",brdp->gamePlayer[0].name);
	}
	else if(brdp->winer == 1){
		printf("%sの勝ちです\n",brdp->gamePlayer[1].name);
	}else if(brdp->winer == 2){
		printf("引き分けです\n");
	}
}