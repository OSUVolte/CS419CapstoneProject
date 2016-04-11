Assignment 2

smithy:

for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
discardCard(handPos, currentPlayer, state, 0);
return 0;

-If the smithy card is played, the player who played the card draws three cards and the
smithy card is discarded from the hand. This is implemented by executing the darwCard() method
three times and then executing the discardCard() method which takes as an input the current hand position
which results in the smithy card being discarded from the hand. Returns 0 on success.



adventurer:

while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--;
	  z++;
	}
      }
    while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
	z=z-1;
      }
      return 0;

-Cards are drawn from the deck until 2 treasure cards are revealed which are added to the player's hand. All other 
revealed cards are discarded from the player's hand. This is implemented via a while loop which checks if the player 
has drawn less than 2 treasure cards. If so, the loop executes. An If loop then checks whether the player's deck is empty
and then calls the shuffle() function which shuffles the discard pile and creates a new deck for the player. The player
then draws a card via the drawCard() function. If the card is 1 of 3 possible treasure cards, then the drawntreasure flag
is incremented. If the player does not draw a treasure card, the drawn card is added to a temporary hand and the while 
loop repeats. After 2 treasure cards are drawn, the temporary hand is discarded. Returns 0 on success.



discardCard()

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
  if (trashFlag < 1)
    {
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  state->hand[currentPlayer][handPos] = -1;
	
  if ( handPos == (state->handCount[currentPlayer] - 1) )
    {
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 )
    {
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}

-The discardCard() method removes cards from the player's hand and adds them to the played pile or the trashed 
pile depending on the state of the trashFlag. If the trashFlag is not set, the card is added to the played pile. 
The card is removed from the player's hand and the number of cards in hand is decremented. The last card in 
hand takes the position of the most recently discarded card. Returns 0 on success.



updateCoins()

int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
  state->coins = 0;
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

  state->coins += bonus;

  return 0;
}

-The updateCoins() method calculates the total value of the Treasure cards in the player's hand in addition 
to any bonus the player has earned. This is accomplished through a for loop which iterates through every card 
in the hand and checks if it matches a copper, silver, or gold and increments the value of state->coins by 
the appropriate amount.