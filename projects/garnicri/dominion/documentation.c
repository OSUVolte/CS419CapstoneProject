/* Rick Garnica

Smithy card:
	Uses a 'for loop' to select three cards and then discards the Smithy card from the pile

Adventurer card:
	Cycles through the cards in your pile until it finds two treasure cards
	When it finds either of the treasure cards, the drawnTreasure count is increased; this controls the while loop
	If a treasure card is not found, the top card--most recently drawn--is discarded
	After two treasure cards are discovered, another while loop cycles through to discard all the other cards that
	were not treasure cards but drawn as a result of searching for the treasure cards

discardCard() function:
	if the trash flag has not been triggered it adds the card to the played list
	the number of player cards is reduced by one
	it checks to make sure if the player has only one card left or if it is the last card in the array

updateCoins() function: 
	loops through all the Treasure cards in the player's deck
	adds one for each copper card
	adds two for each silver card
	adds three for each gold card
	sums all values together


*/