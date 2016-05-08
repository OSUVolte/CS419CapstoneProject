/***
Name: Tiffany Chiou
Assignment: 3
Testcase: unittest3.c
Testing Function: fullDeckCount function in dominion.c
***/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
- When testing, we will want to make sure that the number of cards in the deck, hand, and discard pile do not change
- The deck, hand, discard counts should not change
- The overall number of any specific card should be accurate and should not change after fullDeckCount is called
- Other player's deck, hand, discard pile should not change
- Other player's deck, hand, discard counts should not change
**/

struct gStates {
	struct gameState* gS;
	struct gameState* original;
	int cards[MAX_DECK]; // keeps track of different kinds of cards in full deck
	int numUnique; // number of unique types of cards
};

void checkCount(struct gStates* states, int current, int card, int numPlay) {

	int fullCount = fullDeckCount(current,card,states->gS);
	int originalCount = 0, i, fail=0,a;
	// calculate number of cards with original, then compare with the fullCount result
	// first calculate from deck
	for (i=0; i<states->original->deckCount[current]; i++) {
		if (states->original->deck[current][i] == card)
			originalCount = originalCount + 1;
	}
	// calculate from hand
	for (i=0; i<states->original->handCount[current]; i++) {
		if (states->original->hand[current][i] == card)
			originalCount = originalCount + 1;
	}
	// calculate from discard pile
	for (i=0; i<states->original->discardCount[current]; i++) {
		if (states->original->discard[current][i] == card)
			originalCount = originalCount + 1;
	}
//	printf("%d %d\n",fullCount, originalCount);

	// make sure the count is correct
	if (fullCount == originalCount)
		printf("\nSUCCESS: fullDeckCount returned the right number of cards!\n");
	else
		printf("\nFAILURE: The wrong number of cards was returned.\n");

	printf("\nPlayer %d is the current player.\n",current);
	for (a=0;a<numPlay;a++) {
		// make sure deck count is not changed
		printf("\nPlayer %d:\n",a);
		if (states->gS->deckCount[a] == states->original->deckCount[current]) {
			printf("SUCCESS: The Deck count was unchanged.\n");

			// make sure deck is not changed
			for (i=0; i<states->gS->deckCount[a]; i++) {
				if (states->gS->deck[a][i] != states->original->deck[current][i])
					fail = 1;
			}

			if (fail == 1) {
				printf("FAILURE: The deck was wrongfully changed.\n");
				fail = 0;
			} else {
				printf("SUCCESS: The deck was not changed.\n");
				fail = 0;
			}

		} else
			printf("FAILURE: The Deck count was changed.\n");


		// make sure hand count is not changed
		if (states->gS->handCount[a] == states->original->handCount[current]) {
			printf("SUCCESS: The Hand count was unchanged.\n");

			// make sure hand is not changed
			for (i=0; i<states->gS->handCount[a]; i++) {
				if (states->gS->hand[a][i] != states->original->hand[current][i])
					fail = 1;
			}

			if (fail == 1) {
				printf("FAILURE: The deck was wrongfully changed.\n");
				fail = 0;
			} else {
				printf("SUCCESS: The deck was not changed.\n");
				fail = 0;
			}

		} else
			printf("FAILURE: The Hand count was changed.\n");


		// make sure discard count is not changed
		if (states->gS->discardCount[a] == states->original->discardCount[current]) {
			printf("SUCCESS: The Discard count was unchanged.\n");

			// make sure discard pile is not changed
			for (i=0; i<states->gS->discardCount[a]; i++) {
				if (states->gS->discard[a][i] != states->original->discard[current][i])
					fail = 1;
			}

			if (fail == 1) {
				printf("FAILURE: The deck was wrongfully changed.\n");
				fail = 0;
			} else {
				printf("SUCCESS: The deck was not changed.\n");
				fail = 0;
			}

		} else
			printf("FAILURE: The Discard count was changed.\n");

	}
}

/**
Sets up the inputs for testing
Gets num values for num cards in deck, hand, and discard pile
**/
struct gStates* prepareStates(int dCount, int hCount, int disCount, int current) {
	struct gStates* states = (struct gStates*)malloc(sizeof(struct gStates));
	struct gameState* gS = (struct gameState*)malloc(sizeof(struct gameState));
	struct gameState* original = (struct gameState*)malloc(sizeof(struct gameState));

