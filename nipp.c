#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include "nipp.h"
#define DEBUG 0
int main(){
    //ゲームに使用する駒の構造体を宣言
    board mboard;
    board bkpBoard[200];
    //ゲームに参加するプレイヤーを宣言
    //駒の初期化を行う
    initBoard(&mboard);
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                initBoard(&bkpBoard[i]);
                bkpBoard[i].sqStatus[j][k] = 0;
            }
        }  
    }

    char opening1[36] = "************************************";
    char opening2[36] = "    ##   ##   ##   ######    ###### ";
    char opening3[36] = "   #### ##   ##   ##   ##   ##   ## ";
    char opening4[36] = "  ## ####   ##   ######    ######   ";
    char opening5[36] = " ##   ##   ##   ##        ##        ";
    char opening6[36] = "************************************";
    for (int i = 0; i < 6; i++){
        for(int j=0; j<36; j++){
            switch (i){
            case 0:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening1[j]);
                break;
            case 1:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening2[j]);
                break;
            case 2:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening3[j]);
                break;
            case 3:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening4[j]);
                break;
            case 4:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening5[j]);
                break;
            case 5:
                printf("\x1b[1m\x1b[42m\x1b[37m%c\x1b[39m\x1b[49m\x1b[0m", opening6[j]);
                break;
            }
        }
        printf("\n");
        usleep(0.01*1000000);
    }

    //プレイヤー名の設定
	printf("先手のプレイヤー名を入力してください。\n");
	scanf("%s", mboard.gamePlayer[0].name);
	printf("後手のプレイヤー名を入力してください。\n");
	scanf("%s", mboard.gamePlayer[1].name);
	//strcpy(gamePlayer[0].name,"Jasmine");
	//strcpy(gamePlayer[1].name,"Aladdin");
	printf("プレイヤーが登録されました。\n先手(黒石) : %s\n後手(白石) : %s\n", mboard.gamePlayer[0].name, mboard.gamePlayer[1].name);
	printf("ゲーム開始です。\n");
    mboard.turn = 1;
    mboard.tesuu = -1;
    while(mboard.winer==3){
        //printf("Beforeターン : %d\n", mboard.turn);
        changeTurn(&mboard);
        //printf("Afterターン : %d\n", mboard.turn);
        char str[64];
        int typeJudge;
        do{
            locatePlaceable(&mboard);
            displayBoard(&mboard);
            backupBoard(&mboard, &bkpBoard[mboard.tesuu]);
            #if DEBUG
            /*for (int i = 0; i < 8; i++){
                printf("{");
                for (int j = 0; j < 8; j++){
                    if(mboard.sqStatus[i][j] <10){
                        printf(" ");
                    }
                    printf("%d", mboard.sqStatus[i][j]);
                    if(j!=7){
                        printf(",");
                    }
                }
                printf("},\n");
            }
            */
            #endif
            printf("石を置く場所を選択してください。> ");
            scanf("%s", str);
            typeJudge = inputStonePosition(str, &mboard, bkpBoard);
            #if DEBUG
            /*printf("At Main. mboard.gamePlayer[%d].preX=%d\n", mboard.turn, mboard.gamePlayer[mboard.turn].preX);
            printf("At Main. mboard.gamePlayer[%d].preY=%d\n", mboard.turn, mboard.gamePlayer[mboard.turn].preY);
            */
            #endif
            if (strcmp(str, "<") == 0 || strcmp(str, ">") == 0){
                typeJudge = 1;
            }
        }while(typeJudge==1);
        //printf("Exicute locateOppStone.\n");
        locateOppStone(&mboard, mboard.gamePlayer[mboard.turn].preX, mboard.gamePlayer[mboard.turn].preY);
        #if DEBUG 
        int i = 0;
        do{
            printf("mboard.OpporSiteStone[0][%d]=%d\n", i, mboard.gamePlayer[mboard.turn].opporSiteStone[0][i]);
            printf("mboard.OpporSiteStone[0][%d]=%d\n", i, mboard.gamePlayer[mboard.turn].opporSiteStone[1][i]);
            i++;
        } while (i<9);
        for (int i = 0; i < 8; i++){
            printf("{");
            for (int j = 0; j < 8; j++){
                if(mboard.sqStatus[i][j] <10){
                    printf(" ");
                }
                printf("%d", mboard.sqStatus[i][j]);
                if(j!=7){
                    printf(",");
                }
            }
            printf("},\n");
        }
        #endif
        changeStone(&mboard);
        locatePlaceable(&mboard);
        #if DEBUG
/*         for (int i = 0; i < 8; i++){
            printf("{");
            for (int j = 0; j < 8; j++){
                if(mboard.sqStatus[i][j] <10){
                    printf(" ");
                }
                printf("%d", mboard.sqStatus[i][j]);
                if(j!=7){
                    printf(",");
                }
            }
            printf("},\n");
        } */
        #endif
        judgeGameSet(&mboard);
    }
    displayBoard(&mboard);
    displayWinner(&mboard);
    return 0;
}