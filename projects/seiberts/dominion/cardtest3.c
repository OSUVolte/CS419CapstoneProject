//Shawn Seibert
//Card Test 3
//councilRoomCard()


int councilRoomCard(int handPos, int currentPlayer, struct gameState *state)
{
	int i = 0;
	     //+4 Cards
      for (i = 0; i <= 4; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
      state->numActions++;
			
      //Each other player draws a card
      for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}
			
      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);
	  return 0;
}