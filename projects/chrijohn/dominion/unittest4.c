#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

	printf("TESTING compare()\n");

	int one = 1;
	int two = 2;
	int negone = -1;
	int zero = 0;
	int* One = &one;
	int* Two = &two;
	int* NegOne = &negone;
	int* Zero = &zero;

	assert(compare(One, Two) == -1);
	assert(compare(Two, One) == 1);
	assert(compare(Two, Two) == 0);
	assert(compare(NegOne, Two) == -1);
	assert(compare(Two, NegOne) == 1);
	assert(compare(Two, Zero) == 1);
	assert(compare(Zero, Two) == -1);

	printf("All test passed\n");

	return 0;

}
