/***
Name: Tiffany Chiou
Assignment: 3
Testcase: cardtest2.c
Testing Function: smithy card in dominion.c
***/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct gStates {
	struct gameState* gS;
	struct gameState* original;
	int cards[MAX_DECK]; // keeps track of different kinds of cards in full deck
	int numUnique; // number of unique types of cards
};

/**
Things to test for:
- Player's hand should have 2 additional cards
- Playedcardcount should increase by 1
- playedcardcount+discard+deck+hand count should be the same
- Missing 3 cards in deck+discard should be in the player's hand or the played card pile
- Other player's hand, deck, and discard count should be unchanged
**/
void testingSmithy (struct gStates* states, int currentPlayer, int handPos, int numPlay) {
	int temp[MAX_DECK];
	int temp2[MAX_DECK];
	int cards[MAX_DECK];
	int cardsCount=0, tempCount,count, tempCount2;
	int res,i,j,found,a;
	states->gS->whoseTurn=currentPlayer;
	int total, gSTotal;
	int hCount, dCount, disCount;

	hCount = states->original->handCount[currentPlayer];
	dCount = states->original->deckCount[currentPlayer];
	disCount = states->original->discardCount[currentPlayer];
	// calculate total number of cards in discard+hand+deck+ played count
	total = states->original->handCount[currentPlayer] + states->original->deckCount[currentPlayer];
	total = total + states->original->discardCount[currentPlayer] + states->original->playedCardCount;

	// play smithy card
	res = cardEffect(smithy,0,0,0,states->gS,handPos,NULL);

	printf("\nCurrent Player:\n");
	// evaluate player's hand
	if (states->gS->handCount[currentPlayer] == states->original->handCount[currentPlayer]+2)
		printf("SUCCESS: The player's hand count shows a net gain of 2 cards.\n");
	else if (states->gS->handCount[currentPlayer] > states->original->handCount[currentPlayer]+2)
		printf("FAILURE: The player's hand count shows a net gain of more than 2 cards.\n ");
	else
		printf("FAILURE: The player's hand count shows a net gain of less than 2 cards or net loss.\n ");

	// check played card count
	if (states->gS->playedCardCount == states->original->playedCardCount+1)
		printf("SUCCESS: The player's played card count increased by 1.\n");
	else if (states->gS->playedCardCount > states->original->playedCardCount+1)
		printf("FAILURE: The player's played card count increased by more than 1.\n");
	else
		printf("FAILURE: The player's played card count did not change or decreased.\n");

	// compare total card counts
	// calculate total number of cards in discard+hand+deck+ played count
	gSTotal = states->gS->handCount[currentPlayer] + states->gS->deckCount[currentPlayer];
	gSTotal = gSTotal + states->gS->discardCount[currentPlayer] + states->gS->playedCardCount;

	if (gSTotal == total)
		printf("SUCCESS: The player's total card count is correct.\n");
	else

		printf("FAILURE: The player's total card count is incorrect.\n");

	// combine cards from the deck and discard pile into the temp array
	tempCount=0;
	for (i=0;i<states->original->deckCount[currentPlayer];i++) {
		temp[tempCount] = states->original->deck[currentPlayer][i];
		tempCount++;
	}
	for (i=0;i<states->original->discardCount[currentPlayer];i++) {
		temp[tempCount] = states->original->discard[currentPlayer][i];
		tempCount++;
	}		
	// temp2 should have 3 less cards than temp
	tempCount2=0;
	for (i=0;i<states->gS->deckCount[currentPlayer];i++) {
		temp2[tempCount2] = states->gS->deck[currentPlayer][i];
		tempCount2++;
	}
	for (i=0;i<states->gS->discardCount[currentPlayer];i++) {
		temp2[tempCount2] = states->gS->discard[currentPlayer][i];
		tempCount2++;
	}

	// compare temp and temp2 - temp2 should be missing 3 cards that are in temp
	// place those 3 cards in cards[]
	cardsCount=0;
	for (i=0;i<tempCount;i++) {
		found = 1;
		for (j=0;j<tempCount2;j++) {
			if (temp2[j] == temp[i]) {
				temp2[j] = -1;
				found = 0;
				break;
			}
		}
		if (found == 1) {
			cards[cardsCount] = temp[i];
			cardsCount++;
		}
	}
	if (cardsCount == 3)
		printf("SUCCESS: The deck+discard pile lost 3 cards.\n");
	else if (cardsCount > 3)
		printf("FAILURE: The deck+discard pile lost more than 3 cards.\n");
	else
		printf("FAILURE: The deck+discard pile lost less than 3 cards.\n");

	// combine cards from the hand and played pile into the temp array
	tempCount=0;
	for (i=0;i<states->gS->handCount[currentPlayer];i++) {
		temp[tempCount] = states->gS->hand[currentPlayer][i];
		tempCount++;
	}
	for (i=0;i<states->gS->playedCardCount;i++) {
		temp[tempCount] = states->gS->playedCards[i];
		tempCount++;
	}	

	// check if missing 3 cards in cards are in the hand+played pile array (temp)
	count = 0;
	for (i=0;i<cardsCount;i++) {
		for (j=0;j<tempCount;j++) {
			if (cards[i] == temp[j]) {
				temp[j] = -1;
				count++;
				break;
			}
		}
	}

	if (count == 3)
		printf("SUCCESS: 3 cards from discard+deck are in the hand or played cards pile.\n");
	else if (count > 3)
		printf("FAILURE: More than 3 cards from discard+deck are in the hand or played cards pile.\n");
	else
		printf("FAILURE: Less than 3 cards from discard+deck are in the hand or played cards pile.\n");

	// Evaluate other players
	printf("\nOther Players:\n");

	for (a=0;a<numPlay;a++) {

		if (a==currentPlayer)
			continue; // skip evaluating current player

		if (states->gS->handCount[a] == hCount)
			printf("SUCCESS: Player %d's hand count is unchanged.\n",a);
		else
			printf("FAILURE: Player %d's hand count has changed.\n",a);

		if (states->gS->deckCount[a] == dCount)
			printf("SUCCESS: Player %d's deck count is unchanged.\n",a);
		else
			printf("FAILURE: Player %d's deck count has changed.\n",a);

		if (states->gS->discardCount[a] == disCount)
			printf("SUCCESS: Player %d's discard count is unchanged.\n",a);
		else
			printf("FAILURE: Player %d's discard count has changed.\n",a);

	}


}


