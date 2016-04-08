/*
The five cards I’ve implemented in functions at the beginning of dominion.c are as follows: smithy, adventurer, cutpurse, sea_hag, and tribute. The function names have been formed simply by appending “Action” to the end of the original card name.

First and foremost, I needed to change a few things so that the needed variables could be passed by reference. The variables state and temphand have been passed as-is since they were already pointers. Ints, however, have been passed by reference (C-style) by passing a pointer and dereferencing, where needed, in the functions.

Since the playdom.c file only contained the code necessary to play a game with smithy or adventurer, I added in code necessary for cutpurse, sea_hag, and tribute so that I could test my changes and make sure the program didn’t crash as a result of them. Some has been commented back out, so as to return the gameplay back to what was normally intended.

Changes made:

adventurerAction()- Originally, the while loop for discarding the cards in play continued while
((*z) – 1 > = 0). I’ve simply removed the -1 so that it’s while((*z) >= 0).

smithyAction()- The loop to draw cards now iterates four times instead of three because I made the comparison i <= 3 instead of i < 3.

cutpurseAction()- Where the for loop loops over the players to apply cutpurse to the other players (originally i != *currentPlayer), I changed it to apply to the current player instead ( i == *currentPlayer).

sea_hagAction()- Since I only need to make changes to four of five, I’ve decided to make no changes in this function.

tributeAction()- I changed the if statement that checks to see if the tributeRevealedCards are treasure cards so that it only checks for copper and silver. Gold has been replaced with another copper.

*/
