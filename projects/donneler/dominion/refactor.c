/*************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 2
* Documents the changes made to dominion as well as the bugs that are
* introduced.

--------------------------------- Refactoring of the Code ----------------------------------
1 - Move adventerurer to its own fxn: int playAdventurer(int currentPlayer, struct gameState *state)
  - Add variable declarations/init in fxn for drawntreasure, cardDrawn, temphand[MAX_HAND], z.
  - Removed uneeded declarations/init from the cardEffect fxn for drawntreasure, cardDrawn, and z.
  - Add a return 0 to the fxn

2 - Moved smithy to own fxn: int playSmithy(int currentPlayer, struct gameState *state, int handPos)
  - Add variable declarations/init in the fxn for i.
  - Add a return 0 to the fxn

3 - Moved embargo to its own fxn: int playEmbargo(int currentPlayer, struct gameState *state, int 
	handPos, int choice1)
  - Add a return 0 to the fxn

4 - Moved mine to its own fxn: int playMine(int currentPlayer, struct gameState *state, int choice1, 
	int choice2, int handPos)
  - Add a return 0 to the fxn
  - Add declaration for i and j as ints in the fxn.

5 - Moved cutpurse to its own fxn: int playCutpurse(int currentPlayer, struct gameState *state, 
	int handPos)
  - Add declaration for i,j, and k as ints in the fxn.
  - Removed declaration of k in cardEffect fxn
  - Add a return 0 to the fxn

 -------------------------------------- Introducing Bugs --------------------------------------
 1 - playAdventurer
   - Removed initialization of drawnTreasure to 0, which causes drawnTreausures to not start at 0.
     (line 1247)
   - Change while statement to while(drawntreasure<=2) instead of while(drawntreasure<2), which 
    causes the adventurer to pull 3 cards instead of 2 (if the top bug didnt exist) (line 1252)
   - Did not add in the discardCard fxn that is missing - this means the player will have the same
   	 hand from the round the card is played to next round.


 2 - playSmithy
   - Remove return 0; after the call to playSmithy (line 782), causes the switch statement to
     continue to the next case
   - Remove discardCard Call
   - Change for statement to for (i = 0; i <= 3; i++) instead of for (i = 0; i < 3; i++),
     causes the loop to run 4 times instead of 3 (line 1275)
   - move return 0 statement into for loop - only draws one card before returning

 3 - playEmbargo
   - the return value is not passed back to the cardEffect fxn to return, so the return -1 will
   	 actually return 0


 4 - playMine
   - Remove the + 3 to the cost of the discarded card
   - the return value is not passed back to the cardEffect fxn to return, so the return -1 will
   	 actually return 0

 5 - playCutpurse
   - change update coins to be +3 coins instead of 2
   - change discard to gold instead of copper
   - move discard call into for loop

**************************************************************************/