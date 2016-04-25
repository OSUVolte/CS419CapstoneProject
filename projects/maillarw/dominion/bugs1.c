William Maillard
CS 362
bugs1.c
Assignment 3
	
Unit Test 2

In the function isGameOver() there is bug in which the function returns 1 when 
3 supply stacks are empty and there are 5 players (it should return 0 based on 
the rules of Dominion).  This may be a limitation in the number of allowed 
players in this simulation.

Unit Test 3
	
The scoreFor() function returns a score of 10 when the player has one of every 
card in his/her hand.  This score should be 11.
The scoreFor() function returns a score of -7 when the player has one of every 
card in his/her discard pile.
The scoreFor() function returns 0 when the player’s deck has one of every card 
in it, should return 11.
	
Card Test 1

5.  When playSmithy() is called with normal initial settings, either three 
cards are not drawn or the Smithy card is not dicarded, or both.
6.  When playSmithy() is called with an empty deck and a full discard pile, 
either three cards are not drawn or the Smithy card is not dicarded, or both.

Card Test 2
	
7.   When the playAdventurer() function is called, no cards are added to the 
playedCards array
8.   When the playAdventurer() function is called, with a deck of 10 with the 
last 2 being silver cards either no cards are added to the playedCards array or 
the discard count is not 8 or both.

Card Test 4
	
9. When the playVillage() function is called either a card is not added to the 
player’s hand or a card is not removed from the player’s hand or both.
10.  When the playVillage() function is called, one card, specifically the 
Village card, is not sent to the playedCards array.