Smithy
The smithy card just allows the user to draw three more cards from the game, using a simple for loop to call upon the drawCard() function three times. Finally, after the smity card is finished drawing those three cards, the smithy card is discarded from the player’s hand. 

    case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
		

Adventurer
The adventurer card overall simply reveals each card in the deck until it finds two treasure cards, adds them to the player’s hand, and then discards the rest of the revealed cards. 

Here, while 2 treasure cards have not yet been drawn, a card is drawn (or if it’s empty, the discard pile reshuffled and added to the deck first) and added to the player’s hand, increasing the player’s hand count. If it’s a treasure card, the player keeps the card and goes through the loop again. If it’s not a treasure card, it’ll get stored into a tempHand, removed from the player’s hand, and lower the handCount before going through the loop again. Finally, after enough treasure has been drawn from the pile, this function will discard everything in the temporary hand to the discard pile.  


    case adventurer:
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
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



discardCard()
Overall, this discardCard() function is used when the player has played a card, which then automatically goes to the discard pile. Here, the function first checks to make sure that the card isn’t going to the trash. If it isn’t, the card is added to the played card pile. The played card is then given a value of -1 (inactive). If the played card was the last card in the player’s hand or the only card in the array, then the handCount is simply reduced (preventing the player from seeing in his or her hand). Otherwise, the played card is replaced with the last card in the player’s hand and the last card is given a value of -1 (inactive) before the number of cards in the hand is reduced. 

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





updateCoins()
The updateCoins function is used to calculate the number of coins in each player’s hand. First, the counter is set to zero, and then a for loop goes through each of the cards in a player’s hand, adding up the value of each treasure (1 for copper, 2 for silver, and 3 for gold). Finally, any bonus from the card itself is added and stored into state->coins. 


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
