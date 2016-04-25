#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*******************************************************
** Unit test to check the Smithy card
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

void comparePostSmithy(int player, int preHandCount, struct gameState *state){
	if(preHandCount == state->handCount[player] - 2){
		printf(" - PASSED\n");
	} else {
		printf(" - FAILED\n");
		printf("PRE PLAY:  %i\n", preHandCount);
		printf("POST PLAY: %i\n", state->handCount[player]);
	}
}

void printCards(int player, struct gameState *state){
	int i;
	printf("--Hand:\n");
	for(i = 0; i < state->handCount[player]; i++)
		printf(" - %i", state->hand[0][i]);
	printf("\n");
	printf("--Discard Pile:\n");
	for(i = 0; i < state->discardCount[player]; i++)
		printf(" - %i", state->discard[0][i]);
	printf("\n");
	printf("--Deck:\n");
	for(i = 0; i < state->deckCount[player]; i++)
		printf(" - %i", state->deck[0][i]);
	printf("\n");
}

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


int main() {
    int i, j;
    int seed = 1000;
    int p, r, handCount, preHandCount, postHandCount;
		int curHandSize = 5;
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
		
    printf ("TESTING Smithy Card:\n");


#if (NOISY_TEST == 1)
		printf("Player with all coppers plays a Smithy card.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 5;
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = curHandSize;
			for (j = 0; j < G.handCount[i]; j++)
				G.hand[i][j] = copper;
		}
		
		//Give player one a smithy card
		gainCard(smithy, &G, 2, 0);
		preHandCount = G.handCount[0];
    cardEffect(smithy, 0, 0, 0, &G, G.hand[0][0], 0);
		
		comparePostSmithy(0, preHandCount, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Player with just a Smithy card plays a smithy card.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 2;
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = curHandSize;
			for (j = 0; j < G.handCount[i]; j++)
				G.hand[i][j] = copper;
		}
		
		//Give player one a smithy card
		gainCard(smithy, &G, 2, 0);
		preHandCount = G.handCount[0];
    cardEffect(smithy, 0, 0, 0, &G, G.hand[0][0], 0);
		
		comparePostSmithy(0, preHandCount, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Player with just a Smithy and one copper card plays a smithy card.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 1;
		G.handCount[0] = curHandSize;
		
		//Give player one a smithy card
		gainCard(smithy, &G, 2, 0);
		preHandCount = G.handCount[0];
    cardEffect(smithy, 0, 0, 0, &G, G.hand[0][0], 0);
		
		comparePostSmithy(0, preHandCount, &G);
		
		return 0;
		
}
