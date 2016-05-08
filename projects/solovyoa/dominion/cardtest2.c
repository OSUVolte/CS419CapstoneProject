/*
	Andriy Solovyov
	CS-362
	Assignment 3
        cardtest2.c


Description:
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card. 

*/


#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h>  
#include <stdlib.h>
#include "rngs.h"

#define TESTCARD "adventurer"


/*
	 Here for cardtest2.c we will create a test for adventure card as required
	 It will include 4 different tests:
		1) treasure cards at the top of deck
		2) treasure cards below 1 card from top
        3) No change in state for other players
		4) No change in state to the victory and kindom card piles
*/


int main() {
   	int i;
  	int equal;
    	int successFlag = 0;
    	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    	int seed = 1000;
    	int numPlayers = 2;
    	int thisPlayer = 0;
    	int secPlayer = 1;
	
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int newCards = 0;
    	int discarded = 1;
   	int cardTemp = 0;
   
	
initializeGame(numPlayers, k, seed, &originalG);
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	
	// modify first 2 cards
	testingG.deck[thisPlayer][0] = copper; 
	testingG.deck[thisPlayer][1] = copper; 

	cardEffect(adventurer, choice1, choice2, choice3, &testingG, handpos, &bonus);

	newCards = 2;
	printf("Player's hand card = %d\n", testingG.handCount[thisPlayer], originalG.handCount[thisPlayer] + newCards - discarded);
	printf("Player's deck = %d\n", testingG.deckCount[thisPlayer], originalG.handCount[thisPlayer] - newCards);
	printf("Player's discard = %d\n", testingG.discardCount[thisPlayer], originalG.discardCount[thisPlayer]);

	if (testingG.handCount[thisPlayer] == originalG.handCount[thisPlayer] + newCards) {
		printf ("Test 1 passed, equals to 0\n");
      	successFlag += 1;
    }
    else {
		printf ("Failure on test 1, more/less cards\n");
    }


	memcpy(&testingG, &originalG, sizeof(struct gameState));
	printf("Player's hand card = %d\n", testingG.handCount[thisPlayer], originalG.handCount[thisPlayer]);

	// modify so the card would be on the top of the deck
	testingG.deck[thisPlayer][1] = copper; 
	testingG.deck[thisPlayer][2] = copper; 

	cardEffect(adventurer, choice1, choice2, choice3, &testingG, handpos, &bonus);

	newCards = 2;
	printf("Player's hand card = %d\n", testingG.handCount[thisPlayer], originalG.handCount[thisPlayer] + newCards - discarded);
	printf("Player's deck = %d\n", testingG.deckCount[thisPlayer], originalG.handCount[thisPlayer] - newCards - 1);
	printf("Player's discard = %d\n",testingG.discardCount[thisPlayer], originalG.discardCount[thisPlayer] + 1);

	if (testingG.discardCount[thisPlayer] == originalG.discardCount[thisPlayer] + 1) {
		printf ("passed #2\n");
      	successFlag += 1;
    }
    else {
      printf ("failed#2\n");
    }
 
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testingG, handpos, &bonus);

	newCards = 5;
	printf("Other Hand count = %d\n", testingG.handCount[thatPlayer] + newCards, originalG.handCount[thisPlayer]);
	printf("Other Deck count = %d\n", testingG.deckCount[thatPlayer] - newCards, originalG.deckCount[thisPlayer]);
	if ((testingG.handCount[thatPlayer] + newCards == originalG.handCount[thisPlayer]) && (testingG.deckCount[thatPlayer] - newCards == originalG.deckCount[thisPlayer])) {
		printf ("Success! State remained \n");
      	successFlag += 1;
    }
    else {
      printf ("State changed, failure.\n");
    }
	
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	if (testingG.supplyCount[copper] == originalG.supplyCount[copper]) {
		equal++;
	}
	if (testingG.supplyCount[silver] == originalG.supplyCount[silver]) {
		equal++;
	}
	if (testingG.supplyCount[gold] == originalG.supplyCount[gold]) {
		equal++;
	}

	if (equal == 3) {
		printf ("Pass, state remained the same\n");
      	successFlag += 1;
    }
    else {
      printf ("Fail, state changed\n");
    }

  
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	equal = 0;
    for (i = 0; i < 10; i++) {
    	cardTemp = k[i];
        if (testingG.supplyCount[cardTemp] == originalG.supplyCount[cardTemp]) {
            equal++;
        }
    }

	if (equal == 10) {
		printf ("Kindom piles didn't changed, passed\n");
      	successFlag += 1;
    }
    else {
      printf ("Fail, kindom piles changed\n");
    }

	return 0;
}