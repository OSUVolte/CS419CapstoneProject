//Assignment #3 - Joseph Cuellar
//CS - 362
//This is to test shuffle() and see if cards are properly shuffled
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

const int CARDS_TO_PLAY[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

int main(){
	int numberOfcurrentPlayers, currentPlayer, deckCount;
	struct gameState postGameState; 

	SelectStream(2);
	PutSeed(3);
	printf("START - Running shuffle() unittest1.\n");
	
	for(numberOfcurrentPlayers = 2; numberOfcurrentPlayers <= MAX_PLAYERS; numberOfcurrentPlayers++){
		for(currentPlayer = 0;  currentPlayer < numberOfcurrentPlayers; currentPlayer++){
			for(deckCount = 4; deckCount < 50; deckCount++) 
			{
				int i;
				for (i = 0; i < sizeof(struct gameState); i++) { 
					((char*)&postGameState)[i] = floor(Random() * 256);
				}
				
				int j;
				for(j = 0; j < deckCount; j++){
					int card = floor(Random() * 10);
					postGameState.deck[currentPlayer][j] = CARDS_TO_PLAY[card];
				}
				
				postGameState.numPlayers = numberOfcurrentPlayers;
				postGameState.deckCount[currentPlayer] = deckCount;
				
				struct gameState preGameState;
				memcpy(&preGameState, &postGameState, sizeof(struct gameState));
				
				if(shuffle(currentPlayer, &postGameState) != 0){
					printf("ERROR! shuffle failed.\n\n");
				}
				else if(preGameState.deckCount[currentPlayer] != postGameState.deckCount[currentPlayer]){
					printf("ERROR! Deck counts are NOT equal.\n\n");
				}
				else if(memcmp(&preGameState.deck[currentPlayer], postGameState.deck[currentPlayer], sizeof(int) * preGameState.deckCount[currentPlayer]) == 0){
					printf("ERROR! Deck failed to shuffle.\n");
				}
			}
		}
	}
	printf ("END - Running shuffle() unittest1.\n\n");
	return 0;
}