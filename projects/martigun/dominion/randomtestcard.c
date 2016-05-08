//Gunnar Martin
//CS362
//Assignment #4
//
//Random test: Smithy Card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <tgmath.h>
#include "rngs.h"

#define TRACERS 1
#define NBR_OF_TESTS 10

//For reference...
// struct gameState {
	// int numPlayers; //number of players
	// int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
	// int embargoTokens[treasure_map+1];
	// int outpostPlayed;
	// int outpostTurn;
	// int whoseTurn;
	// int phase;
	// int numActions; /* Starts at 1 each turn */
	// int coins; /* Use as you see fit! */
	// int numBuys; /* Starts at 1 each turn */
	// int hand[MAX_PLAYERS][MAX_HAND];
	// int handCount[MAX_PLAYERS];
	// int deck[MAX_PLAYERS][MAX_DECK];
	// int deckCount[MAX_PLAYERS];
	// int discard[MAX_PLAYERS][MAX_DECK];
	// int discardCount[MAX_PLAYERS];
	// int playedCards[MAX_DECK];
	// int playedCardCount;
// };

//compare 2 game states
void compareStates(struct gameState *state1, struct gameState *state2){
	
	int i, j;
	
	//Check series A
	
	//numPlayers
	if(state1->numPlayers != state2->numPlayers){
		printf("@@@ compareStates @@@\n");
		printf("numPlayers NOT EQUAL\n");
		printf("state1->numPlayers: %d\n",state1->numPlayers);
		printf("state2->numPlayers: %d\n",state2->numPlayers);
	}
	
	//outpostPlayed
	if(state1->outpostPlayed != state2->outpostPlayed){
		printf("@@@ compareStates @@@\n");
		printf("outpostPlayed NOT EQUAL\n");
		printf("state1->outpostPlayed: %d\n",state1->outpostPlayed);
		printf("state2->outpostPlayed: %d\n",state2->outpostPlayed);
	}
	
	//outpostTurn
	if(state1->outpostTurn != state2->outpostTurn){
		printf("@@@ compareStates @@@\n");
		printf("outpostTurn NOT EQUAL\n");
		printf("state1->outpostTurn: %d\n",state1->outpostTurn);
		printf("state2->outpostTurn: %d\n",state2->outpostTurn);
	}
	
	//whoseTurn
	if(state1->whoseTurn != state2->whoseTurn){
		printf("@@@ compareStates @@@\n");
		printf("whoseTurn NOT EQUAL\n");
		printf("state1->whoseTurn: %d\n",state1->whoseTurn);
		printf("state2->whoseTurn: %d\n",state2->whoseTurn);
	}
	
	//phase
	if(state1->phase != state2->phase){
		printf("@@@ compareStates @@@\n");
		printf("phase NOT EQUAL\n");
		printf("state1->phase: %d\n",state1->phase);
		printf("state2->phase: %d\n",state2->phase);
	}
	
	//numActions
	if(state1->numActions != state2->numActions){
		printf("@@@ compareStates @@@\n");
		printf("numActions NOT EQUAL\n");
		printf("state1->numActions: %d\n",state1->numActions);
		printf("state2->numActions: %d\n",state2->numActions);
	}
	
	//coins
	if(state1->coins != state2->coins){
		printf("@@@ compareStates @@@\n");
		printf("coins NOT EQUAL\n");
		printf("state1->coins: %d\n",state1->coins);
		printf("state2->coins: %d\n",state2->coins);
	}
	
	//numBuys
	if(state1->numBuys != state2->numBuys){
		printf("@@@ compareStates @@@\n");
		printf("numBuys NOT EQUAL\n");
		printf("state1->numBuys: %d\n",state1->numBuys);
		printf("state2->numBuys: %d\n",state2->numBuys);
	}
	
	//playedCardCount
	if(state1->playedCardCount != state2->playedCardCount){
		printf("@@@ compareStates @@@\n");
		printf("playedCardCount NOT EQUAL\n");
		printf("state1->playedCardCount: %d\n",state1->playedCardCount);
		printf("state2->playedCardCount: %d\n",state2->playedCardCount);
	}
	
	//Check series B
	for (i=0; i<MAX_PLAYERS; i++){
		
		//handCount
		if(state1->handCount[i] != state2->handCount[i]){
			printf("@@@ compareStates @@@\n");
			printf("handCount[%d] NOT EQUAL\n", i);
			printf("state1->handCount[%d]: %d\n",i,state1->handCount[i]);
			printf("state2->handCount[%d]: %d\n",i,state2->handCount[i]);
		}
		
		//deckCount
		if(state1->deckCount[i] != state2->deckCount[i]){
			printf("@@@ compareStates @@@\n");
			printf("deckCount[%d] NOT EQUAL\n", i);
			printf("state1->deckCount[%d]: %d\n",i,state1->deckCount[i]);
			printf("state2->deckCount[%d]: %d\n",i,state2->deckCount[i]);
		}
		
		//discardCount
		if(state1->discardCount[i] != state2->discardCount[i]){
			printf("@@@ compareStates @@@\n");
			printf("discardCount[%d] NOT EQUAL\n", i);
			printf("state1->discardCount[%d]: %d\n",i,state1->discardCount[i]);
			printf("state2->discardCount[%d]: %d\n",i,state2->discardCount[i]);
		}
	}
	
	//Check series C
	for (i=0; i<MAX_PLAYERS; i++){
		for (j=0; j<MAX_DECK; j++){
			
			//hand
			if(state1->hand[i][j] != state2->hand[i][j]){
				printf("@@@ compareStates @@@\n");
				printf("hand[%d][%d] NOT EQUAL\n", i, j);
				printf("state1->hand[%d][%d]: %d\n",i,j,state1->hand[i][j]);
				printf("state2->hand[%d][%d]: %d\n",i,j,state2->hand[i][j]);
			}
			
			//deck
			if(state1->deck[i][j] != state2->deck[i][j]){
				printf("@@@ compareStates @@@\n");
				printf("deck[%d][%d] NOT EQUAL\n", i, j);
				printf("state1->deck[%d][%d]: %d\n",i,j,state1->deck[i][j]);
				printf("state2->deck[%d][%d]: %d\n",i,j,state2->deck[i][j]);
			}
			
			//discard
			if(state1->discard[i][j] != state2->discard[i][j]){
				printf("@@@ compareStates @@@\n");
				printf("discard[%d][%d] NOT EQUAL\n", i, j);
				printf("state1->discard[%d][%d]: %d\n",i,j,state1->discard[i][j]);
				printf("state2->discard[%d][%d]: %d\n",i,j,state2->discard[i][j]);
			}
		}
	}
	
	//Check series D
	for (i=0; i<treasure_map+1; i++){
		
		//supplyCount
		if(state1->supplyCount[i] != state2->supplyCount[i]){
			printf("@@@ compareStates @@@\n");
			printf("supplyCount[%d] NOT EQUAL\n", i);
			printf("state1->supplyCount[%d]: %d\n",i,state1->supplyCount[i]);
			printf("state2->supplyCount[%d]: %d\n",i,state2->supplyCount[i]);
		}
		
		//embargoTokens
		if(state1->embargoTokens[i] != state2->embargoTokens[i]){
			printf("@@@ compareStates @@@\n");
			printf("embargoTokens[%d] NOT EQUAL\n", i);
			printf("state1->embargoTokens[%d]: %d\n",i,state1->embargoTokens[i]);
			printf("state2->embargoTokens[%d]: %d\n",i,state2->embargoTokens[i]);
		}
	}
	
	//Check series EQUAL\n
	for (i=0; i<MAX_DECK; i++){
		
		//playedCards
		if(state1->playedCards[i] != state2->playedCards[i]){
			printf("@@@ compareStates @@@\n");
			printf("playedCards[%d] NOT EQUAL\n", i);
			printf("state1->playedCards[%d]: %d\n",i,state1->playedCards[i]);
			printf("state2->playedCards[%d]: %d\n",i,state2->playedCards[i]);
		}
	}
}

