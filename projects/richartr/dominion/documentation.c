/*********************************************
** Name: Trent Richardson
** File: Assignment 2 - documentation.c
** Class: CS362-400
*********************************************/

Adventurer - This card is an action card that when played will keep drawing cards from
a player's deck until two treasure cards have been drawn.  Until the player has drawn the
two treasure cards, the card performs the following in a loop: check to see if the player's
deck is empty.  If it is, it shuffles the cards in the discard pile and calls drawCard().
drawCard() will draw and add the two treasure cards to the player's hand while the cards that
are not treasure cards will be placed into the discard pile (temp array then discarded).

Smithy - This card is an action card that is called in cardEffect(). When called, it will add 3
cards from the player's deck to the player's hand. This is done by calling drawCard() 3 times then
calling discardCard() to discards the Smithy card from the hand. If the player's deck is empty
before drawCard() is called, the discarded pile of cards is shuffled into the deck.

discardCard() - this method discards a cards from a player's hand, depending on the cards played
during the player's turn.  The 2 discard methods are: a) the card is removed from the player's
hand and trashed and b) the card is removed from the player's hand and placed into discard pile
to be later reshuffled into the player's draw deck.

updateCoins() - this method checks the number of coins held by the player.  The method iterates
over each card to check if the card is a treasure card.  If the card is a treasure card, then
the number of coins is updated accordingly (copper +1, silver +2, gold +3, and any bonus cards).
