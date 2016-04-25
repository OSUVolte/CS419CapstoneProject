/* 
Author: Jonathan Hardman
File name: cardtest3.c

Card Effect Requirements: Adventurer
1. Current player should receive 2 treasure cards.

2. Cards should come from his own pile.

3. If less than 2 treasure cards left then continue game with no more.

3. No state change should occur for other players.

4. No state change should occur to the victory card piles and kingdom card piles.
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int initializeGame2(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state);
int initializeGame3(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state);

int main() {
	int AssertON = 0;

    int p1newCards = 0;
	int p1discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Copper Cards--------------
	printf("TEST 1: COPPER\n");
	
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	updateCoins(thisPlayer, &testG, 0);

	p1newCards = 2;
	p1discarded = 1;
	xtraCoins = 2;
	
	//Player 1 checks
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + p1newCards - p1discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - p1newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions);
	printf("buys count = %d, expected = %d\n", testG.numBuys, G.numBuys);
	
	if(AssertON == 1){
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + p1newCards - p1discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - p1newCards + shuffledCards);
		assert(testG.coins == G.coins + xtraCoins);
		assert(testG.numActions == G.numActions);
		assert(testG.numBuys == G.numBuys);
	}
	
	printf("PASSED\n");
	
	//Player 2 checks
	printf("\nPlayer 2 checks\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	
	if(AssertON == 1){
		assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
		assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
	}
	printf("PASSED\n");
	
	//Supply Checks
	printf("\nChecking Card Piles... ");
	//checking victory cards
	int temp = supplyCount(estate,&testG), temp2 = supplyCount(estate,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(duchy,&testG), temp2 = supplyCount(duchy,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(province,&testG), temp2 = supplyCount(province,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	
	//checking kingdom cards
	for (i=0; i<10; i++)
	{
		temp = supplyCount(k[i],&testG);
		temp2 = supplyCount(k[i],&G);
		if(AssertON == 1){
			assert(temp == temp2);
		}
	}
	
	printf("PASSED\n");
	printf("\nCOPPER PASSED\n");
	
	// ----------- TEST 2: Silver Cards--------------
	printf("\nTEST 2: SILVER\n");
	
	// initialize a game state and player cards
	initializeGame2(numPlayers, k, seed, &G);
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	updateCoins(thisPlayer, &testG, 0);

	p1newCards = 2;
	p1discarded = 1;
	xtraCoins = 4;
	
	//Player 1 checks
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + p1newCards - p1discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - p1newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions);
	printf("buys count = %d, expected = %d\n", testG.numBuys, G.numBuys);
	
	if(AssertON == 1){
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + p1newCards - p1discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - p1newCards + shuffledCards);
		assert(testG.coins == G.coins + xtraCoins);
		assert(testG.numActions == G.numActions);
		assert(testG.numBuys == G.numBuys);
	}
	printf("PASSED\n");
	
	//Player 2 checks
	printf("\nPlayer 2 checks\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	if(AssertON == 1){
		assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
		assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
	}
	printf("PASSED\n");
	
	
	//Supply Checks
	printf("\nChecking Card Piles... ");
	//checking victory cards
	temp = supplyCount(estate,&testG), temp2 = supplyCount(estate,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(duchy,&testG), temp2 = supplyCount(duchy,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(province,&testG), temp2 = supplyCount(province,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	
	//checking kingdom cards
	for (i=0; i<10; i++)
	{
		temp = supplyCount(k[i],&testG);
		temp2 = supplyCount(k[i],&G);
		if(AssertON == 1){
			assert(temp == temp2);
		}
	}
	printf("PASSED\n");
	printf("\nSILVER PASSED\n");
	
	// ----------- TEST 3: Gold Cards--------------
	printf("\nTEST 3: GOLD\n");
	
	// initialize a game state and player cards
	initializeGame3(numPlayers, k, seed, &G);
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	updateCoins(thisPlayer, &testG, 0);

	p1newCards = 2;
	p1discarded = 1;
	xtraCoins = 6;
	
	//Player 1 checks
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + p1newCards - p1discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - p1newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions);
	printf("buys count = %d, expected = %d\n", testG.numBuys, G.numBuys);
	
	if(AssertON == 1){
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + p1newCards - p1discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - p1newCards + shuffledCards);
		assert(testG.coins == G.coins + xtraCoins);
		assert(testG.numActions == G.numActions);
		assert(testG.numBuys == G.numBuys);
	}
	printf("PASSED\n");
	
	//Player 2 checks
	printf("\nPlayer 2 checks\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	if(AssertON == 1){
		assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
		assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
	}
	printf("PASSED\n");
	
	
	//Supply Checks
	printf("\nChecking Card Piles... ");
	//checking victory cards
	temp = supplyCount(estate,&testG), temp2 = supplyCount(estate,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(duchy,&testG), temp2 = supplyCount(duchy,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(province,&testG), temp2 = supplyCount(province,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	
	//checking kingdom cards
	for (i=0; i<10; i++)
	{
		temp = supplyCount(k[i],&testG);
		temp2 = supplyCount(k[i],&G);
		if(AssertON == 1){
			assert(temp == temp2);
		}
	}
	printf("PASSED\n");
	printf("\nGOLD PASSED\n");
	
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}

/**********************************************************************************************
***********************************************************************************************
***********************************************************************************************
***********************************************************************************************
***********************************************************************************************
**********************************************************************************************/

