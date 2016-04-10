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


---------------------------------------
BUGS INTRODUCED
---------------------------------------

playVillage     - receives a struct instead of pointer to struct, modifications to game state will not persist after function returns
playAdventurer  - doesn't check for case that deck and discard pile are empty (because the deck and draw pile have been revealed already and they contain <2 treasure cards)
                  loop will run forever if the deck contains less than 2 treasure cards
playSmithy      - Off by one error causing function to draw 4 cards instead of 3
playFeast       - uses two loop index and array index values for moving hand to temp array, then back into hand
                  first loop uses "tempHandIndex" as loop control and array copy index
                  second loop uses i as loop control but for the copy source tempHandIndex is still used
                  the hand will be filled with whatever garbage values are at the handLenght+1 index

*/

