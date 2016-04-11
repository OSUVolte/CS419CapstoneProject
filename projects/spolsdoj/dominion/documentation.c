SMITHY
When used the player draws three cards.

It is implemented within a switch statement when the cardEffect function is called.

The card is a simple for loop that runs from i=0 to i<3. Within the loop the darwCard function is called.

At the end of the case the discardCard is called.

ADVENTURER
Reveal cards from your deck until you reveal 2 treasure cards.

It is implemented withinin a switch statement like SMITHY.

The main portion of the implementation is within a while loop that checks if drawntreasure is less than 2.

It first checks if the deck is empty. If so, it calls shuffle.

A card is drawn. The variable cardDrawn is set to the top card of the deck.

An if statement checks if the cardDrawn is copper, silver or gold.

If the drawn card is not a treasure it is put into temphand. The handCount is also -- to remove the top card.

Finally after the three treasure cards are drawn all cards that have been drawn are discarded. 
  
