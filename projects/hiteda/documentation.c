/*******************************************************************************
 * Filename: 		Documentation.c
 * Author:		David Hite
 * Date Created:	4/5/2016
 *
 * Description:
 * Not actually a compilable C file.
 * Contains documentation for smithy and adventurer cards used in the CS362
 * implementation of the Dominion card game.
 ******************************************************************************/

Smithy:
Cost of 4
Draws three cards for the player and is then discarded.

Adventurer:
Cost of 6
Searches the player’s deck for two treasure cards by iterating through the deck. Any non-treasure cards that are revealed in the search are discarded.

discardCard():
Takes as parameters handPos (int), currentPlayer (int), gamestate (*state), and trashFlag (int). Returns an integer indicating success or failure of the function.
If the card is not trashed (indicated by trashFlag), put it in the played card pile. Set the card in the current player’s (currentPlayer) hand position (handPos) to -1. If the card to be discarded is the last card in the current player’s hand, simply decrement currentPlayer’s handCount by one. If the current player’s handcount is one, decrement currentPlayer’s handCount by one. Otherwise, replace the discarded card in the current player’s hand with the last card in his hand, set the last card to -1, and decrement currentPlayer’s handCount by one. Return 0 upon successful execution.

updateCoins():
Takes as parameters player (int), gameState (*state), and bonus (int). Returns an integer indicating success or failure of the function.
Sets the coin count to 0, then adds coins for each treasure card in the player’s hand by iterating through the player’s hand. If the current card is a copper card, add one coin. If silver, add two coins, and if gold, add three. Also add bonus, and return 0 upon successful execution.

