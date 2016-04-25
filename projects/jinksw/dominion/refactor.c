playSmithy
	BUGS:
	for the draw loop: used <= for i, instead of <
	for the draw loop: used gainCard() instead of drawCard
	for discardCard(), set trash flag to 1 instead of 0

playAdventurer
	BUGS:
	cardDrawn = state->hand[currentPlayer][0] //should take the first/bottom card in hand instead of top
	removed else condition for non-treasure cards, statements that would have been evaluated for non-treasure cards are evaluated if the card is a treasure card

playVillage
	BUGS:
	discardCard() -> trash flag is set to 1 instead of 0

playCouncil_room
	BUGS:
	in the for loop for drawCard used <= instead of <
	in the for loop for each player drawing a card, used <= instead of <

playFeast
	BUGS:
	in testing supply count, used <0 instead of <= 0 //will allow cards drawn that aren't remaining?
	for Backup hand and reset hand, used <= instead of <, should loop one more time
