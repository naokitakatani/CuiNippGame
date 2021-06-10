#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"
void testChangeTurn(){
	testStart("changeTurn");
	/*board nippBoard0_pro;*/
	board nippBoard0_ans;
	/*board nippBoard1_pro;*/
	board nippBoard1_ans;
	/*board nippBoard3_pro;*/
	board nippBoard3_ans;

	changeTurn(&nippBoard0_ans);

	/*nippBoard0_pro.turn=0;
	nippBoard0_pro.tesuu = 5;*/
	nippBoard0_ans.turn=0;
	nippBoard0_ans.tesuu=6;
	assertEqualsInt(nippBoard0_ans.turn, 0);
	assertEqualsInt(nippBoard0_ans.tesuu, 6);

	changeTurn(&nippBoard1_ans);

	/*nippBoard1_pro.turn=1;
	nippBoard1_pro.tesuu=8;*/
	nippBoard1_ans.turn=1;
	nippBoard1_ans.tesuu=9;
	assertEqualsInt(nippBoard1_ans.turn, 1);
	assertEqualsInt(nippBoard1_ans.tesuu, 9);

	changeTurn(&nippBoard3_ans);

	/*nippBoard3_pro.turn=3;
	nippBoard3_pro.tesuu=4;*/
	nippBoard3_ans.turn=3;
	nippBoard3_ans.tesuu=5;
	assertEqualsInt(nippBoard3_ans.turn, 3);
	assertEqualsInt(nippBoard3_ans.tesuu, 5);

}