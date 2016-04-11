Smithy card: This card, when played, gives the player an extra three cards for his/her hand (done via three drawCard function calls) and then is discarded.

Adventurer: This card forces the user to reveal cards in his/her deck to the opposition until two treasure cards are found (copper, silver, or gold cards). If the player runs out of cards in their deck before finding two treasure cards, the deck is reshuffled and the drawing continues. After two treasure cards are found, all cards that were shown are discarded.

discardCard(): This function first checks to see if the card being discarded needs to be trashed or added to the discard pile. It then sets the played card to -1 and removes it from the player's hand while reducing the hand count.

updateCoins(): This function first sets the game state's coins to 0, then adds coins for each treasure card in the current player's hand (one coin for copper, two for silver, and three for gold). Finally, it adds a coin bonus if one is needed.