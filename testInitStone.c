#include <stdio.h>
#include "nipp.h"
#include "testNipp.h"
#include "testCommon.h"

void testInitStone(){//4326田口雅将が記述
	// board mboard;
	// stone bkstone;
	stone mstone;

    testStart("initStone");

    mstone.used = 2;
    mstone.black = 3;
    mstone.white = 9;

    initStone(&mstone);

	assertEqualsInt(mstone.used, 0);
	assertEqualsInt(mstone.black, 2);
	assertEqualsInt(mstone.white, 2);


}