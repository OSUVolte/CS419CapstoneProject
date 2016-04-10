Smithy - 
//subtracts an extra card
changed the loop to read (i=1; i<3; i++)


Adventurer- 
//gives an extra card
 changed the while looop to while(drawntreasure<=2)
//removed silver card option
 changed if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to 
			if (cardDrawn == copper || cardDrawn == gold)
  
Feast - 
//gives only 3 additional coins instead of 5
	changed  updateCoins(currentPlayer, state, 5);  
	 updateCoins(currentPlayer, state, 3);
//will need more coins then just the cost of the card chosen 
	 changed (state->coins < getCost(choice1)) 
		to (state->coins <= getCost(choice1))
		
	
Village - 
//changed number of actions from 2 to 1
	changed state->numActions = state->numActions + 2; to
		state->numActions = state->numActions + 1;
//card is now discarded into trash and not the played pile			
     changed discardCard(handPos, currentPlayer, state, 0); to 
		discardCard(handPos, currentPlayer, state, 2);
		
Cutpurse -
// instead of other players losing coin the current player does
	changed if (i != currentPlayer) to	
		if (i == currentPlayer)
//instead of losing copper cards will lose silver cards
	changed if (state->hand[i][j] == copper)
		to if (state->hand[i][j] == silver)
	
	  