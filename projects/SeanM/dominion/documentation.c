/-------Understanding of Adventurer Implementation-----/

   The adventurer card on its own when played allows the player to draw cards until they have retrieved 2 treasure cards (copper, silver, or gold) from the deck. All the non-treasure cards that are drawn in order to retrieve the treasure cards are discarded.

   The code does this by entering a while loop based on a counter for drawnTreasure. Until drawnTreasure gets incremented by 2, the while loop will continue. The deck is not infinite, so the first check is that there is a card to draw, and if not the discarded cards gets reshuffled. The draw card function is then called to draw a card into the players hand. If the drawn card is treasure, the drawnTreasure variable is incremented. If the drawn card is not a treasure card, the index is stored temporarily in a variable called cardDrawn, and then stored at an index in an array called temphand. As cards are drawn any non treasure cards end up in temphand at a unique index. The player's handcount get decremented after drawing a non-treasure card as the card is not going to stay in the players hand. A counter keeps track of how many cards are non treasure, so we can keep track of the size of temphand and by proxy how many cards need to be discarded from the players hand. After the player picks 2 treasures, the indexes stored in temphand get discarded from the player's hand.

/-------Understanding of Smithy Implementation---------/

   The smithy card allows the player to draw 3 cards into their hand. The implementation is pretty simple, it loops a drawCard function 3 times to draw 3 new cards into the player's hand. The smithy card is then immediately discarded from the players hand.

/-------Understanding of discardCard() Function--------/
   
   In the game when a player plays certain cards, or ends their turn they end up discarding either a single card or their whole hand. This is different from trashed cards which are removed.
   
   The discardCard() function will discard a card from the players hand at location handPos (this is the current index in the player's hand array). The call can also include a trashFlag int that indicates whether or not the card is to be trashed and not placed into the discard pile. If the card isn't being trashed, the card is placed into the playedCards array so that if the player has more actions they can see what they've played. The card ID number is then set to -1 in the player's hand array so that it can no longer be played. Then the array undergoes a type of "sorting". If the card played was at the highest index of the array, the size of the hand (handCount) is decremented. If the card played was the last card in the players hand, handCount is decremented. Else, if the card was played from another position, the end card in the hand takes the position of the played card and handCount is decremented.


/-------Understanding of updateCoins() Function--------/

   In the game the player has to lay down treasure cards to add their value to the players money stocks they can use in that turn. 

   The code simplifies this by summing the value of all the treasure cards in the player's hand whenever the function is called. Since this can be run at several points in the players turn depending on which cards are played, the values is always set to 0 at the beginning and summed back up. 
