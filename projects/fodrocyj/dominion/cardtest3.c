#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*******************************************************
** Unit test to check the Village card
*******************************************************/

void comparePostVillage(int player, int preVillageHand, int preVillageActions, struct gameState *state){
	
	if( (preVillageHand == state->handCount[player]) && (preVillageActions + 2 == state->numActions) ){
		printf(" - PASSED\n");
	} else {
		//Check if the player has the same number of cards
		if(preVillageHand == state->handCount[player]){
			printf(" - HAND COUNT PASSED\n");
		} else {
			printf(" - HAND COUNT FAILED\n");
		}
	
		//Check if the player has an additional action
		if(preVillageActions + 2 == state->numActions){
			printf(" - NUM ACTIONS PASSED\n");
		} else {
			printf(" - NUM ACTIONS FAILED\n");
			printf("   PRE VILLAGE:  %i\n", preVillageActions);
			printf("   POST VILLAGE: %i\n", state->numActions);
		}
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
    int p, r, handCount, preVillageActions, preVillageHand, villagePos;
		int curHandSize = 5;
		int curDeckSize = 20;
		int curDiscardSize = 2;
    int bonus;
    int k[10] = {adventurer, sea_hag, feast, gardens, mine
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
		
    printf ("TESTING Village Card:\n");


#if (NOISY_TEST == 1)
		printf("Player uses a Village card in a four player game.\n");
#endif
		numPlayersTest = 4;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 5;
		curDeckSize = 15;
		curDiscardSize = 2;
		
		for (i = 0; i < numPlayersTest; i++){
			G.deckCount[i] = curDeckSize;
			for (j = 0; j < G.deckCount[i]; j++)
				G.deck[i][j] = copper;
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
		
		//Give player one a sea hag card
		gainCard(village, &G, 2, 0);
		preVillageActions = G.numActions;
		preVillageHand = G.handCount[0];
		for(i = 0; i < G.handCount[0]; i++){
			if(G.hand[0][i] == village)
				villagePos = i;
		}
		
		//playCard(seaHagPos, 0, 0, 0, &G);
    cardEffect(village, 0, 0, 0, &G, G.hand[0][0], villagePos);
		
		//Check if player two lost a victory point
		comparePostVillage(0, preVillageHand, preVillageActions, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Player uses a Village card in a two player game.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 3;
		curDeckSize = 20;
		curDiscardSize = 2;
		
		for (i = 0; i < numPlayersTest; i++){
			G.deckCount[i] = curDeckSize;
			for (j = 0; j < G.deckCount[i]; j++)
				G.deck[i][j] = copper;
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
		
		//Give player one a sea hag card
		gainCard(village, &G, 2, 0);
		preVillageActions = G.numActions;
		preVillageHand = G.handCount[0];
		for(i = 0; i < G.handCount[0]; i++){
			if(G.hand[0][i] == village)
				villagePos = i;
		}
		
		//playCard(seaHagPos, 0, 0, 0, &G);
    cardEffect(village, 0, 0, 0, &G, G.hand[0][0], villagePos);
		
		//Check if player two lost a victory point
		comparePostVillage(0, preVillageHand, preVillageActions, &G);
		
		return 0;
		
}
