/*
Assignment 2
documentation.c
Understanding of smithy and adventurer card code, discardCard() and updateCoins().

adventurer: draw until gain two treasure cards, then discard all other cards drawn

smithy: draw three cards and discard smithy

discardCard(): checks if card is trashed and if not signals as played; removes from current hand position; removes from hand by decrementing count for cards in hand and, if there is more than 1 card in hand, setting new card in discarded card's former position

updateCoins(): sets coin count to zero and freshly counts the number of coins using by the treasure cards (copper, silver, gold) currently in the player's hand; adds the bonus
*/