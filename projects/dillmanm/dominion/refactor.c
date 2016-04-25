/*
ALL BUGS OUTLINED BELOW WERE FOUND IN UNIT TESTS AND ARE FIXED IN LATEST VERSION

Refactor playAdventurer
declare currentPlayer, drawntreasure, cardDrawn, tempHand[MAX_HAND], z
Bug: for loop searches hand for two treasures after each draw then terminates
so that treasures already in hand are counted in addition to drawn treasures.
changed at line 1325

Refactor playSmithy
declare currentPlayer, loopvariable
Bug: check if deck has less than three cards left, end turn and return if true.
changed at line 1341

Refactor playGreatHall
declare currentPlayer
Bug: reassign handPos the enum value of handPos
line: 1288

Refactor playAmbassador
declare currentPlayer, loop variable, j counter to track discard
Bug: changed the index of the supply count from the player's choice 1 index to choice2
line 1330

Refactor steward
declare currentPlayer
bug: trashed cards do not go to the trash pile but just to the discard
line1356-7
*/