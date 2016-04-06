/*************************************************************
Name: Shawn Seibert
Date: 4/05/2016
Purpose: Documentation for smithy and adventurer card
************************************************************/

//SMITHY
case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

/***************************************************************************
Description of smithy
If the smithy card is selected, a for loop begins and loops for three iterations.
After each iteration, the draw card function is called which adds a new card to the player’s 
hand. After the loop has completed, the smithy card is discarded from the players hand.
************************************************************/

//------------------------------------------------------------------------------------//

//ADVENTURER
case adventurer:
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){
	//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; 
	  //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
	// discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;

/******************************************************************************
Description of adventurer
If the adventurer card is selected, a while loop is run until the player draws a 
treasure card. Within this loop, if it is determined that the remaining deck is found to 
have no remaining cards, then the discarded pile of cards is reshuffled, placed back
in the deck, and then used to draw from. If a copper, silver, or gold treasure card is 
found, then the loop ends. If a treasure card is drawn initially, then that card is placed
into the players hand and the while loop is not activated.
*******************************************************************************/

//------------------------------------------------------------------------------------//

//updateCoins
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

/***************************************************************************
Description of updateCoins
This function sets the initial coins in the players hand to zero. This is then
followed by a loop based on the number of treasure cards in the players hand.
The loop iterates through the treasure cards and adds each copper, silver and
gold coins. The function ends by returning the total number of coins back to
the player.
***************************************************************************/

//------------------------------------------------------------------------------------//

//discardCard

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

/***************************************************************************
Description of discardCard
When this function is called, it first checks to see if the card is added to the
trash pile. If it is not trashed, then the card is added to the played pile.
After checking the trashing of the desired card, the number of cards in the players 
hand is reduced by one. From there, the desired card is removed from the players
hand, and the number of cards in the players hand is updated to by -1.
***************************************************************************/
