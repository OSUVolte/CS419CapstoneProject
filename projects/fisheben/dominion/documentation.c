/**************************************************************************************************
 * Documentation File for the game Dominion
 * Assignment 2
 * Submit a file called documentation.c (.c file because github thinks you are using github for
 * file storage if you use many .txt files) that contains documentation of smithy, adventurer 
 * cards. Documentation should contain your understanding of smithy and adventurer cards (code). 
 * It should also contain documentation of your understanding of discardCard() and updateCoins() 
 * method.  Keep your documentation short, though there is no upper limit. Documentation.c file 
 * should contain at least 100 words.
 *
 * Smithy Card is an action card that when played gives the player 3 more cards.  It is used in 
 * a strategy called Smithy Big Money, where the idea is to buy one Smithy at the start of the game
 * and another Smithy card shortly after.  Then for the rest of the game buy only money and victory
 * cards. see http://wiki.dominionstrategy.com/index.php/Smithy
 *
 * Adventurer Card is an action card that when played will reveal cards from the deck until 2 
 * treasure cards are revealed.  Then these two cards are added to the players hand.  Strategy-
 * Adventurer Card is a late game card that is ussually best used in a deck with few coppers.  
 * See http://wiki.dominionstrategy.com/index.php/Adventurer
 *
 * discardCard(struct gameState *state, int handPos, int currentPlayer, int trashFlag) 
 * gameState = pointer to gameState var, handPos = the position in the hand of the card to return
 * method puts the played card into the players played card pile if it was not 
 * trashed. The method then updates the players hand to reflect one less card. Method will return 
 * 0 on success.
 *
 * updateCoins(int player, struct gameState *state, int bonus)
 * gameState = pointer to gameState var, bonus extra Coins carried forward
 * Method will add the coins for each Treasure card in the players hand, and then add the bonus
 * coins to the total.  The total coins are then used to update the gameState object.  Method
 * returns zero on success.

