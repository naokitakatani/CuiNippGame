#include <stdio.h>
#include <string.h>
#include "nipp.h"
#include "testNipp.h"
char alphabet[32];
char *assignChar(board *brdp, int x, int y, int count){
	char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
	char *begin="\x1b[37m\x1b[42m";
	char content[2];
	char *end="\x1b[m\033[m";
	char *b = "\x1b[30m\x1b[42m●\x1b[m\033[m";
	char *w = "\x1b[37m\x1b[42m●\x1b[m\033[m";
	char *n = "\x1b[37m\x1b[42m*\x1b[m\033[m";
	char *o = "\x1b[37m\x1b[42m \x1b[m\033[m";
	if (brdp->sqStatus[x][y]==1){
		return b;
	}else if (brdp->sqStatus[x][y]==2){
		return w;
	}else if (brdp->sqStatus[x][y]==(brdp->turn*4)+4 || brdp->sqStatus[x][y]==12){
		alphabet[0]='\0';
		strncpy(content, str+count, 1);
		strcat(alphabet, begin);
		strcat(alphabet, content);
		strcat(alphabet, end);
		strcat(alphabet, "\0");
		return alphabet;
	}else if (brdp->sqStatus[x][y]==0||brdp->sqStatus[x][y]==8-(brdp->turn*4)){
		return n;
	}else if(brdp->sqStatus[x][y]==16){
		return o;
	}
	return "x";
}