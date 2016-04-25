/* -----------------------------------------------------------------------
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: unittest2.c
 * Description: Skeleton taken from CS362 week4 module.
 * Demonstration of how to write unit tests for dominion-base
 * File tests the drawCard in the dominion_helpers.h interface
 * implementation is in the dominion.c file
 *
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
 
 /*
 * DRAW CARD FUNCTION
 * No documentation in the implementation or the interface
 * Description: Function drawCard will draw a card from the players deck and add it to
 * their hand.
 * Preconditions: player and state are valid states of the game
 * Postconditions: A card has been removed from the players deck and a card has been added to
 * the players hand.
 * Testing Requirements: 
 * Only a single card should be removed from the deck and added to the players hand.
 * If the deck is empty then the function will add the discard pile to the deck
 * The discard deck will then be empty after it's added to the deck.
 * No other changes to the game state should occur.
 * The players hand count should increase by one if deck is not empty
 * The players deck count should decrease by one if deck is not empty
 * Player should be a number between 2 and MAX_PLAYERS
 * If player has no cards in deck and no cards in discard pile then no changes should be made
 * 
 int drawCard(int player, struct gameState *state)
{	int count;
  int deckCounter;
  if (state->deckCount[player] <= 0){//Deck is empty
    
    //Step 1 Shuffle the discard pile back into a deck
    int i;
    //Move discard to deck
    for (i = 0; i < state->discardCount[player];i++){
      state->deck[player][i] = state->discard[player][i];
      state->discard[player][i] = -1;
    }

    state->deckCount[player] = state->discardCount[player];
    state->discardCount[player] = 0;//Reset discard

    //Shufffle the deck
    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
   
    if (DEBUG){//Debug statements
      printf("Deck count now: %d\n", state->deckCount[player]);
    }
    
    state->discardCount[player] = 0;

    //Step 2 Draw Card
    count = state->handCount[player];//Get current player's hand count
    
    if (DEBUG){//Debug statements
      printf("Current hand count: %d\n", count);
    }
    
    deckCounter = state->deckCount[player];//Create a holder for the deck count

    if (deckCounter == 0)
      return -1;

    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
    state->deckCount[player]--;
    state->handCount[player]++;//Increment hand count
  }

  else{
    int count = state->handCount[player];//Get current hand count for player
    int deckCounter;
    if (DEBUG){//Debug statements
      printf("Current hand count: %d\n", count);
    }

    deckCounter = state->deckCount[player];//Create holder for the deck count
    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
    state->deckCount[player]--;
    state->handCount[player]++;//Increment hand count
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


#define TEST "DRAW_CARD"
#define TEST_EMPTY 0
#define TEST_NO_CARDS_IN_DECK 1
#define TEST_CARDS_IN_DECK 2

//Function will initialize the gameState struct
int initializeMyGame(struct gameState *G, int actionCards[], int seed, int numPlayer);
//Function will print the state of the test variable if error is found
void printState(struct gameState *G, int hand[], int testDiscardDeckCount, int testHandCount, 
        int testDeckCount, int player, int test);
		
int noPlayerStateChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noVictoryCardChanges(struct gameState *preCall, struct gameState *postCall, int p);
int noDominionCardChanges(struct gameState *preCall, struct gameState *postCall, int p, int deckSize);

int main() {
    int k; //counter
    int seed = 1000; //used in rngs
    int numPlayer = 2;
	
	int errorFlag1 = 0, errorFlag2 = 0, errorFlag3 = 0, errorFlag4 = 0, errorFlag5 = 0, errorFlag6 = 0, errorFlag7 = 0, errorFlag8 = 0;
	int errorFlagP = 0, errorFlagV = 0, errorFlagD = 0;
	int bonus = 0;
    int p;   //used to keep track of player
	const int ACTION_CARD_TOTAL = 20;
    int actionCards[20] = { 
        adventurer, council_room, feast, gardens, mine, remodel, smithy, 
        village, baron, great_hall, minion, steward, tribute, ambassador, 
        cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};   
            
    struct gameState preCall;
    struct gameState postCall;   
	
	
	//used to test a hand with no cards in deck and no cards in discard deck
	const int TEST_ZERO_HAND_COUNT = 0;	
	
	const int ALL_CARDS_COUNT = 27;//all possible cards
	
	// represents a deck with each of the possible cards
    int testAllCardsDeck[ALL_CARDS_COUNT];   	
		
	//represents a discard-deck with each of the possible cards
    int testAllCardsDiscardDeck[ALL_CARDS_COUNT];  
	   
	
	/*
	* Initialize the test hands
	*/			
	//add action cards to no treasure test hand
	for(k = 0; k < ACTION_CARD_TOTAL; ++k){
	  testAllCardsDeck[k] = actionCards[k]; 
	  testAllCardsDiscardDeck[k] = actionCards[k]; 
	}

	//add other cards
	testAllCardsDeck[k] = estate;
	testAllCardsDiscardDeck[k] = estate;
	testAllCardsDeck[k+1] = duchy;
	testAllCardsDiscardDeck[k] = duchy;
	testAllCardsDeck[k+2] = province;
	testAllCardsDiscardDeck[k] = province;	
	testAllCardsDeck[k+3] = curse; 
	testAllCardsDiscardDeck[k] = curse;	 
	testAllCardsDeck[k+4] = gold;
	testAllCardsDiscardDeck[k] = gold;
	testAllCardsDeck[k+5] = silver;			
	testAllCardsDiscardDeck[k] = silver;			
	testAllCardsDeck[k+6] = copper;	
	testAllCardsDiscardDeck[k] = copper;	


    printf ("Starting unittest2\nTESTING drawCard():\n");
	
	//test both players
    for (p = 0; p < numPlayer; p++){
		
		initializeMyGame(&preCall, actionCards, seed++, numPlayer);           
		
		//****************test EMPTY (case 0) where player has no cards************************************			         
		preCall.deckCount[p] = TEST_ZERO_HAND_COUNT; // set deck size to 0  
		preCall.discardCount[p] = TEST_ZERO_HAND_COUNT; // set discard deck size to 0 
		preCall.whoseTurn = p; //set turn
		memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
		drawCard(p, &postCall);
		
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
		
		
		if(((postCall.deckCount[p] != 0 || postCall.discardCount[p] != 0) || 
				(preCall.handCount[p] != postCall.handCount[p])) && !errorFlag1){ 
			printState(&postCall, 0, preCall.discardCount[p], preCall.handCount[p], preCall.deckCount[p], p, TEST_EMPTY); 
			errorFlag1 = 1;
		}
		//make sure counts are correct and game state hasn't changed
		//assert(postCall.handCount[p] == preCall.handCount[p]);
		//assert(postCall.deckCount[p] == preCall.deckCount[p]);
		//assert(postCall.discardCount[p] == preCall.discardCount[p]);
		
		if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag2){ 
			printState(&postCall, 0, preCall.discardCount[p], preCall.handCount[p], preCall.deckCount[p], p, TEST_EMPTY); 
			errorFlag2 = 1;
		}
		//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);
		
		initializeMyGame(&preCall, actionCards, seed++, numPlayer);
		
		//*******************test TEST_NO_CARDS_IN_DECK BUT CARDS IN DISCARD DECK (case 1)***************
		memcpy(preCall.discard[p], testAllCardsDiscardDeck, sizeof(int) * ALL_CARDS_COUNT);			
		preCall.deckCount[p] = TEST_ZERO_HAND_COUNT; // set deck size to 0  
		preCall.discardCount[p] = ALL_CARDS_COUNT;  
		
		memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
		drawCard(p, &postCall);
		
		if(((postCall.deckCount[p] != (ALL_CARDS_COUNT - 1)) || (postCall.discardCount[p] != 0) ||
				((preCall.handCount[p] + 1) != postCall.handCount[p])) && !errorFlag3){ 
			printState(&postCall, preCall.hand[p], preCall.discardCount[p], preCall.handCount[p], 
                    preCall.deckCount[p], p, TEST_NO_CARDS_IN_DECK); 
			errorFlag3 = 1;		
		}
		//make sure counts are correct and game state hasn't changed
		//assert(postCall.handCount[p] == (preCall.handCount[p] + 1));
		//assert(postCall.deckCount[p] == (ALL_CARDS_COUNT - 1));
		//assert(postCall.discardCount[p] == 0);
		
		if(postCall.hand[p][postCall.handCount[p]-1] != postCall.deck[p][postCall.deckCount[p]] && !errorFlag4){ 
			printState(&postCall, 0, preCall.discardCount[p], preCall.handCount[p], preCall.deckCount[p], p, TEST_NO_CARDS_IN_DECK); 
			errorFlag4 = 1;
		}
		//ensure correct card has been added	
		//assert(postCall.hand[p][postCall.handCount[p]-1] == postCall.deck[p][postCall.deckCount[p]]);	
	   
		//make expected changes to preCall so structs are equal
		preCall.handCount[p] += 1;
		preCall.deckCount[p] = (ALL_CARDS_COUNT - 1);
		preCall.discardCount[p] = 0;
		preCall.hand[p][postCall.handCount[p]-1] = postCall.deck[p][postCall.deckCount[p] ];
		memcpy(preCall.deck[p], postCall.deck[p], sizeof(int) * ALL_CARDS_COUNT);//assign deck
		memcpy(preCall.discard[p], postCall.discard[p], sizeof(int) * ALL_CARDS_COUNT);

		if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag5){ 
			printState(&postCall, preCall.hand[p], preCall.discardCount[p], preCall.handCount[p], 
                    preCall.deckCount[p], p, TEST_NO_CARDS_IN_DECK);
			errorFlag5 = 1;		
		}
		assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);

		initializeMyGame(&preCall, actionCards, seed++, numPlayer);			
		//*********************test TEST_CARDS_IN_DECK (case 2) where player has cards in deck and discard deck***			
		memcpy(preCall.deck[p], testAllCardsDeck, sizeof(int) * ALL_CARDS_COUNT);
		preCall.deckCount[p] = ALL_CARDS_COUNT; // set deck size to 17  
				
		memcpy(&postCall, &preCall, sizeof(struct gameState));//save game state before calling updateCoins
		drawCard(p, &postCall);
		
		//test no changes in deck
		if (!errorFlagD && (noDominionCardChanges(&preCall, &postCall, p, ALL_CARDS_COUNT - 1) < 0) ){
			printState(&postCall, 0, 0, TEST_ZERO_HAND_COUNT, bonus, p, TEST_EMPTY); 
			errorFlagD = 1;
		}
		
		if(((postCall.deckCount[p] != (ALL_CARDS_COUNT - 1)) || ((preCall.handCount[p] + 1) != postCall.handCount[p])) && !errorFlag6){ 
			printState(&postCall, preCall.hand[p], preCall.discardCount[p], preCall.handCount[p], 
                    preCall.deckCount[p], p, TEST_CARDS_IN_DECK); 
			errorFlag6 = 1;		
		}
		//make sure counts are correct and game state hasn't changed
		//assert(postCall.handCount[p] == (preCall.handCount[p] + 1));
		//assert(postCall.deckCount[p] == (ALL_CARDS_COUNT - 1));
		//assert(postCall.discardCount[p] == 0);
		
		if(postCall.hand[p][postCall.handCount[p]-1] != preCall.deck[p][preCall.deckCount[p] - 1] && !errorFlag7){ 
			printState(&postCall, 0, preCall.discardCount[p], preCall.handCount[p], preCall.deckCount[p], p, TEST_CARDS_IN_DECK); 
			errorFlag7 = 1;
		}
		//ensure correct card has been added	
		//assert(postCall.hand[p][postCall.handCount[p]-1] == preCall.deck[p][preCall.deckCount[p] - 1]);	
		
		//make expected changes to preCall so structs are equal
		preCall.handCount[p] += 1;
		preCall.deckCount[p] = (ALL_CARDS_COUNT - 1);            
		preCall.hand[p][postCall.handCount[p]-1] = preCall.deck[p][preCall.deckCount[p]];

		if(memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag8){ 
			printState(&postCall, preCall.hand[p], preCall.discardCount[p], preCall.handCount[p], 
                    preCall.deckCount[p], p, TEST_CARDS_IN_DECK);
			errorFlag8 = 1;		
		}
		//assert(memcmp(&preCall, &postCall, sizeof(struct gameState)) == 0);
      
    }

    if(!errorFlag1 && !errorFlag2 && !errorFlag3 && !errorFlag4 && !errorFlag5 && !errorFlag6 && !errorFlag7 && !errorFlag8 &&
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

void printState(struct gameState *G, int hand[], int testDiscardDeckCount, int testHandCount, 
        int testDeckCount, int player, int test){
	
	printf("Error found in %s, %d\n", TEST, test );
	printf("\tpost G->handCount = %d  testHandCount = %d\n", G->handCount[player], testHandCount);
	printf("\tpost G->deckCount = %d  testDeckCount = %d\n", G->deckCount[player], testDeckCount);
	printf("\tpost G->discardCount = %d testDiscardDeckCount = %d\n\n", G->discardCount[player], testDiscardDeckCount);	
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
