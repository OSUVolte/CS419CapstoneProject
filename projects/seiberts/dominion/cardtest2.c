//Shawn Seibert
//Card Test 2
//smithyCard()

int smithyCard(int handPos, int currentPlayer, struct gameState *state)
{
	int i = 0;
      //+3 Cards
      for (i = 0; i <= 3; i++) //Use i <= 3
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
		
}