//Assignment #3 - Joseph Cuellar
//CS - 362
//This is to test discardCard() to see if it can discard a card 
//from the player's hand to the played pile. IF trashed its value becomes -1.
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

const int MAX_CARD_COUNT = 10;

int main(){
	// vars
	int numberOfPlayers, currentPlayer, handPosition, trashFlag;
	struct gameState postGameState; 
	int playedCardCount = 0;
	
	//set up random number generator
	SelectStream(2);
	PutSeed(3);
	printf("START - Running discardCard() unittest1.\n");
	// TEST the max amount of players, each player that is playing, and each card
	for(numberOfPlayers = 2; numberOfPlayers <= MAX_PLAYERS; numberOfPlayers++) {
		for(currentPlayer = 0;  currentPlayer < numberOfPlayers; currentPlayer++){
			for(handPosition = 0; handPosition < MAX_CARD_COUNT; handPosition++){
				int i;
				for (i = 0; i < sizeof(struct gameState); i++) {
					((char*)&postGameState)[i] = floor(Random() * 256);
				}
				postGameState.numPlayers = numberOfPlayers;
				postGameState.playedCardCount = playedCardCount;
				postGameState.handCount[currentPlayer] = MAX_CARD_COUNT;
				trashFlag = floor(Random()*2);
				
				struct gameState preGameState;
				memcpy(&preGameState, &postGameState, sizeof(struct gameState));
				int functionOutput = discardCard(handPosition, currentPlayer, &postGameState, trashFlag);
				
				if( trashFlag < 1){
					preGameState.playedCardCount++;
				}
				preGameState.handCount[currentPlayer]--;
				
				if(functionOutput != 0){
					printf("ERROR! discardCard() failed.\n\n");
				}
				else if(preGameState.playedCardCount != postGameState.playedCardCount){
					printf("ERROR! Played card counts are NOT equal.\n\n");
				}
				else if(preGameState.handCount[currentPlayer] != postGameState.handCount[currentPlayer]){
					printf("ERROR! Player hand counts are NOT equal.\n\n");
				}
			}
		}
	 }
	 printf ("STOP - Running discardCard() unittest1.\n\n");
	 return 0;
}