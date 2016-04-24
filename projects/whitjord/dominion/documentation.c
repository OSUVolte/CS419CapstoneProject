/*

# dominion documentation 
 
## discardCard()

given the card position in the hand this function marks the card as played, 
it is already flages as trash. It then updates the state struct as needed, 
like incrementing the playedCardCount


## updateCoins()

this function loops through all the cards in the given players hand and adds 
coins to the game state.

* copper = +1 coins
* silver = +2 coins
* gold   = +3 coins

## smithy card

draws 3 cards, does not increase actions or coins


## adventurer card

draws cards until it can add two treasure cards to the players hand



*/
