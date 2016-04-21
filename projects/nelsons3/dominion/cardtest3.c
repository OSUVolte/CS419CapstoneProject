#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	int i, r;

	struct gameState state;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("\n\nRunning Unit Test: Gardens \n");
	
	for(i = 0; i < 5; i++){
	
		initializeGame(i, k, 10, &state);
		r = cardEffect(gardens, 0, 0, 0, &state, 0, 0);
		assert(r == -1);
	}
	
	printf("\nCard function properly returned -1. \n");
	printf("\nUnit Test: Gardens complete. \n");
	
	return 0;

}