	int k[10] = {adventurer, baron, steward, ambassador, smithy, feast, tribute, mine, sea_hag, outpost};
	int i,j,choice;

// initialize cards array
	for (j=0;j<10;j++) {
		states->cards[j] = k[j];
	}
	states->cards[10] = copper;
	states->cards[11] = silver;
	states->numUnique = 12;

// fill up deck
	for (i=0;i<dCount;i++) {
		// half the deck are treasure cards
		if (i < (dCount/2)) {
			if (i%2 == 0) {
				gS->deck[0][i] = copper;
				gS->deck[1][i] = copper;
				gS->deck[2][i] = copper;
				gS->deck[3][i] = copper;
				original->deck[current][i] = copper;
			} else {
				gS->deck[0][i] = silver;
				gS->deck[1][i] = silver;
				gS->deck[2][i] = silver;
				gS->deck[3][i] = silver;
				original->deck[current][i] = silver;
			}
			continue;
		}
		// other half of deck are adventure cards
		gS->deck[0][i] = k[1];
		gS->deck[1][i] = k[1];
		gS->deck[2][i] = k[1];
		gS->deck[3][i] = k[1];
		original->deck[current][i] = k[1];
	}
	gS->deckCount[0] = dCount;
	gS->deckCount[1] = dCount;
	gS->deckCount[2] = dCount;
	gS->deckCount[3] = dCount;
	original->deckCount[current] = dCount; 

// fill up hand 
	for (i=0;i<hCount;i++) {
		// half the hand are treasure cards
		if (i < (hCount/2)) {
			if (i%2 == 0) {
				gS->hand[0][i] = copper;
				gS->hand[1][i] = copper;
				gS->hand[2][i] = copper;
				gS->hand[3][i] = copper;
				original->hand[current][i] = copper;
			} else {
				gS->hand[0][i] = silver;
				gS->hand[1][i] = silver;
				gS->hand[2][i] = silver;
				gS->hand[3][i] = silver;
				original->hand[current][i] = silver;
			}
			continue;
		}
		// other half of hand are adventure cards
		gS->hand[0][i] = k[2];
		gS->hand[1][i] = k[2];
		gS->hand[2][i] = k[2];
		gS->hand[3][i] = k[2];
		original->hand[current][i] = k[2];
	}
	gS->handCount[0] = hCount;
	gS->handCount[1] = hCount;
	gS->handCount[2] = hCount;
	gS->handCount[3] = hCount;
	original->handCount[current] = hCount; 

// fill up discard pile
	for (i=0;i<disCount;i++) {
		// half the discard pile are treasure cards
		if (i < (disCount/2)) {
			if (i%2 == 0) {
				gS->discard[0][i] = copper;
				gS->discard[1][i] = copper;
				gS->discard[2][i] = copper;
				gS->discard[3][i] = copper;
				original->discard[current][i] = copper;
			} else {
				gS->discard[0][i] = silver;
				gS->discard[1][i] = silver;
				gS->discard[2][i] = silver;
				gS->discard[3][i] = silver;
				original->discard[current][i] = silver;
			}
			continue;
		}
		// other half of discard pile are adventure cards
		choice = 6; 
		gS->discard[0][i] = k[choice];
		gS->discard[1][i] = k[choice];
		gS->discard[2][i] = k[choice];
		gS->discard[3][i] = k[choice];
		original->discard[current][i] = k[choice];
	}
	gS->discardCount[0] = disCount;
	gS->discardCount[1] = disCount;
	gS->discardCount[2] = disCount;
	gS->discardCount[3] = disCount;
	original->discardCount[current] = disCount; 

	states->gS = gS;
	states->original = original;
	return states;
}



int main() {

	printf("\n-----Testing fullDeckCount function with unittest3.c-----\n");
	struct gStates* states = NULL;
	int i, current = 1;
	states = prepareStates(5,10,12,current);
	int numPlay = 2;
	// calculates the full count for a different card each cycle
	for (i=0; i<states->numUnique; i++) {
		printf("\nTesting for a different card: \n");
		checkCount(states,1,states->cards[i],numPlay);
	}	
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

	return 0;
}