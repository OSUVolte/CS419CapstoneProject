Refactor
John Fodrocy

Salvager Card:
	I implemented a salvagerEffect() function.
	I did this by using the same code from the switch statement found in the cardEffect() function.
	To make this easy, the salvagerEffect() function takes four arguments.
	First, an integer for choice one, next a gameState struct and two more integers, the current player and the hand position.
	I put a bug into the code by changing the if statement which checks if choice one is true to checking if it is false.
	This should have the effect of reversing what the choice does.
	
Embargo Card:
	I implemented an embargoEffect() function by using the same steps found in the switch statement.
	It takes four arguments, an integer for the choice the user made, a state struct, and integers representing the current player and hand position.
	I introduced a simple bug which adds three coins to the state instead of the two which the card is supposed to add.
	
Steward Card:
	I implemented a stewardEffect() function that uses the same code found in the switch statement implemented with arguments.
	It takes six arguments, three integers representing player choices, a state struct and integers representing the current player and the hand position.
	I introduced a bug which draws one card instead of two when choice one has a value of one.
	This may introduce a problem for testing, as the tests must cover three different options for choice one.
	
Adventurer Card:
	I implemented an adventurerEffect() function the same way I did the previous functions.
	It takes only three arguments, a state struct, an integer for the current player and an integer for the hand position.
	I introduced a bug which I personally run into many times by changing the lesser than to lesser than or equal.
	This will result in the adventurer card collecting only one treasure coin when it should collect two.
	
Smithy Card:
	As before, I implemented a smithyEffect() function with the same code from the switch statements by using arguments.
	Like the adventurerEffect() function, there are only three arguments.
	The arguments are a state struct, an integer for the current player and an integer for the hand position.
	The bug I introduced adds an extra call to drawCard() in every iteration of the loop.
	This will result in the player drawing twice as many cards as they should when playing a smithy card.