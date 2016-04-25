/*************************************************
*Robert Tang	
*CS 362
*Assignment 2
*Part 3
*October 11, 2015
***************************************************/

int adventurerEffect(struct gameState *state, int currentPlayer)
{
	int drawntreasure = 0;
	int z = 0;
	int temphand[MAX_HAND];
	int cardDrawn;
	
	while(drawntreasure<3)																// injected bug - draws 3 cards instead of 2
	{
		if (state->deckCount[currentPlayer] <1)
		{//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.

		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else
		{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	
	while(z-1>=0)
	{
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	}
	return 0;
}

/////////////1111111111111111111111111111111111111111111111111111111111111111111111111111111111111/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int smithy (struct gameState *state, int handPos, int currentPlayer)
{      //+3 Cards
	for (i = 0; i < 3; i++)																
	{
		drawCard(currentPlayer, state);
	}
		//discard card from hand
	//discardCard(handPos, currentPlayer, state, 0);									// created bug, no discard
	return 0;
}	

//////////////222222222222222222222222222222222222222222222222222222222222222222222222222222222222/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int village (struct gameState *state, int handPos, int currentPlayer)
{
	int currentPlayer = whoseTurn(state);
	//+1 Card
	drawCard(currentPlayer, state);
		
	//+2 Actions
	state->numActions = state->numActions + 3;											// created bug, +3 actions instead of 2
			
	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
     return 0;
}

///////////////////3333333333333333333333333333333333333333333333333333333333333333333333333333////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int greatHall(struct gameState *state, int handPos, int currentPlayer)
{
	      //+1 Card
      drawCard(currentPlayer - currentPlayer, state);									// player '0' draws the card instead of currentPlayer
			
      //+1 Actions
      state->numActions++;
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
}

//////////////////44444444444444444444444444444444444444444444444444444444444444444444444444444////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int steward(struct gameState *state, int handPos, int currentPlayer)
{
      if (choice1 == 1)
	{
	  //+2 cards
	  drawCard(currentPlayer, state);
	  drawCard(currentPlayer, state);
	}
      else if (choice1 == 2)
	{
	  //+2 coins
	  state->coins = state->coins + 2 + 1;												// player gets +1 coins
	}
      else
	{
	  //trash 2 cards in hand
	  discardCard(choice2, currentPlayer, state, 1);
	  discardCard(choice3, currentPlayer, state, 1);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
	  

      return 0;
}
//////////////////55555555555555555555555555555555555555555555555555555555555555555555555555555////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////