//checkSmithy function
int checkSmithy(int player_nbr, struct gameState *post, int test_run, int handPos) {

	//create struct for game state before running function
	struct gameState pre;
	
	//copy the state to change onto pre
	memcpy (&pre, post, sizeof(struct gameState));
	
	if (TRACERS) printf("~~~~~~~~ checkSmithy ~~~~~~~~\n");
	if (TRACERS) printf("pre.handCount[%d]: %d\n", player_nbr, pre.handCount[player_nbr]);
	if (TRACERS) printf("pre.deckCount[%d]: %d\n", player_nbr, pre.deckCount[player_nbr]);
	if (TRACERS) printf("pre.discardCount[%d]: %d\n", player_nbr, pre.discardCount[player_nbr]);
	if (TRACERS) printf("pre.playedCardCount: %d\n", pre.playedCardCount);
	if (TRACERS) printf("+++ Running cardEffect... +++\n");
	
	//card Effect
	int r = cardEffect(smithy, 0, 0, 0, post, handPos, 0);
	
	if (TRACERS) printf("post->handCount[%d]: %d\n", player_nbr, post->handCount[player_nbr]);
	if (TRACERS) printf("post->deckCount[%d]: %d\n", player_nbr, post->deckCount[player_nbr]);
	if (TRACERS) printf("post->discardCount[%d]: %d\n", player_nbr, post->discardCount[player_nbr]);
	if (TRACERS) printf("post->playedCardCount: %d\n", post->playedCardCount);
	
	//assert that it did not fail
	assert (r == 0);
	
	//test failed if overflow on handCount from drawCard
	if(post->handCount[player_nbr]>=MAX_HAND){
		
		printf("$$$ drawCard caused overflow of hand[] $$$\n");
		printf("test run %d: failed\n", test_run);
		return 0;
	}
	
	//trace the change for all these items
	int handChange = post->handCount[player_nbr] - pre.handCount[player_nbr]; //should be +2
	int deckChange = post->deckCount[player_nbr] - pre.deckCount[player_nbr]; //should be -3
	int playedCardChange = post->playedCardCount - pre.playedCardCount; //should be +1
	
	if (TRACERS) printf("handChange: %d\n", handChange);
	if (TRACERS) printf("deckChange: %d\n", deckChange);
	if (TRACERS) printf("playedCardChange: %d\n", playedCardChange);
	
	//Adjust pre for expected card counts...

	//change played card to +1
	pre.playedCardCount = pre.playedCardCount + 1;
	
	//if our deckCount is greater than 3
	if(pre.deckCount[player_nbr] >= 3){
		//This is normal operating procedure
		
		//Change deckCount by -3 and handCount by +2
		pre.deckCount[player_nbr] = pre.deckCount[player_nbr] - 3;
		pre.handCount[player_nbr] = pre.handCount[player_nbr] + 2;
	} else {
		//This is if the deck is too small, a shuffle will take place
		
		//set pre to post, for deck, discard, and hand
		if (TRACERS) printf("$$$ shuffle took place $$$\n");
		pre.deckCount[player_nbr] = post->deckCount[player_nbr];
		pre.discardCount[player_nbr] = post->discardCount[player_nbr];
		pre.handCount[player_nbr] = post->handCount[player_nbr];
	}
	
	//copy hand, deck, discard, playedCards arrays onto pre
	//since they could all be effected by smitty
	memcpy(pre.hand[player_nbr], post->hand[player_nbr], sizeof(pre.hand[player_nbr]));
	memcpy(pre.deck[player_nbr], post->deck[player_nbr], sizeof(pre.deck[player_nbr]));
	memcpy(pre.discard[player_nbr], post->discard[player_nbr], sizeof(pre.discard[player_nbr]));
	memcpy(pre.playedCards, post->playedCards, sizeof(pre.playedCards));
	
	//compare the game states, member by member
	if (TRACERS) compareStates(&pre, post);
	
	//assert that gameState is the same
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
	printf("test run %d: success\n", test_run);
	
	//return zero
	return 0;
}

