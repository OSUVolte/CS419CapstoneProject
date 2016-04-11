************************
Smithy
************************
Type of Card: Action Card
Cost: $4
Action:
Draw 3 cards from current player's deck into current player's hand

In original dominion.c:
-In getCost() function, 4 is returned when Card is chosen

-In cardEffect() function, when Smithy is chosen:
     -drawCard() is called three times (in a for loop) to add 3 cards to the current player's hand
     -discardCard() is called to discard the Smithy from the current player's hand


************************
Adventurer
************************
Type of Card: Action Card
Cost: $6
Actions:
Reveal cards from current player's deck until 2 Treasure Cards are shown
Add the 2 Treasure Cards to the current player's hand
Discard other cards that were revealed

In original dominion.c:
-In getCost() function, 6 is returned when Adventurer is chosen
-In cardEffect() function, when Adventurer is chosen:
     -While there are less than 2 Treasure Cards revealed
          -If deck is empty, shuffle() discard pile and add it to the deck
          -Call drawCard() to get a card from player's deck
          -This card goes into the player's current hand
          -If drawn card is a Treasure Card
               -The card stays in the player's hand
               -The number of revealed Treasure Cards is incremented
          -If drawn card is not a Treasure Card
               -It is added to a temporary hand (that will be later discarded)
               -It is removed from the player's current hand
               -The number of cards in the temporary hand is incremented

     -After 2 treasure cards are revealed and placed into the player's current hand, the other cards from the temporary hand (those that were drawn but were not Treasure Cards) are discarded.

************************
Function: discardCard()
************************
Description: This function removes a card from a players hand into either the trash pile or the played card pile (based on the value trashFlag) and updates the state of the game with that information.
 
Parameters:
int handPos              indicates the position the card to be discarded
int currentPlayer        indicates the current player
struct gameState *state  indicates the state of the game
int trashFlag            1 if card is to be trashed, 0 if not


************************
Function: updateCoins()
************************
Description: This function will calculate the coin count in the hand of a player based on the treasure cards in the hand. This will be added to the amount of any bonus passed into the function. The function will update the state of the game with this information.

Parameters:
int player               indicates the player
struct gameState *state  indicates the state of the game
int bonus                indicates the amount of the bonus

