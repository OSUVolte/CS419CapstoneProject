//Joseph Cuellar
//CS - 362
//TEST - Embargo Card 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int EmbargoTEST(struct gameState *post, int handPos);

int main(){
	int player, handPos, numPlayers;
	int numTests = 600;
	int maxPlayers = 5;
	int i, j, m, n, q, r, s;
	struct gameState postGameState;

	SelectStream(2);
	PutSeed(3);
	printf ("START - Running callEmbargoCard().\n\n");
	
	for(s = 0; s < numTests; s++){
		for(numPlayers = 2; numPlayers < maxPlayers; numPlayers++){
			for(player = 0; player < numPlayers; player++)	{
				for (i = 0; i < sizeof(struct gameState); i++) {
					((char*)&postGameState)[i] = floor(Random() * 256);
				}
				postGameState.whoseTurn = player;
				postGameState.numPlayers = numPlayers;
				
				for(j = 0; j < numPlayers; j++){
					postGameState.handCount[j] = floor(Random() * MAX_HAND)+1;
					postGameState.deckCount[j] = floor(Random() * MAX_DECK);
					postGameState.discardCount[j] = floor(Random() * MAX_DECK);
					
					for(m = 0; m < postGameState.handCount[j]; m++){
						postGameState.hand[j][m] = floor(Random() * treasure_map) + 1;
					}
					
					for(r = 0; r < postGameState.discardCount[j]; r++){
						postGameState.discard[j][r] = floor(Random() * treasure_map) + 1;
					}

					for(n = 0; n < postGameState.deckCount[j]; n++){
						postGameState.deck[j][n] = floor(Random() * treasure_map) + 1;
					}

				}
				
				postGameState.playedCardCount = floor(Random() * MAX_DECK);
				for(q = 0; q < postGameState.playedCardCount; q++){
					postGameState.playedCards[q] = floor(Random() * treasure_map) + 1;
				}	
				postGameState.numBuys = 1;
				handPos = floor(Random() * postGameState.handCount[player]);
				postGameState.hand[player][handPos] = council_room;
				
				EmbargoTEST(&postGameState, handPos);
				
			}
		}
	}
	
	printf ("STOP - Running callEmbargoCard().\n\n");
	return 0;
}


int EmbargoTEST(struct gameState *post, int handPos){
	int player = post->whoseTurn;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	
	callEmbargoCard(post, copper, player, handPos);

	if(post->coins == pre.coins){
		printf("ERROR! Coins were not incremented!\n");
	}
	if(post->embargoTokens[copper] == pre.embargoTokens[copper]){
		printf("ERROR! Supply pile as not incremented!\n");
	}

	return 0;
}