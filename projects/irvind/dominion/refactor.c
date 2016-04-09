Brett Irvin
CS 362_400--Software Engineering II 
4/3/16
Assignment 2--refactor.c 

adventurerCard()
	change: Moved the card's execution from cardEffect switch statement to separate function adventurerCard()
	BUG: In the while drawntreasure statement, changed if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		to (cardDrawn == copper && cardDrawn == silver && cardDrawn == gold)
	
smithyCard()
	change: Moved from cardEffect switch statement to separate function smithyCard()
	BUG: Changed the loop parameters at the beginning of the function; function only draws 2 cards instead of 3. 

villageCard()
	change: Moved from cardEffect switch statement to separate function villageCard()
	BUG: Removed the call to discardCard.  Function no longer discards the played card from the current hand.

remodelCard()
	change: Moved from cardEffect switch statement to separate function remodelCard()
	BUG: The call to gainedCard now receives choice1 instead of choice2.
	
great_hallCard()
	change: Moved from cardEffect switch statement to separate function great_hallCard()
	BUG: Function now discards the cards in a player's hand in an infinite loop.

