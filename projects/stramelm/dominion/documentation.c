Cash Stramel
CS362
Spring 2016
Assignment #2

smithy:

In the function cardEffect() is a switch( card ) statement.  For case smithy,
the function drawCard() is called three times in a row.  Each time it is passed
arguments currentPlayer and state.  The the function discardCard() is called
just once.  It is passed arguments handPos, currentPlayer, state, and 0 (as
trashflag - indicate card is not to be trashed but rather should be added to
the played pile).

adventurer:

In the function cardEffect() is a switch( card ) statement.  For case
adventurer, the function drawCard() is called repeatedly until two treasure
cards have been drawn.  Before each call to drawCard() a check is performed
to ensure that there is actually a card in the deck to draw.  If not, the
function shuffle() is called which adds shuffled discard pile cards to the
deck.  After each call to drawCard() a check on the card is performed to
determine if it is or isn't a treasure card.  If so, a counter is incremented
for use in determining if the function is done drawing cards.  If not, then
the cards that was just drawn is put into a temphand[] and a separate counter
is incremented.  After all cards have been drawn, any cards that are in
temphand[] are returned to the discard pile.    

discardCard():

This function accepts four arguments.  handPos, currentPlayer, and trashFlag
are all integer arguments and state is a struct of type gameState.  handPos
is the index of the card in the player's hand that is being discarded.
currentPlayer indicates which player's hand we are referring to.  trashFlag
is used to determine if the card is trashed versus being put into the discard
pile.  Within discardCard(), trashFlag is first checked.  If it's <1 then the
card is put into the discard pile.  Next the card value is set to -1 in any
case.  Next the card is removed from the players hand.  If it's the last card
in the player's hand array or there is only one card in the player's hand,
the count of cards is decremented by one and that's it.  Otherwise, the card
that is being discarded is replaced by the last card in the player's hand
which essentially fills in the gap being left by the discard.

updateCoins():

This function accepts three arguments.  player and bonus are integer arguments
and state is a struct of type gameState.  The function starts be resetting the
count of coints in the state struct.  Next it interrogates the cards in the
player's hand for treasure cards.  For any treasure card found the value is
added to the count of coins.  Finally, the bonus is added.
