# Documentation of Cards

## Smithy

The Smithy card costs 4 to purchase and draws three additional cards when played. 

The cardEffect() method details the implementation of this card's actions (as well as the other cards).
A simple loop first draws three additional cards into the player's hand, then afterward the card is discarded using the discardMethod (detailed below).     

Determining the cost of the cards is inside of the getCost() method.


## Adventurer

The Adventurer card costs 6 to purchase and its card text reads "Reveal cards from your deck until you reveal 2 Treasure cards. Put those Treasure cards into your hand and discard the other revealed cards."

The main while loop for the adventurer card checks for `drawnTreasure` being less than 2 (starting at 0) and continues to draw cards 
until two treasure cards are revealed. All other cards are placed into a temporary hand then discarded after each treasure draw.

## discardCard() method

    int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

The handpos is the current card position in the players hand, with the last card in the hand being at the top of the deck
The currentPlayer is the player whose cards we are looking at
state is a pointer to the gamestate struct which references the current game
trashFlag indicates whether the card should be added to the playedCard pile (discard pile) or the trash pile

## updateCoins() method

    int updateCoins(int player, struct gameState *state, int bonus)

This method updates the number of coins that are usable from a player's hand based on the total count of treasure
cards they have as well as any additional coin bonuses from played cards
