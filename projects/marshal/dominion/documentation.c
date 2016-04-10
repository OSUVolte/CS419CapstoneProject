/*Alex Marsh
CS362
Assignment 2
Documentation.c
 
Smithy- the smithy is one of the kingdom cards.  It is a pure action card that will be played in the action round of a players turn. In order to purchase the card durning the buying round a player must use 4 coins.  When a player plays the smithy, the player is then allowed to draw three cards from their draw pile.  In the code the smithy card is places in a switch statement in dominion.c. This statement is activated when played and the drawCard() function is called three times in a for loop.  
 
Adventurer- similar to the smithy card, the adventurer card is one of the kingdom cards.  It is also an action card that may be played in a players action round. The adventurer cost 6 coins.  When played the player should reveal cards from their draw pile until they find two treasure cards.  Once the player finds those treasure cards they may put the two cards in their hand, but must discard those cards revealed before them.  In the code the adventurer card is also in a switch statement.  When played the statement in dominion.c shows in a while loop: while we haven’t drawn two treasure cards, we continue to draw.  There is an if statement checking if the drawing deck is empty (deckCount < 1), and if so the discard deck is shuffled. The code then draws a card and checks if the card is a treasure card. If the card is a treasure card, the drawntreasure count is increased by 1. Otherwise the player discards the top card from their drawn hand.  Once the drawntreasure variable equals 2, the players drawn hand is discarded in a while loop.
 
discardCard()- this function takes four variables, the cards position in a hand(int), the current player(int), the game state structure, and the trash flag(int). This function looks at the card being played and verifies that the card is being played correctly. Once the check is complete the function looks at a players hand to remove the card. If the player plays the last card in their current hand or the player only has one card in their hand, the handCount variable is decreased by one. Else the players card is replaced by the last card in the hand and their last card is set to -1.  The players handCount is then decremented. This function simply returns a 0 when successful.
 
updateCoins()-this function takes three variables, the player(int), the gameState struct, and bonus points(int).  Once the function is called the coin count is set back to zero.  Then inside a for loop the function runs through all of the cards in the players hand.  If the card encountered is a treasure card, through if/ else if statements the appropriate points are totaled.  After the for loop any potential bonus points are added.  This function also returns a 0 when successful. 
*/

