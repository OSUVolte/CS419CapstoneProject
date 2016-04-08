/*
Submit a file called documentation.c (.c file because github thinks you are using github for file storage if you use
many .txt files) that contains documentation of smithy, adventurer cards. Documentation should contain your
understanding of smithy and adventurer cards (code). It should also contain documentation of your understanding of
discardCard() and updateCoins() method.  Keep your documentation short, though there is no upper limit.
Documentation.c file should contain at least 100 words.

The smithy card allows the player to draw three cards. The card is then put in the discard pile.

The adventurer card iterates through the deck, revealing the cards until two treasure cards are found. Once this
happens the two treasure cards are added to the players hand and the other revealed cards are discarded.

The discardCard method takes the position of the card in the players hand, the current player, a pointer to the game
state, and the trashFlag. If the trashFlag is set to 0 then the card was not trashed and is added to the list
of played cards. Otherwise the hand index is just set to -1. If the card was at the end of the player's hand or if
it was the only card in the player's hand then the size of the player's hand is simply decremented. Otherwise it is
replaced by the player's end card.

The updateCoins method takes the player, a pointer to the game state, and a bonus. It iterates through the players
hand, adding to the coin count in the game state whenever it encounters a copper gold or silver. It adds the bonus
at the end.


*/