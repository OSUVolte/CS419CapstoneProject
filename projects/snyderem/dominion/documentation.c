/*

** ALL INFORMATION ON DOMINION RULES WAS FOUND ON WIKI.DOMINIONSTRATEGY.COM **
SMITHY

	Per the rules of Dominion the Smithy card is an action card that allows the 
  player to draw three cards.

  In this implementation, the Smithy card has a simple for loop the player to 
  draw three cards. The Smithy card itself is then discarded, the position of 
  which is passed into the function as handPos. 

ADVENTURER

	Per the rules of Dominion the Adventurer card allows you to "Reveal cards from 
  your deck until you reveal 2 Treasure cards. Put those Treasure cards in your 
  hand and discard the other revealed cards."

	In this implementation, when the adventurer case is entered a while loop begins
  that continues until two treasure cards have been drawn. First, the number of 
  cards in the player's deck is checked, and if it is less than one the deck is 
  shuffled. Next, a card is drawn and then looked at. This occurs, by first adding
  a card to the player's hand using the drawCard function and then by looking
  at the top card in the hand, which is the most recently drawn card. If the
  card that was drawn is a treasure card, the treasure card count is incremented
  and the card remains in the hand. If it is not a treasure card, it is added
  to the temporary hand and removed from the player's hand. The counter for the
  number of ccards in the temporary hand is then incremented. This loop continues  
  until two treasure cards have been drawn.

	Once the two treasure cards have been drawn, the cards in the temporary hand 
  are discarded one at a time using another while loop. While there are still
  cards in the temporary hand the top card in the temporary hand is  discarded 
  by the current player and that player's discard count is increased by one.

discardCard()
	
  In Dominion rules there are two ways that cards can be removed from a player's
  hand, by being trashed or by being discarded. If a card is trashed it is 
  placed in a seperate Trash pile which will not every be shuffled back into
  the player's deck. If a card is discared it is placed in the discard pile
  until there are no more cards in the player's deck, at which point the discard
  pile will be shuffled back into the deck.

  This function first checks if the card was trashed or discarded. If the trash
  flag has not been set (it is less than one), it is added to the played cards 
  and the played card count is increased by one.

  The played card in the player's hand is set to -1 and the card is removed from
  the hand. If the last or second to last card was played, all that occurs is 
  the count of cards in the player's hand is decremented by one. Otherwise, 
  the handPos is set to the next card to play, which is the card at one less than
  the current hand count, the last card is then set to -1 and the hand count is
  decremented by one. 

  When this is finished the function returns 0.

updateCoins()
 
  First the coin count is set to 0. Then it loops through all of the cards in
  the player's hand and adds the appropriate value to the coin count for each
  Treasure card. If a card is Copper 1 is added, if it is Silver 2 is added and 
  if it is Gold 3 is added. Then the value of the bonus that is passed as a 
  parameter is added to the coin count. When this is finished the function returns
  0.

*/
