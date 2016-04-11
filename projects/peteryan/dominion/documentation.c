Smithy Card
When a smithy card is played the player draws three more cards for there current hand.  

Adventurer Card
When an adventurer card is played the players draws cards until two treasure cards are drawn.
If the deck is empty the discard pile is suffled then added to the deck.  If a card is drawn
that is not a treasure card it is held in an array of non-treasure cards drawn.  The array of
non-treasure cards is discarded after two treasure cards are drawn.

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
The discardCard function has four parameters.  The first parameter is an integer that represents
the position of the card played in the player's hand, that is being discarded.  The second
parameter is an integer that represents which play is discarding the card.  The third parameter
is a pointer to the gameState structure.  The gameState structure is used to access the player's
hand and array of cards played.  The final parameter is a flag for trashing the card.  If the flag
is set is not set it is added the array of cards played and the playedCardCount is incremented
by one.  The card played is set to -1.  If the card played is the last one in the player's hand, 
the handCount is decremented by one.  If there is only one card in the player's hand,
the handCount is decremented by one.  In any other situation the discarded card is replaced 
with the last card in the hand, then the last card in the hand is set to -1 and the handCount is 
decremented by one.  Returns 0, if executed.

int updateCoins(int player, struct gameState *state, int bonus)
The updateCoins function has three parameters.  The first parameter is an integer that represents
the player.  The second parameter is a pointer to the gameState structure.  The last parameter is
an integer that represents a bonus.  The coin count is reset to 0.  A loop is used to add the coins
in the player's hand.  Copper coins are worth 1, silver is worth 2, and gold is worth 3.  The bonus
is added to total of the cards in the player's hand.