// header file for nipp

#ifndef __nipp
#define __nipp

// **** 構造体の定義 4326 田口雅将 が記述

typedef struct {
	char name [30];
	int preX;
	int preY;
	int opporSiteStone[2][100];
}player;

typedef struct {
	int used;
	int black;
	int white;
}stone;

typedef struct {
	int sqStatus[8][8];
	int turn;
	int tesuu;
	int winer;
	player gamePlayer[2];
	stone stone;
}board;


// **** プロトタイプ宣言集
// ここから下は 43ww WWWW が記述

// ここから下は 4326 田口雅将 が記述

char *assignChar(board *brdp, int x, int y, int count);
void backupBoard(board *brdp, board *bkbrdp);
int boardTimeMachine(board *brdp, board *bkbrdp, int nb);
void displayWinner(board *brdp);
void initStone(stone *stp);

// ここから下は 4325 滝澤 が記述
extern char alphabet[32];
void initBoard(board *brdp);
void changeTurn(board *brdp);
void initPlayer(player *pyp);
void locatePlaceable(board *brdp);
int locateOppStone(board *brdp, int x, int y);
int prelocateOppStone(board *brdp, int x, int y, int dx, int dy);
int locateOppStoneAround(board *brdp, int x, int y);
void convertToCoodinate(board *brdp, char *ipp);
int isSameOpporSiteStone(board *brdp, int x, int y);

// ここから下は 4305 五十嵐碧唯 が記述
void changeStone(board *brdp);
int blackAvailable(board *brdp);
int whiteAvailable(board *brdp);
void displayBoard(board *brdp);
int inputStonePosition(char *sp, board *brdp, board *bkbrdp);
void judgeGameSet(board *brdp);
void boardContent(board *brdp);
void insertToOpporSiteStone(board *brdp, int x, int y);

#endif // __XXX
