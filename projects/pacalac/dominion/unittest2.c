#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
{
  //Note: supplyPos is enum of choosen card
	
  //check if supply pile is empty (0) or card is not used in game (-1)
  if ( supplyCount(supplyPos, state) < 1 )
    {
      return -1;
    }
	
  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand

  if (toFlag == 1)
    {
      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      state->deckCount[player]++;
    }
  else if (toFlag == 2)
    {
      state->hand[ player ][ state->handCount[player] ] = supplyPos;
      state->handCount[player]++;
    }
  else
    {
      state->discard[player][ state->discardCount[player] ] = supplyPos;
      state->discardCount[player]++;
    }
	
  //decrease number in supply pile
  state->supplyCount[supplyPos]--;
	 
  return 0;
}
*/

void testGainCard()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, minion, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = smithy;	//card to test.
	int fillCard = minion;	//card to act as filler
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		int deckC = game.deckCount[currPlayer];
		int handC = game.handCount[currPlayer];
		int discardC = game.discardCount[currPlayer];
	
		//Try to add card when card has no supply count. All card counts should remain the same.
		game.supplyCount[tarCard] = 0;
		gainCard(tarCard, &game, 0, currPlayer);
		if(deckC == game.deckCount[currPlayer] && handC == game.handCount[currPlayer] && discardC == game.discardCount[currPlayer])
			printf("Adding card with no supply count succeeded. Deck, hand, and discard count unchanged.\n\n");
		else
			printf("Adding card with no supply count failed. Deck, hand, and discard count changed.\n\n");
		
		game.supplyCount[tarCard] = 5; //add supply count to target card for further tests
		deckC = game.deckCount[currPlayer];
		handC = game.handCount[currPlayer];
		discardC = game.discardCount[currPlayer];
		
		//Try to add card that is not used in the game. All card counts should remain the same.
		gainCard(cutpurse, &game, 0, currPlayer);
		if(deckC == game.deckCount[currPlayer] && handC == game.handCount[currPlayer] && discardC == game.discardCount[currPlayer])
			printf("Adding card not in game succeeded. Deck, hand, and discard count unchanged.\n\n");
		else
			printf("Adding card not in game failed. Deck, hand, and discard count changed.\n\n");
		
		deckC = game.deckCount[currPlayer];
		handC = game.handCount[currPlayer];
		discardC = game.discardCount[currPlayer];
		
		//Add card to player's deck. Player's deckCount should be incremented and supplyCount decremented.
		gainCard(tarCard, &game, 1, currPlayer);
		++deckC;
		if(deckC == game.deckCount[currPlayer] && handC == game.handCount[currPlayer] && discardC == game.discardCount[currPlayer])
			printf("Adding card to deck succeeded. Deck incremented. Hand and discard count unchanged.\n\n");
		else
			printf("Adding card to deck failed.\n\n");
			
		deckC = game.deckCount[currPlayer];
		handC = game.handCount[currPlayer];
		discardC = game.discardCount[currPlayer];
		
		//Add card to player's hand. Player's handCount should be incremented and supplyCount decremented.
		gainCard(tarCard, &game, 2, currPlayer);
		++handC;
		if(deckC == game.deckCount[currPlayer] && handC == game.handCount[currPlayer] && discardC == game.discardCount[currPlayer])
			printf("Adding card to hand succeeded. Hand incremented. Deck and discard count unchanged.\n\n");
		else
			printf("Adding card to hand failed.\n\n");
		
		deckC = game.deckCount[currPlayer];
		handC = game.handCount[currPlayer];
		discardC = game.discardCount[currPlayer];
		
		//Add card to player's discard pile. Player's discardCount should be incremented and supplyCount decremented.
		gainCard(tarCard, &game, 0, currPlayer);
		++discardC;
		if(deckC == game.deckCount[currPlayer] && handC == game.handCount[currPlayer] && discardC == game.discardCount[currPlayer])
			printf("Adding card to discard succeeded. Discard incremented. Hand and deck count unchanged.\n");
		else
			printf("Adding card to discard failed.\n");
			
		deckC = game.deckCount[currPlayer];
		handC = game.handCount[currPlayer];
		discardC = game.discardCount[currPlayer];
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testGainCard();
	return 0;
}