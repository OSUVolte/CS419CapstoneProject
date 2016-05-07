/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * bug1.c
 * Description of bugs found
 * -----------------------------------------------------------------------
 */

/********************************************************************************************
numHandCards() was tested by unittest1 and found no bugs
getCost() was tested by unittest2 and found no bugs
isGameOver() was tested by unittest3 and found no bugs
***********************************************************************************************/

/**********************************************************************************************
scoreFor() was tested by unittest 4
Bug #1: The score for a player at the beginning of a test game should have been 3 but was 0.
Bug #2: The score for a player's deck in the middle of a game was off by 6.
These bugs are likely related to each other.
Both of these are likely attributed to the part of the function that calculates
the score of the deck.
Line #444 (for (i = 0; i < state->discardCount[player]; i++) should count the
number of cards in the deck, not the number of cards in the discard pile.
**************************************************************************************************/

/******************************************************************************************
smithy was tested by cardtest1
Bug #3:
The number of cards in hand after Smithy was played was off by 1. The game I was
testing expected 6 cards in the hand, but there were 7.
*********************************************************************************************/

/****************************************************************************************
adventurer was tested by cardtest2
Bug #4: The number of treasure cards in hand after Adventurer was played was incorrect.
The game I was testing expected 4 treasure cards at the end of the turn, but there were 5.   
*******************************************************************************************/

/*********************************************************************************************
village was tested by cardtest3
Bug #5: The number of actions after Village was played was incorrect. The game I was testing
expected there to be 5 actions, but there were only 4.
**********************************************************************************************/

/*************************************************************************************************
gardens was tested by cardtest4
Bug #6: The number of cards in hand after gardens was played was incorret. The game expected 3
cards but there were 4. 
Bug #7: The gardens card remained in the player's hand after the turn was over.
Both of these bugs are likely related to each other.
*************************************************************************************************/



