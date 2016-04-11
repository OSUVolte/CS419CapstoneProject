/*

Documentation of Adventurer: 

Arguments: pointer to gamestate, address of temphand array, int temphand counter, int handpos (handposition)

Enter while loop that terminates when second treasure is drawn.
Check that there are still cards capable of being drawn in the player's deck. If not, shuffle the
current player deck. After shuffle condition is cleared, branch to drawCard call. Check drawn
card by comparing highest index card in hand to the three treasure cards. If it is a treasure
increment treasure count. Else add card to a temp hand array, decrement the handcount of the
player and increment the index of the temporary hand. End while loop. Then use while loop to discard
temphand z. Then return.

Documentation for Smithy:

Arguments: pointer to gamestate, handPos (handposition)

For loop draws three cards to current player's hands then discards the smithy card from the hand.

Documentation for discardCard

Arguments: int handPos (index of card in hand array), int currentPlayer (usually field in gamestate struct),
		   struct gameState *state, int trashFlag (0, regular: 1 determines whether it circumvents played card pile)

Checks if trashflag is empty and adds card to gamestate's played card pile if flag is empty. Then increments playedCardCount.
Sets the value at gamestate struct's currentPlayer hand array at index handpos outside of defined card enum to -1.
Remove card from player's hand. If handPos is the last indexed in hand, reduce number of cards. Else if only 1
card is left in hand, reduce number of cards in hand. Else, shift last card in hand to the played card index handPos
and set last indexed card value in hand outside enum to -1. Then reduce player handcount and return.
Final state: designated card removed from hand and hand clustered into subarray one card smaller than before.

Documentation for updateCoins

Arguments: int player (from gamestate struct member variable), struct gamestate pointer, int bonus)

Set gamestate coins variable to 0. Iterate over cards in current player's hand, increasing state's
coin count by amounts corresponding to copper = 1, silver = 2, gold = 3. Then add bonus (for woodcutter, for
instance) and then return. 
Final state: gamestate coin count updated.
*/