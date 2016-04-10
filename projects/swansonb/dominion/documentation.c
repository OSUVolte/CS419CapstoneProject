/* Brandon Swanson cs362sp16

Assignment 2

Understanding of Smithy and Adventurer cards:

The cardEffect function contains a gigantic switch statement that switches on the card type and then executes the cards behavior, in some cases using the dominion_helper functions like drawCard
These helper functions all receive a state parameter which is a struct containing the variables that define the game's state, such as players hands, the cards in the deck, which player's turn it is.  There is only one instance of this struct at a time and it is passed between functions which modify the game state by modifying this struct. because they receive a pointer to the struct the functions changes to the struct persist outside of their scope and in this way these helper functions affect the game state not through their return value but by modifying this  single struct.
Both of the cards effects are currently executed in the cardEffect function which is called by the playcard function which is called by the main game playing loop (int main)

Smithy:
Intended behavior: current player draws 3 cards from players draw pile and add those cards to player hand
This card's behavior is executed by making use of the drawCard function in a for loop 3 times,  this is done inside the cardEffect function and it should be noted that the length of the for loop is hardcoded instead of referenced from the a property of the smithy card.

Adventurer
Intended behavior: Reveal cards from your deck until you reveal 2 Treasure cards. Put those Treasure cards in your hand and discard the other revealed cards.
This card's behavior is executed by repeated calls to drawCard() until two treasure cards have been drawn, then discarding the other cards.
It does this by tracking the number of treasure cards drawn (drawnTreasure), incrementing this on a 3 way or statement checking if the card is copper, silver or gold.  If  not the card is removed from the player's hand and added to a temporary array that will be discarded (without using the discardCard helper function) at the end, after two treasure cards have been found.  This is done because those revealed cards should not be shuffled in with the previous discards if a shuffle occurs.  This code has a logic error, or runtime bug in that in the case that the player's deck only contains 1 treasure card this loop will run forever.

discardCard():
As mentioned earlier this function modifies the game state by making changes to the gameState struct that it receives a pointer to.  It also receives an index of which card to remove from a player's hand, which player will have a card discarded, and a flag for trashing the card (subset behavior, card is removed from hand but not put in playedCards array that will later get shuffled back into player's deck),  The reason for the currentPlayer variable instead of just referencing the game state struct's whosTurn variable is that some card actions cause a discard from the opponent's hand.  This function avoids moving cards within the player hand array by tracking the number of cards,  if that card was the last card of the only card in the hand, the hand size is reduced (not the size of the array but a variable that would let other loops know how much of the array to iterate over.  otherwise the handSize is reduced by one and the last card in the hand is moved to the position where the discarded card was.

updateCoins():
This function is used to determine how many coins a player has at their disposal (in their current hand).  Unlike the decks and hands this coin has only one state at a time, and is calculated for one player at a time.
The functions receives the player that should be calculated, the pointer to the game struct, and a bonus to be applied (from action cards or otherwise).
It first resets the coin count,  then iterates over the cards in the specified player's hand, adding the appropriate values if the card is either a copper, silver or, gold.
finally it add the bonus.
This computed coin value is stored in the game state struct, not returned.


*/
