/***
Name: Tiffany Chiou
Assignment: 3
Testcase: unittest2.c
Testing Function: shuffle function in dominion.c
***/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
Testing shuffle function in dominion.c
- Want to make sure deckCount stays the same
- Make sure although shuffled, the same exact cards are in the deck
- This can be done by comparing the original deck with the new deck
- If the deck is empty, the function should return with -1
- The other player's deck should be untouched
- Deck should be shuffled so cards should not be in their original order
- Make sure handCount, discardCount stay the same for current player and other players
**/

struct originalDeck {
	int deck[MAX_DECK];
	int deckCount;
	int other[4]; // lists idx of other players
	int numPlayers; // number of other players
	int handCount;
	int discardCount;
};

void testShuffle (struct gameState* gS, int current, struct originalDeck* oD) {
	// implement the shuffle function
	int res = shuffle(current,gS);

	int i, idx, j, fail=0;
	int numCards = 0;

	// if the deck is empty, this should be correctly detected by shuffle
	if (res == -1) {
		if (gS->deckCount[current] == 0)
			printf("SUCCESS: The deck was detected to be empty.\n");
		else
			printf("FAILURE: The deck was incorrectly detected to be empty.\n");
		return;
	}
	printf("SUCCESS: The deck was correctly detected as not empty.\n");
	
	// make sure deck count is correct
	if (gS->deckCount[current] == oD->deckCount) {
		printf("SUCCESS: The deck count is correct.\n");
		// make sure the deck cards are correct, should be the same cards as the original deck
		idx = 0;
		for (i=0;i<oD->deckCount;i++) {
			for (j=0;j<oD->deckCount;j++) {
				// everytime a card in the original deck is found in the current player's deck, set the
				// current player's card to -1 and numCards variable increments by 1
				if (oD->deck[i] == gS->deck[current][j]) {
					gS->deck[current][j] = -1;
					numCards = numCards+1;
					break; // break out of the inner for loop
				}
			}
		}
		if (numCards == oD->deckCount)
			printf("SUCCESS: The current player's shuffled deck has the same cards as the original deck.\n");
		else
			printf("FAILURE: The current player's shuffled and original cards have different cards.\n");

		// checks to make sure the deck is not in the same order as before
		numCards = 0;
		for (i=0;i<oD->deckCount;i++) {
			if (oD->deck[i] == gS->deck[current][i])
				numCards = numCards+1;
		}
		if (numCards == oD->deckCount)
			printf("FAILURE: The current player's deck was not shuffled!\n");
		else
			printf("SUCCESS: The current player's deck was shuffled.\n");

		// make sure handcount and discard count was not wrongfully modified
		if (gS->handCount[current] == oD->handCount)
			printf("SUCCESS: The current player's hand count was not modified.\n");
		else
			printf("FAILURE: The current player's hand count was wrongfully modified.\n");

		if (gS->discardCount[current] == oD->discardCount)
			printf("SUCCESS: The current player's discard count was not modified.\n");
		else
			printf("FAILURE: The current player's discard count was wrongfully modified.\n");

	} else
		printf("FAILURE: The current player's deck count is incorrect. It may be missing or has invalid cards.\n");

	// check other players' deck(s)
	for (i=0;i<oD->numPlayers;i++) {
		idx = oD->other[i];
		// deck count should be the same
		if (gS->deckCount[idx] == oD->deckCount)
		printf("SUCCESS: Player %d's deck count is correct.\n",idx);
		else {
			printf("FAILURE: Player %d's deck count is incorrect. The deck was wrongfully modified.\n",idx);
			continue;
		}
		// check each individual card in the deck
		for (j=0;j<oD->deckCount;j++) {
			if (gS->deck[idx][j] != oD->deck[j]) {
				printf("FAILURE: Player %d's deck was wrongfully modified.\n",idx);
				fail = 1;
				break;
			}
		}
		if (fail == 0)
			printf("SUCCESS: Player %d's deck was not modified.\n",idx);
		else
			fail = 0; //reset


		// make sure handcount and discard count was not wrongfully modified
		if (gS->handCount[idx] == oD->handCount)
			printf("SUCCESS: Player %d's hand count was not modified.\n",idx);
		else
			printf("FAILURE: Player %d's hand count was wrongfully modified.\n",idx);

		if (gS->discardCount[idx] == oD->discardCount)
			printf("SUCCESS: Player %d's discard count was not modified.\n",idx);
		else
			printf("FAILURE: Player %d's discard count was wrongfully modified.\n",idx);


	}

}

