#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	int counter, effectReturn;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Running Unit Test: Gardens\n");
	for(counter = 0; counter < 5; counter++)
    {
		initializeGame(counter, k, 10, &state);
		effectReturn = cardEffect(gardens, 0, 0, 0, &state, 0, 0);
		assert(r == -1);
	}
	printf("unit Test: Gardens test successful \n");
return 0;
}