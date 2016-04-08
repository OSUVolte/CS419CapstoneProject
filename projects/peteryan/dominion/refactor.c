04/06/16
playAdventurer, playSmithy, playMine, playMinion, playAmbassador functions created to 
implement the adventurer, smithy, mine, minion, and ambassador cards.  Thier implementations
in cardEffect function is replaced with a call to the respective function.  Bugs were
introduced into the functions.

BUGS
playAdventurer
	changed if (state->deckCount[currentPlayer] <1) to if (state->deckCount[currentPlayer] <=1)
	changed while(drawntreasure<2) to while(drawntreasure<=2)
	changed cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1] 
		to cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]+1]
	
	
playSmithy
	changed for (i = 0; i < 3; i++) to for (i = 0; i <= 3; i++)
	changed discardCard(handPos, currentPlayer, state, 1) to discardCard(handPos, currentPlayer, state, 0)
	changed return 0 to return 1;
	
playMine
	changed return -1; to return 1;
	changed if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) ) 
		to if ( (getCost(state->hand[currentPlayer][choice1]) + 3) < getCost(choice2) )
	changed gainCard(choice2, state, 2, currentPlayer); to gainCard(choice2, state, 3, currentPlayer);
	changed if (state->hand[currentPlayer][i] == j) to if (state->hand[currentPlayer][i] = j)
	
playMinion
	changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1);
	changed state->coins = state->coins + 2; to state->coins == state->coins + 2;
	changed for (i = 0; i < state->numPlayers; i++) to for (i = 0; i <= state->numPlayers; i++)
	changed if ( state->handCount[i] > 4 ) to if ( state->handCount[i] < 4 )
	changed return 0; to return -1;
	
playAmbassador
	changed if (choice2 > 2 || choice2 < 0) to if (choice2 < 2 || choice2 > 0)
	changed if (choice1 == handPos) to if (choice1 = handPos)
	changed if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
		to if (i != handPos && i = state->hand[currentPlayer][choice2] && i != choice1)
	changed return -1; to return 0;
	changed if (i != currentPlayer) to if (j != currentPlayer)
	changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1); (not in loop)
	remove break from trash loop
	