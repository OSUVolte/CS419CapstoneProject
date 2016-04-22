#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	printf("Testing getCost()");
	assert(getCost(0) == 0);
	assert(getCost(1) == 2);
	assert(getCost(2) == 5);
	assert(getCost(3) == 8);
	assert(getCost(4) == 0);
	assert(getCost(5) == 3);
	assert(getCost(6) == 6);
	assert(getCost(7) == 6);
	assert(getCost(8) == 5);
	assert(getCost(9) == 4);
	assert(getCost(10) == 4);
	assert(getCost(11) == 5);
	assert(getCost(12) == 4);
	assert(getCost(13) == 4);
	assert(getCost(14) == 3);
	assert(getCost(15) == 4);
	assert(getCost(16) == 3);
	assert(getCost(17) == 5);
	assert(getCost(18) == 3);
	assert(getCost(19) == 5);
	assert(getCost(20) == 3);
	assert(getCost(21) == 4);
	assert(getCost(22) == 2);
	assert(getCost(23) == 5);
	assert(getCost(24) == 4);
	assert(getCost(25) == 4);
	assert(getCost(26) == 4);


	printf("All Tests Past!");

	return 0;
}