int main () {

	//initialize game state and variables
	struct gameState G;
	int i, player_nbr, handPos;
	
	//print what we are testing
	printf ("Testing smithy....\n");

	//init the test run
	int test_run = 1;
	
	//init random values
	SelectStream(2);
	PutSeed(-1); //state obtained by system clock
	
	//create randomized game state
	for (test_run = 0; test_run < NBR_OF_TESTS; test_run++) {
		
		//"completely" randomize the game state
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		
		//"controllably" randomize number of players (Can be 2, 3, or 4)
		G.numPlayers = floor(Random() * 3) + 2;
		
		//"controllably" randomize current player
		player_nbr = floor(Random() * G.numPlayers);
		G.whoseTurn = player_nbr;
		
		//"controllably" randomize key members of state
		G.deckCount[player_nbr] = floor(Random() * MAX_DECK);
		G.discardCount[player_nbr] = floor(Random() * MAX_DECK);
		G.handCount[player_nbr] = floor(Random() * MAX_HAND);
		G.playedCardCount = floor(Random() * MAX_HAND);
		handPos = floor(Random() * G.handCount[player_nbr]);
		
		if(TRACERS) printf("---------------test run: %d-------------------\n",test_run);
		if(TRACERS) printf("G.numPlayers: %d\n",G.numPlayers);
		if(TRACERS) printf("player_nbr: %d\n",player_nbr);
		if(TRACERS) printf("handPos: %d\n",handPos);
		
		//run check smithy
		checkSmithy(player_nbr, &G, test_run, handPos);
	}
	
	//print that tests are done
	printf ("------------------------------\n");
	printf ("smithy tests complete\n");

	return 0;
}
