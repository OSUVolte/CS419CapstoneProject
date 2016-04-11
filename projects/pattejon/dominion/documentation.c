/*************************************************************************
 * Jon Patterson
 * CS 362
 * Assignment 2
 * Documentation of Smithy and Adventurer cards as well as an explanation
 of the discardCard() and updateCoins() method.
 ************************************************************************/

Smithy:
The Smithy card calls the drawCard() function three times and then discards the Smithy card.
No action is decremented within this function, it is instead handled a few levels up at the end
of the playCard() function call.

Adventurer:
This card draws cards off the top of the deck into the top of the hand, and if it is a drawn
treasure card, it adds it to the players hand, otherwise it decrements the players hand count,
while keeping the card in the hand, and increments a counter, z. This process continues until
two treasure cards are added. If the deck becomes empty, the discard pile is shuffled into the
deck and the process continues. 

An obvious flaw here is this loop would never exit in the event that less than 2 treasure cards
remain in the player's deck, but moving on - once the two treasure cards are drawn, a second while
loop increments the discard state for the current player for the z number of cards that were drawn
that were not treasures.

discardCard():
This function is called following the end of the cardEffect() function completion. The logic is,
once the card's action is completed, it should be mvoed to the discard pile. The function checks
to see if a trashFlag is set, if it is not, it is added to the Played pile. The played card is 
set to -1, and then removed from the player's hand. Additional logic handles setting state
variables to indicate the number of cards in hand.

updateCoins():
The updateCoins() function loops through the cards in the player's hand and counts the number
of treasure cards, incrementing the state value of coins to add up the total number of coins.
The function can be called with a bonus argument that will add an additional amount of coins to
the player's coins state.
