Changes made to dominion.c while refactoring:
1.	smithyEffect method is added for smithy effect. This method is called inside 
	cardEffect function. gameState and handPos are passed as parameters.
2.	adventurerEffect method is added for adventurer effect. This method is called 
	inside cardEffect function. gameState and handPos are passed as parameters.
3.	councilEffect method is added for council room effect. This method is called 
	inside cardEffect function. gameState and handPos are passed as parameters.
4.	feastEffect method is added for feast card effect. This method is called inside 
	cardEffect function. gameState and choice1 are passed as parameters.
5.	mineEffect method is added for mine card effect. This method is called inside 
	cardEffect function. gameState, choice1, choice2 and handPos are passed as parameters.
Bugs are added as follow:
smithyEffect: In discardCard the parameter is changed to i from 0. 
adventurerEffect: The condition used to check if deck is empty is changed to less than 
				  equal to 1. While loop to discard cards is changed to z >= 0 instead of z – 1 >= 0
councilEffect: numBuy increment execution is removed, so player will never buy a card, which is one of the ability of councilroom card.
feastEffect: For backup Hand loop <= logic is changed to < so last card will never be copied 
			 to temphand. gainCard is moved inside where else if condition state->coins < getCost(choice1), 
			 so player will be able to buy a card more than coins.
