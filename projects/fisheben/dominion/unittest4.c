/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: unittest4.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the getCost function in the dominion_helpers.h interface
 * implementation is in the dominion.c file
 *
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * GET COST FUNCTION
 * No documentation in the implementation or the interface
 * Description: Function getCost will return the cost a card.
 * Preconditions: none
 * Postconditions: A int representing the cost of the card is returned or
 * -1 if the cardNumber is not valid
 * Testing Requirements: 
 * Function returns an int corresponding to the cost of the cardNumber
 * Function return -1 if cardNumber is not present
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h" //random number generator multiple streams


#define TEST "myCost Function"
#define TEST1 1
#define TEST2 2
#define TEST3 3

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int hand[], int testPlayedCardCount, int testHandPosition, 
        int testTrashFlag, int player, int test);
int getMyCost(int cardNum);
int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

   
int main() {
    int i, k; //counter
	
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
    int p;//used to store player 
	int trash = 0;
	int cardPosition = 0;
	const int ACTION_CARD_TOTAL = 10;
    int actionCard[10] = { 
        smithy, smithy, smithy, smithy, smithy, smithy, smithy, 
        smithy, smithy, smithy};   
            
    struct gameState preCall;
    struct gameState postCall;  
	int seed = 1000;

	const int ACTION_CARD_NUM = 20;
	
    int actionCards[20] = { 
        adventurer, council_room, feast, gardens, mine, remodel, smithy, 
        village, baron, great_hall, minion, steward, tribute, ambassador, 
        cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};   
        
    const int ALL_CARDS_COUNT = 29;//all possible cards

    int testAllCardsDeck[ALL_CARDS_COUNT];   		   

	int cost = 0;
	/*
	* Initialize the test hand
	*/			
	//add action cards to no treasure test hand
	for(k = 0; k < ACTION_CARD_NUM; ++k){
	  testAllCardsDeck[k] = actionCards[k]; 	  
	}

	//add other cards
	testAllCardsDeck[k] = estate;	
	testAllCardsDeck[k+1] = duchy;	
	testAllCardsDeck[k+2] = province;	
	testAllCardsDeck[k+3] = curse; 	
	testAllCardsDeck[k+4] = gold;	
	testAllCardsDeck[k+5] = silver;				
	testAllCardsDeck[k+6] = copper;	
	testAllCardsDeck[k+7] = 10121;//add a bad card
	testAllCardsDeck[k+8] = -1011;//add a bad card
	

    printf ("Starting unittest4\nTESTING getCost():\n");

	for (i = 0; i < ALL_CARDS_COUNT; i++){			
		cost = getCost(testAllCardsDeck[i]);
		
		if(cost != getMyCost(testAllCardsDeck[i])){
			printf("Error found in %s", TEST);
			return 1;
		}	
		//assert(cost == getMyCost(testAllCardsDeck[i]));				    
    }

	for (p = 0; p < 2; p++){
		initializeMyGame(&preCall, actionCard, seed++, 2);           
		
		//****************running tests************************************																
		memcpy(preCall.hand[p], actionCard, sizeof(int) * ACTION_CARD_TOTAL);								
		preCall.handCount[p] = i; 					
		preCall.playedCardCount = 0;
		preCall.discardCount[p] = 0;
		preCall.whoseTurn = p; //set turn
		preCall.deckCount[p] = ACTION_CARD_TOTAL;
		memcpy(preCall.deck[p], actionCard, sizeof(int) * ACTION_CARD_TOTAL);
		memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling discardCard
		getCost(smithy);
		
		if((p == 0) && !errorFlagP){
			if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST1); 
				errorFlagP = 1;
			}
		}else if(!errorFlagP){
			if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST1); 
				errorFlagP = 1;
			}
		}
		
		if((!errorFlagV && noVictoryCardChanges(&preCall, &postCall, p) < 0) ){
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST2); 
			errorFlagV = 1;
		}
		if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, ACTION_CARD_TOTAL) < 0)){
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST3); 
			errorFlagD = 1;
		}
		
	}
	
    printf("All tests passed!\nEnd of unittest2\n");

    return 0;
}

int getMyCost(int cardNum){
	switch( cardNum ) 
    {
		case curse:
		  return 0;
		case estate:
		  return 2;
		case duchy:
		  return 5;
		case province:
		  return 8;
		case copper:
		  return 0;
		case silver:
		  return 3;
		case gold:
		  return 6;
		case adventurer:
		  return 6;
		case council_room:
		  return 5;
		case feast:
		  return 4;
		case gardens:
		  return 4;
		case mine:
		  return 5;
		case remodel:
		  return 4;
		case smithy:
		  return 4;
		case village:
		  return 3;
		case baron:
		  return 4;
		case great_hall:
		  return 3;
		case minion:
		  return 5;
		case steward:
		  return 3;
		case tribute:
		  return 5;
		case ambassador:
		  return 3;
		case cutpurse:
		  return 4;
		case embargo: 
		  return 2;
		case outpost:
		  return 5;
		case salvager:
		  return 4;
		case sea_hag:
		  return 4;
		case treasure_map:
		  return 4;
    }
	return -1;
}

void printState(struct gameState *pre, struct gameState *post, int hand[], int testPlayedCardCount, int testHandPosition, 
        int testTrashFlag, int player, int test){
	
	printf("Error found in %s, %d\n", TEST, test );
	printf("\tpost G->playedCardCount = %d  testPlayedCardCount = %d\n", post->playedCardCount, testPlayedCardCount);
	printf("\tpost G->handCount[player] = %d  testHandPosition = %d\n", post->handCount[player], testHandPosition);
	printf("\tpost testTrashFlag = %d Player = %d\n\n", testTrashFlag, player);  
	printf("\tpost.whoseTurn = %d pre.whoseTurn = %d\n", post->whoseTurn, pre->whoseTurn );   
    printf("\tpost.numBuys = %d pre.numBuys = %d\n", post->numBuys, pre->numBuys );   
    printf("\tpost.NumAction = %d pre.NumActions = %d\n", post->numActions, pre->numActions );
    printf("\tpost.Coins = %d pre.Coins = %d\n", post->coins, pre->coins);
	printf("\tpost.HandCount = %d  pre.HandCount = %d\n", post->handCount[player], pre->handCount[player]);	        
    printf("\tpost.discardCount[p] = %d pre.discardCount[p] = %d\n", post->discardCount[player], pre->discardCount[player]); 
    printf("\tpost.deckCount[p] = %d pre.deckCount[p] = %d\n", post->deckCount[player], pre->deckCount[player]);	
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

int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer){
        
    memset(G, 23, sizeof(struct gameState));   // clear the game state
    return initializeGame(numPlayer, actionCards, seed, G); // initialize a new game
}



