/*************************************************************************
 * Andriy Solovyov
 * CS 362
 * Assignment 2
 * 4/9/16
 * Description: Submit a file called documentation.c (.c file because github thinks you are using github for file storage if you use many .txt files) that contains documentation of smithy, 
   adventurer cards. Documentation should contain your understanding of smithy and adventurer cards (code). It should also contain documentation of your understanding of discardCard() and updateCoins() method.  Keep your documentation short, though there is no upper limit. Documentation.c file should contain at least 100 words.  
 ************************************************************************/

/****** 
 *Smithy Card:
        This is an action card, so when a player draws this card from a deck, it allows to draw an additional 3 cards for a player. A player can purchase this card during his turn for 4 coins.
*******/


/******
*Adventurer Card:
		This is an action card, so when a player draws this card from a deck, it can reveal cards from player's deck until they reveal 2 Treasure cards. Player can put those Treasure cards into their hand and discard the other revealed cards.
*******/

/******
*discardCard():
For every time this function is called it passes(pointer of the game state, the hand position, current player, trashFlag to trash payed card)
	* it passes the position of the card in the current player's hand to return
	* if the trash flag isn't called then a played card goes to the player's played card pile array
	* then played pile card count increments with the last card 
	* then player's hand count reduces the players hand count with the last card
	
/*******
* updateCoins():
For each time this function is called it passes(coin variables in the game state, bonus variables)
	* it resets the coin count to zero for a current player 
	* cards in the current players hand are checked for certain coin variables 
	* check for certain treasure card variables and adds 
	* bonus variables are added to the game state after it resets
*******/

