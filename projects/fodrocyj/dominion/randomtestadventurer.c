#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

/*******************************************************
** Random test for the Adventurer card
** Adventurer:
**  Reveal cards from your deck until you reveal 2 Treasure cards
**  Put the Treasure cards inoto your hand
**  Discard the other revealed cards
*******************************************************/


// set NOISY_TEST to 0 to remove printfs from output
// set NOISY_TEST to 1 to show basic printfs
// set NOISY_TEST to 2 to show more printfs
#define NOISY_TEST 0


int main() {
	int numTests = 5000;
	int totalNumTests = numTests;
	int failedTests = 0;
	
	
	int i, j, r;
	int seed = 1000;
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
		
	printf ("TESTING Adventurer CARD:\n");
	//Random number seed
	srand(time(NULL));
		
	while(numTests > 0){
		
		int testFailed = 0;
		
		//***********************************
		//Set up the scenario
		//***********************************
		
		// set up the deck
		// cards should be between 7 and 26
		// adventurer is 7
		for(i = 0; i < 10; i++){
			int validCard = 0;
			while(validCard != 1){
				validCard = 1;
				k[i] = (rand() % 19) + 7;
				// make sure the new card isn't the adventurer
				while(k[i] == 7)
					k[i] = (rand() % 19) + 7;
				// make sure the new card isn't a repeat
				for(j = 0; j < i; j++){
					if(k[i] == k[j])
						validCard = 0;
				}
			}
		}
		// add the adventurer card to the deck randomly
		int adventurerIndex = rand() % 10;
		k[adventurerIndex] = 7;
		
		
		// set the number of players
		int numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;
		// clear the game state
		memset(&G, 23, sizeof(struct gameState));
		// initialize a new game
		r = initializeGame(numPlayers, k, seed, &G);
		
		
		//Setup the hands, decks and discards of the players
		for(i = 0; i < numPlayers; i++){
			G.handCount[i] = rand() % (MAX_HAND - 3) + 2;
			//Make the decks for the players - don't give Treasure cards
			G.deckCount[i] = rand() % (MAX_DECK - 3) + 2;
				for(j = 0; j < G.deckCount[i]; j++){
					G.deck[i][j] = (rand() % 19) + 7;
				}
			G.discardCount[i] = 0;
		}
		
		
		
#if (NOISY_TEST >= 2)
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
		
		//Give the players whose turn it is random cards
		for(i = 0; i < G.numPlayers; i++){
			for(j = 0; j < G.handCount[i]; j++){
				G.hand[i][j] = k[rand() % 10];
			}
		}
		
		//Give player whose turn it is an Adventurer card
		G.hand[G.whoseTurn][0] = adventurer;
		
		//Give the player whose turn it is two treasure cards
		int treasureCardOnePos, treasureCardTwoPos, validCardPos;
		treasureCardOnePos = rand() % G.deckCount[G.whoseTurn];
		validCardPos = 0;
		while(validCardPos == 0){
			treasureCardTwoPos = rand() % G.deckCount[G.whoseTurn];
			if(treasureCardOnePos != treasureCardTwoPos)
				validCardPos = 1;
		}
		
		//printf("treasureCardOnePos: %i\n", treasureCardOnePos);
		//printf("treasureCardTwoPos: %i\n", treasureCardTwoPos);
		
		G.deck[G.whoseTurn][treasureCardOnePos] = copper;
		G.deck[G.whoseTurn][treasureCardTwoPos] = copper;
		
		//Get the number of cards the player will have to draw for Treasure
		int cardsToDraw;
		if(treasureCardOnePos < treasureCardTwoPos){
			cardsToDraw = G.deckCount[G.whoseTurn] - treasureCardOnePos;
		} else {
			cardsToDraw = G.deckCount[G.whoseTurn] - treasureCardTwoPos;
		}
		
		// Get the information from before the play
		int prePlayHandCount[G.numPlayers];
		int prePlayDeckCount[G.numPlayers];
		int prePlayDiscardCount[G.numPlayers];
		for(i = 0; i < G.numPlayers; i++){
			prePlayHandCount[i] = G.handCount[i];
			prePlayDeckCount[i] = G.deckCount[i];
			prePlayDiscardCount[i] = G.discardCount[i];
		}
		int prePlayActionCount = G.numActions;
		
		// Play the card
		playCard(0, 0, 0, 0, &G);
		
		// Get the information from after the play
		int postPlayHandCount[G.numPlayers];
		int postPlayDeckCount[G.numPlayers];
		int postPlayDiscardCount[G.numPlayers];
		for(i = 0; i < G.numPlayers; i++){
			postPlayHandCount[i] = G.handCount[i];
			postPlayDeckCount[i] = G.deckCount[i];
			postPlayDiscardCount[i] = G.discardCount[i];
		}
		int postPlayActionCount = G.numActions;
		
		
		//*************************************************
		//COMPARE THE PRE AND POST STATUS OF THE GAME STATE
		for(i = 0; i < G.numPlayers; i++){
			testFailed = 0;
			//Test for the player who just played the Adventurer Card
			if(i == G.whoseTurn){
				// Test the hand count
				if(postPlayHandCount[i] != prePlayHandCount[i] + 2){
					printf("\nERROR - Dealing Player Hand Count\n");
					printf("--Player Position: %i\n", i);
					printf("--Expected: %i\n", prePlayHandCount[i] + 2);
					printf("--Got:      %i\n", postPlayHandCount[i]);
					printf("--Pre:      %i\n", prePlayHandCount[i]);
					testFailed = 1;
				}
				// Test the deck count
				if(postPlayDeckCount[i] != prePlayDeckCount[i] - cardsToDraw){
					printf("\nERROR - Dealing Player Deck Count\n");
					printf("--Player Position: %i\n", i);
					printf("--Expected: %i\n", prePlayDeckCount[i] - cardsToDraw);
					printf("--Got:      %i\n", postPlayDeckCount[i]);
					printf("--Pre:      %i\n", prePlayDeckCount[i]);
					testFailed = 1;
				}
				// Test the discard count
				if(postPlayDiscardCount[i] != prePlayDiscardCount[i] + cardsToDraw - 2){
					printf("\nERROR - Dealing Player Discard Count\n");
					printf("--Player Position: %i\n", i);
					printf("--Expected: %i\n", postPlayDiscardCount[i] + cardsToDraw - 2);
					printf("--Got:      %i\n", postPlayDiscardCount[i]);
					printf("--Pre:      %i\n", prePlayDiscardCount[i]);
					testFailed = 1;
				}
			//Test for the players who aren't playing the cards
			} else {
				// Test the hand count
				if(postPlayHandCount[i] != prePlayHandCount[i]){
					printf("\nERROR - Non Dealing Player Hand Count\n");
					printf("--Player Position:   %i\n", i);
					printf("--Dealers Position:  %i\n", G.whoseTurn);
					printf("--Expected: %i\n", prePlayHandCount[i]);
					printf("--Got:      %i\n", postPlayHandCount[i]);
					printf("--Pre:      %i\n", prePlayHandCount[i]);
					testFailed = 1;
				}
				// Test the deck count
				if(postPlayDeckCount[i] != prePlayDeckCount[i]){
					printf("\nERROR - Non Dealing Player Deck Count\n");
					printf("--Player Position:   %i\n", i);
					printf("--Dealers Position:  %i\n", G.whoseTurn);
					printf("--Expected: %i\n", prePlayDeckCount[i]);
					printf("--Got:      %i\n", postPlayDeckCount[i]);
					printf("--Pre:      %i\n", prePlayDeckCount[i]);
					testFailed = 1;
				}
				// Test the discard count
				if(postPlayDiscardCount[i] != prePlayDiscardCount[i]){
					printf("\nERROR - Non Dealing Player Discard Count\n");
					printf("--Player Position:   %i\n", i);
					printf("--Dealers Position:  %i\n", G.whoseTurn);
					printf("--Expected: %i\n", prePlayDiscardCount[i]);
					printf("--Got:      %i\n", postPlayDiscardCount[i]);
					printf("--Pre:      %i\n", prePlayDiscardCount[i]);
					testFailed = 1;
				}
			}
			
			//Test the action count
			if(postPlayActionCount != prePlayActionCount - 1){
				printf("\nERROR - Buy Count\n");
				printf("--Expected: %i\n", prePlayActionCount - 1);
				printf("--Got:      %i\n", postPlayActionCount);
				testFailed = 1;
			}
			
			//Test if the player has 2 coppers in their hand
			int copperCount = 0;
			for(i = 0; i < G.handCount[G.whoseTurn]; i++){
				if(G.hand[G.whoseTurn][i] == copper)
					copperCount++;
			}
			if(copperCount != 2){
				printf("\nERROR - Dealing Player Copper Count\n");
				printf("--Expected 2\n");
				printf("--Got:     %i\n", copperCount);
				testFailed = 1;
			}
			
			//If one of the test failed, record it
			if(testFailed != 0){
				failedTests++;
#if (NOISY_TEST >= 1)
				printf("-----FAILURE REPORT-----\n");
				printf("numPlayers: %i\n", G.numPlayers);
				printf("deck\n");
				for(i = 0; i < 10; i++)
					printf("[%i]", k[i]);
				printf("\n");
				printf("handCount\n");
				for(i = 0; i < G.numPlayers; i++){
					printf("--Player %i handCount: %i\n", i, G.handCount[i]);
				}
				printf("-----END FAILURE REPORT-----\n");
#endif
			}
		}		
		
		numTests--;
	}

	printf("\n------------------------------\n");
	printf("Adventurer Random Tests Finished\n");
	printf("--Total Tests:  %i\n", totalNumTests);
	printf("--Passed Tests: %i\n", totalNumTests - failedTests);
	printf("--Failed Tests: %i\n", failedTests);
	printf("------------------------------\n");
	
	return 0;
}
