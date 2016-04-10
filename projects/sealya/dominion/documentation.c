/*
CS 362, 4-8-16, Assignment 2, Aaron Sealy

The smithy card -
It is from the base set (not from the expansion packs). It is an action card.
It costs 4 coins.  When it is played, the player draws three cards and adds them to his or her hand.
The card is then discarded.
Code summary:  drawCard() is called 3 times in a for loop and then discardCard() is called.

The adventurer card -
It is from the base set (not from the expansion packs). It is an action card.
It costs 6 coins.  When it is played, the player begins revealing cards from his or her deck until
two treasure cards are revealed and added to the player's hand. If the deck needs to be reshuffled
, the cards that have already been revealed are not reshuffled. All revealed cards not placed into the
player's hand are discarded.
Code summary: In the first while loop, while drawntreasure is less than 2, if deckCount < 1 then call
shuffle(), then call drawCard() and set cardDrawn to the drawn card, if this is a treasure card then
increment drawntreasure and if else then move this card to temphand.  In the second while loop, while
the z counter for the temphand is more than zero, discard a card and decrement z.

discardCard() -
    Description: This function discards a card from the player's hand to the discard pile or played pile.
    Arguments: handPos, currentPlayer, *state, and trashFlag.
    Returns:  0 indicates success.
    Code summary:
        If trashFlag is false, add the card to the played pile and increment playedCardCount.
        Set discarded card to -1.
        If the discarded card was the only card in the array or was the last card in the array,
            then decrement current player's handCount.
        Otherwise, swap the discarded card with the last card in the hand array and decrement handCount.

updateCoins() -
    Description: This function has to be called before the buy stage.  It calculates the total value of
        the player's treasure cards and bonuses that can be used in the buy stage.
    Arguments: player, gameState, and bonus.
    Returns: 0 indicates success.
    Code summary:
        set coins to zero.
        Use a for loop to move through hand array.
            +1 to coins for a copper, +2 for silver, and +3 for gold cards.
        Then add bonus amount to coins.
*/
