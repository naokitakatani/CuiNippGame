#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
void changeStone(board *brdp){
    #if DEBUG
    printf("-----Begining of ChangeStone Process.-----\n");
    #endif
    int xplace[20] = {2, 3, 4, 5, 6, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 1};
    int yplace[20] = {0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1};
    int arroundJudge=0;
    int onTheCirclePre = 0;
    int onTheCircleOpp=0;
    int clockWise=2;
    player *p;
    int i=0;
    p = &brdp->gamePlayer[brdp->turn];
    //配置候補座標が円周上か?
    for ( i = 0; i < 20; i++){
        if(xplace[i]==p->preX&&yplace[i]==p->preY){
            onTheCirclePre = i;
            arroundJudge++;
        }
    }
    i = 0;
    do{
        #if DEBUG
        printf("###Work Begin###\nturn=%d, pre=[%d:%d], oppNo.%d=[%d:%d]\n",brdp->turn , p->preX, p->preY,i , p->opporSiteStone[0][i],p->opporSiteStone[1][i]);
        #endif
        if (p->preX == p->opporSiteStone[0][i]){
            #if DEBUG
            printf("find culum\n");
            #endif
            int insertJadge = 0;
            int sub = p->opporSiteStone[1][i] - p->preY;
            int pm = ((sub > 0) - (sub < 0));
            for (int j = 1; j < abs(sub); j++){
                if(brdp->sqStatus[p->preY+pm*j][p->preX]!=2-brdp->turn){
                    #if DEBUG
                    printf("sqStatus[%d][%d]=%d. Dispite turn=%d\n", p->preY + pm * j, p->preX ,brdp->sqStatus[p->preY+pm*j][p->preX],  brdp->turn);
                    #endif
                    insertJadge = 1;
                }
            }
            #if DEBUG
            printf("sub=%d, pm=%d, insert=%d\n", sub, pm, 1 + brdp->turn);
            #endif
            if(insertJadge==0){
                for (int j = 0; j < abs(sub); j++){
                    #if DEBUG
                    printf("sqStatus[%d][%d+(%d)]=%d\n", p->preY, p->preX, pm*j, brdp->sqStatus[p->preY+pm*j][p->preX]);
                    #endif
                    brdp->sqStatus[p->preY+pm*j][p->preX]=1+brdp->turn;
                    #if DEBUG
                    printf("->%d\n",brdp->sqStatus[p->preY+pm*j][p->preX]);
                    #endif
                }
            }
        }else if (p->preY == p->opporSiteStone[1][i]){
            #if DEBUG
            printf("Row process.\n");
            #endif
            int insertJadge = 0;
            int sub = p->opporSiteStone[0][i] - p->preX;
            int pm = ((sub > 0) - (sub < 0));
            for (int j = 1; j < abs(sub); j++){
                if(brdp->sqStatus[p->preY][p->preX + pm*j]!=2-brdp->turn){
                    #if DEBUG
                    printf("sqStatus[%d][%d]=%d. Dispite turn=%d\n", p->preY, p->preX+ pm * j, brdp->sqStatus[p->preY][p->preX + pm*j], brdp->turn);
                    #endif
                    insertJadge = 1;
                }
            }
            #if DEBUG
            printf("sub=%d, pm=%d, insert=%d\n", sub, pm, 1 + brdp->turn);
            #endif
            if(insertJadge==0){
                for (int j = 0; j < abs(sub); j++){
                    #if DEBUG
                    printf("sqStatus[%d+(%d)][%d]=%d\n", p->preY, pm*j, p->preX, brdp->sqStatus[p->preY][p->preX + pm*j]);
                    #endif
                    brdp->sqStatus[p->preY][p->preX + pm*j] = 1 + brdp->turn;
                    #if DEBUG
                    printf("->%d\n",brdp->sqStatus[p->preY][p->preX + pm*j]);
                    #endif
                }            
            }
        }else if(abs(p->opporSiteStone[0][i] - p->preX)==abs(p->opporSiteStone[1][i] - p->preY)){
            int insertJadge = 0;
            int subX = p->opporSiteStone[0][i] - p->preX;
            int pmX = ((subX > 0) - (subX < 0));
            int subY = p->opporSiteStone[1][i] - p->preY;
            int pmY = ((subY > 0) - (subY < 0));
            for (int j = 1; j < abs(subX); j++){
                if(brdp->sqStatus[p->preY+pmY*j][p->preX+pmX*j]!=2-brdp->turn){
                    #if DEBUG
                    printf("sqStatus[%d][%d]=%d. Dispite turn=%d\n", p->preY + pmY * j, p->preX + pmX * j, brdp->sqStatus[p->preY+pmY*j][p->preX+pmX*j],brdp->turn);
                    #endif
                    insertJadge = 1;
                }
            }
            #if DEBUG
            printf("subX=%d, pmX=%d, insert=%d\n", subX, pmX, 1 + brdp->turn);
            printf("subY=%d, pmY=%d, insert=%d\n", subY, pmY, 1 + brdp->turn);
            #endif
            if(insertJadge==0){
                for (int j = 0; j < abs(subX); j++){
                    #if DEBUG
                    printf("sqStatus[%d+(%d)][%d+(%d)]=%d\n", p->preY, pmY*j, p->preX, pmX*j, brdp->sqStatus[p->preY+pmY*j][p->preX+pmX*j]);
                    #endif
                    brdp->sqStatus[p->preY+pmY*j][p->preX+pmX*j]=1+brdp->turn;
                    #if DEBUG
                    printf("->%d\n",brdp->sqStatus[p->preY+pmY*j][p->preX+pmX*j]);
                    #endif
                }
            }
        }
        
        if (arroundJudge == 1){
            #if DEBUG
            printf("find on the Circle\n");
            #endif
            //円周上のどの場所に対石候補座標があるか探す。
            for (int j = 0; j < 20; j++){
                if (xplace[j]==p->opporSiteStone[0][i]&&yplace[j]==p->opporSiteStone[1][i]){
                    onTheCircleOpp = j;
                }
            }
            #if DEBUG
            printf("find candidate Done!\n");
            #endif
            //時計回りからアプローチ(可能なら1)
            int places = onTheCirclePre;
            int nextplaces;
            do{
                places == 19? places = 0: places++;//placesをカウントアップして時計回りに動かす。
			    places == 19 ? nextplaces = 0 : (nextplaces=places+1);//placesの一つ先を示すようにする。
                //周回上にの駒がなければ
                #if DEBUG
                printf("j=%d(ontheCircleopp=%d) : sqStatus[%d][%d]=%d\n",places, onTheCircleOpp, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]]);
                #endif
                if(brdp->sqStatus[yplace[places]][xplace[places]]!=2-brdp->turn){
                    clockWise=-1;
                    #if DEBUG
                    printf("find discontinuous on clockWise\n");
                    #endif
                    break;
                }
            }while (nextplaces!=onTheCircleOpp);
            //反時計回りからアプローチ(可能なら-1)
            places = onTheCirclePre;
            do{
                places == 0? places = 19: places--;
                places == 0 ? nextplaces = 19 : (nextplaces=places-1);
                //周回上にの駒がなければ
                #if DEBUG
                printf("places=%d(ontheCircleopp=%d) : sqStatus[%d][%d]=%d\n",places, onTheCircleOpp, yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]]);
                #endif
                if(brdp->sqStatus[yplace[places]][xplace[places]]!=2-brdp->turn){
                    if(clockWise==-1){
                        clockWise = 0;
                    }else{
                        clockWise = 1;
                    }
                    #if DEBUG
                    printf("find discontinuous on counterclockWise\n");
                    #endif
                    break;
                }
            }while (nextplaces!=onTheCircleOpp);
            #if DEBUG
            printf("inspect done : clockWise=%d\n", clockWise);
            #endif
            places = onTheCirclePre;
            for (int k = 0; k < abs(clockWise); k++)
            {
                // printf("No.%d loop\n", k);
                int direc;
                if(clockWise==2){
                    direc = -1 + 2 * k;
                }else{
                    direc = clockWise;
                }
                do{
                    #if DEBUG
                    printf("in/dicrement. j=%d\n", places);
                    printf("sqStatus[%d][%d]=%d\n", yplace[places], xplace[places], brdp->sqStatus[yplace[places]][xplace[places]]);
                    #endif
                    brdp->sqStatus[yplace[places]][xplace[places]] = 1 + brdp->turn;
                    #if DEBUG
                    printf(">%d\n", brdp->sqStatus[yplace[places]][xplace[places]]);
                    #endif
                    places += direc;
                    if (places == 20){
                        places = 0;
                    }else if(places==-1){
                        places = 19;
                    }
                } while (onTheCircleOpp != places);
            }
        }
        i++;
    } while (!(p->opporSiteStone[0][i] == 0) &&!( p->opporSiteStone[0][i] == 0));
    
    stone *s;
    s = &brdp->stone;
    s->black = 0;
    s->white = 0;
    for (int i=0; i < 8; i++){
        for(int j=0; j<8; j++){
           if(brdp->sqStatus[i][j]==1){
               s->black++;
           }else if(brdp->sqStatus[i][j]==2){
               s->white++;
           }
        }
    }
    s->used = s->black + s->white;
    #if DEBUG
    printf("-----End of ChangeStone Process.-----\n");
    #endif
}