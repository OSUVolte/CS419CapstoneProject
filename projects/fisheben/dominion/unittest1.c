/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: unittest1.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the updateCoins in the dominion_helpers.h interface
 * implementation is in the dominion.c                                                       }
 *
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * UPDATE COINS FUNCTION
 * No documentation in the implementation or the interface
 * Description: Function update coins will count the number of coins and bonus coins
 * in the players hand, and then update the state
 * Preconditions: player and state are valid states of the game, bonus is >= 0
 * Postconditions: The state of the correct players coins has been updated to reflect the 
 * the correct sum of the treasure cards and the bonus treasure.
 * Testing Requirements: 
 * Only players coins should be updated all other players coins should remaining unchanged
 * Ony the treasure cards in players hand should be summed
 * The cards in the players hand should not be changed
 * The bonus value is a value >= 0
 * Player should be a number between 2 and MAX_PLAYERS
 * A hand with no treasure cards and no bonus should return 0
 * 
 int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
	
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
		  if (state->hand[player][i] == copper)
		{
		  state->coins += 1;
		}
		  else if (state->hand[player][i] == silver)
		{
		  state->coins += 2;
		}
		  else if (state->hand[player][i] == gold)
		{
		  state->coins += 3;
		}	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h" //random number generator multiple streams


#define TEST "UPDATE_COINS"
#define TEST_EMPTY 0
#define TEST_NO_TREASURE 1
#define TEST_SMALL_HAND 2
#define TEST_BIG_HAND 3

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *G, int hand[], int testTreasureHand, int testHandCount, int bonus, int player, int test);

int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

