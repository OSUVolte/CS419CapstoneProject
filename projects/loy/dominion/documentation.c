/************************************************************************************
** Name: Yi Wei Lo 
** Date: 4/10/16
** Filename: documentation.c
************************************************************************************/

/************************************************************************************
** Card: smithy
************************************************************************************/
Cost: 4
Type: Action
Description:
		Draws three cards using the drawCard() function. The smithy card is
		then put in the discard pile using the discardCard() function.

/************************************************************************************
** Card: adventurer
************************************************************************************/
Cost: 6
Type: Action
Description:
		Reveals cards from your deck until two treasure cards have been
		revealed. You will then put those two treasure cards into you deck 
		and discard the other revealed ones. 

/************************************************************************************
** Function: discardCard()
************************************************************************************/
Parameter(s): 
		int handPos - location of the card that is to be discarded
		int currentPlayer - who the current player is
		struct gameState *state - current state of the game
		int trashFlag - boolean for trash card [trash card > 1 or played 
				 pile < 1]

Description: 
		This method is for discarding a card from the player’s hand to 
		either the trash pile or the played pile. If a card is discarded, 
		then the number of cards in the player’s hand will decrease by 1. 

/************************************************************************************
** Function: updateCoins()
************************************************************************************/
Parameter(s):		
		int player - who the current player is
		struct gameState *state - current state of game
		int bonus - adding coin bonus

Description: 
		This method is for checking if the player has any treasure cards in 
		his/her hand. If there is, the total coin is counted and added up. 
