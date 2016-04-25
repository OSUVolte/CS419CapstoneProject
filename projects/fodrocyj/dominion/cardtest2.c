#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*******************************************************
** Unit test to check the Adventurer card
*******************************************************/

void compareHandCount(int player, int expected, struct gameState *state){
	if(expected == state->handCount[player]){
		printf(" - PASSED\n");
	} else {
		printf(" - FAILED\n");
		printf("   EXP: %i\n", expected);
		printf("   GOT: %i\n", state->handCount[player]);
	}
}

void comparePostAdventurer(int player, int preHandCount, struct gameState *state){
	if(preHandCount == state->handCount[player] - 1){
		printf(" - CARD COUNT PASSED\n");
	} else {
		printf(" - CARD COUNT FAILED\n");
		printf("   PRE PLAY:  %i\n", preHandCount);
		printf("   POST PLAY: %i\n", state->handCount[player]);
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
    int p, r, handCount, preHandCount;
		int curHandSize = 5;
		int curDeckSize = 20;
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
		
    printf ("TESTING Adventurer Card:\n");


#if (NOISY_TEST == 1)
		printf("Player with all coppers in deck plays an Adventurer card.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		
		//Give all players coppers
		curHandSize = 5;
		curDeckSize = 20;
		G.deckCount[0] = curDeckSize;
		for(i = 0; i < G.deckCount[0]; i++)
			G.deck[0][i] = copper;		
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = curHandSize;
			for (j = 0; j < G.handCount[i]; j++)
				G.hand[i][j] = copper;
		}
		
		//Give player one a adventurer card
		gainCard(adventurer, &G, 2, 0);
		
    cardEffect(adventurer, 0, 0, 0, &G, G.hand[0][0], 0);
		preHandCount = G.handCount[0];
		
		//Check if the hand contains two exta cards
		comparePostAdventurer(0, preHandCount, &G);
		
		//Check if the hand's last two cards are coppers
		if(G.hand[0][G.handCount[0]-1] == copper){
			printf("--CORRECT CARD PASSED\n");
		} else{
			printf("--CORRECT CARD FAILED\n");
		}
		
		//Check if the hand's last two cards are coppers
		if(G.hand[0][G.handCount[0]-2] == copper){
			printf("--CORRECT CARD PASSED\n");
		} else{
			printf("--CORRECT CARD FAILED\n");
		}
		

#if (NOISY_TEST == 1)
		printf("Player plays and adventurer card to draw a silver and gold.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		curHandSize = 5;
		curDeckSize = 20;
		
		
		G.deckCount[0] = curDeckSize;
		for(i = 0; i < G.deckCount[0]; i++)
			G.deck[0][i] = copper;
		G.deck[0][G.deckCount[0]-1] = gold;
		G.deck[0][G.deckCount[0]-2] = silver;
		
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = curHandSize;
			for (j = 0; j < G.handCount[i]; j++)
				G.hand[i][j] = copper;
		}
		
		//Give player one a adventurer card
		gainCard(adventurer, &G, 2, 0);
		
    cardEffect(adventurer, 0, 0, 0, &G, G.hand[0][0], 0);
		preHandCount = G.handCount[0];
		
		//Check if the hand contains two exta cards
		comparePostAdventurer(0, preHandCount, &G);
		
		//Check if the hand's last two cards are coppers
		if(G.hand[0][G.handCount[0]-2] == gold){
			printf("--CORRECT CARD PASSED\n");
		} else{
			printf("--CORRECT CARD FAILED\n");
		}
		
		//Check if the hand's last two cards are coppers
		if(G.hand[0][G.handCount[0]-1] == silver){
			printf("--CORRECT CARD PASSED\n");
		} else{
			printf("--CORRECT CARD FAILED\n");
		}
		
		return 0;
}