int main() {
	int i, current=1, choice, other=0,j;
	int k[10] = {adventurer, baron, steward, ambassador, smithy, feast, tribute, mine, sea_hag, outpost};
	struct gameState* gS = NULL;
	struct originalDeck* oD = NULL;
	// initialize gameState struct and originalDeck struct

	printf("\n-----Testing shuffle function with unittest2.c-----\n");
	// test a game with 2 players that have 15 cards each
	gS = (struct gameState*)malloc(sizeof(struct gameState));
	oD = (struct originalDeck*)malloc(sizeof(struct originalDeck));
	// manually assign deck with 15 cards
	gS->numPlayers=2;
	oD->numPlayers=gS->numPlayers-1; // number of other players
	printf("\nTesting deck of 15 cards and 2 players\n");
	gS->deckCount[current] = 15;
	gS->deckCount[other] = 15;
	oD->deckCount = 15;
	oD->other[0] = 0;
	// set hand count
	gS->handCount[current] = 5;
	gS->handCount[other] = 5;
	oD->handCount = 5;
	// set discard count
	gS->discardCount[current] = 3;
	gS->discardCount[other] = 3;
	oD->discardCount = 3;
	for (i=0;i<gS->deckCount[current];i++) {
		// the first 10 cards will be treasure cards
		if (i < 10) {
			if (i<5) {
				gS->deck[current][i] = copper;
				gS->deck[other][i] = copper;
				oD->deck[i] = copper;
			} else {
				gS->deck[current][i] = silver;
				gS->deck[other][i] = silver;
				oD->deck[i] = silver;
			}
			continue;
		}
		// the next 5 cards are adventure cards
		for (j=0; j<5;j++) {
			gS->deck[current][i] = k[j];
			gS->deck[other][i] = k[j];
			oD->deck[i] = k[j];
		}
	}
	// test shuffle function with deck
	testShuffle(gS,current,oD);
	free (gS);
	free (oD);

 	// test a game with 3 players that have 0 cards each
	gS = (struct gameState*)malloc(sizeof(struct gameState));
	oD = (struct originalDeck*)malloc(sizeof(struct originalDeck));
	// manually assign deck with 15 cards
	gS->numPlayers=3;
	oD->numPlayers=gS->numPlayers-1; // number of other players
	printf("\nTesting deck of 0 cards and 3 players\n");
	current = 2;
	gS->deckCount[current] = 0;
	gS->deckCount[0] = 0;
	gS->deckCount[1] = 0;
	oD->deckCount = 0;
	// indicies of other players
	oD->other[0] = 0;
	oD->other[1] = 1;
	// set hand count
	gS->handCount[current] = 3;
	gS->handCount[0] = 3;
	gS->handCount[1] = 3;
	oD->handCount = 3;
	// set discard count
	gS->discardCount[current] = 13;
	gS->discardCount[0] = 13;
	gS->discardCount[1] = 13;
	oD->discardCount = 13;
	// test shuffle function with deck
	testShuffle(gS,current,oD);
	free (gS);
	free (oD);

	// test a game with 4 players that have 10 cards each
	gS = (struct gameState*)malloc(sizeof(struct gameState));
	oD = (struct originalDeck*)malloc(sizeof(struct originalDeck));
	// manually assign deck with 15 cards
	gS->numPlayers=4;
	oD->numPlayers=gS->numPlayers-1; // number of other players
	printf("\nTesting deck of 10 cards and 4 players\n");
	current = 0;
	gS->deckCount[current] = 10;
	gS->deckCount[1] = 10;
	gS->deckCount[2] = 10;
	gS->deckCount[3] = 10;
	oD->deckCount = 10;
	// indicies of other players
	oD->other[0] = 1;
	oD->other[1] = 2;
	oD->other[2] = 3;
	// set hand count
	gS->handCount[current] = 5;
	gS->handCount[1] = 5;
	gS->handCount[2] = 5;
	gS->handCount[3] = 5;
	oD->handCount = 5;
	// set discard count
	gS->discardCount[current] = 9;
	gS->discardCount[1] = 9;
	gS->discardCount[2] = 9;
	gS->discardCount[3] = 9;
	oD->discardCount = 9;
	for (i=0;i<gS->deckCount[current];i++) {
		// the first 15 cards will be treasure cards
		if (i < 5) {
			if (i%2==0) {
				gS->deck[current][i] = copper;
				gS->deck[1][i] = copper;
				gS->deck[2][i] = copper;
				gS->deck[3][i] = copper;
				oD->deck[i] = copper;
			} else {
				gS->deck[current][i] = silver;
				gS->deck[1][i] = silver;
				gS->deck[2][i] = silver;
				gS->deck[3][i] = silver;
				oD->deck[i] = silver;
			}
			continue;
		}
		// the next 5 cards are adventure cards
	for (j=0; j<5;j++) {
		gS->deck[current][i] = k[j];
		gS->deck[1][i] = k[j];
		gS->deck[2][i] = k[j];
		gS->deck[3][i] = k[j];
		oD->deck[i] = k[j];
	}

	}
	// test shuffle function with deck
	testShuffle(gS,current,oD);
	free (gS);
	free (oD);
}