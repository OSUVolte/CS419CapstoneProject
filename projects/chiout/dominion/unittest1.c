/***
Name: Tiffany Chiou
Assignment: 3
Testcase: unittest1.c
Testing Function: discardCard function in dominion.c
***/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
Testcase Details:
- If a player is trashing a card, then the playedCardCount and the playedCards array should not change.
- If a player is discarding a card, then the card should be added to the playedCards array
- Testcase assumes new discarded are added to the last position in the array.
- In addition, the player's hand needs to be reorganized, depending on which card is removed.
- If the last card is removed, then all cards up to that card should be the same.
- If any other card is removed, then its position is replaced by the last card in the player's hand.
- Make sure other player's hands and discard stay the same
**/

void checkDiscard (struct gameState* gS, int currentPlayer,int handPos, int trashFlag, int numPlayers) {

	// make copy of hand array and handCount details for the current player
	int handCount = gS->handCount[currentPlayer];
	int otherCount = gS->handCount[currentPlayer];
	int playerHand[MAX_DECK];
	int other[MAX_DECK]; // use to compare to other players
	int i,a,b;
	for (i=0;i<gS->handCount[currentPlayer];i++) {
		playerHand[i] = gS->hand[currentPlayer][i];
		other[i] = gS->hand[currentPlayer][i];
	}
	// make copy of playedCard array and playedCard details
	int playedCards[MAX_DECK];
	int playedCardCount = gS->playedCardCount;
	int fail=0;
	for (i=0;i<gS->playedCardCount;i++) 
		playedCards[i] = gS->playedCards[i];

	// make copy of discard array and discard details
	int discard[MAX_DECK];
	int discardCount = gS->discardCount[currentPlayer];
	for (i=0;i<gS->discardCount[currentPlayer];i++) 
		discard[i] = gS->discard[currentPlayer][i];

	int pIdx = playedCardCount;
	int dIdx = discardCount;

// run discardcard
	if (discardCard(handPos,currentPlayer,gS,trashFlag) == 0) {

		printf("\nCurrent Player:\n");
		if (trashFlag < 1) {
			// means that the card is discarded - should be added to played card file
			printf("Card is discarded.\n");
			// update our array copy
			playedCards[playedCardCount] = playerHand[handPos];
			playedCardCount = playedCardCount + 1;
			if (gS->playedCardCount == playedCardCount) {
				printf("SUCCESS: Played card count has increased by 1.\n");
			} else
				printf("FAILURE: Played card count is not correct (array was not updated with discarded card).\n");
		} else {
			// means the card is trashed
			printf("Card is not trashed.\n");
			// update our array copy
			if (gS->playedCardCount == playedCardCount) {
				printf("SUCCESS: Played card count has not changed.\n");
			} else
				printf("FAILURE: Played card count is not correct.\n");
		}

		// check played card array if it has changed and for trashed card
		for (i=0; i<playedCardCount;i++) {
			if (gS->playedCards[i] != playedCards[i]) {
				fail = 1;
				printf("FAILURE: The played card pile contains missing or invalid cards.\n");
				break;
			}
		}	
		if (fail == 0 && trashFlag == 0)
			printf("SUCCESS: The played card pile contains correct cards.\n");
		else if (fail == 0 && trashFlag > 0) {
// make sure a card is not added to the played cards array mistakenly
			if (gS->playedCards[pIdx] == playerHand[handPos])
				printf("FAILURE: The played card pile contains invalid cards.\n");
			else
				printf("SUCCESS: The played card pile contains correct cards.\n");			
		} else
			fail = 0; // reset fail flag			


		// now check the hand count and hand array
		// handCount should decrement by 1
		if (gS->handCount[currentPlayer] == handCount -1)
			printf("SUCCESS: Hand count is correct.\n");
		else
			printf("FAILURE: Hand count is not correct.\n");

		if ((handCount-1) > 0) {
			// if card position is last, verify hand array
			// the hand array should be the same up until the card before the one that is removed
			if (handPos == handCount-1) {
				for (i=0;i<(handCount-1);i++) {
					if (gS->hand[currentPlayer][i] != playerHand[i])
						fail = 1; // set fail to 1
				}
				//printf("Removed card is the last one in the player's hand.\n");
			} else {
				// if card position isn't last, verify hand array
				// the removed card should be replaced with the last card in hand array
				//printf("Removed card is not the last one in the player's hand.\n");
				for (i=0;i<(handCount-1);i++) {
					if (i == handPos) {
						if (gS->hand[currentPlayer][i] != playerHand[handCount-1]) {
							printf("FAILURE: Removed card was not replaced by the last card in hand.\n");
							fail = -1;
						} 
						continue;
					}
					if (gS->hand[currentPlayer][i] != playerHand[i]) {
						fail = -1;
					}
				}
			}
		} else {
			// if there are no more cards in the player's hand, make sure this is correctly reflected
			printf("Note: No more cards in the player's hand!\n");
			if (gS->handCount[currentPlayer] == 0)
				printf("SUCCESS: Hand count is correctly recorded as 0.\n");
			else
				printf("FAILURE: Hand count is not correctly recorded as 0.\n");
		}
		// report any failures
		if (fail == 0)
			printf("SUCCESS: Hand array is correct.\n");
		else {
			printf("FAILURE: Hand array is not correct.\n");
			fail = 0;// reset fail flag
		}

		// make sure discard array is the same
		fail = 0;
		for (i=0; i<discardCount;i++) {
			if (gS->discard[currentPlayer][i] != discard[i]) {
				fail = 1;
				break;
			}
		}	
		if (fail == 0)
			printf("SUCCESS: The discard array has not changed.\n");
		else
			printf("FAILURE: The discard array has changed.\n");

	// check other player's hand & discard; should be the same
		printf("\nOther Players:\n");
		for (a=0;a<numPlayers;a++) {
			if (a == currentPlayer)
				continue; // skip current player
			fail = 0;
			// check other players' hand count and pile
			if (otherCount == gS->handCount[a]) {
				printf("SUCCESS: Player %d's hand count is correct.\n",a);

				for (b=0;b<otherCount;b++) {
					if (other[b]!=gS->hand[a][b]) {
						fail = 1;
						break;
					}
				}

				if (fail == 0)
					printf("SUCCESS: Player %d's hand is correct.\n",a);
				else
					printf("FAILURE: Player %d's hand is incorrect.\n",a);
				fail = 0;
			} else {
				printf("FAILURE: Player %d's hand count is incorrect.\n",a);
			}
			fail = 0;
			// now check other players's discard count and pile
			if (discardCount == gS->discardCount[a]) {
				printf("SUCCESS: Player %d's discard count is correct.\n",a);

				for (b=0;b<discardCount;b++) {
					if (discard[b]!=gS->discard[a][b]) {
						fail = 1;
						break;
					}
				}

				if (fail == 0)
					printf("SUCCESS: Player %d's discard pile is correct.\n",a);
				else
					printf("FAILURE: Player %d's discard pile is incorrect.\n",a);
				fail = 0;
			} else {
				printf("FAILURE: Player %d's discard count is incorrect.\n",a);
			}


		}



	}
}

