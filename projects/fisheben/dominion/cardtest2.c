/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: cardtest2.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the Dominion card smithy card effect, cardEffect function is
 * implementated in the dominion.c file                                                     }
 *
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * Adventurer CARD 
 * No documentation in the implementation or the interface
 * Description: Adventurer Card is an action card that when played will reveal cards from the deck until 2 
 * treasure cards are revealed.  Then these two cards are added to the players hand.  Function keeps track
 * of number of treasure cards drawn, and the rest of the cards are added to a temp hand. After 2 treasure
 * cards are found the cards in the temp hand are added to the discard pile.
 * If played the adventurer card is discarded.
 * Testing Requirements: 
 * After the card has been played the adventurer card is removed from the players hand at handPos
 * After the card is played the player get 3 new cards in their hand
 * No other changes to the game state should occur.
 * Test a deck with no cards and no cards in discard deck
 * Test a deck with no cards and cards in discard deck
 * Test a deck with no treasure cards(endless loop?)
 * Test a deck with all treasure cards
 * The players hand count should increase by 2
 * The players deck count should decrease by z + 2
 * The players discard count should increase by z
 * Player should be a number between 2 and MAX_PLAYERS
 * If player has no cards in deck then no changes should be made to deck
 int myAdventurer(struct gameState *state, int currentPlayer ){
      
  int z = 0;// this is the counter for the temp hand
  int temphand[MAX_HAND];// moved above the if statement
  int drawntreasure=0;
  int cardDrawn = 0;

	while(drawntreasure < 2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
		  shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		
		//ADDED A LOGIC BUG HERE WHERE CARD DRAWN IS ASSIGNED TO GOLD
		if (cardDrawn == copper || cardDrawn == silver || (cardDrawn = gold))
		  drawntreasure++;
		else{
		  temphand[z]=cardDrawn;
		  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		  z++;
		}
    }
    while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
    }
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


#define TESTCARD "adventurer"
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

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int hand[], int testHandCount, int z, 
        int treasure, int player, int test);
		
int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

