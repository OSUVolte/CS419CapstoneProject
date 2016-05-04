#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
//This is a unit test for the card Village function using random testing.
//int villageCard(int currentPlayer, struct gameState *state, int handPos);
// Input:   int currentplayer -> currentplayer
//          struct gameState *state -> data about the game
//          int handPos -> Position of where the card is so it can be discarded later.
//Business Rules:
//1. It adds one card to the player's hand.
//2. The card added has to be from the player's deck.
//3. It gives the player 2 actions. 
//4. Other players' states should be unchanged.
// +1 Card to the Current Player's Hand.
// +2 Actions to the Current Player Only.
// Discards the Village Card from the current player's hand. 
// Break the code and make sure the tests detect the problem.
// Ensure the card's function works with various states of the game state.
// Varying deck sizes and players(?) 

int main () {
        //Set Random Generator.
	srand(time(NULL));
 	struct gameState pre,post;

 	int i;
 	int player;
	int pass = 1;
	int passCtr = 0;
	int runs = 10000;
	int failedTests[runs];
	int testsCtr = 0;

 	for(i = 0; i < runs; i++){

        	printf("\nRANDOM GAME %i\n:",i);
		//Set up a Random player.
 		player = floor( rand() % MAX_PLAYERS);
		printf("CURRENT PLAYER: %i\n",player);
 
		//Randomize the DECK, DISCARD AND HAND.
		pre.deckCount[player] = floor( rand() % MAX_DECK);
		printf("DECK COUNT: %i\n", pre.deckCount[player]);
		pre.discardCount[player] = floor( rand() % MAX_DECK);
		printf("DISCARDCOUNT: %i\n", pre.discardCount[player]);
		pre.handCount[player] = floor( rand() % MAX_HAND + 1);
		printf("HANDCOUNT: %i\n", pre.handCount[player]);

		//Randomize the villager card in the player's hand.
		int handPos;
        	int max_handpos = pre.handCount[player];
		handPos = floor( rand() % max_handpos );
        	printf("POSITION of VILLAGE CARD IN HAND: %i\n", handPos);
		pre.hand[player][handPos] = village;

		//Randomize the number of actions.
		int maxActions = 15;
		pre.numActions = floor( rand() % maxActions );
		printf("NUMBER OF ACTIONS PRE: %i\n", pre.numActions);

 		memcpy( &post, &pre, sizeof(struct gameState));

		//Call the function.
		printf("Calling the function.\n");

		//Save the state of the game.
		int returnVal;
		returnVal = villageCard(player, &post, handPos);

		//Oracle Code: Check that it works.
		//Check that the number of actions increased by 2.
		if( pre.numActions + 2 ==  post.numActions ){
			printf("The player correctly gains +2 actions.\n");
		}else{
			printf("ERROR: PRE-ACTIONS:%i POST-ACTIONS:%i\n", pre.numActions, post.numActions);
			pass = 0;
		}

		//Check that a card was drawn drom the deck.
		//Deck should be decremented by one.
		if( pre.deckCount[player] == 0 ){
			if( post.deckCount[player] + 1 == pre.discardCount[player] ){
				
			}else{
				printf("ERROR: PRE-DISCARD COUNT: %i POST-DECKCOUNT:%i  \n", pre.discardCount[player], post.deckCount[player]); 
				pass = 0;
			}

		}else{
			if( pre.deckCount[player] -1  == post.deckCount[player] ){
				printf("The card was successfully drawn from the player's deck.\n");
			}else{
				printf("ERROR: PRE-DECKCOUNT: %i POST-DECKCOUNT:%i\n", pre.deckCount[player], post.deckCount[player]);
				pass = 0;
			}
		}

		//Hand Size shouldn't change. +1 New card -1Village.
		if( pre.handCount[player] != post.handCount[player] ){
			printf("Either the village card was not discarded or a new card was not successfully added to the hand.\n");
			pass = 0;
		}
	
		//Check that the Village card is no longer in that position.
		if( post.hand[player][handPos] != village ){
			printf("The village card used is successfully not in the hand.\n");
		}else{
			printf("The village card used is still in the hand.\n");
			pass = 0;
		}
	
		//Check that the game had no issues.
		if(  returnVal != 0 ){
			printf("ERROR:CALLED FN RETURNED AN ERROR.\n");
			pass = 0;
		}
	
		//Check that no other game state has been altered.
		//Set the changed variables to be equal to each other.
		post.numActions = pre.numActions;
		post.deckCount[player] = pre.deckCount[player];
		pre.handCount[player] = post.handCount[player];
		post.hand[player][handPos] = village; 

		if( memcmp(&pre, &post, sizeof(struct gameState)) == 0){
			printf("ERROR: GAME STATE VARIABLES WERE CHANGED THAT SHOULDN't HAVE.\n");
			pass = 0;
		}
	
		//CHECK IF ALL TESTS PASSED.
		if( pass == 1 ){
			printf("ALL TESTS PASSED.\n");
			passCtr++;
		}else{
			printf("ERROR: TEST(S) FAILED.\n");
			failedTests[testsCtr] = i;
			testsCtr++;		
		}
		//RESET THE PASS BOOLEAN.
		pass = 1;	

  	}

	printf("%i passed out of  %i RUNS\n\n\n", passCtr, runs );
	int k;
	for( k = 0; k < testsCtr; k++){
		printf("FAILED: RUN %i", failedTests[k]);
	}
	
	return 0;
 
} 

