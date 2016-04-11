Cards Changed and Bugs Introduced:


Smithy:
    
    Modified drawCard Calling loop to run four times:
    - for (i = 0; i < 3; i++)
    + for (i = 0; i <= 3; i++)
	{
	  drawCard(currentPlayer, state);
	}

    This allows for user to draw four cards every time smithy is played
    
Adventurer:

    Modified the drawnTreasure to equal 2 as soon as a coin is drawn:
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	-  drawntreasure++;
	+  drawntreasure+=2;
	else{
        
        
Gardens:
    
    No Changes
    
Steward:

    Modified if choice 1 == 2 to assign coin value to 2
  else if (choice1 == 2)
	{
	  //+2 coins
	  - state->coins = state->coins + 2;
	  + state->coins = 2;
	}
    
Village:

    Two modifications:
        1. Double Draw Card
      drawCard(currentPlayer, state);
      drawCard(currentPlayer, state);
			
        2. Only one action increase
      state->numActions = state->numActions + 1;
      
      