/* Brandon Swanson cs362sp16

Assignment 2

playAdventurere and playSmithy are implemented as is in a separate functions with necessary local variables defined
other 3 are left as stubs
refactor tested by running playdom

------------------------------------------------------------------------------------

Made code style and maintainability changes to playSmithy() and playAdventurer()
defined constants for the number of cards to be drawn, used for loop for unconditionally decrementing and loop controlling variable
corrected bug in playAdventurer that would occur when there were 0,1 treasure cards in the players deck/discard pile
corrected bug in playAdventurer that adventurer card was not discarded (play could have more than one action and use the adventurer card more than once otherwise)
refactor tested by running playdom

------------------------------------------------------------------------------------

Implemented playVillage as function
Implemented playFeast as function
removed now unused variables from cardEffect() function
removed while loop from function (while loop from original case statement),
there seemed to be no change to choice1 in the loop that would cause the state of the loop control variable to change
that loop would have run once or infinitely.
Instead if the choice is un-purchasable the function returns -1 which will signal failure all the way up the call hierarchy,  the player will be free to play the card again with a different choice

---------------------------------------------------------------------------------------

implemented playCouncil_room as function
very few changes to original, just named constants for loop controls and buy addition

---------------------------------------------------------------------------------------




*/

