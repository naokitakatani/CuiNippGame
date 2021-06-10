#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void testBoardContent(){
    testStart("boardContent");
    board pboard;
    board *b = &pboard;
    int (*pp)[8];//problem pointer
    
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

    pp = tempa;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->sqStatus[i][j]=pp[i][j];
        }
    }
    boardContent(b);
}