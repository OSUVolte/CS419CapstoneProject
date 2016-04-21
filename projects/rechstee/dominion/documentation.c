//Adventurer Scenario
//The Adventurer card allows the player to draw cards from his or her deck until they have obtained two treasure cards. They may then 
//keep those two treasure cards and discard the rest.
/*
    int playAdventurer(struct gameState *state, int currentPlayer, int drawntreasure, int cardDrawn, int *temphand, int z) {
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
      while(z-2>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;	
}

	  */
	  
//The Smithy
//Straight forward card that allows you to draw three cards from the deck and add them to your hand.
/*
int playSmithy(struct gameState *state, int currentPlayer, int handPos, int i)
{
	for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 1);
      return 0;
}
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