#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	int counter, effectReturn;
	struct gameState game;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("\n\nRunning Unit Test: Gardens \n");
	for(counter = 0; counter < 5; counter++){
	
		initializeGame(counter, k, 10, &game);
		effectReturn = cardEffect(gardens, 0, 0, 0, &game, 0, 0);
		assert(effectReturn == -1);
	}
	printf("\nCard function properly returned -1. \n");
	printf("\nUnit Test: Gardens complete. \n");
return 0;
}