/**
Sets up the inputs for testing
Gets num values for num cards in deck, hand, and discard pile
**/
struct gameState* prepareStates(int pCount, int hCount, int disCount, int current) {
	struct gameState* gS = (struct gameState*)malloc(sizeof(struct gameState));

	int k[10] = {steward, baron, adventurer, ambassador, smithy, mine, tribute, feast, sea_hag, outpost};
	int i,j,choice;


// fill up playedCards
	for (i=0;i<pCount;i++) {
		// half the deck are treasure cards
		if (i < (pCount/2)) {
			if (i%2 == 0) {
				gS->playedCards[i] = copper;
			} else {
				gS->playedCards[i] = silver;
			}
			continue;
		}
		// other half of deck are adventure cards
		gS->playedCards[i] = k[1];
	}
	gS->playedCardCount = pCount;


// fill up hand 
	for (i=0;i<hCount;i++) {
		// half the hand are treasure cards
		if (i < (hCount/2)) {
			if (i%2 == 0) {
				gS->hand[0][i] = copper;
				gS->hand[1][i] = copper;
				gS->hand[2][i] = copper;
				gS->hand[3][i] = copper;
			} else {
				gS->hand[0][i] = silver;
				gS->hand[1][i] = silver;
				gS->hand[2][i] = silver;
				gS->hand[3][i] = silver;
			}
			continue;
		}
		// other half of hand are adventure cards
		gS->hand[0][i] = k[2];
		gS->hand[1][i] = k[2];
		gS->hand[2][i] = k[2];
		gS->hand[3][i] = k[2];
	}
	gS->handCount[0] = hCount;
	gS->handCount[1] = hCount;
	gS->handCount[2] = hCount;
	gS->handCount[3] = hCount;

// fill up discard pile
	for (i=0;i<disCount;i++) {
		// half the discard pile are treasure cards
		if (i < (disCount/2)) {
			if (i%2 == 0) {
				gS->discard[0][i] = copper;
				gS->discard[1][i] = copper;
				gS->discard[2][i] = copper;
				gS->discard[3][i] = copper;
			} else {
				gS->discard[0][i] = silver;
				gS->discard[1][i] = silver;
				gS->discard[2][i] = silver;
				gS->discard[3][i] = silver;
			}
			continue;
		}
		// other half of discard pile are adventure cards
		choice = 6; 
		gS->discard[0][i] = k[choice];
		gS->discard[1][i] = k[choice];
		gS->discard[2][i] = k[choice];
		gS->discard[3][i] = k[choice];
	}
	gS->discardCount[0] = disCount;
	gS->discardCount[1] = disCount;
	gS->discardCount[2] = disCount;
	gS->discardCount[3] = disCount;

