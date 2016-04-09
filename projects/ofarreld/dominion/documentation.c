/*

Name:				Daniel OFarrell
Course:				cs362-400
Date Created:			7 April 2016
Last Modification Date:		7 April 2016

Documentation:
	1. Smithy Card
	The smithy card is very straight forward. It allows the player to draw 3 new cards to 
	be added to their hand. This is handled through a for loop which just calls drawCard() 
	3 times. Next, the smithy card is discarded from the players hand. 

	2. Adventurer Card
	In the actual game, the adventurer card allows the play to keep drawing cards until 2 
	treasure cards are added to their hand. in this implementation, a random card is returned
	from drawCard(). if the card is shown to be a treasure card (id= copper, silver, gold), 
	an int counter is increased. Once the int counter reaches 2, the loops breaks and the 
	two treasures are added to the players hand. The other cards are added to the discard
	struct within the state object.

	3. discardCard()
	discardCard() is meant to simulate discarding a card from the players hand. Once called,
	it will check if a boolean trash flag is set. If not, the card is set to the playedCard
	struct. Next, the position will have it's card value (cards are stored as int's) set to
	-1. Then, an update routine will happen where handCount is decreased. If the card played
	is not in the last position, then other cards will set to show the last position.

	4. updateCoins()
	updateCoins() is meant to simulate an update of the total count of a players coins for
	each turn of play. First, the total is set to 0. Next, each card in the players hand is
	checked to see if it is a coin, with the total then being added to the players coins. 
	Finally, any bonus value is added to the player's coins, via the state->coins int.


*/