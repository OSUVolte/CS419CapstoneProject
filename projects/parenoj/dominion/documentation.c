/************************************************************************
 *
 * 		Smithy
 *
 * 	When the Smithy card is played, the player draws 3 more cards, which 
 * 	is achieved by using a for loop to run the drawCard() function 3 times. 
 * 	The Smithy card is then removed from the current player's hand.
 *
 * ************************************************************************/

/**********************************************************************************
 *
 * 		Adventurer
 *
 * 	When the Adventurer card is played, the player reveals cards from their
 * 	deck until 2 treasure cards are revealed. Those treasure cards go into
 * 	the player's hand, and the others are discarded.
 *
 * 	This is achieved in the code by looping through a while loop until 2
 * 	treasures have been drawn. First the current player's deck is checked 
 * 	to make sure it is not empty. If it is, the discard pile is shuffled 
 * 	and added to the deck. Then, cards are drawn using the drawCard() function.
 * 	If the card is a treasure card, the drawnTreasure variable is incremented.
 * 	Otherwise, the card drawn is added to the tempHand, and removed from the
 * 	deck. This continues until 2 treasure cards are drawn. At this point, all
 * 	of the cards from tempHand are discarded.
 *
 *********************************************************************************/

/*********************************************************************************
 *
 * 		discardCard()
 *
 * 	The discardCard() function takes 4 parameters; int handPos, int currentPlayer,
 *	a gameState struct, and an int trashFlag. The first thing that is checked is
 *	the trashFlag. If it is less than 1, the card is added to the played cards pile. 
 *	The played card is then set to -1. Then we remove the card from the player's hand.
 *	This is handled by an if/else if/else statement. 
 *
 *************************************************************************************/

/**************************************************************************************
 *
 * 		updateCoins()
 *
 * 	The updateCoins() function takes 3 parameters; int currentPlayer, a gameState
 * 	struct, and an int bonus. The number of coins is set at 0 when the function is
 * 	first called. Then for every treasure card in the player's hand, coins is
 * 	incremented by the appropriate amount. After that, any bonuses from other cards
 * 	are applied to the number of coins. 
 *
 **************************************************************************************
