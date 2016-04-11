CARDS

smithy
* play: Action card that costs $4. Draw 3 additional cards. 
* code: The drawCard() method is called 3 times across the iterations of a for loop. This method adds cards from the deck to the player's hand.
The smithy card is then discarded from the hand. 

adventurer
* play: Action card that costs $6. Reveal cards from your deck until you reveal 2 Treasure cards. Put those Treasure cards in your hand and discard the other revealed cards.
* code: The variable "drawntreasure" is initialized to 0. In cardEffect(), a switch statement branches to case adventurer. In the branch, while "drawntreasure" is less than 2, then the following events occur: the deck is checked and if found to be empty, the discard pile is reshuffled and becomes the deck; a new card is drawn from the deck and the deck pointer is decremented; the new card is tested against the treasury values and if it matches one of them then "drawntreasure" is incremented, else the card is added to the temporary hand; After the while loop has completed, each card in the temporary hand is placed in turn into the discard pile.

METHODS

discardCard()
* code: method that takes as its arguments a pointer to a card in a player's hand, the id of the player, a pointer to the game state, and a flag for trashing purpose. If the flag is not set, add the card to the discard pile and increment the discard pile counter. Regardless of flag, set the played card's state to -1. Then remove it from the player's hand and decrement the number of cards in the player's hand. To remove the card from the hand, test whether the card was in the last position of the hand (in which case, decrement the handcount), or was the only card in the hand (in which case, do nothing). If neither case applied, replace the discarded card with the last card in the hand. 

updateCoins()
* code: method taht takes as its arguments a player's id, a pointer to the state of the game, and a bonus value. Reset to 0 the variable coins for that state. Iterate over the cards in the player's hand and if the card is a treasury card, add its value to "coins". Add to the sum the value of "bonus"