int main() {
	int i, k;//counter
    int seed = 1000; //used in rngs
    int numPlayer = 2;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, cardPosition = 0;
    int p;//used to store player 
	int z = 0;
	const int ZERO_CARDS = 0;

	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0, errorFlag6 = 0, errorFlag7 = 0, errorFlag8 = 0, errorFlag9 = 0;	
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
	        
    struct gameState preCall;
    struct gameState postCall;
	
	const int CARDS_TOTAL = 10;
	
	//kingdom cards 
    int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};		

	//all mixed deck
    int tenMixedCards[10] = {gold, gold, adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute};

	int treasures[3] = {silver, copper, gold};	
	int treasureCardDecks [3][10];
	
	for(i = 0; i < 3; ++i){
		for(k = 0; k < CARDS_TOTAL; ++k){
			treasureCardDecks[i][k] = treasures[i];
		}
	}

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	//test both players
    for (p = 0; p < numPlayer; p++){
		
		//****************running tests************************************	
		//test all the treasure decks with no cards in hand or discard deck	
		for (k = 0; k < 3; ++k){
			
			initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);           
							
			//****************TEST WITH EMPTY HAND EMPTY DISCARD DECK AND ALL TREASURE DECKS***********					
			//set the correct turn
			preCall.whoseTurn = p;
			//set hand size
			preCall.handCount[p] = ZERO_CARDS;			
            //set deck count
            preCall.deckCount[p] = CARDS_TOTAL;           
			//copy treasure deck into players deck
			memcpy(preCall.deck[p], treasureCardDecks[k], sizeof(int) * CARDS_TOTAL);
			//save the state
			memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling discardCard
			cardEffect(adventurer, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
			
			//hand should be +1 and deck should be -2
			if(((postCall.handCount[p] != (preCall.handCount[p] + 1)) ||
					  (postCall.deckCount[p] != (preCall.deckCount[p] - 2))) && !errorFlag1){ 
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST1); 
				errorFlag1 = 1;
			}
			
			//test hand counts are correct 
			//assert(postCall.handCount[p] == (preCall.handCount[p] + 1));					
				
			//test deck count is 2 small post call
			//assert(postCall.deckCount[p] == (preCall.deckCount[p] - 2));                
			
			//discard count should not change
			if(postCall.discardCount[p] != preCall.discardCount[p] && !errorFlag2){ 
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST2); 
				errorFlag2 = 1;
			}
		
			//** NEED TO LOOK AT THIS ***discard count should not change*****************
			//assert(postCall.discardCount[p] == preCall.discardCount[p]);
			
			//test no other changes occured to game state	
			preCall.handCount[p] += 1;						
			preCall.deckCount[p] -= 2;			
						
			memcpy(&preCall.hand[p], &postCall.hand[p], sizeof(int) * MAX_HAND);
			//memcpy(&preCall.deck[p], &postCall.deck[p], sizeof(int) * MAX_DECK);
			//memcpy(&preCall.discard[p], &postCall.discard[p], sizeof(int) * MAX_DECK);
			//memcpy(&preCall.playedCards, &postCall.playedCards, sizeof(int) * MAX_DECK);

			//test no other changes occured to game state	
			if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag3){ 
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST3); 
				errorFlag3 = 1;
			}

			//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);					
		}	

		initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);           
						
		//****************TEST ADVENTURER CARD IS DISCARDED PROPERLY*********************************************************		
		//set actions, coins and buys
		preCall.numActions = 0;
		preCall.numBuys = 0;
		preCall.coins = 0;
		//set played cards to zero	
		preCall.playedCardCount = 0;
		//set the correct turn
		preCall.whoseTurn = p;
		//set hand sizeof
		preCall.handCount[p] = CARDS_TOTAL;
		preCall.deckCount[p] = CARDS_TOTAL;
		preCall.discardCount[p] = 0;
		memcpy(preCall.hand[p], tenMixedCards, sizeof(int) * CARDS_TOTAL);
		//add adventurer card into correct position
		preCall.hand[p][cardPosition] = adventurer;
		
		//save the state
		memcpy(&postCall, &preCall, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
		
		if((p == 0) && !errorFlagP){
			if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST9); 
				errorFlagP = 1;
			}
		}else if(!errorFlagP){
			if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
				printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST9); 
				errorFlagP = 1;
			}
		}
		
		if(!errorFlagV && (noVictoryCardChanges(&preCall, &postCall, p) < 0) ){
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST10); 
			errorFlagV = 1;
		}
		if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, CARDS_TOTAL) < 0)){
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST11); 
			errorFlagD = 1;
		}
		
		if(postCall.playedCardCount != (preCall.playedCardCount + 1) && !errorFlag4){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, village, p, TEST4); 
			errorFlag4 = 1;
		}
		
		//test number of played cards is correct 
		//assert(postCall.playedCardCount == (preCall.playedCardCount + 1));
		
		if(((postCall.hand[p][cardPosition] == adventurer) || (preCall.hand[p][cardPosition] != adventurer)) && !errorFlag5){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, adventurer, p, TEST5); 
			errorFlag5 = 1;
		}
	
		//test adventurer card has been removed successfully
		//assert(postCall.hand[p][cardPosition] != adventurer);											   
		//assert(preCall.hand[p][cardPosition] == adventurer);		
		
		initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);
		
		//****************TEST WITH NON EMPTY HAND AND NON EMPTY DISCARD DECK AND 2 TREASURE CARDS AT START OF DECK***********		
		//set actions, coins and buys
		preCall.numActions = 0;
		preCall.numBuys = 0;
		preCall.coins = 0;
		//set played cards to zero	
		preCall.playedCardCount = 0;
		//set the correct turn
		preCall.whoseTurn = p;
		//set hand sizeof		
		preCall.deckCount[p] = CARDS_TOTAL; 
		//copy mixed deck into players deck
		memcpy(preCall.deck[p], tenMixedCards, sizeof(int) * CARDS_TOTAL);
		//save the state
		memcpy(&postCall, &preCall, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
		
		//hand should be +1 and deck should be - 10
		if((postCall.deckCount[p] != (preCall.deckCount[p] - 10)) && !errorFlag6){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST6); 
			errorFlag6 = 1;
		}
		
		//test hand counts are correct 
		//assert(postCall.handCount[p] == (preCall.handCount[p] + 2));
		
		//test deck count is 10 small post call
		//assert(postCall.deckCount[p] == (preCall.deckCount[p] - 10));                
		
		//discard count should have removed 8 cards
		if(postCall.discardCount[p] != preCall.discardCount[p] + 8 && !errorFlag7){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST7); 
			errorFlag7 = 1;
		}
	
		//discard count should not change
		//assert(postCall.discardCount[p] == preCall.discardCount[p] + 8);
		
		//test no other changes occured to game state	
		preCall.handCount[p] += 1;						
		preCall.deckCount[p] -= 10;
        preCall.discardCount[p] += 8;        
					
		memcpy(&preCall.hand[p], &postCall.hand[p], sizeof(int) * MAX_HAND);
		//memcpy(&preCall.deck[p], &postCall.deck[p], sizeof(int) * MAX_DECK);
		memcpy(&preCall.discard[p], &postCall.discard[p], sizeof(int) * MAX_DECK);
		//memcpy(&preCall.playedCards, &postCall.playedCards, sizeof(int) * MAX_DECK);

		//test no other changes occured to game state	
		if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && ! errorFlag8){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST8); 
			errorFlag8 = 1;
		}

		//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);

		initializeMyGame(&preCall, kingdomCards, seed++, numPlayer);
		//****************TEST WITH NO TREASURE CARDS IN DECK***********		
		//set actions, coins and buys
		preCall.numActions = 0;
		preCall.numBuys = 0;
		preCall.coins = 0;
		//set played cards to zero	
		preCall.playedCardCount = 0;
		//set the correct turn
		preCall.whoseTurn = p;
		//set hand sizeof		
		preCall.deckCount[p] = CARDS_TOTAL; 
		//copy mixed deck into players deck
		memcpy(preCall.deck[p], kingdomCards, sizeof(int) * CARDS_TOTAL);
		//save the state
		memcpy(&postCall, &preCall, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &postCall, cardPosition, &bonus);
		
		//hand count should no change since no treasure cards
		if((postCall.handCount[p] != (preCall.handCount[p])) && !errorFlag9){ 
			printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], z, k, p, TEST12); 
			errorFlag9 = 1;
		}
	}

	if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 && !errorFlag6 && !errorFlag7 && !errorFlag8 &&
		!errorFlag9 && !errorFlagP && ! errorFlagV && ! errorFlagD ){
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

void printState(struct gameState *pre, struct gameState *post, int hand[], int testHandCount, int z, 
        int treasure, int player, int test){
	
	printf("Error found in %s, %d\n", TESTCARD, test );
	printf("\tpost.whoseTurn = %d pre.whoseTurn = %d\n", post->whoseTurn, pre->whoseTurn );   
    printf("\tpost.numBuys = %d pre.numBuys = %d\n", post->numBuys, pre->numBuys );   
    printf("\tpost.NumAction = %d pre.NumActions = %d\n", post->numActions, pre->numActions );
    printf("\tpost.Coins = %d pre.Coins = %d\n", post->coins, pre->coins);
	printf("\tpost.HandCount = %d  pre.HandCount = %d\n", post->handCount[player], pre->handCount[player]);
	printf("\tz = %d  \n", z);
    printf("\tpreCall.hand[p][z] = %d\n", pre->hand[player][z]);	 
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