/**
Function is similar to the one in unittest3.c with slight modifications
Sets up the inputs for testing
Gets num values for num cards in deck, hand, and discard pile
**/
struct gStates* prepareStates(int dCount, int hCount, int disCount, int current) {
	struct gStates* states = (struct gStates*)malloc(sizeof(struct gStates));
	struct gameState* gS = (struct gameState*)malloc(sizeof(struct gameState));
	struct gameState* original = (struct gameState*)malloc(sizeof(struct gameState));

	int k[10] = {adventurer, baron, steward, ambassador, smithy, feast, tribute, mine, remodel, outpost};
	int i,j,choice;

// initialize cards array
	for (j=0;j<10;j++) {
		states->cards[j] = k[j];
	}
	states->cards[10] = copper;
	states->cards[11] = silver;
	states->cards[12] = gold;
	states->numUnique = 13;

// fill up deck
	for (i=0;i<dCount;i++) {
		// half the deck are treasure cards
		if (i < (dCount/2)) {
			if (i%2 == 0) {
				gS->deck[current][i] = gold;
				original->deck[current][i] = gold;
			} else {
				gS->deck[current][i] = silver;
				original->deck[current][i] = silver;
			}
			continue;
		}
		// other half of deck are adventure cards
		choice = 6;
		gS->deck[current][i] = k[choice];
		original->deck[current][i] = k[choice];
	}
	// not evaluating other player's cards so just updating counts
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
				gS->hand[current][i] = copper;
				original->hand[current][i] = copper;
			} else {
				gS->hand[current][i] = silver;
				original->hand[current][i] = silver;
			}
			continue;
		}
		// other half of hand are adventure cards
		choice = 7; 
		gS->hand[current][i] = k[choice];
		original->hand[current][i] = k[choice];
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
				gS->discard[current][i] = copper;
				original->discard[current][i] = copper;
			} else {
				gS->discard[current][i] = silver;
				original->discard[current][i] = silver;
			}
			continue;
		}
		// other half of discard pile are adventure cards
		choice = 8; 
		gS->discard[current][i] = k[choice];
		original->discard[current][i] = k[choice];
	}
	gS->discardCount[0] = disCount;
	gS->discardCount[1] = disCount;
	gS->discardCount[2] = disCount;
	gS->discardCount[3] = disCount;
	original->discardCount[current] = disCount; 

	// initialize playedcardcount to 0
	gS->playedCardCount = 0;
	original->playedCardCount = 0;

	states->gS = gS;
	states->original = original;
	return states;
}



int main() {

	printf("\n-----Testing smithy card with cardtest2.c-----\n");
	struct gStates* states = NULL;
	int i, current = 1;
/**** Test 1 ******/
	printf("\nTest1: Deck:29 Hand:6 Discard:0, 2 Players\n");
	states = prepareStates(29,6,0,current);
	testingSmithy(states,current,4,2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 2 ******/
	current = 3;
	printf("\nTest2: Deck:12 Hand:4 Discard:10, 4 Players\n");
	states = prepareStates(12,4,10,current);
	testingSmithy(states,current,5,4);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 3 ******/
	current = 0;
	printf("\nTest3: Deck:0 Hand:6 Discard:19, 3 Players\n");
	states = prepareStates(0,6,19,current);
	testingSmithy(states,current,3,3);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 4 ******/
	current = 1;
	printf("\nTest4: Deck:0 Hand:4 Discard:25, 2 Players\n");
	states = prepareStates(0,4,25,current);
	testingSmithy(states,current,0,2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);
	return 0;
}