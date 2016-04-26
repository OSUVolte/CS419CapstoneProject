#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int checkDeck(struct gameState* state, struct gameState* cpy){

	int i, j;
	int sCards[treasure_map+1];
	memset(sCards, 0, (treasure_map+1)*sizeof(int));
	int dCards[treasure_map+1];
	memset(dCards, 0, (treasure_map+1)*sizeof(int));

	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			sCards[state->deck[i][j]]++;
			dCards[cpy->deck[i][j]]++;
		}
	}

	for(i = 0; i < treasure_map+1; i++){
		if(sCards[i] != dCards[i]) return -1;
	}
	return 0;
}

int checkDeckCount(struct gameState* state, struct gameState* cpy){
	int i;
	for(i = 0; i < MAX_DECK; i++){
		if(state->deckCount[i] != cpy->deckCount[i]) return -1;
	}
	return 0;
}


int checkDiscard(struct gameState* state, struct gameState* cpy){
	int i, j;
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->discard[i][j] != cpy->discard[i][j]) return -1;
		}
	}
	return 0;
}

int checkDiscardCount(struct gameState* state, struct gameState* cpy){
	int i;
	for(i = 0; i < MAX_DECK; i++){
		if(state->discardCount[i] != cpy->discardCount[i]) return -1;
	}
	return 0;
}

int checkState(struct gameState* state, struct gameState* cpy){

	int i, j;

	if(state->numPlayers != cpy->numPlayers) return -1; //number of players
	for(i = 0; i < treasure_map+1; i++){
		if(state->supplyCount[i] != cpy->supplyCount[i]) return -2;
	}
	for(i = 0; i < treasure_map+1; i++){
		if(state->embargoTokens[i] != cpy->embargoTokens[i]) return -3;
	}

	if(state->outpostPlayed != cpy->outpostPlayed) return -4;
	if(state->outpostTurn != cpy->outpostTurn) return -5;
	if(state->whoseTurn != cpy->whoseTurn) return -6;
	if(state->phase != cpy->phase) return -7;
	if(state->numActions != cpy->numActions) return -8; /* Starts at 1 each turn */
	if(state->numBuys != cpy->numBuys) return -9; /* Starts at 1 each turn */
	if(state->coins != cpy->coins) return -10; /* Use as you see fit! */
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_HAND; j++){
			if(state->hand[i][j] != cpy->hand[i][j]) return -11;
		}
	}
	for(i = 0; i < cpy->numPlayers; i++){
		if(state->handCount[i] != cpy->handCount[i]) return -12;
	}
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->discard[i][j] != cpy->discard[i][j]) return -13;
		}
	}
	for(i = 0; i < cpy->numPlayers; i++){
		if(state->discardCount[i] != cpy->discardCount[i]) return -14;
	}
	for(i = 0; i < MAX_DECK; i++){
		if(state->playedCards[i] != cpy->playedCards[i]) return -15;
	}

	if(state->playedCardCount != cpy->playedCardCount) return -16;

	for(i = 0; i < cpy->numPlayers; i++){
		if(state->deckCount[i] != cpy->deckCount[i]) return -17;
	}
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->deck[i][j] != cpy->deck[i][j]) return -18;
		}
	}
	return 0;
}

void setupRandomTestState(int numPlayers, struct gameState* state){
	int i, j;
	state->numPlayers = numPlayers; //number of players
	for(i = 0; i < treasure_map+1; i++){
		state->supplyCount[i] = rand() % MAX_DECK;  //this is the amount of a specific type of card given a specific number.
		state->embargoTokens[i] = rand() % MAX_DECK;
	}
	state->outpostPlayed = rand() % 2;
	state->outpostTurn = rand() % 2;
	state->whoseTurn = rand() % numPlayers;
	state->phase = rand() % 2;
	state->numActions = rand()% 5 + 1;
	state->coins = rand() % 5;
	state->numBuys = rand() % 5; /* Starts at 1 each turn */
	for(i = 0; i < numPlayers; i++){
		state->handCount[i] = rand() % MAX_HAND;
		state->deckCount[i] = rand() % MAX_DECK;
		state->discardCount[i] = rand() % MAX_DECK;
		for(j = 0; j < state->handCount[i]; j++){
			state->hand[i][j] = rand() % (treasure_map+1);
		}
		for(j = 0; j < state->deckCount[i]; j++){
			state->deck[i][j] = rand() % (treasure_map+1);
		}
		for(j = 0; j < state->discardCount[i]; j++){
			state->discard[i][j] = rand() % (treasure_map+1);
		}
	}
	state->playedCardCount = rand() % MAX_DECK;
	for(i = 0; i < state->playedCardCount; i++){
		state->playedCards[i] = rand() % (treasure_map+1);
	}
	return;
}

int* getDeckCount(int player, struct gameState* state){
	int* dC = (int*)(malloc((treasure_map+1)*sizeof(int)));
	memset(dC, 0, (treasure_map+1)*sizeof(int));

	int i;
	for(i = 0; i < state->handCount[player]; i++){
		dC[state->hand[player][i]]++;
	}
	for(i = 0; i < state->deckCount[player]; i++){
		dC[state->deck[player][i]]++;
	}
	for(i = 0; i < state->discardCount[player]; i++){
		dC[state->discard[player][i]]++;
	}

	return dC;
}

int checkGameOver(struct gameState* state){

	if(!state->supplyCount[province]){
		return 1;
	}
	int i, count = 0;
	for(i = 0; i < treasure_map+1; i++){
		if(state->supplyCount[i] == 0) count++;
		if(count >= 3) return 1;
	}

	return 0;
}
