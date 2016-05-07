#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*******************************************************
** Unit test to check the Great Hall card
*******************************************************/

void compareHandCount(int player, int expected, struct gameState *state){
	if(expected == state->handCount[player]){
		printf(" - PASSED\n");
	} else {
		printf(" - FAILED\n");
		printf("EXP: %i\n", expected);
		printf("GOT: %i\n", state->handCount[player]);
	}
}

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


int main() {
    int i, j;
    int seed = 1000;
    int p, r, handCount;
		int curHandSize = 5;
		int curDeckSize = 20;
		int curDiscardSize = 2;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
		int *scoreBuffer;
		int *expectedScoreBuffer;
		int numPlayersTest = 0;
		int handSize = MAX_HAND;
		int deckSize = 100;
		int discardSize = 2;
		
		//Initialize the hands to hold only coppers
		int noPoints[MAX_HAND];
		for (i = 0; i < MAX_HAND; i++){
			noPoints[i] = copper;
		}
		
    printf ("TESTING Great Hall Card:\n");


#if (NOISY_TEST == 1)
		printf("Player uses a Great Hall card in a two player game.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 5;
		curDeckSize = 5;
		curDiscardSize = 2;
		
		for (i = 0; i < numPlayersTest; i++){
			G.deckCount[i] = curDeckSize;
			for (j = 0; j < G.deckCount[i]; j++)
				G.deck[i][j] = adventurer;
		}	
		
		for (i = 0; i < numPlayersTest; i++){
			G.discardCount[i] = curDiscardSize;
			for (j = 0; j < G.discardCount[i]; j++)
				G.discard[i][j] = copper;
		}		
		
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = curHandSize;
			for (j = 0; j < G.handCount[i]; j++)
				G.hand[i][j] = copper;
		}
		
		int originalHandCount = G.handCount[0];
		int originalNumActions = G.numActions;
		
		//Give player one a adventurer card
		G.hand[0][0] = great_hall;
		playCard(0, 0, 0, 0, &G);
		
		//Check that the total number of cards has stayed the same
		if(originalHandCount == G.handCount[0]){
			printf(" - PASSED\n");
		} else{
			printf(" - FAILED\n");
			printf(" --- ORIGINAL HAND COUNT %i\n", originalHandCount);
			printf(" --- CURRENT HAND COUNT  %i\n", G.handCount[0]);
		}
		
		//Check that the total number of actions has stayed the same
		if(originalNumActions == G.numActions){
			printf(" - PASSED\n");
		} else{
			printf(" - FAILED\n");
			printf(" --- ORIGINAL ACTIONS %i\n", originalNumActions);
			printf(" --- CURRENT ACTIONSS %i\n", G.numActions);
		}
		
		return 0;
}
