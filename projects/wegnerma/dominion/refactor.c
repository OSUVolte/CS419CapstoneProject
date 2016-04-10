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
playAdventurer: Instead of using whoseTurn functions currentPlayer 
initialized to 0
playSmithy: for (i = 0; i < 3; i++) change to for (i = 0; i <= 3; i++)
so 4 cards are drawn instead of 3
playVillage: removed line to draw card, so no card is drawn when card
is played
playGreatHall: removed line to discard card so it is kept in hand after 
it is played
**************************************************************************/
