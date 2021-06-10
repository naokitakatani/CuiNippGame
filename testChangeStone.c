#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testChangeStone(){
    testStart("changeStone");
    board pboard;
    board *b = &pboard;
    player *p = b->gamePlayer;
    int (*pp)[8];//problem pointer
    int (*ap)[8];//answer pointer
    int tempa[8][8] = {
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 0, 8, 4, 0, 0, 0},
        { 0, 0, 8, 1, 2, 4, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 0, 4, 8, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    int tempb[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 0, 8, 0, 8, 0, 0},
        { 0, 0, 0, 1, 1, 1, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 4, 0, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };

    pp = tempa;
    ap = tempb;
    for (int i = 0; i < 100; i++){
        p->opporSiteStone[0][i] = 0;
        p->opporSiteStone[1][i] = 0;
    }

    b->turn = 0;
    (p+b->turn)->preX=5;
    (p+b->turn)->preY=3;
    (p+b->turn)->opporSiteStone[0][0] = 3;
    (p+b->turn)->opporSiteStone[1][0] = 3;   

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    changeStone(b);
    #if DEBUG
    boardContent(b);
    #endif
    locatePlaceable(b);
    #if DEBUG
    boardContent(b);
    #endif
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //printf("[%d:%d]\n",j,i);
            assertEqualsInt(b->sqStatus[i][j], ap[i][j]);
        }
    }

    int tempc[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 0, 8, 4, 0, 0, 0},
        { 0, 0, 8, 1, 2, 4, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 0, 4, 8, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    int tempd[8][8] = {
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 4, 2, 4, 0, 0, 0},
        { 0, 0, 0, 2, 2, 0, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 0, 0, 8, 8, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };

    pp = tempc;
    ap = tempd;
    for (int i = 0; i < 100; i++){
        p->opporSiteStone[0][i] = 0;
        p->opporSiteStone[1][i] = 0;
    }

    b->turn = 1;
    (p+b->turn)->preX=3;
    (p+b->turn)->preY=2;
    (p+b->turn)->opporSiteStone[0][0] = 3;
    (p+b->turn)->opporSiteStone[1][0] = 4;
    (p+b->turn)->opporSiteStone[0][1] = 0;
    (p+b->turn)->opporSiteStone[1][1] = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    changeStone(b);
    #if DEBUG
    boardContent(b);
    #endif
    locatePlaceable(b);
    #if DEBUG
    boardContent(b);
    #endif
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //printf("[%d:%d]\n",j,i);
            assertEqualsInt(b->sqStatus[i][j], ap[i][j]);
        }
    }
  int tempe[8][8]={
        {16,16, 1, 1, 1, 1,16,16},
        {16, 1, 1, 1, 1, 1, 1,16},
        { 1, 1, 1, 1, 2, 1, 1, 1},
        { 2, 2, 2, 2, 2, 4, 0, 8},
        { 4, 4, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 4, 8, 8, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    int tempf[8][8]={
        {16,16, 2, 2, 2, 2,16,16},
        {16, 2, 1, 1, 1, 1, 2,16},
        { 2, 1, 1, 1, 2, 1, 1, 2},
        { 2, 2, 2, 2, 2,12, 8, 2},
        { 4, 4, 4, 2, 1,12, 0, 0},
        { 0, 0, 4, 4,12, 8, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
  };

    pp = tempe;
    ap = tempf;
    for (int i = 0; i < 100; i++){
        p->opporSiteStone[0][i] = 0;
        p->opporSiteStone[1][i] = 0;
    }

    b->turn = 1;
    (p+b->turn)->preX=7;
    (p+b->turn)->preY=3;
    (p+b->turn)->opporSiteStone[0][0] = 0;
    (p+b->turn)->opporSiteStone[1][0] = 3;
    (p+b->turn)->opporSiteStone[0][1] = 0;
    (p+b->turn)->opporSiteStone[1][1] = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    changeStone(b);
    #if DEBUG
    boardContent(b);
    #endif
    locatePlaceable(b);
    #if DEBUG
    boardContent(b);
    #endif
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //printf("[%d:%d]\n",j,i);
            assertEqualsInt(b->sqStatus[i][j], ap[i][j]);
        }
    }
    
    int tempg[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 0, 0, 0,16},
        { 0, 0, 0, 8, 1, 8, 0, 0},
        { 0, 0, 0, 1, 1, 0, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 4, 0, 0, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    int temph[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 0, 0, 8, 0, 0,16},
        { 0, 0, 8, 8, 1, 8, 0, 0},
        { 0, 0, 0, 1, 1, 0, 0, 0},
        { 0, 0, 0, 2, 2, 2, 0, 0},
        { 0, 0, 4, 4, 4, 4, 4, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    
    pp = tempg;
    ap = temph;
    for (int i = 0; i < 100; i++){
        p->opporSiteStone[0][i] = 0;
        p->opporSiteStone[1][i] = 0;
    }
    
    b->turn = 1;
    (p+b->turn)->preX=5;
    (p+b->turn)->preY=4;
    (p+b->turn)->opporSiteStone[0][0] = 3;
    (p+b->turn)->opporSiteStone[1][0] = 4;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    changeStone(b);
    #if DEBUG
    boardContent(b);
    #endif
    locatePlaceable(b);
    #if DEBUG
    boardContent(b);
    #endif
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //printf("[%d:%d]\n",j,i);
            assertEqualsInt(b->sqStatus[i][j], ap[i][j]);
        }
    }


    int tempi[8][8] = {
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 4, 0, 0, 8, 0,16},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 0, 0, 8, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };
    int tempj[8][8]={
        {16,16, 0, 0, 0, 0,16,16},
        {16, 0, 1, 8, 0, 8, 0,16},
        { 0, 0, 4, 1, 1, 8, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 2, 1, 8, 0, 0},
        { 0, 0, 4, 4, 0, 8, 0, 0},
        {16, 0, 0, 0, 0, 0, 0,16},
        {16,16, 0, 0, 0, 0,16,16},
    };

    pp = tempi;
    ap = tempj;
    for (int i = 0; i < 100; i++){
        p->opporSiteStone[0][i] = 0;
        p->opporSiteStone[1][i] = 0;
    }
    
    b->turn = 0;
    (p+b->turn)->preX = 2;
    (p+b->turn)->preY=1;
    (p+b->turn)->opporSiteStone[0][0] = 4;
    (p+b->turn)->opporSiteStone[1][0] = 3;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    changeStone(b);
    #if DEBUG
    boardContent(b);
    #endif
    locatePlaceable(b);
    #if DEBUG
    boardContent(b);
    #endif
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //printf("[%d:%d]\n",j,i);
            assertEqualsInt(b->sqStatus[i][j], ap[i][j]);
        }
    }
   
}