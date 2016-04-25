#include <iostream.h>

int main(int argc, char const *argv[])
{
    /* Refactor.c
    
    The following card logic was refactored from with switch statement to individual
    functions: Adventurer, Smithy, Village, Feast, and Council Room.

    Bugs introduced: 

    Adventurer - Each non-treasure card decrements the drawntreasur variable,
    allowing the player to take many more treasures than two.

    Smithy - Allows player to take five cards, rather than three.

    Village - Only adds one action, rather than two.

    Feast - Does not update coins for current player after player chooses card

    Council Room - Does not allow the zero'th player to draw a card.

    ####

    Assignment 3 test suite bugs found:
    cardtest1.c:
    * Player gets more than three cards when playing smithy

    cardtest2.c:
    * Player who plays adventurer gets incorrect amt of cards
    * adventurer does not go to playCards pile

    cardtest3.c:
    * Player does not get two additional actions after play of Village

    cardtest4.c: 
    * Each other player does not get card after council_room played
    * Council room does not go to playedCards

    */

    return 0;
}