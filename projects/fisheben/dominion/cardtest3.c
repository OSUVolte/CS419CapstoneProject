/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: cardtest2.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the Dominion card village card effect, cardEffect function is
 * implementated in the dominion.c file                                                     }
 *
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * Village CARD 
 * No documentation in the implementation or the interface
 * Description: Village Card is an action card that when played will give the player one extra
 * card and 2 extra actions.  At the end of the turn the village card is discarded.
 * Testing Requirements: 
 * After the card has been played the village card is removed from the players hand at handPos
 * After the card is played the player will get 1 new card in their hand
 * After the card is player the player will get 2 more actions
 * No other changes to the game state should occur.
 * The players hand count should not change
 * The players deck count should decrease by 1
 * The players played cards count should increase by 1
 * Player should be a number between 2 and MAX_PLAYERS
 * If player has no cards in deck then no changes should be made to deck
 case village:
      //+1 Card
      drawCard(currentPlayer, state);
			
      //+2 Actions
      state->numActions = state->numActions + 2;
			
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "village"
#define TEST1 1
#define TEST2 2
#define TEST3 3
#define TEST4 4
#define TEST5 5
#define TEST6 6
#define TEST7 7
#define TEST8 8

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int hand[], int testHandCount, int z, 
        int treasure, int player, int test);
		
int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

int main() {
	int i;//counter
    int seed = 1000; //used in rngs
    int numPlayer = 2;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, cardPosition = 0;
    int p;//used to store player 
	
	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0;
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
	        
    struct gameState preCall;
    struct gameState postCall;
	
	const int CARDS_TOTAL = 10;
	
	//kingdom cards with no village
    int noVillageCards[10] = {adventurer, embargo, embargo, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};			

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	//test both players
    for (p = 1; p < numPlayer; p++){
				
		//test different hands
		for (i = 1; i < CARDS_TOTAL; i++){
		
			//test different village card positions in the hand
			for(cardPosition = 0; cardPosition < i; ++cardPosition){
				
				initializeMyGame(&preCall, noVillageCards, seed++, numPlayer);           
				
				//****************running tests************************************									
                //set actions, coins and buys
                preCall.numActions = 0;
                preCall.numBuys = 0;
                preCall.coins = 0;
                //set played cards to zero	
                preCall.playedCardCount = 0;
                //set the correct turn
                preCall.whoseTurn = p;
				//set hand sizeof
				preCall.handCount[p] = i;
			    preCall.deckCount[p] = CARDS_TOTAL;               
                preCall.discardCount[p] = 0; 
                memcpy(preCall.hand[p], noVillageCards, sizeof(int) * CARDS_TOTAL);
            	//add village card into correct position
                preCall.hand[p][cardPosition] = village;
                //save state
				memcpy(&postCall, &preCall, sizeof(struct gameState));
			
                cardEffect(village, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
				
				if((p == 0) && !errorFlagP){
					if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST6); 
						errorFlagP = 1;
					}
				}else if(!errorFlagP){
					if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST6); 
						errorFlagP = 1;
					}
				}
				
				if(!errorFlagV && (noVictoryCardChanges(&preCall, &postCall, p) < 0) ){
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST7); 
					errorFlagV = 1;
				}
				if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, CARDS_TOTAL) < 0) ){
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST8); 
					errorFlagD = 1;
				}
				
				if(((postCall.handCount[p] != (preCall.handCount[p])) ||
                          (postCall.deckCount[p] != (preCall.deckCount[p] - 1))) && !errorFlag1){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST1); 
					errorFlag1 = 1;
				}
				
				//test hand counts are correct 
				//assert(postCall.handCount[p] == (preCall.handCount[p]));					
			    	
                //test deck count is 1 smaller post call
                //assert(postCall.deckCount[p] == (preCall.deckCount[p] - 1));                

				if(((postCall.hand[p][cardPosition] == village) || (preCall.hand[p][cardPosition] != village)) && !errorFlag2){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST2); 
					errorFlag2 = 1;
				}
			
				//test village card has been removed successfully
				//assert(postCall.hand[p][cardPosition] != village);											   
			    //assert(preCall.hand[p][cardPosition] == village);
				
				if(postCall.numActions != (preCall.numActions + 2) && !errorFlag3){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST3); 
					errorFlag3 = 1;
				}
				
				//test number of actions are correct 
				//assert(postCall.numActions == (preCall.numActions + 2));
				
				if(postCall.playedCardCount != (preCall.playedCardCount + 1) && !errorFlag4){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST4); 
					errorFlag4 = 1;
				}
				
				//test number of playcardCount is correct 
				//assert(postCall.playedCardCount == (preCall.playedCardCount + 1));

				//test no other changes occured to game state										
                preCall.deckCount[p] -= 1;
				preCall.numActions += 2;
                preCall.playedCardCount += 1;
                
                //deck has been shuffled so need to copy over to preCall
				memcpy(&preCall.hand[p], &postCall.hand[p], sizeof(int) * MAX_HAND);
				//memcpy(&preCall.deck[p], &postCall.deck[p], sizeof(int) * MAX_DECK);
				//memcpy(&preCall.discard[p], &postCall.discard[p], sizeof(int) * MAX_DECK);
				memcpy(&preCall.playedCards, &postCall.playedCards, sizeof(int) * MAX_DECK);
				
				if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && ! errorFlag5){ 
					printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST5); 
					errorFlag5 = 1;
				}
				//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);	
			}
		}	
	}	

	if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 &&
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
        int treasure, int player, int test){
	
	printf("Error found in %s, %d\n", TESTCARD, test );
	printf("\tpost.whoseTurn = %d pre.whoseTurn = %d\n", post->whoseTurn, pre->whoseTurn );   
    printf("\tpost.numBuys = %d pre.numBuys = %d\n", post->numBuys, pre->numBuys );   
    printf("\tpost.NumAction = %d pre.NumActions = %d\n", post->numActions, pre->numActions );
    printf("\tpost.Coins = %d pre.Coins = %d\n", post->coins, pre->coins);
	printf("\tpost.HandCount = %d  pre.HandCount = %d\n", post->handCount[player], pre->handCount[player]);
	printf("\tcardPosition = %d  \n", cardPosition);
    printf("\tpreCall.hand[p][cardPosition] = %d\n", pre->hand[player][cardPosition]);	 
    printf("\tpost.playedCardCount = %d pre.playedCardCount = %d\n", post->playedCardCount, pre->playedCardCount);
    printf("\tpost.playCards[0] = %d pre.playedCards[0] = %d\n", 
            post->playedCards[0], pre->playedCards[0]);
    printf("\tpost.discardCount[p] = %d pre.discardCount[p] = %d\n", post->discardCount[player], pre->discardCount[player]); 
    printf("\tpost.deckCount[p] = %d pre.deckCount[p] = %d\n", post->deckCount[player], pre->deckCount[player]);
	printf("\ttreasure = %d Player = %d\n\n", treasure, player); 
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
