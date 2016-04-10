John Christiansen (Chrijohn)
Each card or function has two paragraphs.  First is an explaination or requirements.
Second paragraph is how the function works (which may or may not be required for this assignment)

Smithy:
	This card is to draw three new cards.  This will add three cards from the draw pile/players deck into their hand.

	It loops 3 times drawing a new card each time (with the DrawCard() function).  
	Then the discardCard() function is ran to discard the Smithy card from players hand

Adventurer:
	This card will cause the player to continue to draw cards (from deck) until they draw two Teasure cards. 
	The two Treasure cards get placed in users hand while the other cards get placed on discard pile

	A while loop (looping until 2 treasure cards drawn) 
		will first shuffle discard into deck if necessary
		draw card
			Put in hand
			if Treasure, increase Treasure counter
			Else, put card in temp hand, remove from hand
				increase temp hand counter
	Loop through temp hand, adding all temp hand to discard pile
		

discardCard:
	This function is called to remove a card from a players hand.
	Usually called at the end of the players turn but sometimes as result of another card/action.
	Card will move from the players hand to the discard pile or in played pile (if card is getting trashed)

	Inputs: position in hard of card, current player, game, and a flag if card should be trashed
	If trashed flag not indicated, add card to played pile and increase counter
	Remove the played card from players hand array
		set played card to -1
			if last card in hand OR only card in hand, just decrease hand counter by 1
			else, swap played card with last card in hand and then decrease hand counter by 1

updateCoins:
	This function is called the before the "buy stage". 
	It will add coins to players turn based on the number of Treasure cards and bonuses already earned.
	3 for gold, 2 for silver, 1 for copper in hand 
	plus any bonus (coins earned from other cards/actions).

	Inputs: player, gameState, bonus)
		Set coins = 0
		Loop trough players hand adding correct coins for each Treasure card
		Add in bonus to coins


