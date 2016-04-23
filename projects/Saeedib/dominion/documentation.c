Documentation file

Smithy card:
In the game, the Smithy card has the purpose of drawing 3 cards and costs 4 coins.
we can see this in the dominion.c. in this card uses drawCard() function in a for loop that calls it 3
times (drawing 3 cards) and also in cardEffect the cost of the card is stated by (returning a value) of 4.

Adventurer card:
According to describtion, this card's action is to "Reveal cards from our deck until we have revealed 2
treasure cards. Put them into our hand and discard the other revealed cards. This card costs 6 coins.
According to the dominion code the card also costs 6 (since it returns the value 6 in the adventurer's case)
also there is a while loop with this condition (drawntreasure <2) which reflects the fact that we are drawing
2 treasure cards using drawCard() function.

discardCard():
according to this line :
discardCard(handPos, currentPlayer, state, 0);
^		^	^		^  ^
Function       from   player	state of the game
This function takes where we want the card discarded from, which player is discarding it and what state the
game is at while the card is being discarded.

updtaeCoins():
according to documentation :
int updateCoins(int player, struct gameState *state, int bonus)

this function takes the player, game state and the bonous value and adds how much coins need to be added to
the player's turn when it is called