int main() {
    int i;
    int seed = 1000; //used in rngs
    int numPlayer = 2;
    int maxBonus = 10;
    int p;//player counter
    int bonus = 0;
	
	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0, errorFlag6 = 0, errorFlag7 = 0, errorFlag8 = 0;
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	const int ACTION_CARD_TOTAL = 10;
    int actionCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};   
            
    struct gameState preCall;
    struct gameState postCall;   
	  

	//used to test a hand with no cards
	const int TEST_ZERO_HAND_COUNT = 0;	
		
	// hand of copper, silver, and gold of size 3
	const int SMALL_HAND_COUNT = 3;
    int testSmallHand[SMALL_HAND_COUNT];
	int testSmallCoins = 6;
	
    // hand of all coppers, silvers, and golds of size MAX_HAND
    int testBigHand[MAX_HAND];   
	int testBigCoins = 0;   
	
	/*
	* Initialize the test hands
	* Iterate from 0 to MAX_HAND and create the test hands 
	*/
    for (i = 0; i < MAX_HAND; ++i)
    {		
		if(i < 1){
			testSmallHand[i] = copper;
			testSmallHand[i+1] = silver;
			testSmallHand[i+2] = gold;                     
		}
		
		if(MAX_HAND % 3 == 0){
			testBigHand[i] = copper;
			testBigCoins += 1;
		}else if(MAX_HAND % 3 == 1){
			testBigHand[i] = silver;
			testBigCoins += 2;
		}else{
			testBigHand[i] = gold;
			testBigCoins += 3;
		}
    }
	
    printf ("Starting unittest1\nTESTING updateCoins():\n");
	
	//test both players
    for (p = 0; p < numPlayer; p++){
		//test bonus from 0 to maxBonus
		for (bonus = 0; bonus <= maxBonus; bonus++){
		
			initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);           
								
			//****************test EMPTY (case 0) where player has no cards************************************
			preCall.handCount[p] = TEST_ZERO_HAND_COUNT; // set hand size to 0 
			preCall.whoseTurn = p;	//set turn
			preCall.discardCount[p] = 0;
			preCall.deckCount[p] = 0;
            memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
			updateCoins(p, &postCall, bonus);
			
			if((p == 0) && !errorFlagP){
				if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
					printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
					errorFlagP = 1;
				}
			}else if(!errorFlagP){
				if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
					printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
					errorFlagP = 1;
				}
			}
			
			if(!errorFlagV && (noVictoryCardChanges(&preCall, &postCall, p) < 0) ){
				printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
				errorFlagV = 1;
			}			
			
			if(postCall.coins != bonus && !errorFlag1){ 
				printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
				errorFlag1 = 1;
			}
            //make sure coins are correct and game state hasn't changed
			assert(postCall.coins == bonus);
            preCall.coins = bonus;
			
			if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag2){ 
				printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
				errorFlag2 = 1;
			}
            //assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);
			
			initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);
			
			//*******************test TEST_NO_TREASURE (case 1) where player has no treasure cards***************
			memcpy(preCall.hand[p], actionCards, sizeof(int) * ACTION_CARD_TOTAL);
            preCall.handCount[p] = ACTION_CARD_TOTAL;
			preCall.deckCount[p] = ACTION_CARD_TOTAL;
			memcpy(preCall.deck[p], kingdomCards, sizeof(int) * ACTION_CARD_TOTAL);
            memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
			updateCoins(p, &postCall, bonus);
			
			if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, ACTION_CARD_TOTAL) < 0) ){
				printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
				errorFlagD = 1;
			}
			
            if(postCall.coins != bonus && !errorFlag3){ 
				printState(&postCall, actionCards, 0, ACTION_CARD_TOTAL, bonus, 
                        p, TEST_NO_TREASURE); 
				errorFlag3 = 1;		
			}
            //make sure coins are correct and game state hasn't changed
			//assert(postCall.coins == bonus);
            preCall.coins = bonus;
			
			if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag4){ 
				printState(&postCall, actionCards, 0, ACTION_CARD_TOTAL, bonus, 
                        p, TEST_NO_TREASURE); 
				errorFlag4 = 1;		
			}			
            //assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);
			
			initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);
			
			//*********************test TEST_SMALL_HAND (case 2) where player has one gold, silver and copper card***
			memcpy(preCall.hand[p], testSmallHand, sizeof(int) * SMALL_HAND_COUNT);
            preCall.handCount[p] = SMALL_HAND_COUNT;
            memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
			updateCoins(p, &postCall, bonus);
			
            if( postCall.coins != (testSmallCoins + bonus ) && !errorFlag5){
				printState(&postCall, testSmallHand, testSmallCoins, SMALL_HAND_COUNT, 
                        bonus, p, TEST_SMALL_HAND); 
				errorFlag5 = 1;
			}
            //make sure coins are correct and game state hasn't changed
			//assert(postCall.coins == testSmallCoins + bonus);
            preCall.coins = testSmallCoins + bonus;
			
			if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 &&  !errorFlag6){ 
				printState(&postCall, testSmallHand, testSmallCoins, SMALL_HAND_COUNT, 
                        bonus, p, TEST_SMALL_HAND); 
				errorFlag6 = 1;
			}
            //assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);
			
			initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);
			
			//***************test TEST_BIG_HAND (case 3) where player has MAX gold, silver and copper cards************
			memcpy(preCall.hand[p], testBigHand, sizeof(int) * MAX_HAND);
            preCall.handCount[p] = MAX_HAND;
            memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
			updateCoins(p, &postCall, bonus);
			
            if(postCall.coins != (testBigCoins + bonus) &&  !errorFlag7){ 
				printState(&postCall, testBigHand, testBigCoins, MAX_HAND, bonus, p, 
                        TEST_BIG_HAND); 
				errorFlag7 = 1;		
			}
            //make sure coins are correct and game state hasn't changed
			//assert(postCall.coins == testBigCoins + bonus);
            preCall.coins = testBigCoins + bonus;
			
			if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag8){ 
				printState(&postCall, testBigHand, testBigCoins, MAX_HAND, bonus, p, 
                        TEST_BIG_HAND); 
				errorFlag8 = 1;		
			}
            //assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);           
        }
    }

    
    if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 && !errorFlag6 && !errorFlag7 && !errorFlag8 &&
		!errorFlagP && ! errorFlagV && ! errorFlagD){
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TEST);
	}else{
		printf("\n >>>>> FAILURES DETECTED: Examine test cases %s <<<<<\n\n", TEST);
	} 

    return 0;
}

int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer){
	
		memset(G, 23, sizeof(struct gameState));   // clear the game state
        return initializeGame(numPlayer, actionCards, seed, G); // initialize a new game
}

void printState(struct gameState *G, int hand[], int testTreasureHand, int testHandCount, 
        int bonus, int player, int test){
	
	printf("Error found in %s %d\n", TEST, test );
	printf("\tG->handCount = %d  testHandCount = %d\n", G->handCount[player], testHandCount);
	printf("\tBonus = %d  Player = %d\n", bonus, player);
	printf("\tG->Coins = %d testTreasureHand = %d\n\n", G->coins, testTreasureHand);
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
