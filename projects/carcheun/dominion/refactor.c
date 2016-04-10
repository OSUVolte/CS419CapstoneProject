/******************************************************************
 * Carolyn Cheung
 * CS 362
 * Assignment 2
 * Description: Refactor smithy and adventurer. Then pick 3 more 
 * of my choice, which were council room, greathall, and minion
 ******************************************************************/

Adventurer
    calls playAdventurer() in switch statment
    code for adventurer moved into playAdventurer() function
    bug: Drawntreasure is set to 1 instead of 0 at initialization
    
smithy
    calls playSmithy() in switch statement
    code for smithy moved into playSmithy() function
    bug: discardCard doesnt discard current hand position, instead discards
    position 0.
    
council room
    calls playCouncilRoom() in switch statement
    code for council_room moved into playCouncilRoom() function
    bug: playCouncilRoom now has the player draw an additional card instead
    of all the other players in the game.
    
GreatHall
    calls playGreatHall() in switch statement
    code for GreatHall moved into playGreatHall() function
    bug: player 0 always draws an extracard, not current player
    
Minion
    calls playMinion() in switch statement
    code for Minion moved into playMinion() function
    bug: None