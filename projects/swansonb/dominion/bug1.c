/*

Brandon Swanson
Bugs found in dominion.c during Assignment 3

--------------------------------------------------------------------------------
shuffle()
--------------------------------------------------------------------------------
No bugs found


--------------------------------------------------------------------------------
drawCard()
--------------------------------------------------------------------------------
No bugs found


--------------------------------------------------------------------------------
endTurn() function
--------------------------------------------------------------------------------

This function fails to move cards from the played cards array into the discard
pile of the current player's hand.  Once I discovered this bug was present I had
to devise a way of checking independently if it was moving the cards from hand
to discard, and from played to discard, or performing both.  Because the player
might have played a card that they have more than one of in their hand (or more
formally the playedCards array is a subset of the state->hand[currentPlayer]
array), testing for if the cards from the playedCards pile has ended up in the
discard might yield false positives.  But consistently failing tests that check
that all the cards from the playedCards array and the player’s hand have moved
to discard doesn’t give useful information about where the problem is occurring.

Therefore I wrote 3 separate tests, one to test if the cards from the
playedCards are now added to the discard pile, one to test if the players hand
has been added to the discard pile, and another to check if both the playedCards
 and the player’s hand have been added to the discard pile.

This function also fails to account for action cards that cause a player to draw
when it is not their turn.  It sets the current player's handCount to 0 before
drawing 5 new cards to begin their turn,  This means that when testing a card
like Village (where all players draw 1 card), these already drawn cards from the
player's deck are overridden with new values from drawCard and are removed from
the game inextricably.


--------------------------------------------------------------------------------
gainCard()
--------------------------------------------------------------------------------
No bugs found



--------------------------------------------------------------------------------
playSmithey()
--------------------------------------------------------------------------------
Only The bug that was introduced in assignment 2


--------------------------------------------------------------------------------
playAdventurer()
--------------------------------------------------------------------------------
Only The bug that was introduced in assignment 2,  I had to avoid testing for
that bug because it involves an infinite loop and would therefore block the rest
 of the test files from completing


--------------------------------------------------------------------------------
playVillage()
--------------------------------------------------------------------------------
Only The bug that was introduced in assignment 2


--------------------------------------------------------------------------------
playCouncilRoom()
--------------------------------------------------------------------------------
No bugs found





 */
