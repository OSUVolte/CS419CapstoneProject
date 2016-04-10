/****************************************************************************
* FILENAME: documentation.c
* AUTHOR: Nickolas A. Williams
* DATE: 04/10/2016
* DESCRIPTION: Documents code for smithy and adventurer cards, plus
*	discardCard() and updateCoins() methods
* INPUT: n/a
* OUTPUT: n/a
*****************************************************************************/




// Smithy:
// When a player plays the Smithy card, they can draw an additional 3 cards. It does not affect how many actions or coins the player has.



// Adventurer:
// When a player plays the Adventurer cards, they can draw cards from their deck until they reveal 2 treasure cards. They place the 2 treasure
// cards in their hand and any other cards that were drawn back in their deck.


// discardCard():
// The discardCard function is passed the current player (int), hand position (int), the game state (struct gameState), and a trash flag (int).
// 
// The first thing the function does is check if the trash flag is set. If it is not set, then the card is added to the play pile. This is done by
// setting the playedCards variable in the game state struct equal the current player's hand position, and then incrementing the played card count.
// Next, the card that was played is set to -1.
// The played card is then removed from the player's hand. If the played card was the only card in the player's hand, then the handCount (number of
// cards of current player) is decreased by one. If the played card was the last card in the player's hand (e.g. the 5th card in a hand of 5) then the 
// hand count of the current player's hand is also decreased by one. Otherwise, the played card is replaced with the last card in the player's hand,
// the last card is set to equal -1, and the number of cards is decreased by one (the last card is removed).


// updateCoins():
// The updateCoins functions is passed the player (int), game state (struct gameState), and bonus (int)
//
// First, the function resets the coin count to zero by accessing the coins variable in the game state struct
// Next, for each card in the player's hand, the function checks if it is a copper, silver, or gold card. If it is a copper card, the coins variable
// in the game state struct is increased by 1, if it is a silver it is increased by 2, and if it is a gold then it is increased by 3.
// Finally, the bonus is added to the coins varaible. 



