Jason Loomis
4/10/2016
Assignment 2: Documentation
Filename: documentation.c

=== FUNCTIONS ===

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag);

The discardCard() function updates the game state by removing the card in the
currentPlayer's hand at the specified handPos index from play. If the card is
NOT being permanently removed from play (trashed, trashFlag less than 1), it is
added to the player's playedCards and the number of played cards is incremented
correspondingly. The card at the specified handPos index is marked as -1, a
value not corresponding to any of the card types. Finally, the player's hand is
compacted by simply decrementing the number of cards in the player's hand if
the card is the last one in the hand (or only one), otherwise the hand is
compacted by moving the last card in the player's hand to the index of the
removed card and then marking that last card index as -1 and then decrementing
the number of cards in the player's hand. The function always returns 0.


int updateCoins(int player, struct gameState *state, int bonus);

The updateCoins() function updates the game state to reflect the total number
of coins in the player's hand. The function does this by iterating over each of
the cards in the player's hand, and incrementing the coin count by 1 for each
copper treasure card, 2 for each silver treasure card, and 3 for each gold
treasure card. If the player has any extra (bonus) coins, e.g. from a card
played, they are added to the coin total. The function always returns 0.


*** I am including documentation of the drawCard() function since it is used by
the Smithy and Adventurer card effects documented below ***


int drawCard(int player, struct gameState *state);

The drawCard() function updates the game state by drawing the card at the top
of the player's deck and placing it at the end of the player's hand. The number
of cards in the player's deck is decremented, and the number of cards in his
hand is incremented, correspondingly. If the player's deck is empty when
drawCard() is called, the player's discard cards are moved to his deck, the
discard pile is marked as empty, and the deck is then shuffled. Once the deck
has been shuffled, the card is drawn as indicated above. If the player has no
cards in his deck once the discard pile has been moved there, the function
returns a value of -1, otherwise the function always returns 0.


=== CARD EFFECTS IMPLEMENTATION ===

Smithy
EFFECT: +3 cards
IMPLEMENTATION: Playing the Smithy card updates the game state by drawing 3
cards from the current player's deck and putting them into his hand, using the
drawCard() function. Once the cards have been drawn, the played Smithy card in
the player's hand is marked as played by calling the discardCard() function.


Adventurer
EFFECT: Reveal cards from your deck until you reveal 2 Treasure cards. Put
those Treasure cards in your hand and discard the other revealed cards.
IMPLEMENTATION: Playing the Adventurer card updates the game state by drawing
cards from the currentPlayer's deck, using the drawCard() function, until 2
Treasure cards (copper, silver, gold cards) are drawn. Each drawCard() call
adds a card to the end of the player's hand. If, after the draw, the new card
at the end of the player's hand is NOT a Treasure card, it is effectively
removed from the player's hand by decrementing the number of cards in the hand
and the card is temporarily stored. When 2 treasure cards have finally been
drawn (and thus added to the player's hand) all of the non-treasure cards that
were temporarily stored are added to the player's discard and the number of
discarded cards is incremented corresponding. The function always returns 0.
BUGS: As implemented in the switch statement in the cardEffect() method of
dominion.c, the Adventurer card effect does not call discardCard() to mark the
card as played.
