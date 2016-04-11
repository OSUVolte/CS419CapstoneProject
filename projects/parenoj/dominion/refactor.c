
/************************************************************************************************************************************
*Adventurer Refactor:
*
*
*I created a function adventurerCard() with 6 parameters which are the values that the adventurer card uses/modifies.
*They are int cardDrawn, int drawnTreasure, struct gameState *state, int currentPlayer, int *temphand (pointer because it is an array), and int z. 
*
*The 2 pointers are because these values need to pass by reference; gameState because it is a struct that needs to be modified within the function,
*and temphand, because it is an array which is just a pointer.
*
*I also created a function prototype at the top of dominion.c.
*
*I kept all of the variable names the same so I could just copy the code from the switch statement into a function. Then in the switch statement, I just have:
*return adventurerCard(etc); so that whatever the adventurerCard function returns, will be returned by the cardEffect function.
*
*I introduced a bug in the first if statement that is supposed to check to see if the deck is empty. This bug is twofold. I changed the conditional to " = 0". This will always assign
*the deckCount to 0 because it is not "==". Also, it was originally written as "< 1". If the deckCount ever drops below zero (-1, -2, etc) the conditional, even if it is fixed to "=="
*would not always catch an empty deck.
*
************************************************************************************************************************************/


/************************************************************************************************************************************
*Smithy Refactor:
*
*I created a function smithyCard() with 3 parameters; int currentPlayer, gameState *state, and int handPos. The switch statement returns the value that is returned from
*this function. I also created a function prototype at the top of the file. 
*
*Because we are not using C99 variables cannot be defined within the for loop, so I also added an int i into the smithyCard function for the for loop counter. 
*
*I introduced a bug by switching the conditional in the for loop from "< 3" to "> 3". This may be hard to catch, but this will make it so no cards are actually drawn with the smithy card.
*
************************************************************************************************************************************/

/************************************************************************************************************************************
*Cutpurse Refactor:
*
*I created a function cutpurseCard() with 3 parameters; int currentPlayer, gameState *state, and int handPos. The switch statement returns the value that is returned from
*this function. I also created a function prototype at the top of the file. 
*
*Because we are not using C99 variables cannot be defined within the for loop, so I also added an int i,j,k into the cutpurseCard function for the for loop counter. 
*
*I introduced a bug by changing the "!=" to a "==" which will instead of causing the effect of the card to apply to all of the other players, it will only affect the currentPlayer,
*which is incorrect. 
*
************************************************************************************************************************************/

/************************************************************************************************************************************
*Salvager Refactor
*
*I created a function salvagerCard() with 4 parameters; int currentPlayer, gameState *state, int handPos, and int choice1. The switch statement returns the value that is returned from
*this function. I also created a function prototype at the top of the file. 
*
*I introduced a bug in the discardCard function that happens within the if statement. The trash flag is set to 0, even though it should be 1. This will cause the card to get discarded but
*not trashed. This could be an easy mistake to make because of how relatively rarely the trash flag gets set.
*
************************************************************************************************************************************/

/************************************************************************************************************************************
*Great_Hall Refactor
*
*I created a function great_hallCard() with 3 parameters; int currentPlayer, gameState *state, and int handPos. The switch statement returns the value that is returned from
*this function. I also created a function prototype at the top of the file. 
*
************************************************************************************************************************************/