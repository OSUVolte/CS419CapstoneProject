/*************************************************************************
Marta Wegner
Assignment #2

Five cards implemented as functions:
line 647: adventurer
line 675: smithy
line 690: village
line 705: great_hall
line 720: cutpurse

switch statements for these five cards replaced with function calls
Unused variables removed from cardEffect function

BUGS:
playAdventurer: drawntreasure > 2 - the if statement that draws two
treasure cards will not run because drawntreasure start off as less
than two. Because none of this function will run, no unit tests that
test this function should pass.

playSmithy: for (i = 0; i < 3; i++) change to for (i = 0; i <= 3; i++)
so 4 cards are drawn instead of 3 - handCount will therefore be
inceased by 4 rather than 3.

playVillage: removed line to draw card, so no card is drawn when card
is played. The hand will therefore contain only the cards that were 
in the hand to begin with minus the village card.

playGreatHall: removed line to discard card so it is kept in hand after 
it is played also handCount will not decrement.
**************************************************************************/
