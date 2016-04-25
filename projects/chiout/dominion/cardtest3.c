/***
Name: Tiffany Chiou
Assignment: 3
Testcase: cardtest3.c
Testing Function: Great Hall card in dominion.c
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
Testing:
- player's hand count should be the same
- discard+deck should be missing one card, the rest of the cards should be the same
- state's numAction increases
- played card count should increase by 1
- the missing card from discard+deck should be somewhere in the player+played card pile
- all cards in the player's hand should be still in the hand or in the played card pile
- testing is similar to smithy's testing, with some edits and additions
**/
void testingGreatHall (struct gStates* states, int currentPlayer, int handPos) {
	int temp[MAX_DECK];
	int temp2[MAX_DECK];
	int cards[MAX_DECK];
	int cardsCount=0, tempCount,count, tempCount2;
	int res,i,j,found;
	states->gS->whoseTurn=currentPlayer;
	int total, gSTotal;

	// calculate total number of cards in discard+hand+deck+ played count
	total = states->original->handCount[currentPlayer] + states->original->deckCount[currentPlayer];
	total = total + states->original->discardCount[currentPlayer] + states->original->playedCardCount;

	// play great hall card
	res = cardEffect(great_hall,0,0,0,states->gS,handPos,NULL);

	// evaluate player's hand
	if (states->gS->handCount[currentPlayer] == states->original->handCount[currentPlayer])
		printf("SUCCESS: The player's hand count is the same.\n");
	else if (states->gS->handCount[currentPlayer] > states->original->handCount[currentPlayer])
		printf("FAILURE: The player's hand count increased.\n ");
	else
		printf("FAILURE: The player's hand count decreased.\n ");


	// model temp array after the player's original hand and played card pile
	tempCount = 0;
	for (i=0;i<states->original->handCount[currentPlayer];i++) {
		temp[tempCount] = states->original->hand[currentPlayer][i];
		tempCount = tempCount+1;
	}
	for (i=0;i<states->original->playedCardCount;i++) {
		temp[tempCount] = states->original->playedCards[i];
		tempCount = tempCount+1;
	}

	// model temp array after the player's hand and played card pile
	tempCount2 = 0;
	for (i=0;i<states->gS->handCount[currentPlayer];i++) {
		temp2[tempCount2] = states->gS->hand[currentPlayer][i];
		tempCount2 = tempCount2+1;
	}
	for (i=0;i<states->gS->playedCardCount;i++) {
		temp2[tempCount2] = states->gS->playedCards[i];
		tempCount2 = tempCount2+1;
	}
	count = 0;
	for (i=0;i<tempCount2;i++) {
		for (j=0;j<tempCount;j++) {
			if (temp2[i] == temp[j]) {
				count = count+1;
				temp[j] = -1;
				break;
			}
		}
	}
	if (count == tempCount)
		printf("SUCCESS: All original hand cards in in the player's hand or the played card pile.\n");
	else
		printf("FAILURE: One or more cards are missing from the player's hand or played card pile.\n");


	// check played card count - should increase by one
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

	if (tempCount == tempCount2 + 1)
		printf("SUCCESS: THe discard+deck count is 1 card less.\n");
	else
		printf("FAILURE: The discard+deck count is incorrect.\n");

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
	if (cardsCount == 1)
		printf("SUCCESS: The deck+discard pile lost 1 card.\n");
	else if (cardsCount > 1)
		printf("FAILURE: The deck+discard pile lost more than 1 card.\n");
	else
		printf("FAILURE: The deck+discard pile lost less than 1 card.\n");

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

	if (count == 1)
		printf("SUCCESS: 1 card from discard+deck is in the hand or played cards pile.\n");
	else if (count > 1)
		printf("FAILURE: More than 1 card from discard+deck is in the hand or played cards pile.\n");
	else
		printf("FAILURE: Less than 1 card from discard+deck is in the hand or played cards pile.\n");

	// test the number of actions
	if (states->gS->numActions == states->original->numActions+1)
		printf("SUCCESS: Number of Actions increased by 1.\n");
	else if (states->gS->numActions > states->original->numActions+1)
		printf("SUCCESS: Number of Actions increased by more than 1.\n");
	else
		printf("SUCCESS: Number of Actions increased by less than 1.\n");

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

	int k[10] = {adventurer, baron, great_hall, ambassador, smithy, feast, tribute, mine, remodel, outpost};
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
		choice = 5; 
		gS->deck[current][i] = k[choice];
		original->deck[current][i] = k[choice];
	}
	gS->deckCount[current] = dCount;
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
		choice = 2; 
		gS->hand[current][i] = k[choice];
		original->hand[current][i] = k[choice];
	}
	gS->handCount[current] = hCount;
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
		choice = 6; 
		gS->discard[current][i] = k[choice];
		original->discard[current][i] = k[choice];
	}
	gS->discardCount[current] = disCount;
	original->discardCount[current] = disCount; 

	// initialize playedcardcount to 0
	gS->playedCardCount = 0;
	original->playedCardCount = 0;

	// initialize numActions
	gS->numActions = 1;
	original->numActions = 1;

	states->gS = gS;
	states->original = original;
	return states;
}



int main() {

	printf("\n-----Testing great hall card with cardtest3.c-----\n");
	struct gStates* states = NULL;
	int i, current = 1;
/**** Test 1 ******/
	printf("\nTest1: Deck:30 Hand:4 Discard:0\n");
	states = prepareStates(30,4,0,current);
	testingGreatHall(states,current,4);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 2 ******/
	printf("\nTest2: Deck:23 Hand:1 Discard:5\n");
	states = prepareStates(23,6,5,current);
	testingGreatHall(states,current,5);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 3 ******/
	printf("\nTest3: Deck:0 Hand:3 Discard:24\n");
	states = prepareStates(0,3,24,current);
	testingGreatHall(states,current,3);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 4 ******/
	printf("\nTest4: Deck:0 Hand:0 Discard:30\n");
	states = prepareStates(0,0,30,current);
	testingGreatHall(states,current,0);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);
	return 0;
}