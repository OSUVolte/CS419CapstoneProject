/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 8 April 2016
**
** Program Filename: refactor.c
** Description: This is the documentation file for changes made to the 
**				source code for the Dominion game for CS 352.
***************************************************************************/

/***************************************************************************
**                        Changes to dominion.c
***************************************************************************/
--- 8 April 2016 ---
 + refactor code so that the following cards are implemented as functions (from switch statements):
	- Smithy
	- Adventurer
	- Mine
	- Remodel
	- Village
 + Added artifical bug to Smithy card method: cardSmithy()
	- Modified for loop test case logic from '<' to '<='
 + Added artifical bug to Adventurer card method: cardAdventurer()
    - Modified cardDrawn line by removing '-1' from end. Original:
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
 + Added artifical bug to Mine card method: cardMine()
	- Modified gainCard toFlag parameter from 2 (hand) to 1 (deck)
 + Added artifical bug to Remodal card method: cardRemodal()
	- Modified gainCard supplyPosition parameter from 'choice2' to 'choice1'