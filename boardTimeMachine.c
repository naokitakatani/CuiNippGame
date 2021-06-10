#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#define DEBUG 0
int boardTimeMachine(board *brdp, board *bkbrdp ,int nb) {
    /*printf("now tesuu -> %d\n", brdp->tesuu);
    printf("nb is now -> %d\n", nb);
    printf("tesuu is now -> %d\n", (bkbrdp+(brdp->tesuu)+nb)->tesuu);
    */
    if(nb == 1){
        #if DEBUG
        for (int i = 0; i < 10; i++){
            printf("(bkbrdp+%d)->tesuu=%d\n", i, (bkbrdp + i)->tesuu);
        }
        printf("next element = %d\n", brdp->tesuu+nb);
        printf("next element tesuu= %d\n", (bkbrdp+(brdp->tesuu+nb))->tesuu);
        #endif
        if((bkbrdp+(brdp->tesuu)+nb)->tesuu!=-1){
            backupBoard((bkbrdp+(brdp->tesuu)+nb), brdp);
            return 0;
        } else return 1;
    }else if(nb == -1){
        #if DEBUG
        printf("previous element = %d\n", (brdp->tesuu)+nb);
        printf("previous element tesuu= %d\n", (bkbrdp+(brdp->tesuu)+nb)->tesuu);
        #endif
        if(((brdp->tesuu)+nb)>=0){
            backupBoard((bkbrdp+(brdp->tesuu)+nb), brdp);
            #if DEBUG
            printf("Now brdp->tesuu=%d.\n", brdp->tesuu);
#endif
            return 0;
        }else return 1;
    } 
    return 1;
}