#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int effect, handCount;
	struct gameState game;	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
	printf("\n\nRunning Unit Test: Smithy\n");
//create game
//4 players, cards, seed, 
	initializeGame(4, k, 10, &game);
	handCount = game.handCount[0] + 2;
	printf("Current Hand: %d \n", game.handCount[0]);	
//line 646 dominion.c
//pass card (smithy since we are testing it), choice1-3, struct gameState, the handPos and the bonus (which we have none yet)
	effect = cardEffect(smithy, 0, 0, 0, &game, 0, 0);
	printf("\nSmithy played for first player. \n\n");
	if(game.handCount[0] != handCount)
    {
		printf("error: Hands don't match. test: %d. returned: %d \n", handCount, game.handCount[0]);
	}
	else{
		printf("Hand Count: %d \ntest successful: Card properly drawn.\n", game.handCount[0]);
	}
	printf("\nunit Test: Smithy test successful \n");
return 0;
}
