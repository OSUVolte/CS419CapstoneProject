/******************************************************************
 * Michael Lee
 * CS 362
 * Assignment 2
 * *************************************************************/



Cards Adventurer, Smithy, Council, Village, and Great Hall we're all taken out of the card
Effect switch case and they were placed in their own functions which pass in
all of the necessary information into them.

Generally, the gamestate, currentplayer, and handpos, but for cardAdventurer: drawntrasure temphand, z,
and cardDrawn were passed in.

Other than that and the bugs, the code is identical to the one within the switch statement.

//bugs

cardSmithy has a miss-spelling of currentPlayer

cardCouncil does not have int i defined within the function (scoping)

cardVillage does not increment the right actions it only adds one action instead of state->numActions + 2

cardAdventurer is improperly defined in header file