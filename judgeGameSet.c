#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
void judgeGameSet(board *brdp){
	stone *b;
	b=&brdp->stone;
    if (blackAvailable(brdp)==0 || whiteAvailable(brdp)==0){
    	brdp->winer=3;
    }else if(blackAvailable(brdp)==1 || whiteAvailable(brdp)==1){
		#if DEBUG
		printf("b=%d, w=%d\n", blackAvailable(brdp), whiteAvailable(brdp));
#endif
		if (b->black > b->white){
    		brdp->winer=0;
    	}else if(b->black < b->white){
    		brdp->winer=1;
    	}else{
    		brdp->winer=2;
    	}
    }
}