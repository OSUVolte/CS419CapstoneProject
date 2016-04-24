04/06/16
playAdventurer, playSmithy, playMine, playMinion, playAmbassador functions created to 
implement the adventurer, smithy, mine, minion, and ambassador cards.  Thier implementations
in cardEffect function is replaced with a call to the respective function.  Bugs were
introduced into the functions.

BUGS
playAdventurer
	/*Changes the condition to include on card in the deck.  This is a small bug that will not effect overall game play*/
	changed if (state->deckCount[currentPlayer] <1) to if (state->deckCount[currentPlayer] <=1)
	/*Changed to run loop until three instead of two treasure cards are drawn*/
	changed while(drawntreasure<2) to while(drawntreasure<=2)
	/*This changes cardDrawn to a memory location outside of the player's hand*/
	changed cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1] 
		to cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]+1]
	
	
playSmithy
	/*This changes the loop for drawing cards to draw 4 cards instead of three*/
	changed for (i = 0; i < 3; i++) to for (i = 0; i <= 3; i++)
	/*discarded cards will added to the pile played instead of being trashed*/
	changed discardCard(handPos, currentPlayer, state, 1) to discardCard(handPos, currentPlayer, state, 0)
	/*Changed return code to indicate an error*/
	changed return 0 to return 1;
	
playMine
	/*return -1 is used to indicate an error, this change would cause a problem if a 
	check to see if playMine execute without a problem was made*/
	changed return -1; to return 1;
	/*This changes the condition for returning an error*/
	changed if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) ) 
		to if ( (getCost(state->hand[currentPlayer][choice1]) + 3) < getCost(choice2) )
	/*This will cause the card to be discarded instead of added to the player's hand*/
	changed gainCard(choice2, state, 2, currentPlayer); to gainCard(choice2, state, 3, currentPlayer);
	/*The if statement will always evaluate as true*/
	changed if (state->hand[currentPlayer][i] == j) to if (state->hand[currentPlayer][i] = j)
	
playMinion
	/*Card is added to Played pile instead of trashed*/
	changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1);
	/*This bug will do nothing, instead of adding to coins for the player*/
	changed state->coins = state->coins + 2; to state->coins == state->coins + 2;
	/*The loop will exectute one time than it is supposed to, arrays will go out-of-bounds if maximum 
	number of players are playing*/
	changed for (i = 0; i < state->numPlayers; i++) to for (i = 0; i <= state->numPlayers; i++)
	/*Reversed the condition for if statement, now players with less than four cards in their hand
	get to draw cards*/
	changed if ( state->handCount[i] > 4 ) to if ( state->handCount[i] < 4 )
	/*return indicates an error*/
	changed return 0; to return -1;
	
playAmbassador
	/*The if statement will ways be true, causing the function to return an error*/
	changed if (choice2 > 2 || choice2 < 0) to if (choice2 < 2 || choice2 > 0)
	/*The if statement will ways be true, causing the function to return an error*/
	changed if (choice1 == handPos) to if (choice1 = handPos)
	/*Return code for no errors in execution instead of indicating an error, this
	happens before the main portion of the function executes*/
	changed return -1; to return 0;
	/*If statement is used in loop for players gaining a card, using j will changed who gets a card*/ 
	changed if (i != currentPlayer) to if (j != currentPlayer)
	/*This causes the card to trashed instead of added to the played pile*/
	changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1); (not in loop)
	/*The loop for thrashing cards is supposed to stop after on copy of the card is trashed, now
	all copies in the player's hand will be trashed*/
	remove break from trash loop
	