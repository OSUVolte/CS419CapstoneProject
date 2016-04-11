/**********************************************************
  Marta Wegner
  Description: documentaion of smithy and adventurer cards
  documentation of discardCard() and updateCoins()
 
 Smithy: When a player plays the smithy card they draw 3 cards 
 into their hand from their deck. When a smithy card is played 
 the drawCard() function is called 3 times and then the smithy
 card is discarded.


 Adventurer: Draws card from your deck until two treasure cards 
 are drawn. The other cards are discarded. A count of treasure 
 cards drawn is kept. The deck is shuffled if necessary and the 
 drawCard function is called. If the card drawn is a treasure it
 is kept in the hand and treasure count is increased by 1. If it 
 is not a treasure it is discarded. This continues until treasure
 count reaches 2.


discardCard(): discards card from hand
Parameters:
handPos - position of the hand of card
currentPlayer
game state - pointer to game state variable
trashFlag

If the trash flag is not set, card is put into the played pile.

In the hand array, the card played is set to -1. If the last card
in the hand was played or there is only one card in the hand, the
hand count is decreased by 1. Else the last card in the hand 
replaces the played card and then the hand count is decreased by 1.

Returns 0 on success


updateCoins(): Counts number of coins
Parameters: 
game state
bonus

Adds coins for each treasure card in hand (gold, silver, or copper)
Adds bonus to this coin count.
Stores total in state->coins
returns 0 on success
**********************************************************/