/****************************************************************************
* FILENAME: refactor.c
* AUTHOR: Nickolas A. Williams
* DATE: 04/10/2016
* DESCRIPTION: Documents refactoring of adventurer, council_room, minion,
*    salvager, and smithy. Also documents bugs introduced in each of them
*    (except council_room, which has no bugs).
* INPUT: n/a
* OUTPUT: n/a
*****************************************************************************/
adventurer:
moved to playAdventurer(struct gameState *state, int currentPlayer, 
int handPos). Removed the initial if statement to check if the deck is empty
and add the discard pile to the deck.

council_room:
moved to playCouncilRoom(struct gameState *state, int currentPlayer, 
int handPos). I did not introduce any errors here.

minion:
moved to playMinion(struct gameState *state, int currentPlayer, int handPos, 
int choice1, int choice2). Switched the inputs of choice1 and choice2, so 
that choice1 is now tied to the discard hand, and choice2 is tied to the +2 
coins. It should be the other way around.

salvager:
moved to playSalvager(struct gameState *state, int currentPlayer, int handPos, 
int choice). Removed the second discardCard() call that finishes the else
case if choice is empty.

smithy:
moved to playSmithy(struct gameState *state, int currentPlayer, int handPos).
Changed the for loop to be i <= 3 instead of i < 3.