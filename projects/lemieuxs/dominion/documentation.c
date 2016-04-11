/*****************************

1. Smithy
If the Smithy action card is played, three cards are added to the current player's hand using the for loop. The smithy card is then discarded from the current player's hand.

******************************/


/****************************

2. Adventurer

After the Adventure Action card is played, a while loop is entered and exits only after two treasure cards are drawn. Before this condition is reached, the player keeps drawing cards. If the deck becomes empty, then the discard pile is shuffled and added to the deck. After the while loop exits, all cards that were drawn, except for the treasure cards, are added to the discard pile.

*****************************/


/*****************************

3. int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

The discardCard function takes as parameters three integers and a struct gameState pointer.
If the card has not been trashed, it is added to the Played pile.
The card is then removed from the player's hand.
A return value of 0 indicates success.

****************************/


/*************************
 
4. int updateCoins(int player, struct gameState *state, int bonus)

The updateCoins function takes two integers and a struct gameState pointer as parameters.
The coins variable in the state is reset to 0. Then, the for loop iterates through the cards in the player's hand. When a treasure card is encountered, the appropriate number of coins is added to the coins variable. Then, the bonus is added.
A return value of 0 indicates success.


**************************/
