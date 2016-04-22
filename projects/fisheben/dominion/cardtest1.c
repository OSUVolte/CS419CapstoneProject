/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: cardtest1.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the Dominion card smithy card effect, cardEffect function is
 * implementated in the dominion.c file                                                     }
 *
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "smithy"
#define TEST1 1
#define TEST2 2
#define TEST3 3
#define TEST4 4
#define TEST5 5
#define TEST6 6

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int hand[], int testHandCount, int testHandPosition, 
        int card, int player, int test);

int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);
		
int main() {
   
	int i;//counter
    int seed = 1000; //used in rngs
    int numPlayer = 2;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int p;//used to store player 	
	int cardPosition = 0;	

	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0;	
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
	        
    struct gameState preCall;
    struct gameState postCall;
	
	const int NO_SMITHY_CARDS_TOTAL = 10;
	
	//kingdom cards with no smithy
    int noSmithyCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, tribute, council_room};		


	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	//test both players
    for (p = 0; p < numPlayer; p++){
		
		//test different hands
		for (i = 1; i < NO_SMITHY_CARDS_TOTAL; i++){
		
			//test different smithy card positions in the hand
			for(cardPosition = 0; cardPosition < i; ++cardPosition){
		
				initializeMyGame(&preCall, noSmithyCards, seed++, numPlayer);           
				
				//****************running tests************************************
				//set actions, coins and buys
                preCall.numActions = 0;
                preCall.numBuys = 0;
                preCall.coins = 0;				
                //set the correct turn
                preCall.whoseTurn = p;
				//set hand sizeof
				preCall.handCount[p] = i;
			    preCall.deckCount[p] = NO_SMITHY_CARDS_TOTAL;                
                preCall.discardCount[p] = 0;
                memcpy(preCall.hand[p], noSmithyCards, sizeof(int) * NO_SMITHY_CARDS_TOTAL);
            	//add smithy card into correct position
                preCall.hand[p][cardPosition] = smithy;
                //save state
				memcpy(&postCall, &preCall, sizeof(struct gameState));
				cardEffect(smithy, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
				
				if((p == 0) && !errorFlagP){
					if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST4); 
						errorFlagP = 1;
					}
				}else if(!errorFlagP){
					if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST4); 
						errorFlagP = 1;
					}
				}
				
				if(!errorFlagV && (noVictoryCardChanges(&preCall, &postCall, p) < 0)){
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST5); 
					errorFlagV = 1;
				}
				if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, NO_SMITHY_CARDS_TOTAL) < 0)){
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST6); 
					errorFlagD = 1;
				}
				
				if(((postCall.handCount[p] != (preCall.handCount[p] + 2)) ||
                          (postCall.deckCount[p] != (preCall.deckCount[p] - 3))) && !errorFlag1){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST1); 
					errorFlag1 = 1;
				}
				
				//test hand counts are correct 
				//assert(postCall.handCount[p] == (preCall.handCount[p] + 2));					
			    	
                //test deck count is 3 small post call
                //assert(postCall.deckCount[p] == (preCall.deckCount[p] - 3));                

				if(((postCall.hand[p][cardPosition] == smithy) || (preCall.hand[p][cardPosition] != smithy)) && !errorFlag2){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST2); 
					errorFlag2 = 1;
				}
			
				//test smithy card has been removed successfully
				//assert(postCall.hand[p][cardPosition] != smithy);											   
			    //assert(preCall.hand[p][cardPosition] == smithy);

				//test no other changes occured to game state	
				preCall.handCount[p] += 2;						
                preCall.deckCount[p] -= 3;
                
                //deck has been shuffled so need to copy over to preCall
				memcpy(&preCall.hand[p], &postCall.hand[p], sizeof(int) * MAX_HAND);
				//memcpy(&preCall.deck[p], &postCall.deck[p], sizeof(int) * MAX_DECK);
				//memcpy(&preCall.discard[p], &postCall.discard[p], sizeof(int) * MAX_DECK);
				//memcpy(&preCall.playedCards, &postCall.playedCards, sizeof(int) * MAX_DECK);
				
				if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag3){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, smithy, p, TEST3); 
					errorFlag3 = 1;
				}
				//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);												      
			}		  
		}
	}

	if(!errorFlag1 && !errorFlag2 && !errorFlag3 &&
		!errorFlagP && ! errorFlagV && ! errorFlagD ){
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}else{
		printf("\n >>>>> FAILURES DETECTED: Examine test cases %s <<<<<\n\n", TESTCARD);
	}

	return 0;
}

int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer){
	
		memset(G, 23, sizeof(struct gameState));   // clear the game state
        return initializeGame(numPlayer, actionCards, seed, G); // initialize a new game
}

void printState(struct gameState *pre, struct gameState *post, int hand[], int testHandCount, int cardPosition, 
        int card, int player, int test){
	
	printf("Error found in %s %d\n", TESTCARD, test );
	printf("\tpost.whoseTurn = %d pre.whoseTurn = %d\n", post->whoseTurn, pre->whoseTurn );   
    printf("\tpost.numBuys = %d pre.numBuys = %d\n", post->numBuys, pre->numBuys );   
    printf("\tpost.NumAction = %d pre.NumActions = %d\n", post->numActions, pre->numActions );
    printf("\tpost.Coins = %d pre.Coins = %d\n", post->coins, pre->coins);
	printf("\tpost.HandCount = %d  pre.HandCount = %d\n", post->handCount[player], pre->handCount[player]);
	printf("\tpostCall.hand[p][cardPosition] = %d  testHandPosition = %d\n", post->hand[player][cardPosition], cardPosition);
    printf("\tpreCall.hand[p][cardPosition] = %d\n", pre->hand[player][cardPosition]);	 
    printf("\tpost.playedCardCount = %d pre.playedCardCount = %d\n", post->playedCardCount, pre->playedCardCount);
    printf("\tpost.playCards[0] = %d pre.playedCards[0] = %d\n", 
            post->playedCards[0], pre->playedCards[0]);
    printf("\tpost.discardCount[p] = %d pre.discardCount[p] = %d\n", post->discardCount[player], pre->discardCount[player]); 
    printf("\tpost.deckCount[p] = %d pre.deckCount[p] = %d\n", post->deckCount[player], pre->deckCount[player]);
	printf("\tsmithy card = %d Player = %d\n\n", card, player); 
}

int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p){
    //int i = 0;	
	//test no other changes occured to game state	
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

		//for testing
        //for(i=0; i < MAX_DECK ; ++i){
        //    printf("\tpreCall-deck[%d][%d] = %d, postCall-deck[%d][%d] = %d\n",p, i, preCall->deck[p][i], p, i, postCall->deck[p][i]);
        //}

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
