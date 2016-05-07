/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: randomtestcard.c
 * Description: Demonstration of how to write random test for dominion-base
 * File tests the Dominion card smithy card effect for correct functionality, cardEffect function is
 * implementated in the dominion.c file.      
 *
 * Include the following lines in your makefile:
 *
 * randomtestcard: randomtestcard.c dominion.o rngs.o
 *      gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
  /*
 * SMITHY CARD 
 * No documentation in the implementation or the interface
 * Description: Smithy Card is an action card that when played gives the player 3 more cards.
 * Testing Requirements: 
 * After the card has been played the smithy card is removed from the players hand at handPos
 * After the card is played the player get 3 new cards in their hand
 * No other changes to the game state should occur.
 * The players hand count should increase by 2
 * The players deck count should decrease by 3
 * Player should be a number between 2 and MAX_PLAYERS
 * If player has no cards in deck then no changes should be made to deck
 int mySmithy(struct gameState *state, int currentPlayer, int handPos){
	//+3 Cards
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}
		
	//discard card from hand	
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define TESTCARD "smithy"
#define TEST1 1
#define TEST2 2
#define TEST3 3
#define TEST4 4
#define TEST5 5
#define TEST6 6
#define TEST7 7
#define TEST8 8
#define TEST9 9
#define TEST10 10
#define TEST11 11
#define TEST12 12

//used in the qsort function
int adCompare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}

//Function will initialize a Random gameState struct, this is the random test case generator
int initializeRandomGame(struct gameState *preCall, struct gameState *postCall, int * deckSize, int * cardPosition, int * discardSize);

int smithyOracle(struct gameState *G, struct gameState *postCall, int p, int cardPosition, int deckSize, int numTreasInDeck);

//function will simulate the smithy card changes
void mockCardEffect(struct gameState *G, int cardPosition);

//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int card, 
        int treasure, int player, int test);
		
int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

//error flags	
int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0, errorFlag6 = 0, errorFlag7 = 0;	
int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;

int main() {
	int i;//counter
	int deckSize;
	int cardPosition;
	int numTreasInDeck;
	int discardSize;    
	        
    struct gameState preCall;
    struct gameState postCall;			
    
    time_t t;

    srand((unsigned) time(&t));

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	for(i = 0; i < 300000; ++i){
		numTreasInDeck = initializeRandomGame(&preCall, &postCall, &cardPosition, &deckSize, &discardSize);
		smithyOracle(&preCall, &postCall, preCall.whoseTurn, cardPosition, deckSize, numTreasInDeck);    
	}
	
    printf("Random testing complete.\nExecuted %d random tests.", i);

	if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 && !errorFlagP && ! errorFlagV && ! errorFlagD ){
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}else{
		printf("\n >>>>> FAILURES DETECTED: Examine test cases %s <<<<<\n\n", TESTCARD);
	}

	return 0;
}

int initializeRandomGame(struct gameState *preCall, struct gameState *postCall, int *deckSize, int *cardPosition, int *discardSize){
	
		int i = 0;
		
		int numTreasInDeck = 0;		
		
		//set a random number of players
		int randP = rand() % MAX_PLAYERS; 
		randP = (randP < 2) ? MAX_PLAYERS : randP;		
		
		//set deck size
		*deckSize = rand() % MAX_DECK;
		*deckSize = (*deckSize < 10) ? MAX_DECK : *deckSize;		
		
		//all possible cards with extra treasure cards
		int allCards[33] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room, curse, estate, duchy, province, 
		feast, gardens, remodel, baron, great_hall, steward, outpost, salvager, treasure_map,
		ambassador, copper, silver, gold, copper, silver, gold, copper, silver, gold };		
						
		//set a deck of random cards
		int randomDeck[*deckSize];		
		
		for(i = 0; i < *deckSize; ++i){
			randomDeck[i] = allCards[rand() % 33];
      
			if(	randomDeck[i] == copper ||
				randomDeck[i] == silver ||
				randomDeck[i] == gold ){
					++numTreasInDeck;
			}
		}		
				     
		//set discard deck size
		int maxDiscard = MAX_DECK - *deckSize;		

        maxDiscard = (maxDiscard == 0) ? 1 : maxDiscard;
        
		*discardSize = rand() % maxDiscard;
		
		//set a deck of random discard deck
		//set a deck of random cards
		int randomDiscardDeck[*discardSize];		
		
		for(i = 0; i < (*discardSize); ++i){
			randomDiscardDeck[i] = allCards[rand() % 33];				
		}
						
		memset(preCall, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(randP, randomDeck, 1000, preCall); // initialize a new game
		
		//****************SET RANDOM STARTING VALUES***********				

        //set actions
        preCall->numActions = 1;
        //set coins
        preCall->coins = 0;
        //set buys
        preCall->numBuys = 1;
        //set playedcard
        preCall->playedCardCount = 0;    
		//set random turn
		int p = rand() % randP;	
		preCall->whoseTurn = p;
		
		//set number of players
		preCall->numPlayers = randP;
				
		//set hand size
		preCall->handCount[p] = rand() % MAX_HAND ;			
		
		//set a random hand
		int randomHand[preCall->handCount[p]];		
		
		for(i = 0; i < preCall->handCount[p]; ++i){
			randomHand[i] = allCards[rand() % 33];			
		}
		
		//set the random card position
        int pos = (preCall->handCount[p] == 0) ? 1 : preCall->handCount[p];
		*cardPosition = rand() % pos;
		
		//set deck count
		preCall->deckCount[p] = *deckSize;           
		
		//set the discard count
		preCall->discardCount[p] = *discardSize;
		       
		//copy random deck into players deck
		memcpy(preCall->deck[p], randomDeck, sizeof(int) * preCall->deckCount[p]);
		//copy random discard deck into players discard deck
		memcpy(preCall->discard[p], randomDiscardDeck, sizeof(int) * preCall->discardCount[p]);
		//copy random hand into players hand
		memcpy(preCall->hand[p], randomHand, sizeof(int) * preCall->handCount[p]);		
		//add smithy card into correct position
		preCall->hand[p][(*cardPosition)] = smithy;
		//save the state
		memcpy(postCall, preCall, sizeof(struct gameState));//save game state before calling discardCard	
		
		//return the number of treasure cards in the deck
		return numTreasInDeck;
}

void printState(struct gameState *pre, struct gameState *post, int card, 
        int treasure, int player, int test){
	
	printf("Error found in %s, %d\n", TESTCARD, test );
	printf("\tpost.whoseTurn = %d pre.whoseTurn = %d\n", post->whoseTurn, pre->whoseTurn );   
    printf("\tpost.numBuys = %d pre.numBuys = %d\n", post->numBuys, pre->numBuys );   
    printf("\tpost.NumAction = %d pre.NumActions = %d\n", post->numActions, pre->numActions );
    printf("\tpost.Coins = %d pre.Coins = %d\n", post->coins, pre->coins);
	printf("\tpost.HandCount = %d  pre.HandCount = %d\n", post->handCount[player], pre->handCount[player]);
	if(card > -1){
		printf("\tcard = %d  \n", card);
		printf("\tpreCall.hand[p][card] = %d\n", pre->hand[player][card]);	 
	}
    printf("\tpost.playedCardCount = %d pre.playedCardCount = %d\n", post->playedCardCount, pre->playedCardCount);
    printf("\tpost.playCards[0] = %d pre.playedCards[0] = %d\n", 
            post->playedCards[0], pre->playedCards[0]);
    printf("\tpost.discardCount[p] = %d pre.discardCount[p] = %d\n", post->discardCount[player], pre->discardCount[player]); 
    printf("\tpost.deckCount[p] = %d pre.deckCount[p] = %d\n", post->deckCount[player], pre->deckCount[player]);
	printf("\ttreasure cards in deck = %d Player = %d\n\n", treasure, player); 
}

int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall){
    int p = 0;	
	//test no other changes occured to game state	
	for(p = 0; p < preCall->numPlayers && (p != preCall->whoseTurn); ++p){
		if(preCall->deckCount[p] != postCall->deckCount[p]){ 
			printf("ERROR noPlayerStateChanges DECKCOUNT's off\n");
			return -1;
		}
		if(preCall->discardCount[p] != postCall->discardCount[p]){ 
			printf("ERROR noPlayerStateChanges DISCARDCOUNT's off\n");
			return -1;
		}
		if(preCall->handCount[p] != postCall->handCount[p]){ 
			printf("ERROR noPlayerStateChanges HANDCOUNT's off\n");
			return -1;
		}
		if(memcmp(&preCall->deck[p], &postCall->deck[p], MAX_DECK) != 0){
			printf("ERROR noPlayerStateChanges DECK is off\n");

			return -1;
		}
		if(memcmp(&preCall->discard[p], &postCall->discard[p], MAX_DECK) != 0){ 
			printf("ERROR noPlayerStateChanges DISCARD DECK is off\n");
			return -1;
		}
		if(memcmp(&preCall->hand[p], &postCall->hand[p], MAX_HAND) != 0){ 
			printf("ERROR noPlayerStateChanges HAND is off\n");
			return -1;
		}
	}
	return 0;
}

int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p){
	if(scoreFor(p, preCall) != scoreFor(p, postCall)){
		printf("ERROR noVictoryCardChanges\n");
		return -1;
	}
	return 0;
}

int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize){
	if(memcmp(&preCall->deck[p], &postCall->deck[p], sizeof(int) *  deckSize) != 0){
		printf("ERROR noDominionCardChanges\n");
		return -1;
	}
	return 0;
}

//treasure is the number of treasure cards in the deck
//function returns the result of the test, 0 = pass, 1 = fail
int smithyOracle(struct gameState *preCall, struct gameState *postCall, int p, int cardPosition, int deckSize, int treasure ){
    int result = 0;	
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;	
	int card = -1;
	
	//**********************************running tests**********************************************	          
	
    //for testing    
	//printState(preCall, postCall, card, treasure, p, TEST1);
    //printf("INITIAL GAME STATES******\n");
    cardEffect(smithy, choice1, choice2, choice3, postCall, cardPosition, &bonus);

    //for testing    
	//printState(preCall, postCall, card, treasure, p, TEST1);
    //printf("AFTER CALL TO CARD EFFECT******\n");
	mockCardEffect(preCall, cardPosition);//will simulate the smithy card function

	
	//**********************************TEST #1****************************************************	          	
	//hand count should be the same
	if((postCall->handCount[p] != preCall->handCount[p]) && !errorFlag1){ 
		printState(preCall, postCall, card, treasure, p, TEST1); 
		result = errorFlag1 = 1;
	}
				
	//**********************************TEST #2****************************************************
	//deck count should be -2 in all cases where there are 2 treasure cards in deck
	if((postCall->deckCount[p] != preCall->deckCount[p]) && !errorFlag2){ 
		printState(preCall, postCall, card, treasure, p, TEST2); 
		result = errorFlag2 = 1;
	}	
               
	//**********************************TEST #3****************************************************
	//discard count should not change with no shuffling	
	if((postCall->discardCount[p] != preCall->discardCount[p]) && !errorFlag3){ 
		printState(preCall, postCall, card, treasure, p, TEST3); 
		result  = errorFlag3 = 1;
	}

	//**********************************TEST #4****************************************************
	//test that the played card counts are the same, need to address shuffling
	if(postCall->playedCardCount != (preCall->playedCardCount) && !errorFlag4){ 
		printState(preCall, postCall, card, treasure, p, TEST4); 
		result = errorFlag4 = 1;
	}
	
	//**********************************TEST #5****************************************************
	//test the smithy card was discarded properly
	if(((postCall->hand[p][cardPosition] == smithy) ) && !errorFlag5){ 
		printState(preCall, postCall, card, treasure, p, TEST5); 
		result = errorFlag5 = 1;
	}
	
	//**********************************TEST #6****************************************************
	//test no unexpected changes to hand for unshuffled deck
	if((memcmp(preCall->hand[p], postCall->hand[p], sizeof(int) * postCall->handCount[p] ) != 0 ) && !errorFlag6){
		printState(preCall, postCall, card, treasure, p, TEST6); 
		result = errorFlag6 = 1;
	}	
 					
	//**********************************TEST #P****************************************************	
	//test no other change to other players
	if(!errorFlagP && noPlayerStateChanges(preCall, postCall) < 0){
		printState(preCall, postCall, card, treasure, p, TEST9); 
		result = errorFlagP = 1;
	}
	
	//**********************************TEST #V****************************************************
	//test no changes to victory cards
	if(!errorFlagV && (noVictoryCardChanges(preCall, postCall, p) < 0) ){
		printState(preCall, postCall, card, treasure, p, TEST10); 
		result = errorFlagV = 1;
	}
	
	//**********************************TEST #D****************************************************
	//test no changes to dominion cards
	qsort ((void*)(preCall->deck[p]), preCall->deckCount[p], sizeof(int), adCompare);
	qsort ((void*)(postCall->deck[p]), postCall->deckCount[p], sizeof(int), adCompare);
	if (!errorFlagD && (noDominionCardChanges(preCall, postCall, p, deckSize) < 0)){
		//sort decks first		
		printState(preCall, postCall, card, treasure, p, TEST11); 
		result = errorFlagD = 1;
	}
	
	//**********************************TEST #7****************************************************
	//test no unexpected changes to game state 
	//copy random deck into players deck
	memcpy(preCall->deck[p], postCall->deck[p], sizeof(int) * (deckSize));
	memcpy(preCall->discard[p], postCall->discard[p], sizeof(int) * postCall->discardCount[p]);
	memcpy(preCall->hand[p], postCall->hand[p], sizeof(int) * postCall->handCount[p]);
	
	preCall->discardCount[p] = postCall->discardCount[p];
	if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag7){ 			
		printState(preCall, postCall, card, treasure, p, TEST7);
		result = errorFlag7 = 1;
	}
	  
	return result;
}


//Function simulates the smithy card
void mockCardEffect(struct gameState *preCall, int cardPosition){
	//+3 Cards
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(preCall->whoseTurn, preCall);
	}
		
	//discard the smithy card
	discardCard(cardPosition, preCall->whoseTurn, preCall, 0);
}
