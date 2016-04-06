/*CS362 Spring 2016
Assignment 2
Tatsiana Clifton

Smithy card: It is an action card. If the player plays the smithy card, it will draw three additional
cards and place them into the player's hands. Then, the smithy card is discarded from the player's hands.

Adventurer card: If the player plays the adventurer card, it will draw cards from the player's deck until 
two treasure cards are drawn. All drawn card that are not a treasure card are kept in a temporary pile
and are discarded when two treasure cards are found. If during this process the deck becomes empty it 
is reshuffled.

discardCard(): This function excepts four arguments: handPos, currentPlayer, gameState, trashFlag. 
It returns zero indicating the success. If trashFlag indicates that a card needs to be discarded,
the function moves card to played pile, moves card from player's hand decrementing the number 
of card in the player's hands. If trashFlag indicates that a card needs to be trashed, the function
removes a card from the game to the trash.

updateCoins(): This function excepts three arguments: player, gameState, and bonus. It returns zero 
indicating the success. The function goes trough every treasure card in player hands and depending on
its value calculates the total amount of treasure cards in the player's hands. Then, it adds to 
this value the amount of the bonus. As a result, number of coins is set to new value.
*/
