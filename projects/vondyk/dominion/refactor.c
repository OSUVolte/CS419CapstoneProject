****************
** File name: refactor.c
** Description: This file contains documentation for 
**		the five cards I implemented into their own 
**		functions as opposed to leaving them in their 
**		original places in the switch statement in the
**		cardEffect() function in the file dominion.c.
****************

Changes to Smithy:
	In the for loop, I altered the "i<3" to "i<=3" which 
	changes the number of times the loop runs (line 680). I also 
	altered the trashFlag--from 0 to 1--that is passed to the discardCard() 
	function. This prevents the card from being added to the 
	played pile. (line 686)

Changes to Adventurer:
	I removed the call to the drawCard() function. This altered 
	the cardDrawn and made the loop cycle through the current 
	hand looking for two treasures already in the hand instead of 
	adding them from the deck. (line 657)

Changes to Village:
	Altered the handPos variable that is passed to the discardCard() 
	function. This will cause the wrong card to be discarded. (line 700)

Changes to Feast:
	In the first for loop I altered the second variable from "i<=" 
	to "i<" (line 710). The toFlag variable in the call to the gainCard() 
	function was altered so that the card that is passed to that function 
	goes to the hand instead of the discard pile.

Changes to Council Room:
	No changes.