	return gS;
}


int main () {

	// initialize necessary variables
	struct gameState* gS = NULL;
	int k[10] = {adventurer, baron, steward, ambassador, smithy, feast, tribute, mine, sea_hag, outpost};
	int numPlayers = 2;
	int success, handPos, trashFlag, numP, numH;
	// initialize new game
	int currentP = 0;
	printf("\n-----Testing discardCard function with unittest1.c-----\n");
	handPos = 2;
	trashFlag = 1;
	numP = 2;
	numH = 3;
	gS = prepareStates(5, numH, 2, currentP); 
	printf("\nTesting with handPos: %d (%d cards), trashFlag: %d, and %d players\n", handPos, numH, trashFlag, numP);
	checkDiscard(gS,currentP,handPos,trashFlag,numP);
	free(gS);

	handPos = 0;
	trashFlag = 0;
	numP = 3;
	currentP = 2;
	numH = 1;
	gS = prepareStates(10, numH, 4, currentP); 
	printf("\nTesting with handPos: %d (%d cards), trashFlag: %d, and %d players\n", handPos, numH, trashFlag, numP);
	checkDiscard(gS,currentP,handPos,trashFlag,numP);
	free(gS);

	handPos = 1;
	trashFlag = 1;
	numP = 4;
	currentP = 2;
	numH = 5;
	gS = prepareStates(16, numH, 8, currentP); 
	printf("\nTesting with handPos: %d (%d cards), trashFlag: %d, and %d players\n", handPos, numH, trashFlag, numP);
	checkDiscard(gS,currentP,handPos,trashFlag,numP);
	free(gS);

	handPos = 2;
	trashFlag = 0;
	numP = 3;
	currentP = 1;
	numH = 4;
	gS = prepareStates(0, numH, 2, currentP); 
	printf("\nTesting with handPos: %d (%d cards), trashFlag: %d, and %d players\n", handPos, numH, trashFlag, numP);
	checkDiscard(gS,currentP,handPos,trashFlag,numP);
	free(gS);

	return 0;
}
