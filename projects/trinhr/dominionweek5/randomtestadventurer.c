#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
//This is a unit test for the card Adventurer function using randomtest.
//int adventurerCard(struct gameState *state, int currentPlayer, int handPos);
//Input: int currentplayer --> current player
//	 struct gamestate
//	 int handPos
//Business Rules:
//1. It needs to draw cards from the players own deck until
//two treasure cards are revealed. 
//2. The two treasure cards are added to the the player's hand.

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

        	printf("\nRANDOM GAME: %i\n",i);
		//Set up a Random player:0,1,2,3
 		player = floor( rand() % MAX_PLAYERS);
		printf("CURRENT PLAYER: %i\n",player);

		int deckCount = 0;
		int discardCount = 0;
 
		//Randomize the card count in DECK, DISCARD AND HAND.
		//Has to be at least four cards total between the two decks. 
		while( deckCount + discardCount < 4 ){
		
			pre.deckCount[player] = floor( rand() % MAX_DECK);
			printf("DECK COUNT: %i\n", pre.deckCount[player]);
			pre.discardCount[player] = floor( rand() % MAX_DECK);
			printf("DISCARD COUNT: %i\n", pre.discardCount[player]);
			pre.handCount[player] = floor( rand() % MAX_HAND +1);
			printf("HAND COUNT: %i\n", pre.handCount[player]);

			deckCount = pre.deckCount[player];
			discardCount = pre.discardCount[player];
		}

		//Randomize the cards in the DECK and DISCARD.
		int i;
		for( i = 0; i < deckCount; i++){
			pre.deck[player][i] = village;
		}

		int j;
		for( j = 0; j < discardCount; j++){
			pre.discard[player][j] = village;
		}

		//Ensure there are at least two treasure cards in the combined decks.
		//Randomize the position of the treasures. 
		int firstPos;
		int secPos;

		//Randomize the treasure.
		int randTres1 = floor( rand() % 3 );
		int randTres2 = floor( rand() % 3 );
		int treasure1;
		int treasure2;

		if(randTres1 == 0){
			treasure1 = copper;
		}else if(randTres1 == 1){
			treasure1 = silver;
		}else{
			treasure1 = gold;
		}

		if(randTres2 == 0){
			treasure2 = copper;
		}else if(randTres2 == 1){
			treasure2 = silver;
		}else{
			treasure2 = gold;
		}

		
		if( pre.deckCount[player] > 1 ){
			firstPos = floor( rand() % deckCount);	
		}	
	
		if( pre.deckCount[player] > 1 ){
			firstPos = floor( rand() % deckCount);	
			secPos = floor( rand() % deckCount );
		
			while( firstPos == secPos ){
				secPos = floor( rand() % deckCount );
			}

			pre.deck[player][firstPos] = treasure1;
			printf("The first treasure card is at pos %i on the deck.\n", firstPos);	
			pre.deck[player][secPos] = treasure2;
			printf("The second treasure card is at pos %i on the deck.\n", secPos);

		}else{
			firstPos = floor( rand() % discardCount);	
			secPos = floor( rand() % discardCount );
		
			while( firstPos == secPos ){
				secPos = floor( rand() % discardCount );
			}

			pre.discard[player][firstPos] = treasure1;
			printf("The first treasure card is at pos %i on the discard deck.\n", firstPos); 
			pre.discard[player][secPos] = treasure2;
			printf("The second treasure card is at pos %i on the discard deck.\n", secPos);
		}

 		memcpy( &post, &pre, sizeof(struct gameState));

		//Call the function.
		printf("Calling the function.\n");
		
		//Save the state of the game.
		int returnVal = 0 ;
		returnVal = adventurerCard(player, &post);
/*
		//Print the DECK.
		for( i = 0; i < deckCount; i++){
			printf("Pos%i DECK CARD#%i\n", i, pre.deck[player][i]);
		}

		for( j = 0; j < discardCount; j++){
			printf("Pos%i DISCARD DECK CARD#%i\n", j, pre.discard[player][j]);
		}

*/
		//Oracle Code: Check that it works.

		//Check that the last two cards in the player's hand are treasure cards.
		int postHC = post.handCount[player];
		int lastCard = post.hand[player][postHC-1];
		int seclastCard = post.hand[player][postHC-2];
	
		if( lastCard == copper || lastCard == gold || lastCard == silver ){
			if( seclastCard == copper || seclastCard == gold || seclastCard == silver ){
				printf("The player has successfully drawn two treasure cards.\n");

			}else{
				printf("ERROR: The second to last in his hand is not a treasure card.\n");
				pass = 0;	
			}
		}else{
			printf("ERROR: The last card in hand is not a treasure card.\n");
			pass = 0;
		} 
		
		//Check tht the handCount has only increased by two cards.
		if( post.handCount[player] != 2 + pre.handCount[player] ){
			printf("ERROR: POST HAND COUNT WAS NOT INCREMENTED BY TWO CARDS.\n");
			pass = 0;	
		}

		printf("POST HAND COUNT: %i\n", post.handCount[player]);
	
		//Check that the game had no issues.
		if(  returnVal != 0 ){
			printf("ERROR:CALLED FN RETURNED AN ERROR.\n");
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

