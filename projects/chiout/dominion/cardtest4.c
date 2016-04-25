/***
Name: Tiffany Chiou
Assignment: 3
Testcase: cardtest4.c
Testing Function: Council Room card in dominion.c
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
- current player should have a net gain of 3 cards in their hand
- current player's deck+discard should be missing 4 cards 
- these four cards should be in their hand+played cards pile
- other players should have 1 more card in their hand
- other players' decks should be missing 1 card each
- the card should be in their hand+played cards pile
- all players should have the same full deck count since they all were intiailized to have the same
- numBuys should increase by 1
**/
void testingCouncilRoom(struct gStates* states, int currentPlayer, int handPos, int numPlayers) {
	int temp[MAX_DECK];
	int temp2[MAX_DECK];
	int temp3[MAX_DECK];
	int cards[MAX_DECK];
	int cardsCount=0, tempCount, count, tempCount2,tempCount3;
	int res,i,a,b,j,found, total, nTotal;
	// play the card
	states->gS->whoseTurn=currentPlayer;
	res = cardEffect(council_room,0,0,0,states->gS,handPos,NULL);

	// evaluate hand counts
	// check all players
	for (i=0;i<numPlayers;i++) {
		if (i == currentPlayer) {
			if (states->gS->handCount[currentPlayer] == states->original->handCount[currentPlayer]+3)
			printf("SUCCESS: The current player's hand count increased by 3.\n");
		else if (states->gS->handCount[currentPlayer] > states->original->handCount[currentPlayer])
			printf("FAILURE: The current player's hand count increased by more than 3.\n ");
		else
			printf("FAILURE: The current player's hand count increased by less than 3.\n ");
		} else {
			if (states->gS->handCount[i] == states->original->handCount[currentPlayer]+1)
				printf("SUCCESS: Player %d hand count increased by 1.\n",i);
			else if (states->gS->handCount[i] > states->original->handCount[currentPlayer]+1)
				printf("FAILURE: Player %d hand count increased by more than 1.\n",i);
			else
				printf("FAILURE: Player %d hand count increased by less than 1.\n",i);	
		}
	}

	// puts discard and deck cards together in an array for evaluation
	// temp holds the original cards
	tempCount=0;
	for (i=0;i<states->original->deckCount[currentPlayer];i++) {
		temp[tempCount] = states->original->deck[currentPlayer][i];
		tempCount++;
	}
	for (i=0;i<states->original->discardCount[currentPlayer];i++) {
		temp[tempCount] = states->original->discard[currentPlayer][i];
		tempCount++;
	}		
	for (a=0; a<numPlayers; a++) {
		// assembles the discard and deck cards together
		tempCount2=0;
		for (i=0;i<states->gS->deckCount[a];i++) {
			temp2[tempCount2] = states->gS->deck[a][i];
			tempCount2++;
		}
		for (i=0;i<states->gS->discardCount[a];i++) {
			temp2[tempCount2] = states->gS->discard[a][i];
			tempCount2++;
		}
		printf("\nPlayer %d:\n",a);
		if (a == currentPlayer) {
			if (tempCount == tempCount2 + 4)
				printf("SUCCESS: The current player's discard+deck is 4 cards short.\n");
			else if (tempCount > tempCount2 + 4)
				printf("FAILURE: The current player's discard+deck is more than 4 cards short.\n");
			else
				printf("FAILURE: The current player's discard+deck is less than 4 cards short.\n");
		} else {
			if (tempCount == tempCount2 + 1)
				printf("SUCCESS: Player %d's discard+deck is 1 card short.\n",a);
			else if (tempCount > tempCount2 + 1)
				printf("FAILURE: Player %d's discard+deck is more than 1 card short.\n",a);
			else
				printf("FAILURE: Player %d's discard+deck is less than 1 card short.\n",a);
		}
		// isolates the missing cards from deck + discard
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
			// cards array holds the missing cards
			// these cards should be verified to be in the hand+played card array
			if (found == 1) {
				cards[cardsCount] = temp[i];
				cardsCount++;
			}
		}

		if (a == currentPlayer) {
			if (cardsCount == 4)
				printf("SUCCESS: 4 cards are missing from the deck+discard piles.\n");
			else if (cardsCount > 4)
				printf("FAILURE: More than 4 cards are missing from the deck+discard piles.\n");
			else
				printf("FAILURE: Less than 4 cards are missing from the deck+discard piles.\n");
		} else {
			if (cardsCount == 1)
				printf("SUCCESS: 1 card is missing from the deck+discard piles.\n");
			else if (cardsCount > 1)
				printf("FAILURE: More than 1 card is missing from the deck+discard piles.\n");
			else
				printf("FAILURE: Less than 1 card is missing from the deck+discard piles.\n");
		}

		// temp array will now hold the hand+played cards
		tempCount3=0;
		for (i=0;i<states->gS->handCount[a];i++) {
			temp3[tempCount3] = states->gS->hand[a][i];
			tempCount3++;
		}
		for (i=0;i<states->gS->playedCardCount;i++) {
			temp3[tempCount3] = states->gS->playedCards[i];
			tempCount3++;
		}	

		count = 0;
		for (i=0;i<cardsCount;i++) {
			for (j=0;j<tempCount3;j++) {
				if (cards[i] == temp3[j]) {
					temp3[j] = -1;
					count++;
					break;
				}
			}
		}

		if (a == currentPlayer) {
			if (count == 4)
				printf("SUCCESS: The 4 drawn cards are in the hand+played card pile.\n");
			else 
				printf("FAILURE: The 4 drawn cards are not all in the hand+played card pile.\n");
		} else {
			if (count == 1)
				printf("SUCCESS: The drawn card is in the hand+played card pile.\n");
			else 
				printf("FAILURE: The drawn card is not in the hand+played card pile.\n");
		}

		// check total card count
		total = states->original->handCount[currentPlayer] + states->original->deckCount[currentPlayer];
		total = total + states->original->discardCount[currentPlayer];

		nTotal = states->gS->handCount[a] + states->gS->deckCount[a];
		nTotal = nTotal + states->gS->discardCount[a];

		if (a == currentPlayer) {
			nTotal = nTotal + states->gS->playedCardCount;
			if (nTotal == total)
				printf("SUCCESS: The total card count is correct.\n");
			else
				printf("FAILURE: The total card count is incorrect.\n");
		} else  {
			if (nTotal == total)
				printf("SUCCESS: The total card count is correct.\n");
			else
				printf("FAILURE: The total card count is incorrect.\n");
		}

	}

	// check number buys value
	if (states->gS->numBuys == states->original->numBuys+1)
		printf("\nSUCCESS: The numBuys value is correct.\n");
	else
		printf("\nSUCCESS: The numBuys value is incorrect.\n");
}


