//
// Created by Michael Loo on 4/9/16.
//

/*
 * adventurer card
 *
 *it initializes drawntreasure to 0
 * while drawntreasure is less than 2, it allows the user to draw
 * if the deck is empty inside of the state struct, the discard shuffles
 *
 * the cards are drawn, and if they are treasure cards, drawntreasure increments
 * otherwise, it goes into a temp fake hand
 * then, it discards all hands drawn
 *
 * smithy card
 *
 * iterates through for loop 3 times, drawing three cards
 * then discards the cards in hand
 *
 * discardCard
 *
 *takes in four arguments
 * if the trash flag is set, then the card goes into the played pile
 * the played card is set to -1
 * the card is removed from the state variable for the current player
 * and the number of cards in that current player's hand is reduced by one
 * it checks for two different states, but does the same thing, not sure why
 * if it doesn't meet those two requirements, then it just replaces discarded card with last card in hand
 * sets the last card to -1
 * decrements the value for the number of cards in their hand
 *
 *
 * updateCoins
 * it first sets the number of coins in the state struct to 0
 * then iterates through the cards in the players hand.  For each card, it checks if it is a coin card
 * and increments the amount of money the player has depending on the card
 */