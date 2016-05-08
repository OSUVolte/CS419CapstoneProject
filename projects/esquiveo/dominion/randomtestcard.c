// Osbaldo Esquivel
// CS 362
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"

/*
 * This program will test the cutpurse card by randomizing the state of the
 * game and then comparing the results to what the expected results are. This
 * is done using assert statements that will fail if they are not true.
 */

#define TESTNUM 4000
 
int main() {
	int i, j, ii, count, preCount, treasure, val, currUser = 0, 
	    tempCard, preBuys, preAction, zed = -200, copp = copper, 
	    cut = cutpurse;
	struct gameState *game = newGame();
	
	// set rngs variables	
	SelectStream(2);
	PutSeed(3);
	
	printf("Random test for cutpurse card begins.\n");
	
	for(i = 0; i < TESTNUM; i++) {
		// random treasure value
		treasure = floor(Random() * 2);
		
		// set random hand count for players
		for(j = 0; j < game->numPlayers; j++) {
			game->handCount[j] = 1 + (floor(Random() * 15));
		}
		
		// randomize count, actions, and buys for player
		preAction = floor(Random() * 10);
		preBuys = floor(Random() * 5);
		preCount = floor(Random() * 5);
		
		// randomize game state
		game->coins = floor(Random() * 8);
		game->numActions = preAction;
		game->playedCardCount = preCount;
		game->discardCount[currUser] = floor(Random() * 50);
		game->deckCount[currUser] = (floor(Random() * 41)) + 10;
		game->numBuys = preBuys;
		game->numPlayers = MAX_PLAYERS - (floor(Random() * 2));
		
		// set hand values to some number other than zero
		// to indicate it is empty
		for(j = 0; j < game->numPlayers; j++) {
			for(ii = 0; ii < MAX_HAND; ii++) {
				game->hand[j][ii] = zed;
			}
			
			for(ii = 0; ii < game->numPlayers; ii++) {
				game->hand[j][ii] = treasure * copp;
			}
		}
		
		for(ii = 0; ii < MAX_DECK; ii++) {
			game->deck[currUser][ii] = zed;
			game->discard[currUser][ii] = zed;
		}
		
		for(ii = 0; ii < game->discardCount[currUser]; ii++) {
			game->discard[currUser][ii] = 0;
		}
		
		for(ii = 0; ii < game->deckCount[currUser]; ii++) {
			game->deck[currUser][ii] = 0;
		}
		
		// set value to result of cardEffect function
		val = cardEffect(cut,0,0,0,game,2,NULL);
		
		// assert that actions and value of cardAffect match 
		// expectations
		assert(preAction == game->numActions);
		assert(val == 0);
		//assert(preBuys == game->numBuys);
		
		// check player hands to make sure cutpurse worked
		for(j = 0; j < game->numPlayers; j++) {
			count = 0;
			
			for(ii = 0; ii < game->handCount[j]; ii++) {
				if(game->hand[j][ii] == copp) {
					count = count + 1;
				}
			}
			
			if(!treasure) {
				assert(game->playedCardCount == preCount + 1);
				assert(0 == count);
			}
			else {
				assert(preCount + game->numPlayers == game->playedCardCount);
			}
		}
	}
	
	printf("All tests have passed.\n");
	
	return 0;
}
