Dane Schoonover
CS362_400
Assignment 2, part 2

Submit a file called documentation.c (.c file because github thinks you are using github for file storage if you use many .txt files) that contains documentation of smithy, adventurer cards. Documentation should contain your understanding of smithy and adventurer cards (code). It should also contain documentation of your understanding of discardCard() andupdateCoins() method.  Keep your documentation short, though there is no upper limit. Documentation.c file should contain at least 100 words.  


Smithy card: This is an action card that costs 4 to purchase. Its effects are +3 draws from a player's deck.


Adventurer card: This is an action card that costs 6 to purchase. Its effects are to draw from a player's deck until 2 Treasure cards are found. The player keeps those two treasure cards in their hand.


discardCard(): This function takes as parameters the position of the card in the hand, the player that is discarding, the game state, and whether or not the card is being trashed. It then either discards or trashes the card. This has some sub-functionality to modify the game state such as removing the card from the players hand and adding a discarded card to the played pile.


updateCoins(): This function takes as parameters the current player, game state, and the current coin bonus the player receives. It then updates the player's coin count based on what types of coins they have and/or bonuses.