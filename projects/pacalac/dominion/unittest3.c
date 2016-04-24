#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
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
void testDiscardCard()
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
		int i=0;
		int plHand[MAX_HAND];
		game.deckCount[currPlayer] = 0;
		game.discardCount[currPlayer] = 0;
		game.playedCardCount = 0;
		
		//add cards to player's hand
		for(i; i < MAX_DECK; ++i)
		{
			plHand[i] = smithy;
		}
		memcpy(game.hand[currPlayer], plHand, sizeof(int) * MAX_HAND);
		
		game.handCount[currPlayer] = 10;
		int handC = game.handCount[currPlayer];
		int playedC = game.playedCardCount;
		
		//Discard card with trash flag set to 0. Hand count decremented, played card count incremented
		discardCard(0, currPlayer, &game, 0);
		--handC;
		++playedC;
		
		if(handC == game.handCount[currPlayer] && playedC == game.playedCardCount)
			printf("Discarding card succeeded. Hand count and played count correct.\n\n");
		else
			printf("Discarding card failed. Hand count and played count mismatch.\n\n");
		
		//Discard card with trash flag set to 1. Hand count decremented
		handC = game.handCount[currPlayer];
		playedC = game.playedCardCount;
		
		discardCard(0, currPlayer, &game, 1);
		--handC;
		
		if(handC == game.handCount[currPlayer] && playedC == game.playedCardCount)
			printf("Discarding card succeeded. Hand count and played count correct.\n\n");
		else
			printf("Discarding card failed. Hand count and played count mismatch.\n\n");
		
		//Discard card in middle of player's hand. Hand count decremented
		handC = game.handCount[currPlayer];
		playedC = game.playedCardCount;
		
		discardCard(handC / 2, currPlayer, &game, 1);
		--handC;
		
		if(handC == game.handCount[currPlayer] && playedC == game.playedCardCount)
			printf("Discarding card succeeded. Hand count and played count correct.\n\n");
		else
			printf("Discarding card failed. Hand count and played count mismatch.\n\n");
		
		//Discard card in first position of player's hand. Hand count decremented
		handC = game.handCount[currPlayer];
		playedC = game.playedCardCount;
		
		discardCard(0, currPlayer, &game, 1);
		--handC;
		
		if(handC == game.handCount[currPlayer] && playedC == game.playedCardCount)
			printf("Discarding card succeeded. Hand count and played count correct.\n\n");
		else
			printf("Discarding card failed. Hand count and played count mismatch.\n\n");
		
		//Discard last card in player's hand. Hand count decremented
		handC = game.handCount[currPlayer];
		playedC = game.playedCardCount;
		
		discardCard(handC - 1, currPlayer, &game, 1);
		--handC;
		
		if(handC == game.handCount[currPlayer] && playedC == game.playedCardCount)
			printf("Discarding card succeeded. Hand count and played count correct.\n");
		else
			printf("Discarding card failed. Hand count and played count mismatch.\n");
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testDiscardCard();
	return 0;
}