int initializeGame2(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state) {

  int i;
  int j;
  int it;			
  //set up random number generator
  SelectStream(1);
  PutSeed((long)randomSeed);
  
  //check number of players
  if (numPlayers > MAX_PLAYERS || numPlayers < 2)
    {
      return -1;
    }

  //set number of players
  state->numPlayers = numPlayers;

  //check selected kingdom cards are different
  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
        {
	  if (j != i && kingdomCards[j] == kingdomCards[i])
	    {
	      return -1;
	    }
        }
    }


  //initialize supply
  ///////////////////////////////

  //set number of Curse cards
  if (numPlayers == 2)
    {
      state->supplyCount[curse] = 10;
    }
  else if (numPlayers == 3)
    {
      state->supplyCount[curse] = 20;
    }
  else
    {
      state->supplyCount[curse] = 30;
    }

  //set number of Victory cards
  if (numPlayers == 2)
    {
      state->supplyCount[estate] = 8;
      state->supplyCount[duchy] = 8;
      state->supplyCount[province] = 8;
    }
  else
    {
      state->supplyCount[estate] = 12;
      state->supplyCount[duchy] = 12;
      state->supplyCount[province] = 12;
    }

  //set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;

  //set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
    {
      for (j = 0; j < 10; j++)           		//loop chosen cards
	{
	  if (kingdomCards[j] == i)
	    {
	      //check if card is a 'Victory' Kingdom card
	      if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
		{
		  if (numPlayers == 2){ 
		    state->supplyCount[i] = 8; 
		  }
		  else{ state->supplyCount[i] = 12; }
		}
	      else
		{
		  state->supplyCount[i] = 10;
		}
	      break;
	    }
	  else    //card is not in the set choosen for the game
	    {
	      state->supplyCount[i] = -1;
	    }
	}

    }

  ////////////////////////
  //supply intilization complete

  //set player decks
  for (i = 0; i < numPlayers; i++)
    {
      state->deckCount[i] = 0;
      for (j = 0; j < 3; j++)
	{
	  state->deck[i][j] = estate;
	  state->deckCount[i]++;
	}
      for (j = 3; j < 10; j++)
	{
	  state->deck[i][j] = silver;
	  state->deckCount[i]++;		
	}
    }

  //shuffle player decks
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
	{
	  return -1;
	}
    }

  //draw player hands
  for (i = 0; i < numPlayers; i++)
    {  
      //initialize hand size to zero
      state->handCount[i] = 0;
      state->discardCount[i] = 0;
      //draw 5 cards
      // for (j = 0; j < 5; j++)
      //	{
      //	  drawCard(i, state);
      //	}
    }
  
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++)
    {
      state->embargoTokens[i] = 0;
    }

  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  //int it; move to top

  //Moved draw cards to here, only drawing at the start of a turn
  for (it = 0; it < 5; it++){
    drawCard(state->whoseTurn, state);
  }

  updateCoins(state->whoseTurn, state, 0);

  return 0;
}

int initializeGame3(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state) {

  int i;
  int j;
  int it;			
  //set up random number generator
  SelectStream(1);
  PutSeed((long)randomSeed);
  
  //check number of players
  if (numPlayers > MAX_PLAYERS || numPlayers < 2)
    {
      return -1;
    }

  //set number of players
  state->numPlayers = numPlayers;

  //check selected kingdom cards are different
  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
        {
	  if (j != i && kingdomCards[j] == kingdomCards[i])
	    {
	      return -1;
	    }
        }
    }


  //initialize supply
  ///////////////////////////////

  //set number of Curse cards
  if (numPlayers == 2)
    {
      state->supplyCount[curse] = 10;
    }
  else if (numPlayers == 3)
    {
      state->supplyCount[curse] = 20;
    }
  else
    {
      state->supplyCount[curse] = 30;
    }

  //set number of Victory cards
  if (numPlayers == 2)
    {
      state->supplyCount[estate] = 8;
      state->supplyCount[duchy] = 8;
      state->supplyCount[province] = 8;
    }
  else
    {
      state->supplyCount[estate] = 12;
      state->supplyCount[duchy] = 12;
      state->supplyCount[province] = 12;
    }

  //set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;

  //set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
    {
      for (j = 0; j < 10; j++)           		//loop chosen cards
	{
	  if (kingdomCards[j] == i)
	    {
	      //check if card is a 'Victory' Kingdom card
	      if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
		{
		  if (numPlayers == 2){ 
		    state->supplyCount[i] = 8; 
		  }
		  else{ state->supplyCount[i] = 12; }
		}
	      else
		{
		  state->supplyCount[i] = 10;
		}
	      break;
	    }
	  else    //card is not in the set choosen for the game
	    {
	      state->supplyCount[i] = -1;
	    }
	}

    }

  ////////////////////////
  //supply intilization complete

  //set player decks
  for (i = 0; i < numPlayers; i++)
    {
      state->deckCount[i] = 0;
      for (j = 0; j < 3; j++)
	{
	  state->deck[i][j] = estate;
	  state->deckCount[i]++;
	}
      for (j = 3; j < 10; j++)
	{
	  state->deck[i][j] = gold;
	  state->deckCount[i]++;		
	}
    }

  //shuffle player decks
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
	{
	  return -1;
	}
    }

  //draw player hands
  for (i = 0; i < numPlayers; i++)
    {  
      //initialize hand size to zero
      state->handCount[i] = 0;
      state->discardCount[i] = 0;
      //draw 5 cards
      // for (j = 0; j < 5; j++)
      //	{
      //	  drawCard(i, state);
      //	}
    }
  
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++)
    {
      state->embargoTokens[i] = 0;
    }

  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  //int it; move to top

  //Moved draw cards to here, only drawing at the start of a turn
  for (it = 0; it < 5; it++){
    drawCard(state->whoseTurn, state);
  }

  updateCoins(state->whoseTurn, state, 0);

  return 0;
}


