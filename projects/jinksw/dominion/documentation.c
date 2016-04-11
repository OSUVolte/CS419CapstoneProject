Documentation for Smithy and Adventurer Cards

Documentation:
Smithy Card

getCost method.
returns 4

playSmithy method.

This function draws three random cards for the current player and game in the for loop by calling method drawCard() three times.
The card is played and discarded using discardCard(). Since the trash flag is 0, the card is not trashed, but is added to the played pile.
This also increments the played card count. 


Documentation:
Adventurer Card

getCost method.
returns 6

playAdventurer method.

drawnTreasure is set to 0 and represents a count of treasure cards drawn
currentPlayer is set to the player whose turn it is: int currenPlayer = whoseTurn(state)
cardDrawn is set to 0 and represents to current drawn card
tempHand is initialized as size of a maximum hand and holds non-treasure cards
z is initialized to 0 to represent drawn cards in temphand

A while loop is initialized until 2 treasure cards are drawn: while( drawnTreasure < 2 ). 

First the loop checks to see if the deck is empty. If it is, the discard pile is shuffled to add it to the deck:
if( state->deckCount[currentPlayer] < 1 ) { shuffle( currentPlayer, state ); }

Then draw a card: drawCard( currentPlayer, state );
Set cardDrawn equal to the top card of the hand/most recently drawn card: cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
If the card drawn is a copper, silver, or gold, the drawnTreasure increments
Otherwise, the drawn card is put into a temporary hand and the hand count of the player is decremented to remove the drawn card:
	temphand[z] = cardDrawn
	state->handCount[currentPlayer]--;
	z++;

After the loop terminates another loop: while(z-1>=0) is initiated to discard the non-treasure cards in the temp hand:
	state->discard[currentPlayer][state-discardCount[currentPlayer]++]=temphand[z-1];
	z=z-1;
