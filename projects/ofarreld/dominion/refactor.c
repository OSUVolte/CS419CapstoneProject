/*

Name:				Daniel OFarrell
Course:				cs362-400
Date Created:			7 April 2016
Last Modification Date:		7 April 2016

Changes made are as follows:
	1. Smithy:
	line 1352, changed     
		for (i = 0; i < 3; i++)
	to read     
		for (i = 0; i < 4; i++)

	2. Adventurer:
	line 1397, changed  
		if (state->deckCount[currentPlayer] <1){
	to read  
		if (state->deckCount[currentPlayer] <=1){
	line 1402, changes 
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	to read 
		if (cardDrawn == silver || cardDrawn == gold)
	
	3. Village:
	line 1368, changed
		state->numActions = state->numActions + 2;
	to read 
		state->numActions = state->numActions - 2;

	4. Steward:
	line 1381, changed   
		else if (choice1 == 2) {
	to read   
		else if (choice1 != 2) {

	5. Sea_hag:
	line 1423 removed     
		if (i != currentPlayer){

Update 21 April 2016:
	Adventurer card was changed. The line 1402 but was removed. This proved to be
	a fatal error while conducting unit tests. The other errors remain, however.

*/
