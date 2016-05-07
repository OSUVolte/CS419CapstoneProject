/*
Miranda Weldon
April 24, 2016
CS 362 Spring 2016
Assignment 3
bug1.c

unittest1.c
	Testing isGameOver(): no bugs found

unittest2.c
	Testing updateCoins(): no bugs found

unittest3.c
	Testing fullDeckCount(): 1 bug found
	The function has three conditional statements, but only the second one actually executes. This means that the final deck count does not count cards in the player's deck, not discard pile. 

	  for (i = 0; i < state->deckCount[player]; i++)
	    {
	      if (state->deck[player][i] == card) count++;
	    }	
	//only this conditional statement that executes
	  for (i = 0; i < state->handCount[player]; i++)
	    {
	      if (state->hand[player][i] == card) count++;
	    }	
	  for (i = 0; i < state->discardCount[player]; i++)
	    {
	      if (state->discard[player][i] == card) count++;
	    }

unittest4.c
	Testing numHandCards(): 1 bug found
	Only the first player is shown to have any cards in their hand. This pattern continues for multiple means of finding base numbers for comparison (comparing against a static number and against the player's handCount) and was test at both the initialization of a game and after getting rid of a card from two of the three players' hands. The function has no means of running differently across different players, so the bug may originate within initializeGame(), which determines how many cards a player gets at the beginning of the game, or within whoseTurn().

cardtest1.c
	Testing Adventurer Card: no bugs found

cardtest2.c
	Testing Smithy Card: 1 bug found
	The smithy card never deletes a card.

cardtest3.c
	Testing Salvager Card: 
	As mentioned, the second player first never gets any cards in their hand(s). As this bug has also been found in numHandCards, it is likely not an issue with the salvager card directly, but with a function that it depends on, such as discardCard(), initializeGame(), or whoseTurn().

cardtest4.c
	Testing Feast Card: 1 bug found
	As mentioned before, any subsequent players after the first never get any cards in their hand(s). As this bug has also been found in numHandCards, which only make use of two function (one of which implicitly), the bug seems more likely to originate within initializeGame(), or whoseTurn().

	Testing Feast Card

	Player 0:
	        Expected HandCount: 5
	        Actual HandCount: 5
	...
	Player 1:
	        Expected HandCount: 0
	        Actual HandCount: 0
	        Test Pass
	...
	Player 2:
	        Expected HandCount: 0
	        Actual HandCount: 0
	        Test Pass
	...

*/
