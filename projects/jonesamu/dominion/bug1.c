/*
Sam Jones
Date: 04/25/16

General Info
	I test invalid inputs by using numbers out of range or negative. To confirm my results
	I first confirm the methods perform as expected. I run the tests with inputs expecting them to pass. 
	
	
buyCard()
	There is no bound checking for whose turn it is.  The function executed
	without a problem when state.whoseTurn was an invalid number [negative and
	more than max players].  When using invalid input for state.whoseTurn 
	the test PASSED when I expect it to FAIL.  
	
	The function failed to add the card to the player's hand or deck.
	
	There is no bound checking for the supplyPos of card to buy.  An invalid
	card can be passed to getCost([card]).  If an invalid card is passed the
	getCost() the player gains a coin.
	
isGameOver()
	If a supply stack has ends up with a negative number it will not be viewed as empty
	& the game will continue
	
updateCoins()
	There is no validation for the bonus. So if we input a negative for the bonus it will subtract 
	from the bonus total instead of having no effect. 
	
gainCard()
	Again there is no input validation for gainCard(). This could cause all sorts of chaos
	
	
Smithy Card
	These bugs are the ones I introduced in assignment 2. I the smithy card 
	smithy card effect.
	
Adventure Card
	The adventurer effect does not add two treaure cards to the player's hand.
	The adventurer does not add any cards to the player's hand.
	
*/