Assignment 2: Dominion Documentation

Lauren Miller
Software Engineering II (CS362)
4/6/2016

Smithy Card

Description: The Smithy card is played using a switch() to the Smithy case in cardEffect(). This calls drawCard() thrice for the current player and discardCard() for the Smithy card. 

The cost, as returned from getCost(), is 4.

Adventurer

Description: The Adventurer card is played using a switch() to the Adventurer case in cardEffect(). This, while the count drawn treasure is less than 2, checks the state of the current player’s deck and shuffles using shuffle() if if there is less than 1 card. Inside this conditional, it also draws another card using drawCard(), then, acts based on what type of card it is. If it is a treasure card, the drawn treasure count increases. If not, this card is added to temphand[]. This continues until the count of the drawn treasure is equal to 2. Then, if there are any cards in temphand[], these cards are discarded. In short, two treasure cards are drawn and the rest of the drawn cards are discarded.

The cost, as returned from getCost(), is 6.

discardCard()

Description: if the trashFlag is not set, then the card in the hand of the current player at handPos is added to the played pile for the current player and that players count of played cards is increased.This card in the hand of the current player is set to -1. Then, if the count of cards in the player’s hand is the same as the handPos, that is if there are 0 cards left in hand, the hand count for the current player is decreased by one. If there is 1 card left, likewise, the hand count is also decreased by 1. Otherwise, the discarded card is replaced by the last card in hand, and the last card in the hand is set to -1. The count of the player’s hand is also decreased by 1. In short, it reduces the number of cards in the hand, optionally adding it to the played pile depending on the trashFlag.
Input: handPos is the position the card to be discarded, currentPlayer is the int representing the current player, state is the gameState struct with the hand and hand count of the player, and trashFlag is the int that determines whether the card should be added to the played pile before it is removed from the hand.
Output: 0
Declared In: dominion_helper.h
Defined In: dominion.c
Declaration:  int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag) 

updateCoins()

Description: It loops through the hand of the current player, adding to the count of the coins by 3 if the card is a gold, 2 if it is a silver, and 1 if it is a copper. It also adds the bonus value input. In short, is totals the treasure in hand.
Input: the player is the int that represents the current player, state is the gameState struct that holds the coins value and the hand of cards, and bonus is an extra amount to be added to the coins value.
Output: 0
Declared In: dominion_helper.h
Defined In: dominion.c
Declaration: int updateCoins(int player, struct gameState *state, int bonus)


