/* -----------------------------------------------------------------------
 * Unit test for the getWinners() function
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


void compareReturns(int bufferPlayers[MAX_PLAYERS], int curPlayers[MAX_PLAYERS], int numPlayersTest){
	int pass = 1;
	int i = 0;
	for(i=0; i < numPlayersTest; i++){
		if(bufferPlayers[i] != curPlayers[i])
			pass = 0;
		else
			pass = 1;
	}
		
	if(pass == 1){
		printf("-PASSED\n");
	} else {
		printf("-FAILED\n");
		printf("EXP| ");
		for(i = 0; i < numPlayersTest; i++){
			printf("%i | ", bufferPlayers[i]);
		}
		printf("\n");
		printf("ACT: ");
		for(i = 0; i < numPlayersTest; i++){
			printf("%i | ", curPlayers[i]);
		}
		printf("\n");
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

void setExpectedWinners(int one, int two, int three, int four, int bufferPlayers[MAX_PLAYERS]){
	bufferPlayers[0] = one;
	bufferPlayers[1] = two;
	bufferPlayers[2] = three;
	bufferPlayers[3] = four;
}

int main() {
    int i, j;
    int seed = 1000;
    int p, r, handCount, deckCount, discardCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
		int actualWinners[MAX_PLAYERS];
		int expectedWinners[MAX_PLAYERS];
		int numPlayersTest = 0;
		
    printf ("TESTING getWinners():\n");


#if (NOISY_TEST == 1)
		printf("Test when player one is the clear winner with one estate.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = numPlayersTest;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
		}
		//Give Player One one estate card
		G.hand[0][0] = estate;
		
		setExpectedWinners(1, 0, 0, 0, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
		
#if (NOISY_TEST == 1)
		printf("Test when player two is the clear winner with one estate.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = numPlayersTest;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
		}
		//Give Player One one estate card
		G.hand[1][0] = estate;
		
		setExpectedWinners(0, 1, 0, 0, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
	
#if (NOISY_TEST == 1)
		printf("Test when player one is the clear winner with one province and other estates.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = numPlayersTest;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
		}
		//Give Player One one estate card
		G.hand[0][0] = province;
		G.hand[1][0] = estate;
		
		setExpectedWinners(1, 0, 0, 0, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
	
#if (NOISY_TEST == 1)
		printf("Test when everyone is tied.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = numPlayersTest;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
			G.hand[i][0] = estate;
		}
		
		setExpectedWinners(1, 1, 1, 1, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
		
#if (NOISY_TEST == 1)
		printf("Test when everyone is tied but the first two players have gone.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 4;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = 1;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
			G.hand[i][0] = estate;
		}
		
		setExpectedWinners(0, 0, 1, 1, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
		
#if (NOISY_TEST == 1)
		printf("Test with some values.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 4;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = 1;
		//Give all players nothing but copper
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = MAX_HAND;
			for(j = 0; j < MAX_HAND; j++)
				G.hand[i][j] = copper;
		}
		
		G.hand[0][0] = estate;
		G.hand[0][1] = province;
		G.hand[0][2] = duchy;
		G.hand[1][0] = province;
		G.hand[1][1] = province;
		G.hand[1][2] = province;
		G.hand[2][0] = province;
		G.hand[2][1] = estate;
		G.hand[2][2] = estate;
		G.hand[3][0] = estate;
		G.hand[3][1] = estate;
		G.hand[3][2] = estate;
		
		setExpectedWinners(0, 1, 0, 0, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
		
#if (NOISY_TEST == 1)
		printf("Test with one estate in the deck for Player One.\n");
#endif
		//Initialize and clear the game
		numPlayersTest = 4;
		handCount = 5;
		deckCount = 10;
		discardCount = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		
		G.whoseTurn = numPlayersTest;
		//Give all players nothing but copper in the hand
		for (i = 0; i < numPlayersTest; i++){
			G.handCount[i] = handCount;
			for(j = 0; j < handCount; j++)
				G.hand[i][j] = copper;
		}
		//Give all players nothing but copper in the discard
		for (i = 0; i < numPlayersTest; i++){
			G.discardCount[i] = deckCount;
			for(j = 0; j < G.discardCount[i]; j++)
				G.discard[i][j] = copper;
		}
		//Give all players nothing but copper in the deck
		for (i = 0; i < numPlayersTest; i++){
			G.deckCount[i] = deckCount;
			for(j = 0; j < G.deckCount[i]; j++)
				G.deck[i][j] = copper;
		}
		
		G.deck[0][0] = estate;
		
		setExpectedWinners(1, 0, 0, 0, expectedWinners);
		getWinners(actualWinners, &G);
		compareReturns(expectedWinners, actualWinners, numPlayersTest);
		
		return 0;
}

