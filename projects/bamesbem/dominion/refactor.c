Michael Bamesberger
Software Engineering II
Assignment 2: refactor.c
4-10-2016


Smithy:

The Smithy card was refactored into a function called playSmithy().
It is called from within the cardEffect() function. 

Inputs: int handPos, int currentPlayer, struct gameState *state

The function called the drawCard function three times. Then
the function calls discardCard, which discards the Smithy card. 

Output: returns 0

Bug: If the player’s hand is greater than 1, the player draws
another card. This is an unnecessary statement.
 if (state->deckCount[currentPlayer] > 1){
        drawCard(currentPlayer,state);
    }





Adventurer:

The Adventurer card was refactored into a function called
playAdventurer(). It is called from within the cardEffect()
function. 

Inputs: int drawntreasure, int currentPlayer,
struct gameState *state, int handPos, int cardDrawn,
int temphand, int z

The function uses a while loop to test whether the
drawntreasure variable is less than two (remember, the purpose
of the Adventurer card is to draw two treasure card from the
hand). Inside the while loop, the code draws a card from the
hand and tests whether it is a treasure card. If it is, the
drawntreasure variable is incremented. If not, the card is
removed from consideration.

Output: returns 0;

Bug: if the cardDrawn is a treasure card, the drawntreasure
variable increments by two (instead of one previously).





Embargo:

The Embargo card was refactored into a function called
playEmbargo(). It is called from within the cardEffect() function. 

Inputs: struct gameState *state, int choice1,
int handPos, int currentPlayer

The function increments the player’s coins by 2. Then the
function adds an embargo token to the supply pile and then
discards the embargo card with discardCard(). 

Output: returns -1 or 0;




Village: 

The Village card was refactored into a function called
playVillage(). It is called from within the cardEffect() function. 

Inputs: int currentPlayer, struct gameState *state, int handPos

The function calls the drawCard function once and increments
the player’s Actions twice. Finally the village card is
discarded with discardCard().

Output: returns 0;

Bug: Instead of incrementing the player’s numActions by two,
it decrements the variable by 1





Sea Hag:

 The Sea Hag card was refactored into a function called playSeaHag().
 It is called from within the cardEffect() function.

Inputs: struct gameState *state, int i, int currentPlayer

This function forces all other players (but not the person who played
the card) to discard the first card in their deck. Then, these players
are forced take a curse card, which becomes the top of their deck.

Output: returns 0;

Bug: An else statement was added inside the for loop, which returns 0.
In addition, there is a drawCard statement at the beginning of the
function that shouldn’t be there. 
