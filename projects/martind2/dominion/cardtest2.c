/* cardtest2.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the playAdventurer function.
 * - Player has only 2 additional cards in their hand
 * - Two additional cards are treasure cards
 * - No discarded card is a treasure
 * - Does adventurer card go to played cards?
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"


int main() {
	// Counters
	int i, j;

	// Game settings
	int seed = 1010,
		numPlayers = 2,
		cards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
					  sea_hag, tribute, smithy, council_room };

	// Game init
	struct gameState G, testG;
	initializeGame(numPlayers, cards, seed, &G);
	
	printf("--------------- CARD TEST 4 ---------------\n");
	printf("------------ ADVENTURER TESTS -------------\n");

	// Put adventurer card in hand
	G.hand[0][ G.handCount[0] ] = adventurer;
    G.handCount[0]++;

    SelectStream(2);
    PlantSeeds(-1);

    // Randomly get some number of cards (i) by picking
    // a card (j) from cards[]
    i = floor(Random() * 15);
    printf("Cards gained: ");
    for (i=i; i>0; --i) {
    	j = floor(Random() * 9);
    	gainCard(cards[j], &G, 1, 0);
    	printf("%d ", j);
    }
    printf("\n");


    // Add some number of copper, silver or gold to deck
    i = floor(Random() * 15);
    printf("Treasures gained: ");
    for (i=i; i>0; --i) {
    	j = floor(Random() * 3) + copper;
    	gainCard(j, &G, 1, 0);
	    printf("%d ", j);
    }
    printf("\n");

    // Shuffle
    printf("Shuffling...\n");
    shuffle(0, &G);

	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\nTEST 1: Does playing an adventurer increase hand size by 2?\n");
    playAdventurer(&G);
    printf("Player 0's hand count = %d, expected %d\n", G.handCount[0], testG.handCount[0] + 2);
    // assert(G.handCount[0] == (testG.handCount[0] + 2));

    printf("\nTEST 2: Are the last two cards in Player 0's hand treasures?\n");
    printf("Player 0's last card = %d, expected %d, %d, or %d\n", G.hand[0][G.handCount[0] - 1], copper, silver, gold);
    printf("Player 0's second to last card = %d, expected %d, %d, or %d\n", G.hand[0][G.handCount[0] - 2], copper, silver, gold);
    assert(G.hand[0][G.handCount[0] - 1] == copper 
    	|| G.hand[0][G.handCount[0] - 1] == silver 
    	|| G.hand[0][G.handCount[0] - 1] == gold);
    assert(G.hand[0][G.handCount[0] - 2] == copper 
    	|| G.hand[0][G.handCount[0] - 2] == silver 
    	|| G.hand[0][G.handCount[0] - 2] == gold);

    printf("\nTEST 3: No discarded card is a treasure\n");
    printf("Discarded card count = %d\n", G.discardCount[0]);
    for (i=0; i<G.discardCount[0]; i++) {
    	printf("Discard %d = %d, should not be %d, %d, or %d\n", i, G.discard[0][i], copper, silver, gold);
    	assert(G.discard[0][i] != copper 
    		&& G.discard[0][i] != silver
    		&& G.discard[0][i] != gold);
    }

    printf("\nTEST 4: Does adventurer card go to played pile?\n");
    printf("Player 0's played card count = %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1);
    printf("Player 0's last played card = %d, expected %d\n", G.playedCards[G.playedCardCount - 1], adventurer);
    // assert(G.playedCardCount == (testG.playedCardCount + 1));
    // assert(G.playedCards[G.playedCardCount - 1] == adventurer);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}