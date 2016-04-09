/************************************************************************************
** Name: Yi Wei Lo 
** Date: 4/10/16
** Filename: refactor.c
** Description: Documentation of bugs on five different cards. All of these will 
		 be separate functions and not part of the switch statement in
		 cardEffect() 
************************************************************************************/

/************************************************************************************
** Card: smithy
** Function: cardEffectSmithy()
************************************************************************************/
Description:
		- Draw four cards instead of three

Implementation:
		In the for loop (i = 0; i < 3; i++), change it to (i = 0; i < 4; i++)
		
/************************************************************************************
** Card: adventurer
** Function: cardEffectAdventurer
************************************************************************************/
Description:
		- Reveal three treasure cards instead of two

Implementation:
		In the while loop, change (drawnTreasure < 2) to (drawnTreasure <= 2)

/************************************************************************************
** Card: council room
** Function: cardEffectCouncilRoom
************************************************************************************/
Description:
		- Draw three cards instead of four
		- No additional buys added
		- Only the current player gets additional cards

Implementation:
		In the for loop, change (i = 0; i < 4; i++) to (i = 0; i < 3; i++) 
		and eliminate the line state->numBuys++; along with the for loop
		for letting each other player draw a card when this card is used.

/************************************************************************************
** Card: village
** Function: cardEffectVillage
************************************************************************************/
Description:
		- No action added

Implementation:
		Eliminate the line state->numActions = state->numActions + 2;

/************************************************************************************
** Card: feast
** Function: cardEffectFeast
************************************************************************************/
Description:
		- Gain a card up to 6 cost instead of 5

Implementation:
		In the updateCoins() function, change (currentPlayer, state, 5) to
		(currentPlayer, state, 6)
