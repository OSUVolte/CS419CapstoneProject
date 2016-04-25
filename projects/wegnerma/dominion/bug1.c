//Assignment #3
//Bugs found in dominion code

//playAdventurer
I had set currentPlayer = 0 instead of whoseTurn(state) which 
resulted in an infinite loop when the unit test was run. Due to 
problems running the unit test on this case, I decided to change the
bug in that funtion to changing drawntreasure < 2 to drawntreasure > 2.
This caused all of the unit tests to fail for this function since 
most of the statements do not run in the function becuase the 
value of drawntreasure is initiazlied to 0 which is < 2.

Another bug I discovered in this function, was that all the unit tests
failed because the hand count was off due to the adventurer card not being 
discared at the end of the turn. To fix this handPos needed to be 
passed to the function and discardCard to discard the card.

A final bug found in this function is that the shuffle function was 
called on an empty deck which just returns -1. The cards from the 
discard pile first needed to be moved to the deck, like they are in
the drawCard() function. Once this is done shuffle can be called. 
Also, deck and discard counts needed to be adjusted to reflect 
this movement of cards.


//playSmithy
The only bug I found in this code is the one that I introduced. Instead
of < 3, <= 3 is used when determining how may cards to draw. This adds
4 cards to the hand instead of 3. Since the hand count is off, the 
unit tests for this function are not passed.

//playVillage
Again, the only bug I found in this code if the one I introduced.
The function does not draw card as it should. Because this leads to the 
hand counts being off, the unit tests for drawing a card fail.

//playGreatHall
Since I removed the discardCard() function from this function, it 
fails the unit test that tests if the card is discarded. It also
fails the draw card test because this function uses the handCount
which is off when a card is not discarded.