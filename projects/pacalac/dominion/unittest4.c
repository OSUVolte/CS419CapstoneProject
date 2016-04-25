#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
int buyCard(int supplyPos, struct gameState *state) {
  int who;
  if (DEBUG){
    printf("Entering buyCard...\n");
  }

  // I don't know what to do about the phase thing.

  who = state->whoseTurn;

  if (state->numBuys < 1){
    if (DEBUG)
      printf("You do not have any buys left\n");
    return -1;
  } else if (supplyCount(supplyPos, state) <1){
    if (DEBUG)
      printf("There are not any of that type of card left\n");
    return -1;
  } else if (state->coins < getCost(supplyPos)){
    if (DEBUG) 
      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    return -1;
  } else {
    state->phase=1;
    //state->supplyCount[supplyPos]--;
    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
  
    state->coins = (state->coins) - (getCost(supplyPos));
    state->numBuys--;
    if (DEBUG)
      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
  }

  //state->discard[who][state->discardCount[who]] = supplyPos;
  //state->discardCount[who]++;
    
  return 0;
}
*/
void testBuyCard()
{	
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, minion, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = smithy;	//card to test.
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		int handC = 0;
		int buyC = 0;
		int coinC = 0;
		int suppC = 0;
		game.handCount[currPlayer] = 0;
	
		//Try to buy card when player has no buys left.
		game.numBuys = 0;
		game.coins = 10;
		game.supplyCount[tarCard] = 5;
		
		handC = game.handCount[currPlayer];
		buyC = game.numBuys;
		coinC = game.coins;
		suppC = game.supplyCount[tarCard];
		
		buyCard(tarCard, &game);
		
		if(handC == game.handCount[currPlayer] && buyC == game.numBuys && coinC == game.coins && suppC == game.supplyCount[tarCard])
			printf("Test to buy a card with no buy points succeeded. Hand, buy, coin, and supply counts unchanged.\n\n");
		else
			printf("Test to buy a card with no buy points failed.Hand, buy, coin, and supply counts mismatch.\n\n");
		
		//Try to buy card where none are left.
		game.numBuys = 10;
		game.coins = 10;
		game.supplyCount[tarCard] = 0;
		
		handC = game.handCount[currPlayer];
		buyC = game.numBuys;
		coinC = game.coins;
		suppC = game.supplyCount[tarCard];
		
		buyCard(tarCard, &game);
		
		if(handC == game.handCount[currPlayer] && buyC == game.numBuys && coinC == game.coins && suppC == game.supplyCount[tarCard])
			printf("Test to buy a card with no supply succeeded. Hand, buy, coin, and supply counts unchanged.\n\n");
		else
			printf("Test to buy a card with no supply failed. Hand count and buy count mismatch.\n\n");
		
		
		//Try to buy card without enough coins.
		game.numBuys = 10;
		game.coins = 0;
		game.supplyCount[tarCard] = 5;
		
		handC = game.handCount[currPlayer];
		buyC = game.numBuys;
		coinC = game.coins;
		suppC = game.supplyCount[tarCard];
		
		buyCard(tarCard, &game);
		
		if(handC == game.handCount[currPlayer] && buyC == game.numBuys && coinC == game.coins && suppC == game.supplyCount[tarCard])
			printf("Test to buy a card with no coins succeeded. Hand, buy, coin, and supply counts unchanged.\n\n");
		else
			printf("Test to buy a card with no coins failed. Hand count and buy count mismatch.\n\n");
		
		
		//Buy card with enough coins and enough cards left.
		game.numBuys = 10;
		game.coins = 10;
		buyC = game.numBuys;
		handC = game.handCount[currPlayer];
		game.supplyCount[tarCard] = 5;
		
		handC = game.handCount[currPlayer];
		buyC = game.numBuys;
		coinC = game.coins;
		suppC = game.supplyCount[tarCard];
		
		buyCard(tarCard, &game);
		++handC;
		
		if(handC == game.handCount[currPlayer] && buyC > game.numBuys && coinC > game.coins && suppC > game.supplyCount[tarCard])
			printf("Test to buy a card with correct points succeeded. Hand, buy, coin, and supply counts changed correctly.\n");
		else
			printf("Test to buy a card with correct points failed. Hand %d != %d, buy %d !> %d, coin %d !> %d, or supply %d !> %d.\n", handC, game.handCount[currPlayer], buyC, game.numBuys, coinC, game.coins, suppC, game.supplyCount[tarCard]);
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testBuyCard();
	return 0;
}