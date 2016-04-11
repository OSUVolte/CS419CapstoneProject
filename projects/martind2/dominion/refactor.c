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

    */

    return 0;
}