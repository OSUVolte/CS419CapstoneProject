/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: unittest3.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the discardCard function in the dominion_helpers.h interface
 * implementation is in the dominion.c file                                                     }
 *
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * DISCARD CARD FUNCTION
 * No documentation in the implementation or the interface
 * Description: Function drawCard will d iscard a card from the players deck and put it
 * in the playedCards deck if the trash flag is not set.  If the trash flag is set then the 
 * discarded card is trashed.
 * Preconditions: player and state are valid states of the game, handPos is the position of the card
 * in the hand, trash flag is set if it's > 0
 * Postconditions: A card has been removed from the players hand and either trashed or added 
 * to the played cards pile.
 * Testing Requirements: 
 * Only a single card should be removed from the deck and added to the played card deck if trash flag not set.
 * If the trash flag is set then the card is removed from the hand and not added to the played cards deck
 * No other changes to the game state should occur.
 * The players hand count should decrease by one if deck is not empty
 * The players deck count should decrease by one if deck is not empty
 * Player should be a number between 2 and MAX_PLAYERS
 * If player has no cards in deck then no changes should be made
 * Discard count should increase by 1000
 * Discard deck should contain the card discarded
 * if handCount is > 1 then last card in hand will replace the discarded card and then
 * last card in deck is set to -1(empty)
 * NOT SURE WHAT PLAYEDCARDS[] IS FOR I THINK PLAYEDCARDS SHOULD GET DUMPED INTO DSICARD[] AT SOME POINT
 int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h" //random number generator multiple streams


#define TEST "DISCARD_CARD"

#define TEST0 0
#define TEST1 1
#define TEST2 2
#define TEST3 3
#define TEST4 4
#define TEST5 5
#define TEST6 6
#define TEST7 7

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *pre, struct gameState *post, int hand[], int testPlayedCardCount, int testHandPosition, 
        int testTrashFlag, int player, int test);

int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

int main() {
    int i;//counters
    int seed = 1000; //used in rngs
    int numPlayer = 2;

	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0;
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
    int p;//used to store player 
	int trash = 0;
	int cardPosition = 0;
	const int ACTION_CARD_TOTAL = 10;
    int actionCards[10] = { 
        smithy, smithy, smithy, smithy, smithy, smithy, smithy, 
        smithy, smithy, smithy};   
            
    struct gameState preCall;
    struct gameState postCall;   		
	
    printf ("Starting unittest3\nTESTING discardCard():\n");
	
	//test both players
    for (p = 0; p < numPlayer; p++){
		
		//test different hands
		for (i = 1; i <= ACTION_CARD_TOTAL; i++){
			
			//test different trash flags
			for(trash = 0; trash < 2; ++trash){
			
				//test different card positions in the hand
				for(cardPosition = 0; cardPosition < i; ++cardPosition){
			
					initializeMyGame(&preCall, actionCards, seed++, numPlayer);           
					
					//****************running tests************************************																
					memcpy(preCall.hand[p], actionCards, sizeof(int) * ACTION_CARD_TOTAL);								
					preCall.handCount[p] = i; 					
                    preCall.playedCardCount = 0;
                    preCall.discardCount[p] = 0;
					preCall.whoseTurn = p; //set turn
					preCall.deckCount[p] = ACTION_CARD_TOTAL;
					memcpy(preCall.deck[p], actionCards, sizeof(int) * ACTION_CARD_TOTAL);
					memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling discardCard
					discardCard(cardPosition, p, &postCall, trash);
					
					if((p == 0) && !errorFlagP){
						if(noPlayerStateChanges(&preCall, &postCall, 1) < 0){
							printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST5); 
							errorFlagP = 1;
						}
					}else if(!errorFlagP){
						if(noPlayerStateChanges(&preCall, &postCall, 0) < 0){
							printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST5); 
							errorFlagP = 1;
						}
					}
					
					if((!errorFlagV && noVictoryCardChanges(&preCall, &postCall, p) < 0) ){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST6); 
						errorFlagV = 1;
					}
					if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, ACTION_CARD_TOTAL) < 0)){
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST7); 
						errorFlagD = 1;
					}
					
					if(postCall.discardCount[p] != preCall.discardCount[p] + 1 && !errorFlag1){ 
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST0); 
						errorFlag1 = 1;
					}
					
					if(postCall.handCount[p] != (i - 1) && !errorFlag2){ 
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST1); 
						errorFlag2 = 1;
					}
					if (trash < 1){
						if(preCall.playedCardCount != (postCall.playedCardCount - 1) && !errorFlag3){
							printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST2); 
							errorFlag3 = 1;
						}
					}
					//make sure counts are correct and game state hasn't changed
					//assert(postCall.handCount[p] == (preCall.handCount[p] - 1));					
					
                    if(trash < 1){
						
						//assert(postCall.playedCardCount == (preCall.playedCardCount + 1));						
						//assert(postCall.playedCards[(postCall.playedCardCount - 1)] == preCall.hand[p][cardPosition]);
						
						preCall.playedCardCount += 1;
						preCall.playedCards[(postCall.playedCardCount - 1)] = preCall.hand[p][cardPosition];
					}
                    //set card played to -1
                    preCall.hand[p][cardPosition] = -1;

					//check card has been removed successfully
					if(i > 1 || (preCall.handCount[p] - 1) > cardPosition){

						if(((postCall.hand[p][cardPosition] != preCall.hand[p][(preCall.handCount[p] - 1)]) ||
								(postCall.hand[p][preCall.handCount[p] - 1])) == -1 && ! errorFlag4){ 
							printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST3); 
							errorFlag4 = 1;
						}
						//assert(postCall.hand[p][cardPosition] == preCall.hand[p][(preCall.handCount[p] - 1)]);
						//assert(postCall.hand[p][preCall.handCount[p] - 1] == -1);
                		preCall.hand[p][cardPosition] = preCall.hand[p][(preCall.handCount[p] - 1)];
					    preCall.hand[p][(preCall.handCount[p] - 1)] = -1;			
				    }
								
					preCall.handCount[p] -= 1;					

					if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && ! errorFlag5){ 
						printState(&preCall, &postCall, preCall.hand[p], preCall.handCount[p], cardPosition, trash, p, TEST4); 
						errorFlag5 = 1;
					}
					//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);									
                }        
			}		  
		}
	}

	if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 &&
		!errorFlagP && ! errorFlagV && ! errorFlagD ){
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
