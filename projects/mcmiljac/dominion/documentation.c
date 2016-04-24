Jacob McMillen
CS 362 - Assignment 2
10 April 2016

Documentation for adventurer and smithy card code, along with discardCard() and updateCoins() methods.

int playAdventurer(struct gameState *state){
	Parameters: pointer to current state of game

	Effect: currentPlayer is determined from game state, and drawnCard counter is initialized to 0. While drawnTreasure is less than 2, drawCard is called and cardDrawn is set to equal this card. If the cardDrawn is a treasure card (copper, silver, or gold), increment drawnTreasure; otherwise add the card to tempHand to be discarded later. Once 2 treasure cards have been drawn, discard all cards in tempHand.

int playSmithy(struct gameState *state, int handPos)

	Parameters: pointer to current state of game, position in hand of played smithy card

	Effect: currentPlayer is stermined from game state. drawCard() method is called 3 times for current player, whichadds 3 cards to their hand. discardCard() is called to discarded played smithy card.


int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

	Parameters: position in hand of card to be discarded, currentPlayer, pointer to current game state, trashFlag to determine whether card is discarded or trashed.

	Effect: If trashFlag is 0, card will be discarded - card is first added to top of discard pile and the number of played cards is incremented. The card is removed from hand by first setting it's handPos to -1. Then, if it was the last card in hand, simply decrement the hand size. If it was the only card in the hand then again, decrement hand size. Otherwise, replace position of discarded card with last card in hand, set last card to -1, and then decrement hand size.

	
int updateCoins(int player, struct gameState *state, int bonus)

	Parameters: player, pointer to current state of game, bonus coin amount

	Effect: Set the current number of coins in state to 0. Walkthrough player's hand. For each copper add 1 coin, for each silver add 2 coins, and for each gold add 3 coins. Finally, add the bonus coin amount to the coin total.
	
	Note: This function could be used in the playdom.c file to replace blocks of code that recount coins after a smithy or adventure is played.