/**
Function is similar to the one in unittest3.c with slight modifications
Sets up the inputs for testing
Gets num values for num cards in deck, hand, and discard pile
**/
struct gStates* prepareStates(int dCount, int hCount, int disCount, int current, int numPlayers) {
	struct gStates* states = (struct gStates*)malloc(sizeof(struct gStates));
	struct gameState* gS = (struct gameState*)malloc(sizeof(struct gameState));
	struct gameState* original = (struct gameState*)malloc(sizeof(struct gameState));

	int k[10] = {adventurer, baron, steward, ambassador, council_room, feast, tribute, mine, remodel, outpost};
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
		choice = 9; 
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
		choice = 0; 
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
		choice = 8; 
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

	// initialize playedcardcount to 0
	gS->playedCardCount = 0;
	original->playedCardCount = 0;

	// initialize numActions
	gS->numActions = 1;
	original->numActions = 1;

	// initialize numBuys
	gS->numBuys = 1;
	original->numBuys = 1;

	gS->numPlayers = numPlayers;

	states->gS = gS;
	states->original = original;

	return states;
}



int main() {

	printf("\n-----Testing council room with cardtest4.c-----\n");
	struct gStates* states = NULL;
	int i, current = 0;
/**** Test 1 ******/
	printf("\nTest1: Deck:27 Hand:5 Discard:0\n");
	states = prepareStates(27,5,0,current,2);
	testingCouncilRoom(states, current, 2, 2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 2 ******/
	printf("\nTest2: Deck:23 Hand:1 Discard:8\n");
	states = prepareStates(23,1,8,current,3);
	testingCouncilRoom(states, current, 2, 3);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 3 ******/
	printf("\nTest3: Deck:0 Hand:2 Discard:19\n");
	states = prepareStates(0,2,19,current,4);
	testingCouncilRoom(states, current, 2, 4);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);

/**** Test 4 ******/
	printf("\nTest4: Deck:0 Hand:0 Discard:30\n");
	states = prepareStates(0,0,30,current,2);
	testingCouncilRoom(states, current, 2, 2);
	// free memory
	free(states->gS);
	free(states->original);
	free(states);
	return 0;
}