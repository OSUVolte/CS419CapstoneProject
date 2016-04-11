//Adventurer Scenario
//The Adventurer card allows the player to draw cards from his or her deck until they have obtained two treasure cards. They may then 
//keep those two treasure cards and discard the rest.
/*case adventurer:
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){
	  shuffle(currentPlayer, state);
	}
	//We check to see if the deck is empty. In the case that it is we will shuffle, draw the card and then discard it.
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	//First, you draw a card from the top of the deck
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--;
	  z++;
	}
	//Remove cards until two treasure cards have been revealed
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
	z=z-1;
      }
	 //Gets the cards that the player has drawn and then discards them.
      return 0;
	  */
	  
//The Smithy
//Straight forward card that allows you to draw three cards from the deck and add them to your hand.
/*
	for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
*/

/*
	DiscardCard function
	
	This function takes card(s) flagged as trash cards and then removes them from the player's hand. Also accounts for situations where cards get replaced.
	Also worth noting, there is a if statement dedicated to the scenario in which the player only has one card in their hand. In this case the removed card
	is also replaced.
*/

/*
updateCoins function

//This function resets the coins to be added to the player's total and then tallies up the next set of treasures to be added from the player's hand.

*/