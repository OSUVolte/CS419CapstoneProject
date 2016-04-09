// Diana O'Haver
// Assignment 2

// Specs:
// Documentation of smithy, adventurer cards. 
// Documentation should contain your understanding of smithy and adventurer cards (code). 
// It should also contain documentation of your understanding of discardCard() and updateCoins() method.

// Smithy: 
//   The smithy card causes the user to draw three cards. It does not have any effect on Actions or Treasure. 

// Adventurer:
//   The adventurer card is an Action card that allows the user to draw cards from their deck until they 
//   find two Treasure cards, in essence "digging" for Treasure cards. The found Treasure cards are then
//   added to the user's hand and the cards drawn in the process are discarded.

// discardCard():
//   This function receives four values as parameters (handPos, currentPlayer, state, and trashFlag). 
//   The function checks if the trashFlag is set; if it is not, then the card is added to the played pile.
//   The function then removes the card from the player's hand, reducing the number of cards tracked in
//   handCount in the process. If the card is not the last card in the hand or it is not the only card in the
//   hand, the discarded card is replaced with the last card in the hand. 

// updateCoins():
//   This function receives three values as parameters (player, state, and bonus). The game state's coin count is reset to 0.
//   The function then loops through the player's hand, checking for Treasure cards, and adds together the number of 
//   Treasure cards in the user's hand. The game state's coin count is updated with this number as the function loops.
//   Whatever bonus was passed into the function is added to the the game state's coin count as the final step.