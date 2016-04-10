/* Aleksandr Balab

Card type: Smithy

Adds 3 additional cards to your hand using for loop.
After 3 cards were drawn the smithy card is discarded.

Card type: Adventurer
Reveals cards from your deck until you reveal 2 Treasure cards.(while (drawntreasure<2))
Once it find either of treasure cards it increases the drawntreasure count in order to get out of the while loop.
If not a treasure card then we remove the top card.(most recently drawn) 
Once we found two treasure cards we enter another while loop where we discard all card in play that
have been drawn before finding the treasure cards.


Funtion name: discardCard()
Card is removed from players hand.
Adds the card to playedCards array if the trashflag has not been triggered.

Function name: updateCoins()
The function will loop thru all the player's cards.
Checks if the a card a treasure one. Checks what kind of treasure card it is and adds the respective value to the coin count.
After the for loop the passed bonus value is added to the coin count. 


*/