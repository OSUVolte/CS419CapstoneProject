Documentation of smithy cards, adventurer cards, discardCard(), and updateCoins() function from dominion.c
Author: Patrick Ho
Assignment: 2
Due Date: April 10, 2016

smithy card:
The smithy card allows the player to draw 3 additional cards. It is implemented in dominion.c's cardEffect() switch structure under the case, smithy.  Under this case, three calls to drawCard are made by passing in the currentPlayer # and the state of game, which is a container of information regarding the current game such as: number of players, whose turn it is, number of actions, number of coins, number of buys, what's in player's hand, what's in the deck, what's in the discard pile, and which cards have been played.  Once the three cards are drawn, remove the smithy card from hand by using discardCard().


adventurer cards:
The adventurer card is implemented in dominion.c's cardEffect() switch statement under the case, adventurer. The adventurer card allows the player to draw their deck until two treasure card (copper, silver, or gold) is revealed.  If their deck is empty, they shuffle their played deck and continue to draw cards until two treasure cards are drawn. Once those two cards are drawn, they go in the player's hands and all the cards that were drawn are discarded.


discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
This function removes a card from a player's hand.  Card at "handPos" is removed from the "currentPlayer"'s hand and placed into the discard pile. The "trashFlag" is used to remove card at "handPos" to the discard pile without invoking it's action.  Everytime a card is played, the gameState (card counts in hand, in deck) is updated.


updateCoins(int player, struct gameState *state, int bonus)
This function updates the coin count of a given "player" during a player's turn.  Coin count is tracked in the gameState object attribute, "state->coins".  The function loops thru each card in hand and determines if it is a treasure card (copper, silver, or gold).  If so, the coin count is accumulated with the value of the treasure count.  If during the action phase a card offers a +bonus coin value, then updateCoins will add that "bonus" into the accumulated coin count. 


