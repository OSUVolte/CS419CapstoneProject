/*
 * documentation.c
 *
 *  Created on: April 10, 2016
 *      Author: Brian Brown
 */


/* The smithy card, when played, counts as an action for the current turn
 * that allows the current player to add 3 cards to their current hand. After it's effect,
 * the card is then added to the discard pile. It can be purchased for 4 coins.
 *
 * The adventurer card, when played, counts as an action for the current turn
 * that allows the current player to begin revealing cards from the player's deck
 * until two treasure cards have been revealed. Those treasure cards are then added
 * to the player's hand and all other cards, including the adventurer, are added to the
 * user's discard pile. This card costs 6 coins.
 *
 * discardCard() initially checks to see if the card is being validly discarded and not "trashed",
 * (removed from the game). It then calculates how many cards are still in the current player's
 * hand and keeps track of the amount of cards until there are no longer cards present.
 *
 * updateCoins() returns the value of coins that a user has in their hand. When called, the
 * function resets the player's total coins to 0, then adds up the value of the treasure coins
 * in the player's hand (1 for copper, 2 for silver, 3 for gold) and then adds in any bonus coins
 * that may or may not be present. The function then returns an integer value for the amount of coins
 * a user can have for the turn. To me, this indicates the maximum number of coins that a player can
 * play in each turn: the initial hand draw, followed by any actions that increase the amount of
 * coins. Note: nothing in the function removes coins from the total, this must be handled elsewhere,
 * most likely in actions of specific cards.
 */

