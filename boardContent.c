#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
#define DEBUG 0
void boardContent(board *brdp){
    printf("#####\n");
    for (int i = 0; i < 8; i++){
        printf("{");
        for (int j = 0; j < 8; j++){
            if(brdp->sqStatus[i][j] <10) printf(" ");
            printf("%d", brdp->sqStatus[i][j]);
            if(j!=7) printf(",");
        }
        printf("},\n");
    }
}