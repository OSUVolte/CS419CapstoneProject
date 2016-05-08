#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

/*******************************************************
** Random test for the Council Room card
** Council Room:
**   Add four cards to the person who played the card
**   Add one buy to the person who played the card
**   Add one card to every other player
*******************************************************/


// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


int main() {
	int numTests = 10000;
	int totalNumTests = numTests;
	int failedTests = 0;
	
	
	int i, j;
	int seed = 1000;
	int p, r;
	int k[10] = {
		adventurer,
		remodel,
		feast,
		mine,
		gardens,
		smithy,
		village,
		baron,
		great_hall,
		council_room
	};
	struct gameState G;
		
	printf ("TESTING Council Room CARD:\n");
	//Random number seed
	srand(time(NULL));
		
	while(numTests > 0){
		
		int testFailed = 0;
		
		//***********************************
		//Set up the scenario
		//***********************************
		
		// set up the deck
		// cards should be between 7 and 26
		// council_room is 8
		for(i = 0; i < 10; i++){
			int validCard = 0;
			while(validCard != 1){
				validCard = 1;
				k[i] = (rand() % 19) + 7;
				// make sure the new card isn't the council room
				while(k[i] == 8)
					k[i] = (rand() % 19) + 7;
				// make sure the new card isn't a repeat
				for(j = 0; j < i; j++){
					if(k[i] == k[j])
						validCard = 0;
				}
			}
		}
		// add the council room card to the deck randomly
		int councilRoomIndex = rand() % 10;
		k[councilRoomIndex] = 8;
		
		
		// set the number of players
		int numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;
		// clear the game state
		memset(&G, 23, sizeof(struct gameState));
		// initialize a new game
		r = initializeGame(numPlayers, k, seed, &G);
		
		
		
		for(i = 0; i < numPlayers; i++){
			G.handCount[i] = (rand() % (MAX_HAND - 4)) + 0;
		}
		
		
		
#if (NOISY_TEST == 1)
		printf("\n-----NEW GAME-----\n");
		printf("numPlayers: %i\n", G.numPlayers);
		for(i = 0; i < 10; i++)
			printf("[%i]", k[i]);
		printf("\n");
		printf("handCount\n");
		for(i = 0; i < G.numPlayers; i++){
			printf("--Player %i handCount: %i\n", i, G.handCount[i]);
		}
#endif
		
		G.whoseTurn = rand() % G.numPlayers;
		
		//Give player one a Council Room card
		G.hand[G.whoseTurn][0] = council_room;
		
		// Get the information from before the play
		int prePlayHandCount[G.numPlayers];
		for(i = 0; i < G.numPlayers; i++)
			prePlayHandCount[i] = G.handCount[i];
		int prePlayBuyCount = G.numBuys;
		
		// Play the card
		playCard(0, 0, 0, 0, &G);
		
		// Get the information from after the play
		int postPlayHandCount[G.numPlayers];
		for(i = 0; i < G.numPlayers; i++)
			postPlayHandCount[i] = G.handCount[i];
		int postPlayBuyCount = G.numBuys;
		
		for(i = 0; i < G.numPlayers; i++){
			testFailed = 0;
			//Test for the player who just played the Council Room Card
			if(i == G.whoseTurn){
				// Test the hand count
				if(postPlayHandCount[i] != prePlayHandCount[i] + 3){
					printf("\nERROR - Dealing Player Hand Count\n");
					printf("--Expected: %i\n", prePlayHandCount[i] + 3);
					printf("--Got:      %i\n", postPlayHandCount[i]);
					printf("--Pre:      %i\n", prePlayHandCount[i]);
					testFailed = 1;
				}
			} else {
				if(postPlayHandCount[i] != prePlayHandCount[i] + 1){
					printf("\nERROR - Non Dealing Player Hand Count\n");
					printf("--Expected: %i\n", prePlayHandCount[i] + 1);
					printf("--Got:      %i\n", postPlayHandCount[i]);
					printf("--Pre:      %i\n", prePlayHandCount[i]);
					testFailed = 1;
				}
			}
			//Test the buy count
			if(postPlayBuyCount != prePlayBuyCount + 1){
				printf("\nERROR - Buy Count\n");
				printf("--Expected: %i\n", prePlayBuyCount + 1);
				printf("--Got:      %i\n", postPlayBuyCount);
				testFailed = 1;
			}
			//If one of the test failed, record it
			if(testFailed != 0){
				failedTests++;
				printf("-----FAILURE REPORT-----\n");
				printf("numPlayers: %i\n", G.numPlayers);
				printf("whoseTurn:  %i\n", G.whoseTurn);
				printf("deck\n");
				for(i = 0; i < 10; i++)
					printf("[%i]", k[i]);
				printf("\n");
				printf("handCount\n");
				for(i = 0; i < G.numPlayers; i++){
					printf("--Player %i handCount: %i\n", i, G.handCount[i]);
				}
				printf("-----END FAILURE REPORT-----\n");
			}
		}		
		
		numTests--;
	}

	printf("\n------------------------------\n");
	printf("Council Room Random Tests Finished\n");
	printf("--Total Tests:  %i\n", totalNumTests);
	printf("--Passed Tests: %i\n", totalNumTests - failedTests);
	printf("--Failed Tests: %i\n", failedTests);
	printf("------------------------------\n");
	
	return 0;
}
