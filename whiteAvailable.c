#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
int whiteAvailable(board *brdp){
	for (int x = 0; x < 8; ++x){
		for (int y = 0; y < 8; ++y){
			if(brdp->sqStatus[x][y]==8){
				return 0;
			}else if(brdp->sqStatus[x][y]==12){
				return 0;
			}
		}
	}


	return 1;
}
