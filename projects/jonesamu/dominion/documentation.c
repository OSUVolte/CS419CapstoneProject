
Assignment2 jonesamu
documentation.c
4/08/2016

Adventurer: Draw until you gain two treasure cards. Next discard all aditional draw cards.

Smithy: Draw three cards then discard smithy card.

discardCard(): checks if card is trashed and if not signals as played; removes from current hand position; 
removes from hand by decrementing count for cards in hand and, if there is more than 1 card in hand, setting new card in discarded card's former position

updateCoins(): re-sets coin count to zero and uses by the treasure cards (copper, silver, gold) currently in the player's to count. Adds round bonus
