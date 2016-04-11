/*smithy documentation
  calls drawCard method three times
  then discards smithy and returns
*/

/*adventurer documentation
  the implementation uses a while loop to draw from the deck until the drawntreasure == 2
  in the loop - it first shuffles the deck if the deckCount is zero
  then it calls drawCard and inspects the most recently drawn card
  if the most recently drawn card is a silver, gold, or copper, it increments drawntreasure
  else it places the drawn card into a temphand array and removes it from the current hand
  the integer z is used to track the number of cards in the temphand
  
  once two treasure cards are drawn and the while loop completes, z cards in the temphand
  are added to the discard card array in state
  the case then returns
*/

/*discardCard() documentation 
  accepts the handPos as an integer, the value of the currentPlayer as an integer, 
  a pointer to the current gamestate struct, and an integer trashFlag
  
  the card is identified by looking at the handPos of the hand of the current player (2D array in gamestate)
  if the trashFlag is not set (less than 1), the card is added to the playedCards array in
  the gamestate struct
  
  the value of the card in the hand is set to -1 to show it is gone
  
  if the handPos was equal to the handCount - 1, the card was the last card in the hand array,
  so handCount is just decremented
  if the handCount was equal to 1, the card was the only card in the hand array,
  so handCount is just decremented
  else the value of the current cards index is set to the value of the last card in the hand,
  the value of the index of the last card in hand is set to -1, and handCount is decremented
*/

/*updateCoins() documentation
  accepts the value of the player as an integer, a value bonus as an integer,
  and a pointer to the current gamestate struct
  
  sets value of coins variable in gamestate to 0
  
  iterates through all cards in a players hand (from 0 to handCount)
  if the card is a copper, adds 1 to value of coins,
  if the card is a silver, adds 2,
  if the card is a gold, adds 3
  
  finally, adds bonus to coins, and then returns
*/