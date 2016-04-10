Smithy Card:
    The smithy card has a simple effect. It runs a loop calling the drawCard method three times, allowing the player to draw three cards. It then discards the card from its current position in the players hand.

Adventurer Card:
    The adventurer card cycles through the deck of the player until he or she has drawn two treasure cards. Code wise, the card works in the following manner:
    * We start with a counter, drawntreasure at 0.
    * We then start a while loop that runs until drawntreasure is at least 2.
    * Within the loop, we first check the deck to see if the player is able to draw cards. If there are no cards left in the deck, we shuffle the deck.
    * We then draw the top card of the deck and check to see if it is a treasure. If it is, we increment the drawntreasure counter.
    * If it is not, we add it to a temp hand array.
    * When we reach 2 treasure and the loop ends, we then iterate through the temp hand array and discard the cards that are part of it.

discardCard Method:
      The discardCard method takes four arguments:
        * handpos -- indicates the position in the hand of the card to discard.
        * currentPlayer -- the player who is discarding.
        * state -- a struct that holds persistent game information.
        * trashFlag -- indicates if the card is to be discarded or trashed.

      The method works as follows:
        * First it checks to see if the card is to be discarded rather than trashed. If it is, the card is added to an array representing the played cards.
        * Next the value of the card is set to -1 to identify it.
        * The method then checks if the handpos index indicates if the last card in the hand is being dicarded. If so, the handsize is decremented by one to remove the card from the hand.
        * The next (else if) check is if the player has only one card in hand. If this is the case, that card is discarded by decrementing the handsize.
        * The final block runs if the other two did not -- it sets the value of the discarded card equal to the last card in the hand, and the value of the last card in the hand equal to -1. Then it decrements the size of the hand to discard the swapped card.


updateCoins Method:
      The updateCoins method takes three arguments:
        * player -- the player whose coins are being counted.
        * state -- a struct that holds persistent game information.
        * bonus -- an int indicating if a bonus should be added to the count.

      The method executes as follows:
        * First the value of the coins counter of the state struct is set to zero.
        * Next a for loop is executed through the players hand.
        * In the loop, for each copper, silver, or gold found, the coins counter is increased by 1, 2, or 3.
        * After the loop, the coins counter is increased by the size of the bonus.
