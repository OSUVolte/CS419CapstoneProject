Documentation for Dominion Game - Assignment 2


Cards:

	Smithy Card:
		The concept of the smithy card is that when this card is played, the player who used it draws
		three cards followed by discarding the smithy card. 

		In the code the drawCard function is called three times using a for loop with the parameters
		currentPlayer and state. This gives the currently player the three cards. Then discardCard
		function is called which discards the smithy card from the currentPlayer who played it . 		


	Adventure Card:
		The concept of the adventure card is that the currentPlayer will keep drawing cards until
		two treasure cards are pulled. Then after the two treasure cards are pulled, the currentPlayer
		discards all non treasure cards that were pulled in the process of this.

		In the code this is achieved using a while loop. currentPlayer keeps calling drawCard function
		until copper, silver, or gold happens(a total of two). The drawnTreasure++ keeps track of this.
		If the the deck gets empty in the process, the currentPlayer's deck is reshuffled. The cards
		that are not treasures are kept track of using temphand[z]. These are then discarded at the end
		in another while loop after the while(drawntreasure<2) loop finishes. 	


Functions:

	discardCard():
		The concept of the discardCard function is to simply  remove a card. 

		In the code there are quite a few checks that take place. The parameters for the function
		takes in handposition, currentPlayer, gameState, and trashFlag. The position tells where it is 
		in the deck, then it is removed. If the card is marked for trashed, then the card is removed 
		from the deck entirely. If the card is not trashed, then it is added to cards in play. Then 
		number of cards in hand are adjusted, discarded card is replaced with last card in hand.

	updateCoins():
		The concept of the updateCoins function is to tally up the treasures. 

		In the code, the coins is reset to 0 when called, then for each treasure(copper, silver, gold)
		The appropriate coin amount is added to the count. Then the bonus amount is added to the coin
		tally. This is then the total amount of coins. 
