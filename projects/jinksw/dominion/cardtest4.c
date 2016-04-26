/* -----------------------------------------------------------------------
		Unit Testing for council_room card 
		**Used testUpdateCoins.c template for r

		___ council_room ___
			Basic Requirements:
				1. Current Player Should Recieve Exactly 4 Cards
				2. 3 cards should come from player's own pile
				3. Current player should get +1 buys
				3. Each other player should recieve exactly 1 card
				4. No State change should occur in victory or kingdom piles
				
 * -----------------------------------------------------------------------
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

int main() {
    int newCards = 0;
		int discarded = 1;
    int shuffledCards = 0;
		int xtraCoins = 0;
		int actions = 1;
		int buys = 0;
		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int i, j, m;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
		int failFlag = 0;
		int passCount = 0;
		int tests = 4;
		int tE = 0, tH = 0; //treasureExpected, treasureInHand
		int newActions = 0;	

		struct gameState G, testG;
		int k[10] = {council_room, embargo, adventurer, minion, mine, cutpurse,
			sea_hag, tribute, smithy, village};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Hand Count, Deck Count, and Discard Count ------------- 
	printf("TEST 1: Hand Count = 8 From 4 new cards, Buys +1, Deck Count = Expected, Discard Count = Expected \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 1;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("numBuys = %d, expected = %d\n", testG.numBuys, G.numBuys - buys + 1);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions - actions + newActions);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	//Is the discard count what we expect?
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer],  discarded);	
	if( !(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) ){
		printf( "Test 1 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numBuys == G.numBuys - buys) ){
		printf( "Test 1 Failed: Player buy count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numActions == G.numActions - actions + newActions) ){
		printf( "Test 1 Failed: Player action count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) ){
		printf( "Test 1 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.discardCount[thisPlayer] == discarded) ){
		printf( "Test 1 Failed: Player discard count different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "Test 1 Passed" );
		passCount++;
	}
	
	
	// ----------- TEST 2: Testing that the other player's state doesn't change --------------
	printf("TEST 2: Player 2 gets to draw a card, but no other states change when Player 1 plays council_room\n");
	failFlag = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	newCards = 1;
	discarded = 0;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer] + newCards - discarded);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - newCards + shuffledCards);
	//Is the discard count what we expect?
	printf("discard count = %d, expected = %d\n", testG.discardCount[otherPlayer],  discarded);	
	//We don't need to run the coin, action, or buys for this because those are reset each turn for players.
	if( !(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) ){
		printf( "Test 2 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) ){
		printf( "Test 2 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.discardCount[thisPlayer] == discarded) ){
		printf( "Test 2 Failed: Player discard count different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "Test 2 Passed\n" );
		passCount++;
	} 
	

	// ----------- TEST 3: Council_room is discarded from hand--------------
	failFlag = 0;
	printf("TEST 3: Council_room is successfully discarded, Other Cards are kept\n");

	int offset;
	// Cycle through each  possible  hand position
	for (i=0; i<G.handCount[thisPlayer]; i++) {
			offset = 1;
			handpos = i;
			//Smithy Position for each iteration
			G.hand[thisPlayer][i] = council_room;			 // 0 1 2 3 4 

			//Other cards position for each iteration. Managed by i and offset
			// card position on each iteration = 1, 2, 3, 4, 0
			if ( (i + offset) <= 4 ){
					G.hand[thisPlayer][i+offset] = copper;	 
			} else {
				G.hand[thisPlayer][0] = copper;						 
			}

			offset++; //offset = 2
			// card position on each iteration = 2, 3, 4, 0 1
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i + offset] = duchy;			
			} else {
				G.hand[thisPlayer][i-1-offset] = duchy;			
			}
			
			offset++; //offset = 3
			// card position on each iteration = 3, 4, 0, 1, 2
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i + offset] = estate;					 
			} else {
				G.hand[thisPlayer][i+1-offset] = estate;					 
			}

			offset++; //offset = 4;
			// card position on each iteration =  4, 0, 1, 2, 3
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i+offset] = feast;		
			} else {
				G.hand[thisPlayer][i+3-offset] = feast;		
			}			 

			// copy the game state to a test case
			memcpy(&testG, &G, sizeof(struct gameState));

			printf("Cards in Hand Before Playing council_room: ");
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf("\n ");

			cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

			printf("ending cards: ");
			// tests that card played is no longer in the player's hand
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf(", expected cards: ");
			for (m=0; m<G.handCount[thisPlayer]; m++) {
				if ( m <G.handCount[thisPlayer]; m++ ){
					if ( m != i  ) {
						printf("(%d)", G.hand[thisPlayer][m]);
					} else {
						printf( "(Last drawn card)" );
					}
				}
			}
			printf("(drawn Card),(drawn Card)\n");

			for (m=0; m<G.handCount[thisPlayer]; m++) {
				if( m=i ){
					if( G.hand[thisPlayer][m] == testG.hand[thisPlayer][m] ){
						printf( "Test 3 Failed: council_room remained in same position in hand for iteration # %d, but was in starting position: %d.\n", i+1, i );
						failFlag = 1;
					} else if ( testG.hand[thisPlayer][m] == smithy ){
						printf( "Test 3 Failed: council_room remained in hand for iteration # %d, but moved to position %d, but was in starting position: %d.\n", i+1, m, i );
						failFlag = 1;
					} else {
						passCount++;
						printf( "Test 3 Passed" );
					}
				}
			}
	}
	

	// ----------- TEST 4: Coin, Kingdom, Victory states don't change ---------
	failFlag = 0;
	handpos = 0;
	printf("TEST 4: Coin, Kingdom, Victory states don't change\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Estate cards = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
	printf("Duchy cards = %d, expected = %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
	printf("Province cards = %d, expected = %d\n", testG.supplyCount[province], G.supplyCount[province]);
	printf("Player turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn );
	printf("Kingdom cards = ");
	for( i=0; i< 10; i++ ){ 
		printf( "(%s = %d)", testG->kingdomCards[i], testG.supplyCount[i] );
	}
	printf(", expected = ");
	for( i=0; i< 10; i++ ){
		printf( "(%s = %d)", G->kingdomCards[i], G.supplyCount[i] );
	}
	
	//Tests
	if( !(testG.coins == G.coins + xtraCoins) ){
		printf( "Test 4 Failed: Player coins different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[estate] == G.supplyCount[estate] ) ){
		printf( "Test 4 Failed: Estate Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[duchy] == G.supplyCount[duchy] ) ){
		printf( "Test 4 Failed: Duchy Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[province] == G.supplyCount[province] ) ){
		printf( "Test 4 Failed: Province Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.whoseTurn == G.whoseTurn ) ){
		printf( "Test 4 Failed: Whose Turn Changed\n" );
		failFlag = 1;
	}
	for( i=0; i< 10; i++ ){
		if( !( testG.kingdomCards[i] == G.kingdomCards[i] ) ){
			printf( "Test 4 Failed:Kingdom card %s changed to %s \n", G.kingdomCards[i], testG.kingdomCards[i] );
			failFlag = 1;
		}
		if( !( testG.supplyCount[i] == G.supplyCount[i] ) ){
			printf( "Test 4 Failed:Kingdom card count %d for %s changed to %d for %s \n", G.supplyCount[i], G.kingdomCards[i], testG.supplycount[i], testG.kingdomCards[i] );
			failFlag = 1;
		}

	}

	if( failFlag == 0 ){
		passCount++;
		printf( "Test 4 Passed" );
	}


	printf("\n >>>>> SUCCESS: Testing complete %s, %d tests failed, %d tests passed. <<<<<\n\n", TESTCARD, tests-passCount, passCount);


	return 0;
}

