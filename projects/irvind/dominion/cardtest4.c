/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--cardtest4.c
* Tests the steward card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// This test was built from the cardtest4.c example provided for Week 4.

/* Citation for card requirements: http://wiki.dominionstrategy.com/index.php/Steward
Steward Card's requirements:
1. Choice 1: Current player receives 2 cards.
2. Choice 2: Current player receives 2 coins.
3. Choice 3: Current player trashes 2 cards from current hand.
4. No state change should occur for other players.
*/

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int secPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	// Initialize a game with the steward card in Player 1's hand
	initializeGame(numPlayers, k, seed, &G);
	printf ("\n----------Testing the Steward card's basic requirements:----------\n");

	/*---------------------------------------------------------*/
	printf ("\n---Testing Choice 1: Player Receives 2 new cards---\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	//receiving 2 new cards, no new coins
	newCards = 2;
	xtraCoins = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("Failure: Hand count is incorrect.");
	}
		
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("Failure: Deck count is incorrect.");
	}
	
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	if(testG.coins != G.coins + xtraCoins){
		printf("Failure: Coin count is incorrect.");
	}
	/*---------------------------------------------------------*/
	
	printf("\n---Testing Choice 2: Current player Receives 2 coins---\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 2;
	cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);

	//receiving 2 coins, no new cards
	newCards = 0;
	xtraCoins = 2;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("Failure: Hand count is incorrect.");
	}
	
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("Failure: Deck count is incorrect.");
	}
	
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	if(testG.coins != G.coins + xtraCoins){
		printf("Failure: Coin count is incorrect.  Should have received 2 coins.");
	}
	/*---------------------------------------------------------*/

	printf("\n---Testing Choice 3: Player Trashes 2 cards---\n");
	choice1 = 3;

	// cycle through each eligible combination of 2 cards to trash
	for (i=1; i<G.handCount[thisPlayer]; i++) {
		for (j=i+1; j<G.handCount[thisPlayer]; j++) {

			G.hand[thisPlayer][0] = steward;
			G.hand[thisPlayer][1] = copper;
			G.hand[thisPlayer][2] = duchy;
			G.hand[thisPlayer][3] = estate;
			G.hand[thisPlayer][4] = feast;

			memcpy(&testG, &G, sizeof(struct gameState));

			printf("starting cards: ");
			for (m = 0; m < testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf("; ");

			choice2 = j;
			choice3 = i;
			remove1 = testG.hand[thisPlayer][i];
			remove2 = testG.hand[thisPlayer][j];
			cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);

			printf("removed: (%d)(%d); ", remove1, remove2);
			printf("ending cards: ");

			// Verify that the trashed cards were removed from the player's hand
			for (m = 0; m < testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
				assert(testG.hand[thisPlayer][m] != remove1);
				assert(testG.hand[thisPlayer][m] != remove2);
			}
			printf(", expected: ");
			for (m = 1; m < G.handCount[thisPlayer]; m++) {
				if (G.hand[thisPlayer][m] != G.hand[thisPlayer][i] && G.hand[thisPlayer][m] != G.hand[thisPlayer][j]) {
					printf("(%d)", G.hand[thisPlayer][m]);
				}
			}
			printf("\n");

			// Verify that the remaining number of cards is correct
			newCards = 0;
			xtraCoins = 0;
			discarded = 3;
			if (i==1 && j==2) {
				printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
				if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
					printf("Failure: Hand count is incorrect.");
				}
				
				printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
				if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
					printf("Failure: Deck count is incorrect.");
				}
			}
		}
	}
	
	/*---------------------------------------------------------*/
	
	printf ("\n----------Testing the Steward card's effect on Player 2:----------\n");
	// Checks whether player 1's Steward card affected player 2's hand count, deck count, or discard count.
	printf("hand count = %d, expected %d\n", testG.handCount[secPlayer], G.handCount[secPlayer]);
	if(testG.handCount[secPlayer] != G.handCount[secPlayer]){
		printf("Failure: Player 2's hand count was modified.\n\n");
	}
	
	printf("deck count = %d, expected %d\n", testG.deckCount[secPlayer], G.deckCount[secPlayer]);
	if(testG.deckCount[secPlayer] != G.deckCount[secPlayer]){
		printf("Failure: Player 2's deck count was modified.\n\n");
	}
	
	printf("discard count = %d, expected %d\n\n", testG.discardCount[secPlayer], G.discardCount[secPlayer]);
	if(testG.discardCount[secPlayer] != G.discardCount[secPlayer]){
		printf("Failure: Player 2's deck count was modified.\n\n");
	}
	printf("---Steward card's testing is complete--- \n\n");
	return 0;
}


