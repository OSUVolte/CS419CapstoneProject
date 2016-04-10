/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 8 April 2016
**
** Program Filename: documentation.c
** Description: This is the documentation file for various cards in Dominion
**              and functions. Descriptions are taken from the official 
**              Dominion cards.
***************************************************************************/

/***************************************************************************
**                              Card: Adventurer
***************************************************************************/
Card Type: Action
Description: Reveal cards from your deck until you reveal 2 Treasure cards. Put those cards into your hand and discard the other revealed cards.
Cost: 6

The player that plays the Adventrer card will continuly draw cards (using the drawCard() function and shuffle(), if required) until the number of drawn treasure cards (copper, silver, or gold) reaches 2 (counter variable name: drawntreasure). During execution, a card is drawn into the player's hand. If a treasure card is drawn, the treasure counter is incremented. Otherwise, the card is moved from the players hand to a temporary hand where is discarded. Once complete, the Adventurer card is discarded.

/***************************************************************************
**                              Card: Smithy
***************************************************************************/
Card Type: Action
Description: +3 Cards
Cost: 4

The player that plays the Smithy card immediatly draws 3 additional cards (done by calling drawCard() 3 times), then discards the Smithhy card using the discardCard() function.

/***************************************************************************
**                              Function: discardCard
***************************************************************************/
Inputs: handPos [int] - location of card to be discarded
        currentPlayer [int] - player who is being referenced
		gameState [*state] - current state of game
		trashFlag [int] - boolean for sending card to trash (> 1) or played pile (< 1)
Returns: 0 (For all cases)

The discardCard() method is for removing a card from the specified player's hand based on the given card location. If the card is not marked for being trashed (trashFlag < 1), then the card is added to the player's played card pile. The card then removed from the player's hand and the hand is reorganized by moving the last card in the hand to where the discarded card use to be (if applicable) and the hand count is updated.

/***************************************************************************
**                              Function: updateCoins
***************************************************************************/
Inputs:	player [int] - player who is being referenced
		gameState [*state] - current state of game
		bonus [int] - coin bonus to add (from non-treasure cards)
Returns: 0 (For all cases)

The updateCoins() method recalculates the specified player's total coin count for their current hand. It adds 1 coin per copper card, 2 coins per silver card, and 3 coins per gold card. Then it adds the coin bonus (from the input).