/*

Bug found in function isGameOver:
	When looping through all supply piles to find empties, the function only goes through 25 of the 27 card piles.
	If the last two card piles are empty, it will not trigger a 'Game Over'
	

Bug found in function scoreFor:
	When calculating a score with the gardens card, the function calls fullDeckCount with 0 as its second parameter.
	This means that it will only return a count of how many curse cards are in each deck, not the total card count 
	which is what is needed based on the purpose of the gardens card.

Bug found in adventurerCard
	The handCount is not updating as it should. This is because of the bug I introduced in assignment 2 that always assigns the deck count 
	to zero, forcing a shuffle. This also messes up the deck count. 
	Also, there is no call to discardCard at the end of the card's function.
	
Bug found in smithyCard
	For statement that should have player draw three cards never executes due to incorrect conditional introduced in assignment 2.
	
Bug found in cutpurseCard
	When looking through all players, to force everyone but the current player to discard a copper, the function actually causes the
	current player to discard a copper, not all of the other players due to a bug introduced in assignment 2.
	
	
	
	
	
Bug found. When a card is discarded using the discardCard function, it is added to a playedCard pile. When the turn is over,
	the played card pile, should be moved to the discardCard pile, with the discardCount increased, but it is not.
	
Possible bug: According to my understanding of Dominion, every player has a hand at all times, but it seems like only the 
	current player has an active hand. This could be an issue with how I was testing but I wanted to mention it.
	
	
Possible bug: In adventurerCard, shuffle is called when "state->deckCount[currentPlayer] < 1", but in the shuffle function,
	there is an if statement: "state->deckCount[player] < 1" return -1. This seems to be incorrect.
*/