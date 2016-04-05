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

