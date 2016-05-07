/***
Name: Tiffany Chiou
Assignment: 3
Testcase: cardtest1.c
Testing Function: adventurer card in dominion.c
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
- Player's hand should have 2 additional treasure cards
- All cards from deck+discard combined should be the same, aside from losing 2 additional treasures
- Discard, hand, and deck counts should be accurate in relation to one another
- Discard + hand + deck total count should be unchanged
- Other player's discard, hand, and decks should stay the same
**/
void testingAdventurer (struct gStates* states, int currentPlayer, int numPlayers) {
	int temp[MAX_DECK];
	int temp2[MAX_DECK];
	int cards[MAX_DECK];
	int cardsCount=0, tempCount,count, tempCount2;
	int res,i,j,a,b,found,treasure=0;
	int total, gSTotal;
	// for comparision with other players
	int hCount,dCount,disCount;
	hCount = states->original->handCount[currentPlayer];
	dCount = states->original->deckCount[currentPlayer];
	disCount = states->original->discardCount[currentPlayer];

	// set current player
	states->gS->whoseTurn=currentPlayer;

	// calculate total number of cards in discard+hand+deck
	total = states->original->handCount[currentPlayer] + states->original->deckCount[currentPlayer];
	total = total + states->original->discardCount[currentPlayer];

// populate temp array to use
	for (i=0;i<states->original->handCount[currentPlayer];i++) {
		temp[i] = states->original->hand[currentPlayer][i];
	}
	tempCount = states->original->handCount[currentPlayer];
	// play adventurer card
	res = cardEffect(adventurer,0,0,0,states->gS,0,NULL);

	printf("\nCurrent Player:\n");

	// total card count should be the same
	gSTotal = states->gS->handCount[currentPlayer] + states->gS->deckCount[currentPlayer];
	gSTotal = gSTotal + states->gS->discardCount[currentPlayer];

	if (gSTotal == total)
		printf("SUCCESS: Total card count is correct (deck+hand+discard).\n");
	else
		printf("FAILURE: Total card count is incorrect (deck+hand+discard).\n");

	// first verify 2 extra treasure cards in player's hand

	// hand count should be 2 more
	states->original->handCount[currentPlayer] = states->original->handCount[currentPlayer] + 2;
	if (states->gS->handCount[currentPlayer] == states->original->handCount[currentPlayer])
		printf("SUCCESS: The handCount increased by 2.\n");
	else
		printf("FAILURE: The handCount did not increase by 2.\n");

	// hand array should have all the same cards plus 2 new treasure cards
	for(i=0;i<states->gS->handCount[currentPlayer];i++) {
		found = 1;
		for (j=0;j<tempCount;j++) {
			if (states->gS->hand[currentPlayer][i] == temp[j]) {
				found=0;
				temp[j] = -1; // if the card is found in the temp array, set its value to -1
				break;
			}
		}
		// if found == 1, that means the card was not found in the original player's hand
		// add the card to the cards array
		if (found == 1) {
			cards[cardsCount] = states->gS->hand[currentPlayer][i];
			cardsCount++;
		} 
	}
	// make sure all cards are treasure cards
	treasure = 0;
	for (i=0;i<cardsCount;i++) {
		if (cards[i] != copper && cards[i] != silver && cards[i] != gold) {
			treasure = 1;
		}
	}

	// print out results from directly evaluating the hand array
	if (cardsCount == 2)
		printf("SUCCESS: The hand array increased by 2 cards.\n");
	else
		printf("FAILURE: The hand array did not increase by 2 cards.\n");

	if (treasure == 0 && cardsCount == 2)
		printf("SUCCESS: The hand array increased by 2 treasure cards.\n");
	else
		printf("FAILURE: The hand array did not increase by 2 treasure cards.\n");


	// combine cards in original and gS together to compare them
	// temp array holds all the cards from the original deck+discard
	tempCount=0;
	for (i=0;i<states->original->deckCount[currentPlayer];i++) {
		temp[tempCount] = states->original->deck[currentPlayer][i];
		tempCount++;
	}
	for (i=0;i<states->original->discardCount[currentPlayer];i++) {
		temp[tempCount] = states->original->discard[currentPlayer][i];
		tempCount++;
	}
	//temp2 array holds all the cards from the deck+discard+2 treasure cards in player's hand
	tempCount2=0;
	for (i=0;i<states->gS->deckCount[currentPlayer];i++) {
		temp2[tempCount2] = states->gS->deck[currentPlayer][i];
		tempCount2++;
	}
	for (i=0;i<states->gS->discardCount[currentPlayer];i++) {
		temp2[tempCount2] = states->gS->discard[currentPlayer][i];
		tempCount2++;
	}

	//tempCount and tempCount2 should be equal to each other
	if (tempCount == tempCount2+2)
		printf("SUCCESS: The total number of cards in the deck+discard pile is 2 less than before.\n");
	else
		printf("FAILURE: The total cards in deck+discard is not 2 cards less than before.\n");

	// add the extra cards from the player's hand that they drew this turn
	for (i=0;i<cardsCount;i++) {
		temp2[tempCount2] = cards[i];
		tempCount2++;
	}

	count = 0; // keep track of how many of the same cards are found
	// count should equal tempCount and tempCount2

	if (tempCount == tempCount2) {
		// check if the cards are equal
		for (i=0;i<tempCount;i++) {
			for (j=0;j<tempCount2;j++) {
				if (temp[i] == temp2[j]) {
					temp2[j] = -1;
					count++;
					break;
				}
			}
		}
		if (count == tempCount)
			printf("SUCCESS: The deck and discard contain valid cards.\n");
		else
			printf("FAILURE: The deck and discard are either missing or containing invalid cards.\n");
	} else {
		// if the counts aren't equal then the deck and discard decks are missing
		// or have invalid cards
		printf("FAILURE: The deck and discard are either missing or containing invalid cards.\n");
	}

	printf("\nOther Players:\n");
	for (a=0;a<numPlayers;a++) {
		// if a is the current player, skip
		if (a==currentPlayer)
			continue;

		count = 0;
		// verify hand count is correct
		if (hCount == states->gS->handCount[a]) {
			printf("SUCCESS: Player %d's hand count did not change.\n",a);
			for (b=0;b<hCount;b++) {
				if (states->gS->hand[a][b] == states->original->hand[currentPlayer][b])
					count++;
			}
			if (count == hCount)
				printf("SUCCESS: Player %d's hand cards are the same.\n",a);
			else
				printf("FAILURE: Player %d's hand cards are not the same.\n",a);
		} else
			printf("FAILURE: Player %d's hand count did change. It may have missing or invalid cards.\n",a);

		// verify deck count is correct
		if (dCount == states->gS->deckCount[a]) {
			printf("SUCCESS: Player %d's deck count did not change.\n",a);
			count = 0;
			for (b=0;b<dCount;b++) {
				if (states->gS->deck[a][b] == states->original->deck[currentPlayer][b])
					count++;
			}
			if (count == dCount)
				printf("SUCCESS: Player %d's deck cards are the same.\n",a);
			else
				printf("FAILURE: Player %d's deck cards are not the same.\n",a);
		} else
			printf("FAILURE: Player %d's deck count did change. It may have missing or invalid cards.\n",a);

		// verify discard count is correct
		if (disCount == states->gS->discardCount[a]) {
			printf("SUCCESS: Player %d's discard count did not change.\n",a);
			count = 0;
			for (b=0;b<disCount;b++) {
				if (states->gS->discard[a][b] == states->original->discard[currentPlayer][b])
					count++;
			}
			if (count == disCount)
				printf("SUCCESS: Player %d's discard cards are the same.\n",a);
			else
				printf("FAILURE: Player %d's discard cards are not the same.\n",a);
		} else
			printf("FAILURE: Player %d's discard count did change. It may have missing or invalid cards.\n",a);
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
				gS->deck[0][i] = gold;
				gS->deck[1][i] = gold;
				gS->deck[2][i] = gold;
				gS->deck[3][i] = gold;
				original->deck[current][i] = gold;
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
		choice = 5; 
		gS->deck[0][i] = k[choice];
		gS->deck[1][i] = k[choice];
		gS->deck[2][i] = k[choice];
		gS->deck[3][i] = k[choice];
		original->deck[current][i] = k[choice];
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
		choice = 6; 
		gS->hand[0][i] = k[choice];
		gS->hand[1][i] = k[choice];
		gS->hand[2][i] = k[choice];
		gS->hand[3][i] = k[choice];
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
		choice = 2;
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

	printf("\n-----Testing adventurer card with cardtest1.c-----\n");
	struct gStates* states = NULL;
	int i, current = 1;
/**** Test 1 ******/
	printf("\nTest1: Deck:6 Hand:5 Discard:20\n");
	states = prepareStates(6,5,20,current);
	testingAdventurer(states,current,2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 2 ******/
	current = 3;
	printf("\nTest2: Deck:20 Hand:3 Discard:5\n");
	states = prepareStates(20,3,5,current);
	testingAdventurer(states,current,4);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 3 ******/
	current = 2;
	printf("\nTest3: Deck:0 Hand:2 Discard:18\n");
	states = prepareStates(0,2,18,current);
	testingAdventurer(states,current,3);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 4 ******/
	current = 0;
	printf("\nTest4: Deck:0 Hand:5 Discard:15\n");
	states = prepareStates(0,5,15,current);
	testingAdventurer(states,current,2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);
	return 0;
}