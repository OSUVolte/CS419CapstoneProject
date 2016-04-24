/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  bug1.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description:  This is a text file that is will be used to 
** document the bugs that have been found from my unit tests
** [1 to 4] and card tests [1 to 4].  
*************************************************************/

/*
Unit Test 1 Bugs
Test: initializeGame()
After running this unit test, each subtest passed without revealing any bugs
*/

/*
Unit Test 2 Bugs
Test: getCost()
After running this unit test, each test reveal zero bugs.
*/

/*
Unit Test 3 Bugs
Test: updateCoins()
This unit test did not reveal any bugs.
*/

/*
Unit Test 4 Bugs
Test: isGameOver()
This unit test did not reveal any bugs.
*/

/*
Card Test 1 Bugs
Test: Smithy Card Effect
This unit test revealed an error involved with the addition/subtraction of
cards from the current players hand.  The unit test did not reveal bugs
involving the cards return value or the location in which cards were drawn 
and discarded to.
*/

/*
Card Test 2 Bugs
Test: Adventurer Card Effect
This unit test had two failures...One in checking the total # of cards in 
the current players hand and another checkin the total # of treasure cards
in the current players hand after using the adventure card.  Each of the
tests revealed values off by one.  This suggests that there is an off by
one error in the the amount of treasure cards that are drawn. Which happens
to be the case, since that is the error in which I introduced in refactor.c
*/

/*
Card Test 3 Bugs
Test: Great_Hall Card Effect
There were no bugs revealed in the, number or actions++, the current players handCount,
or other players deckCount. The cardEffect for Great_Hall returned 0 successfully.  
However, the card test revealed a failure involving the deckCount of the current player
after the the action had been made.  There seemed to be an off by one error
involving the discard, since the player had 1 less card in their deck than they
should have. NOTE: This was what was to be seen, see refactor.c.
*/

/*
Card Test 4 Bugs
Test: Embargo Card Effect
The card test revealed two errors.  1. The number state.coins off by 1, suggesting a bug,
in how the state.coins was incremented.  And 2. The number of cards in the current 
player's deck was off by 1 too many.  This suggests an error in the process of trashing the 
embargo card.  NOTE: THis was expected.  The other tests involving the state of other players
decks as well as the return of an error if the player chooses to place an embargo token on 
a card that is not in the game's supply, revealed no bugs.
*/