/*

 cardtest1.c -- SMITHY
 A bug was detected in the playSmithy() function. It was the one I introduced in our refactor two weeks ago: if the player's hand is greater than one, the player unnecessarily draws another card. That caused the actual values to be different expected values.
 
 cardtest2.c -- ADVENTURER
 Several bugs were dectected in the playAdventurer() function. In addition to the missing discard call for the adventurer card itself (as was noted in the class forum), there was the bug I introduced into the program.
 Instead of requiring two treasure cards to be drawn, my bug increments the drawntreasure by one extra, so that the player only actually draws one treasure card.
 
 cardtest3 -- VILLAGE
 A bug was detected in the playVillage function. The bug was the one I introduced in the refactor two weeks ago. 
    Instead of adding two to the players numActions, the bug actually subtracts one of the actions. 
 
 cardtest4 -- COUNCIL ROOM
    No bugs detected. All tests passed.
 

 unittest1 -- discardCard
    No bugs detected. All tests passed.
 
 unittest2 -- gainCard
    No bugs detected. All tests passed.
 
 unittest3 -- isGameOver
    No bugs detected. All tests passed.
 
 


*/