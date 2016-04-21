/*************************************************************************
 * Jon Patterson
 * CS 362
 * Assignment 2
 * Description: Descrptions of changes made to dominion.c
 * **********************************************************************/


Smithy:
This already looks like a fairly correct implementation, so I instead added a bug by
changing the bounds of the for loop to <= 3 from < 3. This will make it draw 4 cards
instead of 3.


Adventurer:
This implementation I added another equal sign to the drawntreasure while loop, but
as I noted in the other file, this function already has an edge case where it will 
loop indefinitely. If there is some case in which there is only 1 treasure card in
the deck and discard pile, the first loop  will never exit. Since there are cards
in domininion that allow you to trash treasures, there exists a scenario where this
function would loop indefinitely.

CouncilRoom:
For this implementation I again used an off-by-one bounds error and also changed
the bounds of the "let other player draw a card block" to give it a 50/50 chance
of not allowing the other player to draw a card.

Cutpurse:
This card I implemented without implementing any error, to my understanding. The 
implementation is the same as what was originally included in the dominion.c file
but wrapped within a function call with the state as an argument. I also had to
re-set the currentPlayer variable as it was set outside of that scope and I figured
it would look a bit cleaner to have the function not using variables from the
calling state.

Village:
This card was simply implemented in the previous fashion, but I left the discardCard()
function within both the function implementation as well as the calling state, so playing
the Village card should cause two cards to be discarded, in some cases this may 
hit an out-of-bounds error, but in other cases it will just discard two cards.
