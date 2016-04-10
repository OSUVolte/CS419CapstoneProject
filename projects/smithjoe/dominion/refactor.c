The functions described below are defined in the file assignment2.c . This file is included in dominion.c
he implementations of smithy, adventurer, concilroom, feast, and gardens were refactored into the functions:


int smithyAss2(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer, int i)
int adventurerAss2(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int drawntreasure, int currentPlayer, int cardDrawn, int temphand[MAX_HAND], int z)
int councilroomAss2(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int i, int currentPlayer)
int feastAss2(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int i, int temphand[MAX_HAND], int currentPlayer, int x)
int gardensAss2()

the previous code was commented out.

adventurer bugs:
line 29 should be 2, not 1
while(drawntreasure<2){

councilroom bugs
line 55 should be 4, not 3
for (i = 0; i < 4; i++)

feast bugs
line 85 should be 0 , not 1
for (i = 0; i <= state->handCount[currentPlayer]; i++){

smithy bugs
line 15 should be 0, not 1
    for (i = 0; i < 3; i++)