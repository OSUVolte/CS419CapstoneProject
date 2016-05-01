/* -----------------------------------------------------------------------
		Unit Testing for endTurn() function in dominion.c
		**Used testUpdateCoins.c template for reference

		--endTurn()--
		Description: Resets Game State. Moves to next player

		Input:  struct gameState *state
		Return: 0 on success
		
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include "interface.h"
#include "interface.c"


int main() {

		//Initialize Game
		int i;
    int seed = 777;
		int players = 2;
    int k[10] = {smithy, village, council_room, adventurer, feast
               , gardens, mine, remodel, baron, great_hall};
    struct gameState G, Gest;
		initializeGame( players, k, seed, &G );
		
		int passCount = 0;
		int failCount = 0;
		int passList[17] = { 0 };
		int failList[17] = { 0 };
		char *cardName = NULL;
		cardNumToName( 1, cardName );
		memcpy( &Gest, &G, sizeof(struct gameState));
		endTurn( &Gest );
	
	printf( "***TEST 1. Player count shouldn't change./n" );
  if( Gest.numPlayers != G.numPlayers ){
		printf( "TEST 1 FAILED. Player count = %d Expected = %d/n", Gest.numPlayers, G.numPlayers );
		failList[failCount] = 1;
		failCount++;
	} else {
		printf( "TEST 1 PASSED. Player count = %d Expected = %d/n", Gest.numPlayers, G.numPlayers );
		passList[passCount] = 1;
		passCount++;
	}

	printf( "TEST 2. Supply Count Shouldn't Change./n" );	
  for( i=0; i<10; i++ ){
		if( Gest.supplyCount[i] != G.supplyCount[i] ){  
			printf( "TEST 2 FAILED. Supply Count = %d; expected = %d./n", Gest.supplyCount[i], G.supplyCount[i] );  
			failList[failCount] = 2;
			failCount++;
		} else {
			printf( "TEST 2 PASSED. Supply Count = %d; expected = %d./n", Gest.supplyCount[i], G.supplyCount[i] );  
			passList[passCount] = 2;
			passCount++;
		}
	}

	printf( "TEST 3. Embargo Count Shouldn't Change./n" );	
  for( i=0; i<=treasure_map; i++ ){
		cardNumToName( i, cardName );
		if( Gest.embargoTokens[i] != G.embargoTokens[i] ){
			printf( "TEST 3 FAILED. Embargo Count for %s = %d, expected = %d./n", cardName, Gest.embargoTokens[i], G.embargoTokens[i] );
			failList[failCount] = 3;
			failCount++;
		} else {
			printf( "TEST 3 PASSED. Embargo Count for %s = %d, expected = %d./n", cardName, Gest.embargoTokens[i], G.embargoTokens[i] );
			passList[passCount] = 3;
			passCount++;
		}
	}

	printf( "TEST 4. State reset: Outpost Shouldn't Be Played ./n" );	
  if( Gest.outpostPlayed != G.outpostPlayed ){
		printf( "TEST 4 FAILED. Outpost played = %d, expected = %d./n", Gest.outpostPlayed, G.outpostPlayed );
		failList[failCount] = 4;
		failCount++;
	} else {
		printf( "TEST 4 PASSED. Outpost played = %d, expected = %d./n", Gest.outpostPlayed, G.outpostPlayed );
		passList[passCount] = 4;
		passCount++;
	}

	printf( "TEST 5. State reset: It shouldn't be an Outpost turn ./n" );	
  if( Gest.outpostTurn != G.outpostTurn ){
		printf( "TEST 5 FAILED. Outpost turn = %d, expected = %d./n", Gest.outpostPlayed, G.outpostPlayed );
		failList[failCount] = 5;
		failCount++;
	} else {
		printf( "TEST 5 PASSED. Outpost turn = %d, expected = %d./n", Gest.outpostPlayed, G.outpostPlayed );
		passList[passCount] = 5;
		passCount++;
	}

	printf( "TEST 6. Whose turn changes to next player ./n" );	
  if( Gest.whoseTurn == G.whoseTurn ){
		printf( "TEST 6 FAILED. Player turn = %d, expected = %d./n", Gest.whoseTurn, G.whoseTurn );
		failList[failCount] = 6;
		failCount++;
	} else {
		printf( "TEST 6 PASSED. Player turn = %d, expected = %d./n", Gest.whoseTurn, G.whoseTurn );
		passList[passCount] = 6;
		passCount++;
	}

	printf( "TEST 7. Phase should reset to 0 ./n" );	
 if( Gest.phase != G.phase ){
		printf( "TEST 7 FAILED. Phase = %d, expected = %d./n", Gest.phase, G.phase );
		failList[failCount] = 7;
		failCount++;
	} else {
		printf( "TEST 7 PASSED. Phase = %d, expected = %d./n", Gest.phase, G.phase );
		passList[passCount] = 7;
		passCount++;
	}

	printf( "TEST 8: numActions should reset to 1 ./n" );	
  if( Gest.numActions != G.numActions ){
		printf( "TEST 8 FAILED. numActions = %d, expected = %d./n", Gest.numActions, G.numActions );
		failList[failCount] = 8;
		failCount++;
	} else {
		printf( "TEST 8 PASSED. numActions = %d, expected = %d./n", Gest.numActions, G.numActions );
		passList[passCount] = 8;
		passCount++;
	}
	
	printf( "TEST 9: Player whose turn ended should have an empty hand ./n" );	
  if( Gest.handCount[G.whoseTurn] != 0 ){
		printf( "TEST 9 FAILED. handcount = %d, expected = 0./n", Gest.handCount[G.whoseTurn] );
		failList[failCount] = 9;
		failCount++;
	} else {
		printf( "TEST 9 PASSED. handcount = %d, expected = 0./n", Gest.handCount[G.whoseTurn] );
		passList[passCount] = 9;
		passCount++;
	}

	printf( "TEST 10: numBuys resets to 1 ./n" );	
  if( Gest.numBuys != 1 ){
		printf( "TEST 10 FAILED. numBuys = %d, expected = 1./n", Gest.numBuys );
		failList[failCount] = 10;
		failCount++;
	} else {
		printf( "TEST 10 Passed. numBuys = %d, expected = 1./n", Gest.numBuys );
		passList[passCount] = 10;
		passCount++;
	}

	printf( "TEST 11: Player whose turn ended should have an empty hand ./n" );	
  if( Gest.handCount[G.whoseTurn] != 0 ){
		printf( "TEST 11: FAILED. handCount = %d, expected = 0./n", Gest.handCount[G.whoseTurn] );
		failList[failCount] = 11;
		failCount++;
	} else {
		printf( "TEST 11: Passed. handCount = %d, expected = 0./n", Gest.handCount[G.whoseTurn] );
		passList[passCount] = 11;
		passCount++;
	}
	
	printf( "TEST 12: New Player whose turn is starting should have 5 cards in hand ./n" );	
  if( Gest.handCount[Gest.whoseTurn] != 5 ){
		printf( "TEST 12: FAILED. handCount = %d, expected = 0./n", Gest.handCount[Gest.whoseTurn] );
		failList[failCount] = 12;
		failCount++;
	} else {
		printf( "TEST 11: Passed. handCount = %d, expected = 0./n", Gest.handCount[Gest.whoseTurn] );
		passList[passCount] = 12;
		passCount++;
	}

	printf( "TEST 13: Player whose turn is ending should have 5 less cards in deck because they are in the discard pile ./n" );	
  if( Gest.deckCount[G.whoseTurn] != ( G.deckCount[G.whoseTurn] - 5 )  ){
		printf( "TEST 13 FAILED. DeckCount = %d, expected = %d./n", Gest.deckCount[G.whoseTurn], (G.deckCount[G.whoseTurn]-5) );
		failList[failCount] = 13;
		failCount++;
	} else {
		printf( "TEST 13 Passed. DeckCount = %d, expected = %d./n", Gest.deckCount[G.whoseTurn], (G.deckCount[G.whoseTurn]-5) );
		passList[passCount] = 13;
		passCount++;
	}

	printf( "TEST 14: New player should have 5 less cards in deck because they drew 5 ./n" );	
  if( Gest.deckCount[Gest.whoseTurn] != (G.deckCount[Gest.whoseTurn] -5 ) ){
		printf( "TEST 14 FAILED. DeckCount = %d, expected = %d./n", Gest.deckCount[Gest.whoseTurn], (G.deckCount[Gest.whoseTurn]-5) );
		failList[failCount] = 14;
		failCount++;
	} else {
		printf( "TEST 14 Passed. DeckCount = %d, expected = %d./n", Gest.deckCount[Gest.whoseTurn], (G.deckCount[Gest.whoseTurn]-5) );
		passList[passCount] = 14;
		passCount++;
	}

	printf( "TEST 15: Player whose turn ended should have 5 cards in discard deck ./n" );	
  if( Gest.discardCount[G.whoseTurn] != 5 ){
		printf( "TEST 15 FAILED. discardCount = %d, expected = 5./n",  Gest.discardCount[G.whoseTurn] );
		failList[failCount] = 15;
		failCount++;
	} else {
		printf( "TEST 15 PASSED. discardCount = %d, expected = 5./n",  Gest.discardCount[G.whoseTurn] );
		passList[passCount] = 15;
		passCount++;
	}

	printf( "TEST 16: New Player should have 0 cards in discard deck because they haven't had a turn ./n" );	
  if( Gest.discardCount[Gest.whoseTurn] != 0 ){
		printf( "TEST 16 FAILED. discardCount = %d, expected = 0./n",  Gest.discardCount[Gest.whoseTurn] );
		failList[failCount] = 16;
		failCount++;
	} else {
		printf( "TEST 16 PASSED. discardCount = %d, expected = 0./n",  Gest.discardCount[Gest.whoseTurn] );
		passList[passCount] = 16;
		passCount++;
	}

	printf( "TEST 17: Played Card Count is Reset to 0 ./n" );	
  if( Gest.playedCardCount != 0 ){
		printf( "TEST 17 FAILED. playedCardCount = %d, expected = 0./n",  Gest.playedCardCount );
		failList[failCount] = 17;
		failCount++;
	} else {
		printf( "TEST 17 PASSED. playedCardCount = %d, expected = 0./n", Gest.playedCardCount );
		passList[passCount] = 17;
		passCount++;
	}

	//Done Testing. Print Unit Test Results
			printf( "****DONE TESTING**** Results: \n");
			printf("%d tests passed -- %d tests failed\n", passCount, failCount);
			printf( "FAILED TESTS: \n");
			for( i=0; i<failCount; i++ ){
				printf( "	%d FAILED\n", failList[i] ); 
			}
    return 0;
}
