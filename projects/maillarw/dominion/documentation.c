/*
Documentation for Dominion
William Maillard
CS 362

----smithy---
Calling the smithy card simply draws three cards for the current player by calling drawCard() 
three times, then discards the smithy card by calling discardCard() for the current player  

---adventurer---
Calling the adventurer card does the following until the number of treasure cards drawn is 2 (the point of this card
is to have the current player draw until two treasure cards are found and add those cards into the player's hand):
1. Check the current players deck with deckCount and if it is empty, refill it by calling shuffle()
2. Draw a card with drawCard() (place the card in the player's hand)
3. If the card drawn is a treasure card, increase the number of treasure cards drawn by 1;
Else place the drawn card into a temporary hand (remove it from the current player's hand) and increase the count of 
cards in the temporary hand.
4. Repeat back to 1 until the number of treasure cards drawn is 2
5. Discard all of the cards in the temporary hand.


---discardCard ()---
Discards a card from the current player's hand
Input: int handPos, int currentPlayer, struct gameState *state, int trashFlag
Return 0 on success
Does the following:
1. Checks to see if the card has been trashed and if not adds it to the played pile
2. Sets the current card in the players hand to -1, meaning it is dead.
3. Does one of the following things, all of which just remove the dead card from the player's hand:
	1. If the card is the last in the hand array, just decrement the hand count.
	2. If the card is the only card in the hand array, just decrement the hand count.
	3. Otherwise, take the last card int he hand array, swap it with the dead card, and decremnt the hand count
	
--updateCoins()--
Updates a players coin count based on the player's hand, possibly adding a bonus number of coins.
Input: int player, struct gameState *state, int bonus
Returns 0 on success
Does the following:
1. Resets the player's coin count to 0
2. Increments the coin count by 1 for copper, 2 for silver, and 3 for gold
3. Increments the coin count by the bonus amount






*/