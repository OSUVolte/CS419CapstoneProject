# Author: tranm2
# CS362 - Spring 2016

# Refactor 5 cards including smithy and adventurer
# so that cardEffect is replaced with each card's own function by introducing 5 new functions:
	- int smithy_effect(int currentPlayer, struct gameState *state, int handPos) i<=3 
	- int adventurer_effect(int currentPlayer, struct gameState *state) drawntreasure<=2 
	- int mine_effect(int choice1, int choice2, int currentPlayer, struct gameState *state, int handPos) discard trashed cards i == 0
	- int village_effect(int currentPlayer, struct gameState *state, int handPos) trashflag=1
	- int council_room_effect(int currentPlayer, struct gameState *state, int handPos)

# Subtle bugs must be included in 4/5 card effect,
# code must compile without error. Below is the list of bugs introduced
	- in smithy_effect() method, counter i set <=3 so player would withdraw more than 3 cards
	- in adventurer_effect() method, counter for drawn treasure is set <=2 so player would gain 3 treasure cards instead of 2
	- in mine_effect(), at the discard trashed cards step, trashflag is set to 1 instead of 0
	- in village_effect(), at the discard card from hand step, trashflag is set to 1 instead of 0